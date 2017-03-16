#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <set>

using namespace std;

void resolver(int caso)
{
    int pos[31], i, va[11], r, tot, c, d, v, j;
    scanf("%d %d %d", &c, &d, &v);
    tot = 0;
    memset(pos, 0, sizeof(pos));
    for(i=0;i<d;i++)
    {
        scanf("%d", &va[i]);
        pos[va[i]] = 1;
        tot++;
    }
    r = 0;
    while(tot<v)
    {
        for(i=0;i<1024;i++)
        {
            int soma = 0;
            for(j=0;j<d;j++)
            {
                //printf("Pos: %d\n", i&(1<<j));
                if((i&(1<<j))!=0)
                {
                    //printf("Va: %d J: %d\n", va[j], j);
                    soma+=va[j];
                }
            }
            //printf("Soma: %d\n", soma);
            //system("PAUSE");
            if(soma>=1 && soma<=v && pos[soma]==0)
            {
                //printf("Soma: %d\n", soma);
                pos[soma] = 1;
                tot++;
            }
        }
        for(i=1;i<=v;i++)
        {
            if(pos[i]==0)
            {
                r++;
                tot++;
                va[d] = i;
                d++;
                pos[i] = 1;
                //printf("%d\n", i);
                break;
            }
        }
    }
    printf("Case #%d: %d\n", caso, r);
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
