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
	int n;
	cin >> n;
	map<int, int> cnt;
	for (int i = 0; i < 2 * n - 1; ++i) {
		for (int j = 0; j < n; ++j) {
			int h;
			cin >> h;
			++cnt[h];
		}
	}
	for (const auto &p: cnt) if (p.second & 1)
		cout << p.first << ' ';
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
