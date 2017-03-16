#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;


long long m, r;

void Load()
{
	cin >> r >> m;
}

const long long MAX = 4000000000000000000L;

long long f(long long r, long long n) {
	if (n > MAX / (2*r+2*n-1))
		return MAX;
	return n * (2 * r + 2 * n - 1);
}

void Solve()
{
	long long ll, rr;
	ll = 1;
	rr = 1;
	while (f(r, rr) <= m)
		rr *= 2;
	long long ans = 0;
	while (ll <= rr) {
		long long mid = (rr + ll) / 2;
		long long cur = f(r, mid);
		if (cur > m) rr = mid-1;
		else {
			if (ans < mid)
				ans = mid;
			ll = mid+1;	
		}
	}
	cout << ans << "\n";
}

int main()
{
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Load();
		Solve(); 
	}
	return 0;
}
