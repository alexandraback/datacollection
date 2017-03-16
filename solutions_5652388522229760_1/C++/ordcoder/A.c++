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
	int64_t n;
	cin >> n;
	array<bool, 10> use{{false}};
	if (n == 0) {
		cout << "INSOMNIA\n";
		return;
	}
	int64_t i, q;
	for (i = 1, q = n; i < 10000; ++i, q += n) {
		for (int64_t w = q; w;) {
			auto dr = lldiv(w, 10);
			use[dr.rem] = true;
			w = dr.quot;
		}
		if (all_of(all(use), [](bool b){return b;}))
			break;
	}
	if (i < 10000) {
		cout << q << "\n";
	} else {
		cout << "INSOMNIA\n";
		cerr << "bad " << n << "\n";
	}
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
