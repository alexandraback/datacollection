#include <vector>
#include <stack>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <functional>
#include <set>
#include <cstring>
#include <queue>
#include <stdlib.h>
#include <time.h>
#define all(o) (o).begin(), (o).end()
#define mp(x, y) make_pair(x, y)
//#define x first
//#define y second
//#define pt pair <double, double>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int S = int(2e5) + 105;
const int INF = int(1e9) + 7;


ll t, n;

ll solve(ll n)
{
	int had[11], cnt = 10;
	ll m = 0;
	memset(had, 0, 10 * sizeof(int));
	while(cnt > 0)
	{
		m += n;
		ll m1 = m;
		while(m1 > 0)
		{
			if(had[m1 % 10] == 0)
			{
				had[m1 % 10] = 1;
				cnt--;
			}
			m1 /= 10;
		}
	}
	return m;
}


int main()
{
	freopen("/Users/user/Downloads/A-small-attempt0.in", "r", stdin);
	freopen("key.out", "w", stdout);
	cin >> t;
	for(int q = 0; q < t; q++)
	{
		scanf("%lld", &n);
		if(n == 0)
			printf("Case #%d: INSOMNIA\n", q + 1);
		else
			printf("Case #%d: %lld\n", q + 1, solve(n));
	}
	
	return 0;
}