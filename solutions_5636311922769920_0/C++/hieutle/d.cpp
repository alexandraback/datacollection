#include <stdio.h>
#include <iostream>
// #define TEST

using namespace std;
typedef unsigned long long uint64;

uint64 power(int a, int b)
{
	if (b == 0) 
		return 1;
	uint64 res = power(a, b >> 1);
	res *= res;
	if (b % 2 == 1)
		res *= a;
	return res;
}

int main()
{
	#ifndef TEST
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		int k, c, s;
		cin >> k >> c >> s;
		uint64 step = power(k, c - 1);
		cout << "Case #" << tt << ":";
		uint64 tile = 1;
		for (int i = 0; i < s; i++) {
			cout << " " << tile;
			tile += step;
		}
		cout << endl;
	}
}
