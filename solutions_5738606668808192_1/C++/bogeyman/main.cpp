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



int t, cnt = 32, num = 500;

ull convert(ull mask, ull base, ull mod)
{
	ull res = 0, a = 1;
	for(int i = 0; i < cnt; i++)
	{
		res = (res + a * (mask & 1)) % mod;
		mask >>= 1;
		a = (a * base) % mod;
	}
	return res;
}


int main()
{
//	freopen("/Users/user/Downloads/B-large.in", "r", stdin);
//	freopen("key.out", "w", stdout);
//	cin >> t;
	t = 1;
	for(int q = 0; q < t; q++)
	{
		printf("Case #%d:\n", q + 1);
		for(ull mask = (1LL << (cnt - 2)); num > 0 && mask < (1LL << (cnt - 1)); mask++)
		{
			bool flag = true;
			vector <ull> v;
			for(int b = 2; b <= 10; b++)
			{
				for(int i = 2; i < 10000; i++)
					if(convert(2 * mask + 1, b, i) == 0)
					{
						v.push_back(i);
						break;
					}
				if(int(v.size()) < b - 1)
					flag = false;
			}
			if(flag)
			{
				num--;
				vector <int> u;
				ull m = 2 * mask + 1;
				for(int i = 0; i < cnt; i++)
				{
					u.push_back(m & 1);
					m >>= 1;
				}
				reverse(all(u));
				for(int i = 0; i < cnt; i++)
					printf("%d", u[i]);
				printf(" ");
				for(int i = 0; i < 9; i++)
					printf("%llu ", v[i]);
				printf("\n");
			}
		}
	}
	
	return 0;
}