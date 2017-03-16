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
const int S = int(2e6) + 5;
const ull INF = ull(1e9) + 7;



int t;
ll k, c, s;



int main()
{
	freopen("/Users/user/Downloads/D-small-attempt0.in", "r", stdin);
	freopen("key.out", "w", stdout);
	cin >> t;
	for(int q = 0; q < t; q++)
	{
		scanf("%lld %lld %lld", &k, &c, &s);
		printf("Case #%d: ", q + 1);
		if(s < (k + c - 1)/c)
			printf("IMPOSSIBLE");
		else
			for(int i = 0; i < k;)
			{
				ll r = 0, a = 1;
				for(int j = 0; j < c && i < k; i++, j++)
				{
					r += a * i;
					a *= k;
				}
				printf("%lld ", r + 1);
			}
		if(q != t - 1)
			printf("\n");
	}
	
	return 0;
}