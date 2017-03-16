#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
int n,m;
long double pro[1<<20];
void precompute(void)
{
}
long double expected1()
{
	return n+2;
}
long double expected2()
{
	int i;
	long double tota=1.0;
	for(i=0;i<m;i++)
		tota*=pro[i];
	return (n-m+1.0)+(1.0-tota)*(n+1);
}
long double expected3()
{
	int i;
	long double ret=n+2;
	long double tota=1.0;
	for(i=1;i<=m;i++)
	{
		tota*=pro[i-1];
		ret=min(ret,tota*(n-m+2*(m-i)+1)+(1-tota)*(n-m+2*(m-i)+2+n));
	}
	return ret;
}
int main()
{
	precompute();
	int t,test,i;
	long double ans;
	while(scanf("%d",&t)!=EOF)
	{
		test=0;
		while(t--)
		{
			test++;
			scanf("%d%d",&m,&n);
			for(i=0;i<m;i++)
				scanf("%Lf",&pro[i]);
			ans=expected1();
			ans=min(expected2(),ans);
			ans=min(expected3(),ans);
			printf("Case #%d: %Lf\n",test,ans);
			fprintf(stderr,"Case #%d: %Lf\n",test,ans);
		}
	}
	return 0;
}
