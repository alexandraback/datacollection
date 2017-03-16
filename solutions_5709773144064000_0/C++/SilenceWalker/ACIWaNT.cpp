#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;
#define eps 1e-9
double C, F, X;

double f[10000];
int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int T; cin >> T;
	for (int Cas = 1; Cas <= T; ++Cas)
	{
		cin >> C >> F >> X;
		double ans = 1e15;
		double t = 0, rest = 0;
		double speed = 2.0;
		f[0] = X / 2.0;
		f[1] = C / 2.0 + X / (2.0 + F);
		for (int i = 2; i < 10000; ++i)
			f[i] = f[i - 1] + C / (2.0 + (i-1)*F) - X / (2 + (i - 1)*F) + X / (2 + i*F);
		for (int i = 0; i < 10000; ++i)
			ans = min(ans, f[i]);
		printf("Case #%d: %.7lf\n", Cas, ans);
	}
}