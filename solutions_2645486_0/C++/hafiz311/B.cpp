#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include <stack>
#include <list>

#define SZ 10000002
#define EPS 1e-10
#define pb push_back
#define pi (acos(-1.0))


using namespace std;

typedef long long Long;


Long dp[20][20];
int vis[20][20],True;
Long v[20];
int n,E,R;

Long back(int pos,int l)
{
    if(vis[pos][l]==True) return dp[pos][l];
    dp[pos][l] = 0; vis[pos][l] = True;

    if(pos==n) return 0;

    for(int i=0;i<=l;i++) {
        Long x = i*v[pos] + back(pos+1,min(l-i+R,E));
        if(x>dp[pos][l]) dp[pos][l] = x;
    }
    return dp[pos][l];

}


int main()
{
    int tst,cas;
    freopen("B.in","rt",stdin);
    freopen("B.out","wt",stdout);
    scanf("%d",&tst);
    for(cas=1;cas<=tst;cas++)
    {
        scanf("%d%d%d",&E,&R,&n);
        for(int i=0;i<n;i++) scanf("%lld",&v[i]);
        True++;
        printf("Case #%d: %lld\n",cas,back(0,E));
    }
    return 0;
}
