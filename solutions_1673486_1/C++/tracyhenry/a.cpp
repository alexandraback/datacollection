#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;

double P[201010];
double C[201010];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
	int A, B, T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t ++)
	{
		cout << "Case #" << t << ": ";
		scanf("%d %d", &A, &B);
		for (int i = 1; i <= A; i ++)
			cin >> P[i];
		C[0] = 1.0;
		for (int i = 1; i <= A; i ++)
			C[i] = C[i - 1] * P[i];
		double ans = B + 2;
		ans = min(ans, C[A] * (B - A + 1) + (1 - C[A]) * (B - A + 1 + B + 1));
		//
		for (int i = 1; i <= A; i ++)
		{
			double cur;
			cur = C[A - i] * (B - (A - i) + 1) + (1 - C[A - i]) * (B - (A - i) + 1 + B + 1) + i;
			ans = min(ans, cur);
		}
		printf("%.6lf\n", ans);
	}
	return 0;
}
			
