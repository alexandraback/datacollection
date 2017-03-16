#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>

#define inf 0x3f3f3f3f
using namespace std;
int a[105];
int ans;
int n,m;

void Dfs(int cnt,int L,int t)
{
    if(cnt==n+1)
    {
        if(t<ans)
            ans=t;
        return ;
    }
    if(t+n-cnt+1<ans)
        Dfs(cnt+1,L,t+1);
    while(L<=a[cnt])
    {
        L=L+L-1;
        t++;
    }
    Dfs(cnt+1,L+a[cnt],t);
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int cases,id=1;
    scanf("%d",&cases);
    while(cases--)
    {
        printf("Case #%d: ",id++);
        scanf("%d%d",&m,&n);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        if(m==1)
        {
            printf("%d\n",n);
            continue;
        }
        sort(a+1,a+n+1);
        ans=inf;
        Dfs(1,m,0);
        printf("%d\n",ans);
    }
	return 0;
}
