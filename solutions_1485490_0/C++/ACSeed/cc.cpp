#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;

const int MAX = 1010;
const int maxint = 1 << 20;

long long a[MAX],anum[MAX];
long long b[MAX],bnum[MAX];

int n, m;
long long ans = 0;

long long dfs(int x,int y)
{
    if(x > n  || y > m) {
        return 0;
    }
    long long maxx = 0;

    if(a[x] == b[y]) {
        if(anum[x] > bnum[y]) {
            anum[x] -= bnum[y];
            maxx = dfs(x,y + 1) + bnum[y];
            anum[x] += bnum[y];
        } else if(anum[x] < bnum[y]) {
            bnum[y] -= anum[x];
            maxx = dfs(x + 1,y) + anum[x];
            bnum[y] += anum[x];
        } else maxx = dfs(x + 1, y + 1) + anum[x];
    } else {
        maxx = max(dfs(x + 1,y), dfs(x, y + 1));
    }
    return maxx;
}

int main()
{
    freopen("in.txt","r",stdin);
     freopen("out.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for(int id = 1; id <= t; ++id) {
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; ++i) {
            scanf("%lld%lld",&anum[i],&a[i]);
        }
        for(int i = 1; i <= m; ++i) {
            scanf("%lld%lld",&bnum[i],&b[i]);
        }
        ans = dfs(1,1);
        printf("Case #%d: %lld\n",id,ans);
    }
    return 0;
}

