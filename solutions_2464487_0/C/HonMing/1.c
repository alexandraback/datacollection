#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j;
    int ii,jj,kk;
    int res;
    int mm;
    int end, xw, ow;
    int n, m;
    int max;
    unsigned long long r,t;

    unsigned long long result;

    scanf("%d", &mm);

    for(ii = 1; ii <= mm; ii++)
    {
        scanf("%lld %lld", &r, &t);

        
        i = 2;
        while(1)
        {
            result = (2*r +(i - 1)) * i / 2;
            if(result > t)
                break;
            i += 2;
        }
        i = (i - 2) / 2;

        printf("Case #%d: %d\n", ii, i);
    }
}
