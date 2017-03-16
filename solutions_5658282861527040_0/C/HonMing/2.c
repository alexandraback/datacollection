#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j;
    int ii,jj,kk;
    int res;
    int m;
    char map[10][10];
    int end, xw, ow;
    int a, b, k;

    unsigned long long ans;

    scanf("%d", &m);

    for(ii = 1; ii <= m; ii++)
    {
        ans = 0;
        scanf("%d%d%d", &a, &b, &k);
        //printf("a:%d b:%d k:%d\n", a,b,k);
        for(i =0; i < a; i++)
        {
            for(j =  0; j < b; j++)
            {
                if((i & j) < k)
                    ans++;
         //       printf("i:%d j:%d i&j:%d, ans:%llu\n", i, j, i&j, ans);
            }
        }

        printf("Case #%d: %llu\n", ii, ans);
    }
}
