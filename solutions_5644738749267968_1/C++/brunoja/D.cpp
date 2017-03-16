#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1000;

int n, out[N];
double A[N], B[N];

int solve2()
{
	int r = 0, p = n-1;
	
	for (int i = n-1; i >= 0; --i)
	{
		while (p >= 0 && A[i] < B[p]) --p;
		if (p == -1) break;
		--p;
		++r;
	}
	
	return r;
}

int solve1()
{
	int r = 0;
	memset(out, 0, sizeof out);
	
	for (int i = 0; i < n; ++i)
	{
		int k = -1;
		for (int j = 0; j < n && k == -1; ++j)
			if (B[j] > A[i] && !out[j]) k = j;
		if (k == -1)
		{
			for (int j = 0; j < n; ++j) if (!out[j])
			{
				out[j] = 1;
				break;
			}
			++r;
		}
		else out[k] = 1;
	}
	
	return r;
}

int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	
	for (int q = 1; q <= t; ++q)
	{
		cout << "Case #" << q << ": ";
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> A[i];
		for (int i = 0; i < n; ++i)
			cin >> B[i];
		sort(A, A+n);
		sort(B, B+n);
		cout << solve2() << ' ' << solve1() << endl;
	}
}
		
