#include <stdio.h>
#include<vector>
#include<iostream>
#include <math.h>
#include <algorithm>
#include<cstring>
#include<ctime>
#include<set>
#include <queue>
#include<map>
#include<string>
using namespace std;
const double EPS = 1e-9;
typedef long long ll;
typedef unsigned long long ull; 
int nextint(){int a;scanf("%d",&a);return a;}
ll nextll(){ll a;scanf("%lld",&a);return a;}
double nextdouble(){double a;scanf("%lf",&a);return a;}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t = nextint();

	for(int test = 1; test <= t; test++)
	{
		ll a = nextint();
		int n = nextint();
		vector<ll> v(n);
		for(int i = 0; i < n; i++)
			v[i] = nextint();

		sort(v.begin(), v.end());
		int ret = n;
		int res = 0;
		if(a == 1)
			res = n;
		else
		{
			for(int i = 0; i < n; i++)
			{
				while(a <= v[i])
				{
					a += a-1;
					res++;
				}
				a += v[i];
				ret = min(ret, res+(n-i-1));
			}
		}
		printf("Case #%d: %d\n", test, ret);
	}

	return 0;
}