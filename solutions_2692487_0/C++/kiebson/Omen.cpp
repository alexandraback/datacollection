#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long testy,a,n,wyn,r,x,wynik;
long long t[1000001];

int main()
{
    scanf ("%lld", &testy);
    for (int i=1; i<=testy; i++)
    {
        scanf ("%lld%lld", &a, &n);
        for (int j=1; j<=n; j++)
            scanf ("%lld", &t[j]);
        
        sort (t+1, t+n+1);
        
        wyn = 0; x = 0; wynik = 999999999999999999LL;
        
        if (a == 1)
            wyn = n;
        else
        {
            for (int j=1; j<=n; j++)
            {
                if (a > t[j])
                    a += t[j];
                else
                {
                    r = t[j] - a + 1;
                    if (r < a)
                    {
                        a += a-1;
                        a += t[j];
                        wyn ++;
                    }
                    else
                    {
                        wynik = min (wynik, wyn + n-j+1);
                        while (a <= t[j])
                        {
                            a += a-1;
                            wyn ++;
                        }
                        a += t[j];
                    }
                }
            }
        }
        
        printf ("Case #%d: %lld\n", i, min (wynik,wyn));               
    }
    
cin.ignore(2);
return 0;
}
