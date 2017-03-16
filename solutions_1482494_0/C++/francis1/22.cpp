#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
    int a,b;
    bool operator < (const node &x) const
    {
        if(b==x.b)return a<x.a;
        return b<x.b;
    }
}gao[1010];
int n;
int flag[1010];
int main()
{
    freopen("C:\\Users\\James\\Desktop\\in.txt","r",stdin);freopen("C:\\Users\\James\\Desktop\\out.txt","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        scanf("%d%d",&gao[i].a,&gao[i].b);
        sort(gao+1,gao+1+n);
        memset(flag,0,sizeof(flag));
        int ans=0;
        int now=0;
        bool ok=1;
        while(1)
        {
            int pos=-1;
            for(int j=1;j<=n;j++)
            if(flag[j]!=1)
            {
                pos=j;break;
            }
            if(pos==-1)break;
            if(gao[pos].b<=now)
            {
                if(flag[pos]==0)now+=2;
                else now++;
                flag[pos]=1;
                ans++;
            }
            else
            {
                pos=-1;
                for(int j=n;j>=1;j--)
                {
                    if(flag[j]==0&&now>=gao[j].a)
                    {
                        pos=j;
                        break;
                    }
                }
                if(pos==-1)
                {
                    ok=0;
                    break;
                }
                else
                {
                    flag[pos]=2;
                    now++;
                    ans++;
                }
            }
        }
        printf("Case #%d: ",++cas);
        if(!ok)
        puts("Too Bad");
        else
        printf("%d\n",ans);
    }
}
