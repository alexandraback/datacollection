#include <stdio.h>
#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull r, t;
int T;

ull get(ull x)
{
	ull start = 2 * r + 1;
	ull d = 4;
	ull n = x;
	double dv = (double)start * n + (double)n * (n - 1) * 2;
	if (dv > 3e18) return (ull)3e18;
	ull v = start * n + n * (n - 1) * 2;
	return v;
}

void work()
{
	cin >> r >> t;
	ull left = 0, right = t;
	while (left + 1 < right) {
		ull mid = (left + right) / 2;
		ull midvalue = get(mid);
		//cout << left << ' ' << right << ' ' << midvalue << endl;
		if (midvalue > t)
			right = mid;
		else
			left = mid;
	}
	static int ttt = 0;
	cout << "Case #" << ++ttt << ": ";
	cout << left << endl;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	while (T--) work();
}