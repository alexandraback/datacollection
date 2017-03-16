#include <fstream>
#include <iostream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

unsigned long long Euclide(unsigned long long a, unsigned long long b) // prototipo della funzione Euclide //
{
    if (b == 0) return a; // controlla che b non sia 0, in caso restituisce a //

    unsigned long long r;
    r = a % b;             // operazione modulo //
    while(r != 0)          // ciclo di iterazione //
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

bool isntMult(unsigned long long q)
{
    if(q==1)
        return false;
    if(q%2==1)
        return true;
    return isntMult(q/2);
}

int main()
{
    unsigned long long t;
    unsigned long long p, q, mcd;
    char c;
    in >> t;
    for(unsigned long long i=1; i<=t; i++)
    {
        unsigned long long counter=0;
        in >> p >> c >> q;
        mcd=Euclide(p,q);
        p/=mcd;
        q/=mcd;
        if(isntMult(q))
            out << "Case #" << i << ": impossible" << endl;
        else
        {
            while(p<q)
            {
                counter++;
                q/=2;
            }


            out << "Case #" << i << ": " << counter << endl;
        }

    }
    return 0;
}
