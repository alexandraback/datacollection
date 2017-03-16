#include<stdio.h>
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        int n,s,p,ts=0,ans=0;
        scanf("%d%d%d",&n,&s,&p);
        for(int i=0;i<n;i++)
        {
            int t;
            scanf("%d",&t);
            int d=t/3,res=t%3;
            if(res==0)
            {
                if(d>=p) ans++;
                else if(d+1>=p&&d>0&&ts<s)
                {
                    ans++;
                    ts++;
                }
            }
            else if(res==1)
            {
                if(d+1>=p) ans++;
            }
            else
            {
                if(d+1>=p) ans++;
                else if(d+2>=p&&ts<s)
                {
                    ans++;
                    ts++;
                }
            }
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
