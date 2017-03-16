#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
#include <iterator>
#include <list>
#include <set>
#include <map>
#include <bitset>

using namespace std;

#define MEMSET(x,v) memset(x,v,sizeof(x))
template<class A, class B> inline bool mina(A &x, B y) {return (x > y)?(x=y,1):0;}
template<class A, class B> inline bool maxa(A &x, B y) {return (x < y)?(x=y,1):0;}
typedef long long int LL;

int main()
{
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        int B;
        LL M;

        scanf("%d %lld", &B, &M);

        printf("Case #%d: ", t);
        if(M > (1L << (B-2)))
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");

        if(M == (1L << (B-2)))
        {
            for(int i = 0; i < B; i++)
            {
                for(int j = 0; j < B; j++)
                    printf("%d", (i < j ? 1 : 0));
                printf("\n");
            }
            continue;
        }

        printf("0");
        for(int j = 1; j < B-1; j++)
            printf("1");
        printf("0\n");

        for(int i = 0; i < B-1; i++)
        {
            for(int j = 0; j < B-1; j++)
            {
                printf("%d", (i+1<j?1:0));
            }
            if(M & (1L << i))
                printf("1\n");
            else
                printf("0\n");
        }
    }
}
