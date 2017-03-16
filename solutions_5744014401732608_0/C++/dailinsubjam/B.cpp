#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int B;
long long M;
int a[55][55];

int main()
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; ++Case)
    {
        scanf("%d%lld", &B, &M);
        
        printf("Case #%d: ", Case);
        long long cur = 1;
        for(int i = 0; i <= B - 2; ++i)
        {
            if(i) cur <<= 1ll;
            if(M < cur) break;
        }
        if(cur < M) {printf("IMPOSSIBLE\n"); continue;}
        
        
        
        printf("POSSIBLE\n");
        
        memset(a, 0, sizeof(a));
        
        //cerr<<cur<<" "<<M<<endl;
        if(cur == M)
        {
            for(int i = 1; i <= B; ++i)
                for(int j = 1; j < i; ++j)
                    a[j][i] = 1;

        }
        else
        {
        for(int i = 1; i < B; ++i)
            for(int j = 1; j < i; ++j)
                a[j][i] = 1;
        
        int t = 0;
        for(; M; M >>= 1)
        {
            if(M & 1ll)
            {
                a[t + 2][B] = 1;
            }
            ++t;
        }
        }
        for(int i = 1; i <= B; ++i)
        {
            for(int j = 1; j <= B; ++j) printf("%d", a[i][j]);
            printf("\n");
        }
    }
    
    return 0;
}