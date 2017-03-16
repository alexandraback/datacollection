#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
#define maxn 101010
#define LL long long
int n,m;
double r,t;
double bin()
{
	double l=0,rr=(2000000000000000000LL);
	long long ans=0;
	while(l<rr)
	{
		long long mid=(l+rr)/2;
		double tmp=mid;
		if(tmp*(2*r-3)+2*(tmp+1)*tmp<=t)
			l=mid+1,ans=mid;
		else
			rr=mid;
	}
	return ans;
}
int main()
{
	int ncase,tt=0,i,j;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%lf %lf",&r,&t);
		double f=2*r+1;
		if(f>t)
		{
			printf("Case #%d: 0\n",++tt);
			continue;
		}
		//an=2*r+4*n-3
		printf("Case #%d: %.0lf\n",++tt,bin());
	}
	return 0;
}
