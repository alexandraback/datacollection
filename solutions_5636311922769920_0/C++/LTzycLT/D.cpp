#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;


int k, c, s;
int main() {
    freopen("/home/zyc/Downloads/in", "r", stdin);
    freopen("/home/zyc/Downloads/out", "w", stdout);
    //freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d%d", &k, &c, &s);
        printf("Case #%d:", cas);
        if(k != s)
        {
            printf(" IMPOSSIBLE\n");
        }
        else
        {
            for(int i = 1; i <= k; i++) 
            {
                ll x = i;
                for(int j = 2; j <= c; j++) 
                {
                    x = (x - 1) * k + 1;
                }
                printf(" %lld", x);
            }
            puts("");
        }

    }
    return 0;
}
