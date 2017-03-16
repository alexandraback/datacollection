#include<stdio.h>
#include<algorithm>
using namespace std;
int t,n,ans,ans2,pos;
double nao[1005],ken[1005];
int main()
{
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);

    scanf("%d",&t);
    for (int l=1;l<=t;l++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%lf",&nao[i]);
        for (int i=1;i<=n;i++)
            scanf("%lf",&ken[i]);
        sort(nao+1,nao+n+1);
        sort(ken+1,ken+n+1);
        ans=ans2=0;
        pos=n;
        for (int i=n;i>=1,pos>0;i--)
        {
            while(ken[pos]>nao[i] && pos>1)
                pos--;
            if (nao[i]>ken[pos]) ans++;
            pos--;
        }
        pos=1;
        for (int i=1;i<=n;i++)
        {
            while(pos<=n &&ken[pos]<nao[i])
            {
                pos++;
                ans2++;
            }
            pos++;
        }

        printf("Case #%d: %d %d\n",l,ans,ans2);
    }
    return 0;
}
