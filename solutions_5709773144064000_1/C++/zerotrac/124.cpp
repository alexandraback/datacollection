#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#define maxlongint 2147483647
#define LL long long
#define pb push_back
#define mp make_pair

using namespace std;

int T,cs=0;
double c,f,x;

int main()
{
	freopen("123.in","r",stdin);
	freopen("123.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		double ans=x/2.0,tm=0.0,cook=2.0;
		while(1)
		{
			tm+=c/cook;
			cook+=f;
			double now=tm+x/cook;
			if(now<ans)ans=now;else break;
		}
		printf("Case #%d: %.10lf\n",++cs,ans);
	}
	return 0;
}
