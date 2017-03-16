#include <bits/stdc++.h>
using namespace std;
#if defined(ILIKEGENTOO)
void E(){}template<class A,class...B>void E(A _,B...$){cerr<<' '<<_;E($...);}
#define E($...) E(#$,'=',$,'\n')
#else
#define E($...) ;
#endif
#define all(x) begin(x), end(x)
struct ${$(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}}$;

void solve() {
	int64_t k, c, s;
	cin >> k >> c >> s;
	int64_t sans = (k + c - 1) / c;
	if (s < sans) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	for (int64_t i = 0; i < k; i += c) {
		int64_t ind = 0;
		for (int64_t j = 0; j < c; ++j) {
			int64_t m = min(i + j, k - 1);
			ind = k * ind + m;
		}
		cout << (1 + ind) << ' ';
	}
	cout << '\n';
}

int main() {
	int tc;
	cin >> tc;
	for (int ti = 1; ti <= tc; ++ti) {
		cout << "Case #" << ti << ": ";
		solve();
	}
	return 0;
}
