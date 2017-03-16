#include <bits/stdc++.h>
using namespace std;
#if defined(ILIKEGENTOO)
void E(){}template<class A,class...B>void E(A _,B...$){cerr<<' '<<_;E($...);}
#define E($...) E(#$,'=',$,'\n')
#else
#define E($...) ;
#endif
#define all(x) begin(x), end(x)

void solve() {
	int n;
	string s;
	cin >> n >> s;
	assert(s.size() == n + 1ull);
	int ans = 0;
	int sum = 0;
	for (int i = 0; i <= n; ++i) if (s[i] != '0') {
		int v = s[i] - '0';
		assert(0 < v && v < 10);
		if (sum < i) {
			ans += i - sum;
			sum += i - sum;
		}
		sum += v;
	}
	cout << ans;
}

int main() {
	int tcase;
	cin >> tcase;
	for (int t = 0; t < tcase; ++t) {
		cout << "Case #" << (t + 1) << ": ";
		solve();
		cout << "\n";
	}
	ios_base::sync_with_stdio(false);
	return 0;
}

