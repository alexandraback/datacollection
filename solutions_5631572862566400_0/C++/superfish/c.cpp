#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define rep(i,n) for (int i=1;i<=(n);++i)
#define rep2(i,x,y) for (int i=(x);i<=(y);++i)
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VII;
int n;
int a[10000],id[10000];
int gone[10000];
VI g[10000];
int tmpmax;
void dfs(int t,int dep)
{
    id[t]=dep;
    tmpmax=max(dep,tmpmax);
    rep(i,g[t].size())
        if (id[g[t][i-1]]==0)
            dfs(g[t][i-1],dep+1);
}

void MAIN(){
    scanf("%d",&n);
    rep(i,n) g[i].clear();
    rep(i,n) scanf("%d",&a[i]);
    rep(i,n) g[a[i]].push_back(i);
    rep(i,n) gone[i]=0;
    int ans=0;
    rep(i,n)
        if (gone[i]==0){
            int t=a[i]; gone[i]=i; int cnt=0; id[i]=0;
            while (gone[t]==0)
            {
                gone[t]=i;
                id[t]=++cnt;
                t=a[t];
            }
            if (gone[t]!=i) continue;
            ans=max(ans,cnt-id[t]+1);
        }
    rep(i,n) gone[i]=0,id[i]=0;
    int plan2=0;
    rep(i,n)
        if (a[a[i]]==i && i<a[i])
        {
            id[i]=id[a[i]]=1;
            tmpmax=0;
            dfs(i,1);
            plan2+=tmpmax;
            tmpmax=0;
            dfs(a[i],1);
            plan2+=tmpmax;
        }
    ans=max(ans,plan2);
    cout << ans << endl;
}
int main() {
    freopen("d:\\oi\\gcj1a\\c-small-attempt0.in","r",stdin);
    freopen("d:\\oi\\gcj1a\\c-small-attempt0.out","w",stdout);
    int tt;
    scanf("%d",&tt);
    rep(i,tt)
    {
        printf("Case #%d: ",i);
        MAIN();
    }
    return 0;
}