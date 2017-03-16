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
        int J, P, S, K;
        scanf("%d %d %d %d", &J, &P, &S, &K);

        printf("Case #%d: %d\n", t, min(K, S)*J*P);
        for(int k = 0; k < min(K, S); k++)
            for(int j = 0; j < J; j++)
                for(int p = 0; p < P; p++)
                    printf("%d %d %d\n", 1+j, 1+p, 1+(j+p+k)%S);
    }
}
