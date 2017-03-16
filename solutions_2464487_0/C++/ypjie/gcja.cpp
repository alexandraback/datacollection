#include <math.h>
#include <iostream>
using namespace std;

const long long OO = 800000000;

long long ans;
long long nowtd;
long long r;
long long t;
long long tdnum;

long long min(long long a, long long b) {return a < b ? a : b;}

void ri() {cin >> r >> t;}

long long calc(long long mid)
{
	long long part1 = 2 * r * mid;
	long long part2 = mid * (2 * mid - 1);
	
	return part1 + part2;
}

void solve()
{	
	long long hi = min(OO, min(t / r, (long long)sqrt(t) +10)) + 100;
	long long mid;
	long long lo = 0;
	
	while (lo < hi - 1)
	{
		mid = (lo + hi) >> 1;
		if (calc(mid) <= t) lo = mid; else hi = mid;
	}
	ans = lo;
}
void print() {cout << "Case #" << nowtd << ": " << ans << "\n";}

int main()
{
	cin >> tdnum;
	for (nowtd = 1; nowtd <= tdnum; nowtd++)
	{
		ri();
		solve();
		print();
	}
	return 0;
}
