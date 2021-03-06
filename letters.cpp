// 1 = 0..19
// 2 = 20..99
// 3 = 100..999
// 4 = 1000 ... 9 999
// 5 = 10 000 .. 99 999 -> Atentie la 11, 12, 13
// 6 = 100 000 .. 999 999
// 7 = 1 000 000 ... 9 999 999
// 8 = 10 000 000 .. 99 999 999
// 9 = 100 000 000 .. 999 999 999
// Default = 1 000 000 000


#include <iostream>
using namespace std;



string convert(int numar, bool doi){

    switch (numar)
    {
    case 0:
        return "zero";
    case 1:
        if (doi) return "o";
        else return "unu";
    
    case 2:
        if (doi) return "doua";
        else return "doi";

    case 3:
        return "trei";

    case 4:
        return "patru";

    case 5:
        return "cinci";

    case 6:
        if (doi) return "sai";
        else return "sase";

    case 7:
        return "sapte";
    
    case 8:
        return "opt";

    case 9:
        return "noua";

    case 10:
        return "zece";

    case 11:
        return "unsprezece";

    case 12:
        return "doisprezece";
    
    case 13:
        return "treisprezece";
    case 14:
        return "paisprezece";
    case 15:
        return "cincisprezece";
    case 16:
        return "saisprezece";
    case 17:
        return "saptesprezece";
    case 18:
        return "optsprezece";
    case 19:
        return "nouasprezece";
    }

}


int nr_cifre(int n)
{
    int i = 0;
    if (n == 0)
        return n;
    else
    {
        while(n )
        {
        i++;

        n = n / 10;
        }
    }

    return i;
}


void alg(int numar, int alegere){

    switch (alegere)
    {
        case 1:
            cout << convert(numar, false);
        break;

        case 2:
            cout << convert(numar / 10, true) << "zeci";
            if (numar % 10 != 0) cout << "si" << convert(numar % 10, false);
        break;

        case 3:
            if (numar / 100 == 6) cout << convert(numar / 100, false) << "sute";
            else cout << convert(numar / 100, true) << ((numar / 100 == 1)? "suta" : "sute");
            //---
            if (numar % 100 != 0) {
                if (numar % 100 < 19) alg(numar%100, 1);
                else alg(numar%100, 2);
            }
        break;

        case 4:
            if (numar / 1000 == 6) cout << convert(numar / 1000, false) << "mii";
            else cout << convert(numar / 1000, true) << ((numar / 1000 == 1)? "mie" : "mii");
            //-- sute
            if (numar % 1000 != 0) {
                if (numar % 1000 < 19) alg(numar%1000, 1);
                else if (numar % 1000 <= 99) alg(numar%1000, 2);
                else alg(numar % 1000, 3);
            }

        break;

        case 5:
            if (numar / 1000 <= 19) {alg(numar/1000, 1); cout << "mii";}
            else {alg(numar/1000, 2); cout << "demii";}
            //sute
            if (numar % 1000 != 0){
                if (numar % 1000 < 19) alg(numar%1000, 1);
                else if (numar % 1000 <= 99) alg(numar%1000, 2);
                else alg(numar % 1000, 3);
            }

        break;

    }

}


int main(){
    
    int numar;

    cout << "Alege un numar [0 ... 1 000 000]: "; cin >> numar;
    cout << "Transformarea: ";

    if (numar < 19) alg(numar, 1);
    else {
        switch (nr_cifre(numar))
        {
        case 2: alg(numar, 2); break;
        case 3: alg(numar, 3); break;
        case 4: alg(numar, 4); break;
        case 5: alg(numar, 5); break;
        case 6: alg(numar, 6); break;
        case 7: alg(numar, 7); break;
        case 8: alg(numar, 8); break;
        case 9: alg(numar, 9); break;
        }
        
    }
    
    return 0;
}
