#include <cstdio>
int a[1005],n,ans;
int cuts[1005];
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
        ans=10005;
        for (int i=1;i<=1000;i++)
        {
            int tmp=i;
            for (int j=1;j<=n;j++)
                tmp+=(a[j]/i+!(!(a[j]%i))-1);
            if (tmp<ans) ans=tmp;
        }
        printf("Case #%d: %d\n",++ca,ans);
    }
    return 0;
}