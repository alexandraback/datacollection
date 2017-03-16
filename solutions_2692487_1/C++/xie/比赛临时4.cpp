#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[2000];
int s;
int n;
int main()
{
    freopen("12.in","r",stdin);
    freopen("1.out","w",stdout);
    int T;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        scanf("%d%d",&s,&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(s==1)
        {
            printf("Case #%d: %d\n",++cas,n);
            continue;
        }
        sort(a+1,a+1+n);
        int ans=1000;
        for(int i=0;i<=n;i++)
        {
            int res=i;
            int now=s;
            for(int j=1;j<=(n-i);j++)
            {
                if(now>a[j])
                    now+=a[j];
                else
                {
                    while(now<=a[j])
                    {
                        now+=(now-1);
                        res++;
                    }
                    now+=a[j];
                }
            }
            ans=min(res,ans);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
}
