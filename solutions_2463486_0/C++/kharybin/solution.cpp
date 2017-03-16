#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

template <class T> T sqr(T x) { return x*x; }

const int INF = 1000*1000*1000;
const long long INF64 = sqr(static_cast<long long>(INF));
const double PI = acos(-1.0);

long long rev(long long x)
{
	long long ret = 0;
	while(true)
	{
		ret = 10 * ret + (x % 10);
		if (x < 10)
			break;
		x /= 10;
	}
	return ret;
}

bool isPalindrom(long long x)
{
	return x == rev(x);
}

int mySqrt(long long x)
{
	return sqrt((double)x) + (1e-8);
}

const int N = 10000500;

int ans[N];

void calc(bool verbose = false)
{
	ans[0] = 0;
	for (int i = 1; i < N; ++i)
	{
		ans[i] = ans[i-1];
		long long s = sqr((long long)i);
		if (isPalindrom(i) && isPalindrom(s))
		{
			++ans[i];
			if (verbose)
				cout << i << " " << s << endl;
		}
	}
}

int get(long long n)
{
	return ans[mySqrt(n)];
}

int get(long long l, long long r)
{
	return get(r) - get(l-1);
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	calc();
	int testCaseCount;
	cin >> testCaseCount;
	for(int testCaseNumber = 1; testCaseNumber <= testCaseCount; ++testCaseNumber)
	{
		long long l, r;
		cin >> l >> r;
		cout << "Case #" << testCaseNumber << ": " << get(l, r) << endl;
	}
	return 0;
}