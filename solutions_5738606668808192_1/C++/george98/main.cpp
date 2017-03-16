#include <cstdio>

using namespace std;

const int limc=100000;
int prim[limc+10],div[40];
char vaz[limc+10];

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int nr=0,test;
    for(int i=2;i<=limc;i++)
        if(!vaz[i])
        {
            prim[++nr]=i;
            if(1LL*i*i<=limc)
                for(int j=i*i;j<=limc;j+=i) vaz[j]=1;
        }
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        n-=2;
        printf("Case #%d:\n",t);
        int lim=1<<n,sol=0;
        for(int mask=0;mask<lim && sol<m;mask++)
        {
            int ok=1;
            for(int b=2;b<=10;b++)
            {
                div[b]=0;
                for(int i=1;i<=nr;i++)
                {
                    int s=1,p=b;
                    for(int j=0;j<n;j++,p=(p*b)%prim[i])
                        if(mask&(1<<j)) s=(s+p)%prim[i];
                    s=(s+p)%prim[i];
                    if(s==0)
                    {
                        div[b]=prim[i];
                        break;
                    }
                }
                if(!div[b])
                {
                    ok=0;break;
                }
            }
            if(ok)
            {
                sol++;
                printf("1");
                for(int i=n-1;i>=0;i--)
                    if(mask&(1<<i)) printf("1");
                    else printf("0");
                printf("1");
                for(int i=2;i<=10;i++) printf(" %d",div[i]);
                printf("\n");
            }
        }
    }
    return 0;
}
