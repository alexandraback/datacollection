#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           std::make_pair(a,b)
#define      X                 first
#define      Y                 second
#define      pb(x)             push_back(x)


typedef long long LL;
LL MOD = 1000000007;
int main()
{
    int t;
    scanf("%d",&t);

    for(int tt=0; tt<t; tt++)
    {
        printf("Case #%d: ",tt+1 );
        LL b, m;
        scanf("%lld%lld",&b,&m);
        if(m > (1ll<<(b-2)))
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");
        int connect[100];
        memset(connect, 0, sizeof connect);
        if(m == (1ll<<(b-2))) connect[0] = 1, m--;
        for(int i=1; i<b-1; i++)
        {
            if(m & (1ll << (i-1))) connect[i] = 1;
        }
        for(int i=0; i<b; i++)
        {
            for(int j=0; j<b; j++)
            {
                if(j <= i) printf("0");
                else if(j == b-1) printf("%d",connect[i]);
                else printf("1");
            }
            printf("\n");
        }
    }
    return 0;
}
