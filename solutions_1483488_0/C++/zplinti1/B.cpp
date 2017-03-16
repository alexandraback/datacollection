#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int visit[2000001],ba[20];

int main()
{
    int cas,n,a,b;

    freopen("in.in","r",stdin);
    freopen("ans.out","w",stdout);
    ba[1]=1;
    for(int i=2;i<10;i++) ba[i]=ba[i-1]*10;
    scanf("%d",&cas);
    for(int ii=1;ii<=cas;ii++)
    {
        scanf("%d %d",&a,&b);
        int ans=0;
        memset(visit,0,sizeof(visit));
        for(int i=a;i<b;i++)
        {
            int x=i;
            int len=0;
            while(x) len++,x/=10;
            x=i;
            for(int j=len-1;j>0;j--)
            {
                x=x/10+x%10*ba[len];
                if (x<=b&&x>i&&visit[x]!=i)
                {
                     ans++;
                     visit[x]=i;
                }
            }
        }
        printf("Case #%d: %d\n",ii,ans);
    }
    return 0;
}
