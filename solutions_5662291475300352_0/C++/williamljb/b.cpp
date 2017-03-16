#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
using namespace std;

int p[10];
double v[10];
int tt;

void solve()
{
	int n;
	tt = 0;
	scanf("%d", &n);
	while (n--)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		for (int i = tt; i < tt + y; ++i)
		{
			p[i] = x;
			v[i] = (double)360 / (z+i-tt);
		}
	}
	double k = (360.0 - p[0]) / v[0];
	double k0 = ((360 + p[0] - p[1])%360 == 0 ? 360.0 : (360 + p[0] - p[1])%360+0.0) / (v[1] - v[0]);
	//cout << k << " " << k0 << endl;
	if (k > k0 - 1e-8 && k0 > 1e-8)
	{
		printf("1\n");
		return;
	}
	k = (360.0 - p[1]) / v[1];
	k0 = ((360 + p[1] - p[0])%360==0 ? 360.0 : (360 + p[1] - p[0])%360+0.0) / (v[0] - v[1]);
	//cout << k << " " << k0 << endl;
	if (k > k0 - 1e-8 && k0 > 1e-8)
	{
		printf("1\n");
		return;
	}
	printf("0\n");
}

int main()
{
	freopen("a.txt", "r", stdin);
	freopen("b.out", "w", stdout);
	int times;
	scanf("%d", &times);
	for (int i = 1; i <= times; ++i)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}