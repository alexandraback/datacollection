#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 55

int t, b;
int v[maxn][maxn];
long long n;

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("data.out", "w", stdout);

    cin>>t;

    for(int test=1; test<=t; ++test)
    {
        cin>>b>>n;

        printf("Case #%d: ", test);

        if(n>(1LL<<(b-2)))
        {
            printf("IMPOSSIBLE\n");
            continue;
        }

        printf("POSSIBLE\n");

        memset(v, 0, sizeof(v));

        for(int i=1; i<b; ++i)
            for(int j=i+1; j<b; ++j)
                v[i][j]=1;

        for(int j=b-1; j>1; --j)
            if(n>=(1LL<<(j-2)))
            {
               v[j][b]=1;
               n-=(1LL<<(j-2));
            }
        if(n==1)
            v[1][b]=1;

        for(int i=1; i<=b; ++i)
        {
            for(int j=1; j<=b; ++j)
                printf("%d", v[i][j]);
            printf("\n");
        }
    }

    return 0;
}

