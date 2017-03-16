#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int a,n;

int przyp()
{
	scanf("%d%d",&a,&n);
	vector<int>v;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	if(a==1) return n;
	sort(v.begin(),v.end());
	int wyn=1e9;
	for(int i=0;i<=n;i++)
	{
		ll sum=a;
		int op=0;
		for(int j=0;j<i;j++)
		{
			while(v[j]>=sum) op++,sum+=sum-1;
			sum+=v[j];
		}
		wyn=min(wyn,op+n-i);
	}
	return wyn;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) printf("Case #%d: %d\n",i,przyp());
	return 0;
}
