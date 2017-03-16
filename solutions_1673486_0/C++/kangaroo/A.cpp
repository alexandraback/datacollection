//============================================================================
// Name        : A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
using namespace std;

const int maxn = 200000;
double p[maxn];

void pressEnter(int m, int n, double &ans)
{
	ans = 1 + n + 1;
}

void keepTyping(int m, int n, double &ans)
{
	double tmp = 1;
	for (int i = 1; i <= m; ++i)
		tmp *= p[i];
	double cnt = tmp * (n - m + 1);
	cnt += (1 - tmp) * (n - m + 1 + n + 1);
	if (cnt < ans)
		ans = cnt;
}

void backspace(int m, int n, double &ans)
{
	double prob = 1;
	if (m + n + 1 < ans)
		ans = m + n + 1;
	for (int i = m - 1; i >= 0; --i)
	{
		prob *= p[m - i];
		double cnt = prob * (n - m + i * 2 + 1);
		cnt += (1 - prob) * (n - m + i * 2 + 1 + n + 1);
		if (cnt < ans)
			ans = cnt;
	}
}

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int casenum = 1; casenum <= T; ++casenum)
	{
		int m, n;
		scanf("%d %d", &m, &n);
		for (int i = 1; i <= m; ++i)
			scanf("%lf", &p[i]);

		double ans;
		pressEnter(m, n, ans);
		keepTyping(m, n, ans);
		backspace(m, n, ans);

		printf("Case #%d: %.6f\n", casenum, ans);
	}
	return 0;
}
