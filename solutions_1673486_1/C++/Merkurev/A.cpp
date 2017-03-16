#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

double probTypeCorrect[100500];
double p[100500];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for (int T=0;T<t;T++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for (int i=0;i<a;i++)
			scanf("%lf",&p[i]);
		probTypeCorrect[0]=1;
		for (int i=1;i<=a;i++)
		{
			probTypeCorrect[i]=probTypeCorrect[i-1]*p[i-1];
		}
		double ans = b+2;
		for (int i=a;i>=0;i--)
		{
			double ca = b - a + 1 + (1.-probTypeCorrect[i])*(b+1) + 2*(a-i);
			ans=min(ans,ca);
		}
		printf("Case #%d: %.8lf\n",T+1,ans);
	}
	return 0;
}