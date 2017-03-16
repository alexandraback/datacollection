#include <cstdio>
int a[1005],n,ans;
int cuts[1005];
void dfs(int t)
{
    if (t>n){
        int tmp=0;
        for (int i=1;i<=n;i++)
        {
            if (tmp<a[i]/(cuts[i]+1)+!(!(a[i]%(cuts[i]+1)))) tmp=a[i]/(cuts[i]+1)+!(!(a[i]%(cuts[i]+1)));
        }
        for (int i=1;i<=n;i++)
            tmp+=cuts[i];
        if (tmp<ans) ans=tmp;
        return ;
    }
    for (cuts[t]=0;cuts[t]<=a[t];cuts[t]++)
        dfs(t+1);
}
int main(int argc, char const *argv[])
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);

    int T,ca=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ans=10000;
        dfs(1);
        printf("Case #%d: %d\n",++ca,ans);
    }
    return 0;
}