#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

long long x;
int a[100];

long long rev(long long x)
{
	int cnt = 0;
	for( ; x; x /= 10) a[cnt ++] = x % 10;
	x = 0;
	for(int i = 0; i < cnt; ++ i)
		x = x * 10 + a[i];
	return x;
}

long long solve(long long x)
{
	if (x <= 20) return x;
	if (x % 10 == 0) {
		return solve(x - 1) + 1;
	}
	int cnt = 0;
	for(long long y = x; y; y /= 10) {
		a[cnt ++] = y % 10;
	}
	for(int i = 0; i < cnt / 2; ++ i) {
		a[i] = 0;
	}
	a[0] = 1;
	long long toG = 0, nx = 0;
	for(int i = cnt - 1; i >= 0; -- i) {
		toG = toG * 10 + a[i];
	}
	for(int i = 0; i < cnt / 2; ++ i) {
		swap(a[i], a[cnt - 1 - i]);
	}
	for(int i = cnt - 1; i >= 0; -- i) {
		nx = nx * 10 + a[i];
	}
	if (nx < toG) {
		return solve(nx) + x - toG + 1;
	} else {
		return solve(nx - 1) + x - toG + 1;
	}
}

void solve()
{
	cin >> x;
	cout << solve(x) << endl;
}

int main()
{
	//freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-attempt0.out", "w", stdout);
	//freopen("A-small-attempt1.in", "r", stdin); freopen("A-small-attempt1.out", "w", stdout);
	freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	int test_case;
	cin >> test_case;
	for(int i = 0; i < test_case; ++ i) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
