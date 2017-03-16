/*
 * File: A.cpp
 * Author: wym510 
 * Email: <wym6110@gmail.com>
 * Create Date: 2012-4-28 9:36:32
*/

#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define S size()
#define B begin()
#define E end()
#define P push_back
#define fu(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=b-1;i>=a;--i)
typedef long long int64;
using namespace std;

const int MaxN=400000;
double p[MaxN];

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);

	int test;

	cin>>test;
	for(int no=1;no<=test;no++)
	{
		int n,m;

		scanf("%d%d",&n,&m);
		p[0]=1;
		for(int i=1;i<=n;i++)
		{
			double a;

			scanf("%lf",&a);
			p[i]=p[i-1]*a;
		}

		double ans=m+2;

		for(int i=0;i<=n;i++)
		{
			double tmp=2*i+m-n+1+(1-p[n-i])*(m+1);

			ans=min(ans,tmp);
		}

		printf("Case #%d: %.10lf\n",no,ans);
	}

	return 0;
}

/* vim: set ts=4 sw=4: */

