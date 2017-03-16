#include <iostream>
using namespace std;
#include <stdio.h>
int value[20],E,R,N,ans;
int MAX(int a,int b) { return a>b?a:b; }
int nowenergy(int now) { return now>=E?E:now; }
void dfs(int now,int energy,int total)
{
    if(now==N)
    {
        ans = MAX(ans,total);
        return ;
    }
    for(int i=0;i<=energy;i++)
    {
        if(energy-i+R<=0) return ;
        //cout<<i<<" "<<total+i*value[now]<<endl;
        dfs(now+1,nowenergy(energy-i+R),total+i*value[now]);
    }
}
int main()
{
        freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    int cnt=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&E,&R,&N);
        for(int i=0;i<N;i++) scanf("%d",&value[i]);
        ans = 0;
        dfs(0,E,0);
        printf("Case #%d: %d\n",cnt++,ans);
    }
}
