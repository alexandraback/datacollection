#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int INF=1<<30;
const int maxn=100005;
int n,m,a[maxn];
int main()
{
	freopen("1.in","r",stdin);
	freopen("ans.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d",&n);
		double sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		double v=2.0*sum/n,ssum=2.0*sum;
		int cnt=n;
		for(int i=0;i<n;i++)
		{
			if(a[i]*1.0-v>0.000001)
				ssum-=a[i]*1.0,cnt--;
		}
		printf("Case #%d:",t);
		double vv=ssum/(1.0*cnt);
		for(int i=0;i<n;i++)
		{
			if(a[i]*1.0-v>0.000001)
				printf(" %.6f",0);
			else
			printf(" %.6f",100.0*(vv-1.0*a[i])/(sum));
		}
		puts("");
	}
	return 0;
}