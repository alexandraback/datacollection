#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cmath>

using namespace std;

#define maxn 1100000
#define maxm 1100000
#define eps 1e-10
#define inf 1000000000

double pro[maxm],mat[maxm],dp[maxn];
int main()
{
	int t,i,l1,l2,n,m,ca;
	double temp,ans;
	scanf("%d",&t);
	for(ca=1;ca<=t;ca++)
	{
		printf("Case #%d: ",ca);
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%lf",&mat[i]);
		}
		temp=1.0;
		for(i=0;i<n;i++)
		{
			pro[i]=temp*(1.0-mat[i]);
			temp=temp*mat[i];
		}
		pro[n]=temp;
		temp=1.0;
		ans=1e20;
		l1=m-n+1;
		l2=l1+m+1;
		for(i=0;i<=n;i++)
		{
			temp-=pro[n-i];
			dp[i]=l1*(1.0-temp)+l2*temp;
			l2+=2;
			l1+=2;
		}
		for(i=0;i<=n;i++)
		{
			if(ans>dp[i])
			{
				ans=dp[i];
			}
		}
		if(m+2<ans)ans=m+2;
		printf("%.6lf\n",ans);
	}
}
