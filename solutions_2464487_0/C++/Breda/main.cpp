#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*        int vet[10];
int rec(int so, int atu, int ea, int e, int r, int n)
{
    if(atu>=n)
        return so;
    int s, j, maxs = 0;
    ea+=r;
    if(ea>e)
        ea = e;
    for(j=0;j<=ea;j++)
    {
        s = so+j*vet[atu];
        s = rec(s, atu+1, ea-j, e, r, n);
        if(maxs<s)
            maxs = s;
    }
    return maxs;
}*/


int main()
{
    /*int t, i;
    scanf("%i", &t);
    i = 1;
    while(t>0)
    {
        t--;

        int e, r, n, j;
        scanf("%i %i %i", &e, &r, &n);
        for(j=0;j<n;j++)
        {
            scanf("%i", &vet[j]);
        }

        int maxs = 0, s;
        for(j=0;j<=e;j++)
        {
            s = j*vet[0];
            s = rec(s, 1, e-j, e, r, n);
            if(maxs<s)
                maxs = s;
        }

        printf("Case #%i: %i\n", i, maxs);
        i++;
    }*/


    int T, t, i;
    scanf("%i", &T);
    i = 1;
    while(T>0)
    {
        int r;
        T--;
        scanf("%i %i", &r, &t);
        int a = r+1;
        int q = 1;
        int s = (a*a)-(a-1)*(a-1);
        a+=2;
        while(s+(a*a)-(a-1)*(a-1)<=t)
        {
            q++;
            s+=(a*a)-(a-1)*(a-1);
            a+=2;
            //printf("S: %i A: %i\n", s, a);
        }
        printf("Case #%i: %i\n", i, q);
        i++;
    }
    return 0;
}
