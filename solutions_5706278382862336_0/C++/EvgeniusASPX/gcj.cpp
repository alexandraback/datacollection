#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include "stdio.h"
using namespace std;
int gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return a + b;
	else if (a < b)
		return gcd(a, b % a);
	else
		return gcd(a % b, b);
		
}
void solve_case(int test_case)
{
	int n, res = -1;
	long long p, q;
	cout << "Case #" << test_case << ": ";
	long long deep = 0;
	char c;
	cin >> p >> c>> q;
	long long gg = gcd(p, q);
	p /= gg;
	q /= gg;
	long long base = 1;
	while (deep < 42)
	{
		if (base % q == 0)
			break;

		base *= 2;
		deep++;
	}
	long long mod = base % q;
	if (mod != 0)
	{
		cout << "impossible\n";
		return;
	}
	long long k = base / q;
	p *= k;
	q = base;
	long long t = 2;
	while (t <= p)
	{
		t *= 2;
		deep--;
	}
	cout << deep << endl;
}

int main()
{

#ifdef __OLIMP__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
		solve_case(tc);

	return 0;
}