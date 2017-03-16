#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1005;
int f[N],gline[N];
bool gay[N],vis[N];
int main() {
    freopen("C-small-attempt3.in","r",stdin);
    freopen("C-small-attempt3.out","w",stdout);
    int t,n;
    scanf("%d",&t);
    for(int cas=1; cas<=t; ++cas) {
        scanf("%d",&n);
        for(int i=1; i<=n; ++i)
            scanf("%d",&f[i]);
        memset(gay,false,sizeof(gay));
        int gcnt=0;
        for(int i=1; i<=n; ++i)
            if(!gay[i]&&f[f[i]]==i) {
                gay[i]=gay[f[i]]=true;
                gcnt+=2;
            }
        int ans=gcnt;
        memset(gline,0,sizeof(gline));
        for(int i=1; i<=n; ++i)
            if(!gay[i]) {
                memset(vis,false,sizeof(vis));
                int cur=i,cnt=0;
                for(; !vis[cur]&&!gay[cur]; cur=f[cur]) {
                    vis[cur]=true;
                    ++cnt;
                }
                if(!gay[cur]&&cur==i)
                    ans=max(ans,cnt);
                else if(gay[cur]&&cnt>gline[cur])
                    gline[cur]=cnt;
            }
        for(int i=1; i<=n; ++i)
            if(gay[i])
                gcnt+=gline[i];
        ans=max(ans,gcnt);
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
