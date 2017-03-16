#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

long long ret;
int A,B,lst;

long long dp[33][2][2];
int vis[33][2][2];

long long dfs(int dep,int sta1,int sta2,int msk)
{
    if(dep<0)
    {
	if(!sta1&&!sta2)
	    return 1;
	return 0;
    }
    if(dep<lst)
    {
	long long ret1,ret2;

	if(sta1)
	    ret1=(A&((1<<lst)-1));
	else
	    ret1=(1<<lst);

	if(sta2)
	    ret2=(B&((1<<lst)-1));
	else
	    ret2=(1<<lst);

	return ret1*ret2;
    }
    if(vis[dep][sta1][sta2])
	return dp[dep][sta1][sta2];
    vis[dep][sta1][sta2]=1;
    dp[dep][sta1][sta2]=0;
   
    if(msk&(1<<dep))
    {
	if(sta1&&(A&(1<<dep))==0)
	    return 0;
	if(sta2&&(B&(1<<dep))==0)
	    return 0;
	dp[dep][sta1][sta2]+=dfs(dep-1,sta1,sta2,msk);
    }
    else
    {
	if(!sta1||(A&(1<<dep)))
	{
	    int s1,s2;
	    if(!sta2)
		s2=0;
	    else if(B&(1<<dep))
		s2=0;
	    else
		s2=1;
	    dp[dep][sta1][sta2]+=dfs(dep-1,sta1,s2,msk);
	}
	if(!sta2||(B&(1<<dep)))
	{
	    int s1;
	    if(!sta1)
		s1=0;
	    else if(A&(1<<dep))
		s1=0;
	    else
		s1=1;
	    dp[dep][sta1][sta2]+=dfs(dep-1,s1,sta2,msk);
	}
	int s1,s2;
	if(!sta1||(A&(1<<dep)))
	    s1=0;
	else
	    s1=1;
	if(!sta2||(B&(1<<dep)))
	    s2=0;
	else
	    s2=1;
	dp[dep][sta1][sta2]+=dfs(dep-1,s1,s2,msk);
    }
    return dp[dep][sta1][sta2];
}
int main()
{
    int a,b,i,j,k,t;
    int ii=0;

    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);

    scanf("%d",&t);
    while(t--)
    {
	scanf("%d%d%d",&a,&b,&k);
	long long ans=0;

	A=a,B=b;
	for(i=0;i<30;i++)if(k&(1<<i))
	{
	    int tmp=0;
	    for(j=i+1;j<30;j++)if(k&(1<<j))
		tmp+=(1<<j);
	    memset(vis,0,sizeof(vis));
	    lst=i;
	    ans+=dfs(30,1,1,tmp);
	}

	printf("Case #%d: %lld\n",++ii,ans);
    }
}
