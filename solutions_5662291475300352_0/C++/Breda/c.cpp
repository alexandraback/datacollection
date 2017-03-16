#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>

using namespace std;

unsigned long long pos[500000];
unsigned long long tem[500000];

void resolver(int caso)
{
    unsigned long long n, i, d, h, m, j, q, aux, r;
    q = 0;
    scanf("%llu", &n);
    for(i=0;i<n;i++)
    {
        scanf("%llu %llu %llu", &d, &h, &m);
        for(j=0;j<h;j++)
        {
            pos[q] = d;
            tem[q] = m+j;
            q++;
        }
    }
    if(tem[0]==tem[1])
        r = 0;
    else
    {
        if(tem[0]>tem[1])
        {
            aux = tem[0];
            tem[0] = tem[1];
            tem[1] = aux;
            aux = pos[0];
            pos[0] = pos[1];
            pos[1] = aux;
        }
        if((360-pos[1])*tem[1]>=(360-pos[0])*tem[0]+360*tem[0])
            r = 1;
        else
            r = 0;
    }

    printf("Case #%d: %llu\n", caso, r);
}

int main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        resolver(i);
    }
    return 0;
}
