#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const double PI = 3.141592653589793238;
#define sqr(x) ((x) * (x))

unsigned long long r, t;

bool bigger(long long &x)
{
	unsigned long long a = x;
	unsigned long long rr = r;
	if (a != 0 && (rr * 2 - 1) > (t / a))
		return true;
	a = sqr(a) * 2 + (rr * 2 - 1) * a;
	return a > t;
}

long long calc()
{
	long long L = 0, R = 2000000000;
	while (L <= R)
	{
		long long mid = (L + R) / 2;
		//cout << L << ' ' << R << ' ' << mid << endl;
		if (bigger(mid))
			R = mid - 1;
		else 
			L = mid + 1;
	}
	return R;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt)
	{
		cin >> r >> t;
		/*
		long double b = (long double)2.0 * r - 1.0;
		long double c = t;
		c *= 2 * 4;
		long double tmp = sqr(b);
		tmp += c;
		tmp = sqrt(tmp);
		cout << tmp << endl;
		tmp -= b;
		tmp /= 4;
		long long ans = tmp;
		*/
		long long ans = calc();
		printf("Case #%d: %I64d\n", tt, ans);
	}

	return 0;
}
