#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int res;
int e,r,n;
int v[20];
void dfs(int st,int tres,int now)
{
   // printf("st=%d tres=%d now=%d\n",st,tres,now);
    if(st>=n)
    {
        if(tres>res)
            res=tres;
        return ;
    }
    else
    {
        for(int i=0;i<=now;i++)
        {
            dfs(st+1,tres+i*v[st],(now+r-i)>e?e:(now+r-i));
        }
    }
}
int main()
{
    int T;
    int ca=0;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("b.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        memset(v,0,sizeof(v));
        scanf("%d%d%d",&e,&r,&n);
        for(int i=0;i<n;i++)
            scanf("%d",&v[i]);
        res=0;
        dfs(0,0,e);
        printf("Case #%d: %d\n",++ca,res);
    }


}
