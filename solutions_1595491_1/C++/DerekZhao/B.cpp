#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int tc,ti,n,s,p,a,i,sc,ans;
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&tc);
    for(ti=0;ti<tc;ti++)
    {
        sc=0;ans=0;
        scanf("%d%d%d",&n,&s,&p);
        if(p==0)
        {
            for(i=0;i<n;i++)
            {
                scanf("%d",&a);
            }
            printf("Case #%d: %d\n",ti+1,n);
            continue;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(a%3)
            {
                if(a/3+1>=p)ans++;
                else
                {
                    if(a%3==2&&a/3+1==p-1)
                    {
                        sc++;
                    }
                }
            }
            else
            {
                if(a/3>=p)ans++;
                else
                {
                    if((a/3)&&a/3==p-1)
                    {
                        sc++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",ti+1,ans+(sc>s?s:sc));
    }
    return 0;
}
