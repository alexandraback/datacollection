#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int v[20000];
int e, r, n, m;

int go(int ee, int pos)
{
    int i; 
    int max = 0;
    int temp = 0;
    int e2;
    if(pos == n-1)
    {
        return ee * v[pos];
    }
    else
    {
        for(i = 0; i <= ee; i++)
        {
            if(ee-i+r > e)
                e2 = e;
            else
                e2 = ee-i+r;

            temp = i * v[pos] + go(e2, pos+1);
            if(temp > max)
                max = temp;

        }
        return max;
    }
}


int main()
{
    int i,j;
    int ii,jj,kk;
    int res;
    int mm;
    int end, xw, ow;
    int max;

    unsigned long long result;

    scanf("%d", &mm);

    for(ii = 1; ii <= mm; ii++)
    {
        scanf("%d%d%d", &e, &r, &n);

        for(i = 0; i < n; i++)
        {
            scanf("%d", &v[i]);
        }

        printf("Case #%d: %d\n", ii, go(e,0));
    }
}
