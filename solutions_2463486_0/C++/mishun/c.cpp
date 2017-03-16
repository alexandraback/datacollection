#include <cassert>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPal(long long n)
{
	int l = 0;
	int t[1024];

	while(n > 0)
	{
		t[l++] = (int)(n % 10);
		n /= 10;
	}

	for(int i = 0; i < l; i++)
		if(t[i] != t[l - 1 - i])
			return false;

	return true;
}

vector<long long> generateTo(long long n)
{
	vector<long long> r;
	for(long long a = 1; a <= n; a++)
	{
		long long b = a * a;
		if(b > n)
			break;
		if(isPal(a) && isPal(b))
			r.push_back(b);
	}
	return r;
}

int before(const vector<long long> a, long long n)
{
	int r = 0;
	for(int i = 0; i < a.size(); i++)
		if(a[i] <= n)
			r++;
	return r;
}

int main()
{
/*	{
		vector<long long> r = generateTo(10000000);
		for(int i = 0; i < r.size(); i++)
			cout << r[i] << "\n";

		for(long long x = 1; x < 10000000; x++)
		{
			long long y = x * x;
			if(isPal(x) && isPal(y))
				cout << x << " " << y << "\n";
		}
	}*/

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t = 0;
	cin >> t;

	vector<long long> r = generateTo(100000000000000LL);
	for(int tn = 1; tn <= t; tn++)
	{
		long long a, b;
		cin >> a >> b;

		printf("Case #%i: %i\n", tn, before(r, b) - before(r, a - 1));
	}

	return 0;
}
