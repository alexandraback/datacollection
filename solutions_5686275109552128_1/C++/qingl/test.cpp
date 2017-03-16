#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const int MOD = 1000000007;
const int N = 1005;
int a[N],n;
bool got(int t,int k)
{
	int md=k-t;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>md)
		{
			int need=(a[i]+md-1)/md-1;
			if(need>t)return false;
			t-=need;
		}
	}
	return true;
}
bool check(int k)
{
	for(int i=0;i<k;i++)
	{
		if(got(i,k))return true;
	}
	return false;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",ca++);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ret=10086,low=0,high=1001;
		while(low<high-1)
		{
			int mid=(low+high)/2;
			//printf("low:%d high:%d mid:%d \n",low,high,mid);
			if(check(mid))high=mid;
			else low=mid;
		}
		ret=high;
		printf("%d\n",ret);
	}
	return 0;
}
