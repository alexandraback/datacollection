#include <cstdio>
char a[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d%s",&n,a);
        int tot=0,ans=0;
        for (int i=0;i<=n;i++)
        {
            if (tot<i)
            {
                ans+=i-tot;
                tot=i;
            }
            tot+=a[i]-'0';
        }
        static int id=0;
        printf("Case #%d: %d\n",++id,ans);
    }
    return(0);
}

