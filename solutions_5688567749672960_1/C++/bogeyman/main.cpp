#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <fstream>
#include <map>
#include <cmath>
#include <set>
#include <string.h>
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long ll;

ll deg[20], f[20];
int t;

int main()
{
	freopen("/Users/user/Downloads/A-large.in", "r", stdin);
	freopen("z.out", "w", stdout);
	
	cin >> t;
	
	deg[0] = 1;
	f[1] = 0;
	for(int i = 1; i < 17; i++)
	{
		deg[i] = deg[i - 1] * 10;
		if(i < 4)
			f[i + 1] = f[i] + deg[i - 1] + 9;
		else
			f[i + 1] = f[i] + deg[i / 2] + deg[i - i / 2] - 1;
	}
	for(int q = 0; q < t; q++)
	{
		ll x, res = 0;;
		cin >> x;
		if(x == 1)
		{
			printf("Case #%d: %d\n", q + 1, 1);
			continue;
		}
		if(x % 10 == 0)
		{
			x--;
			res++;
		}
		vector <int> v;
		while(x > 0)
		{
			v.push_back(x % 10);
			x /= 10;
		}
		res += f[v.size()];
		ll a = 0, b = 0;
		for(int i = int((v.size() - 1) / 2); i >= 0; i--)
			a = a * 10 + v[i];
		for(int i = int((v.size() - 1) / 2) + 1; i < v.size(); i++)
			b = b * 10 + v[i];
		res += a + b;
		if(b == 1)
			res--;
		printf("Case #%d: %lld\n", q + 1, res);
	}
}