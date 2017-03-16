#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int d[104];
int C,D,V,T;
int est[105];
int bag[104];
int dp[104];
int gen[55];
bool check()
{
    for(int i=1;i<=V;i++)
        if(!bag[i]) return false;
    return true;
}
int res=5;
void dfs(int i,int len,int last)
{
    if(i==len+1)
    {
        for(int j=1;j<=len;j++)
            if(est[gen[j]]) return;
        memcpy(dp,bag,sizeof(dp));
        for(int j=1;j<=len;j++)
            for(int v=V;v>=gen[j];v--)
                if(dp[v-gen[j]]) dp[v]=1;
        for(int j=1;j<=V;j++) if(!dp[j]) return;
        res=min(res,len);
        return ;
    }
    for(int j=last;j<=V;j++)
    {
        gen[i]=j;
        dfs(i+1,len,j+1);
    }

}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d%d%d",&C,&D,&V);
        for(int i=1;i<=D;i++) scanf("%d",&d[i]);
        memset(est,0,sizeof(est));
        for(int i=1;i<=D;i++) if(d[i]<=V) est[d[i]]=1;
        memset(bag,0,sizeof(bag));
        bag[0]=1;
        for(int i=1;i<=D;i++)
            for(int v=V;v>=d[i];v--)
                if(bag[v-d[i]]) bag[v]=1;
        res=5;
        for(int i=0;i<=4;i++)
            dfs(1,i,1);
        printf("Case #%d: %d\n",kase,res);
    }
    return 0;
}
