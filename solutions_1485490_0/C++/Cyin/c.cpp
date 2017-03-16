#include<stdio.h>
#include<string.h>
#define ll long long
ll a[5],sa[5],b[110],sb[110],ans;
int n,m;
void dfs(ll x,ll lx,ll y,ll ly,ll sum){
    if (ans<sum) ans=sum;
    if (x>=n||y>=m) return;
    if (sa[x]==sb[y]){
        if (lx>=ly) dfs(x,lx-ly,y+1,b[y+1],sum+ly);
        else dfs(x+1,a[x+1],y,ly-lx,sum+lx);
        return;
    }
    dfs(x+1,a[x+1],y,ly,sum);
    dfs(x,lx,y+1,b[y+1],sum);
}
int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int ca,cc=0;
    int i;
    scanf("%d",&ca);
    while (ca--){
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++)
            scanf("%lld%lld",&a[i],&sa[i]);
        for (i=0;i<m;i++)
            scanf("%lld%lld",&b[i],&sb[i]);
        ans=0;
        dfs(0,a[0],0,b[0],0);
        cc++;
        printf("Case #%d: ",cc);
        printf("%lld\n",ans);
    }
    return 0;
}
