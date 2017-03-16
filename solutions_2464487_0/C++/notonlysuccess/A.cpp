#include <cstdio>
#include <iostream>
using namespace std;
long long r , t;
bool ok(long long mid) {
	if (mid == 0) return true;
	return 2 * r * mid + (4 * mid - 2) * mid / 2 <= t;
}
int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T , cas = 1;
	cin >> T;
	while (T --) {
		cin >> r >> t;
		long long lo = 0;
		long long hi = t / r / 2;
		while (lo <= hi) {
			long long mid = (lo + hi) >> 1;
			if (ok(mid)) lo = mid + 1;
			else hi = mid - 1;
		}
		cout << "Case #" << cas ++ << ": " << lo - 1 << endl;
	}
	return 0;
}