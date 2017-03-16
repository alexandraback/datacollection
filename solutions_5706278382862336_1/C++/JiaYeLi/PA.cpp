#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

long long int GCD(long long int a, long long int b)
{
    long long int t;
    while(b!=0)
    {
        t = b;
        b = a%b;
        a = t;
    }
    return a;
}

struct Fraction
{
    long long int P;
    long long int Q;

    Fraction(long long int p, long long int q)
    {
        P = p;
        Q = q;
        reduce();
    }

    void reduce()
    {
        long long int gcd = GCD(P,Q);
        P = P/gcd;
        Q = Q/gcd;
    }

#define MAXG 65
    int generation()
    {
        bool one_showed = false;
        int g = 0;
        int i = 0;
        while(P!=0&& i < MAXG)
        {
            P = P * 2;
            if(P>=Q)
            {
                if(!one_showed)
                    g=i+1;
                P = P - Q;
                one_showed = true;
            }
            i++;
        }

        if(P!=0)
            return -1;
        else
            return g;
    }

};


int main()
{

    int n;
    cin >> n;

    for(int run=0; run<n; run++)
    {
        long long int P,Q;
        char c;
        cin >> P >> c >> Q;

        Fraction f = Fraction(P,Q);

        int ans = f.generation();

        cout << "Case #"<< run+1 <<": ";
        if(ans<0)
        {
            cout << "impossible" << endl;
        }
        else
            cout << ans << endl;

    }

    return 0;
}
