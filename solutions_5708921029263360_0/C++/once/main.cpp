#include <bits/stdc++.h>
using namespace std;
int a,b,c,m;
const int N=10;
int ab[N][N],bc[N][N],ac[N][N];
int all[N*N*N][3],tot;
int ans,lst[N*N*N],tmp[N*N*N];
void dfs(int x,int cur)
{
    if (x==tot)
    {
        if (cur>ans)
        {
            for (int i=0;i<cur;++i)
                lst[i]=tmp[i];
            ans=cur;
        }
        return;
    }
    dfs(x+1,cur);
    if (ab[all[x][0]][all[x][1]]==m) return;
    if (ac[all[x][0]][all[x][2]]==m) return;
    if (bc[all[x][1]][all[x][2]]==m) return;
    ++ab[all[x][0]][all[x][1]];
    ++ac[all[x][0]][all[x][2]];
    ++bc[all[x][1]][all[x][2]];
    tmp[cur]=x;
    dfs(x+1,cur+1);
    --ab[all[x][0]][all[x][1]];
    --ac[all[x][0]][all[x][2]];
    --bc[all[x][1]][all[x][2]];
}
int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int cas;
    cin>>cas;
    for (int run=1;run<=cas;++run)
    {
        cin>>a>>b>>c>>m;
        cout<<"Case #"<<run<<":";
        tot=0;
        for (int i=0;i<a;++i)
            for (int j=0;j<b;++j)
                for (int k=0;k<c;++k)
                {
                    all[tot][0]=i;
                    all[tot][1]=j;
                    all[tot][2]=k;
                    ++tot;
                }
        ans=0;
        dfs(0,0);
        cout<<' '<<ans<<endl;
        for (int i=0;i<ans;++i)
            cout<<all[lst[i]][0]+1<<' '<<all[lst[i]][1]+1<<' '<<all[lst[i]][2]+1<<endl;
    }
    return 0;
}
