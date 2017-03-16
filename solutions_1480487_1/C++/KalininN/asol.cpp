#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int maxn=205;

double ans[maxn];
int ju[maxn];

int main()
{
	int NT=0;
	scanf("%d",&NT);
	for (int T=1;T<=NT;T++)
	{
		int n;
		scanf("%d",&n);
		int x=0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&ju[i]);
			x+=ju[i];
		}
		double l=0;
		double r=200*100*10;
		for (int IT=0;IT<100;IT++)
		{
			double m=(l+r)/2;
			double sum=0;
			for (int i=0;i<n;i++) if (ju[i]<m) sum+=(m-ju[i])/x;
			if (sum<1) l=m;
			else r=m;
		}
		for (int i=0;i<n;i++)
		{
			if (ju[i]<l) ans[i]=(l-ju[i])/x;
			else ans[i]=0;
		}
		printf("Case #%d:",T);
		for (int i=0;i<n;i++) printf(" %.7f",100*ans[i]);
		printf("\n");
	}
	return 0;
}