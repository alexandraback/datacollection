#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<iostream>
#include<cstring>
using namespace std;
const int maxint=214748364;
int times,n;
long double num[300],total;
void mem()
{
	total=0;
}
bool getans(double x,int y,double z)
{
	double now=x*total;
	for (int a=0;a<n;++a)
	if (a!=y)
	if (z-num[a]>0)
	{
		if (z-num[a]<now)
		{
			now-=z-num[a];
		}else return true;
	}
	if (now==0) return true;
	return false;
}
double getmin (int x)
{
	double l=0,r=1,mid;
	while (fabs(l-r)>1e-10)
	{
		mid=(l+r)/2.0;
		if (getans(1.0-mid,x,num[x]+mid*total))
		{
		//	printf("Y");
			r=mid;
		}else
		{
		//	printf("N");
			l=mid;
		}
	}
	return r;
}
int main()
{
	freopen("A1.in","r",stdin);
	freopen("A1.out","w",stdout);
	scanf("%d",&times);
	for (int z=1;z<=times;++z)
	{
		mem();
		scanf("%d",&n);
		int p1,p2,m1,m2;
		m1=m2=maxint;
		for (int a=0;a<n;++a)
		{
			scanf("%lf",&num[a]);
			num[a]*=100000;
			total+=num[a];
		}
		printf("Case #%d:",z);
		for (int a=0;a<n;++a)
		{
			printf(" %.7lf",100.0*getmin(a));
		}
		printf("\n");
	}
}