#include<cstdio>

using namespace std;

int T,n;

inline int read()
{
    char c=getchar();
    while(c<48||c>57)c=getchar();
    return c-'0';
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d",&n);
        int ans=0,sum=0;
        for(int i=0;i<=n;i++)
        {
            int c=read();
            if(c)
            {
                if(sum<=i)
                {
                    ans+=i-sum;
                    sum=i;
                }
                sum+=c;
            }
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
