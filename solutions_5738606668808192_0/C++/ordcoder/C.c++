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
	uint64_t j;
	cin >> n >> j;
	assert((uint64_t(1) << (n / 2 - 2)) >= j);
	for (uint64_t i = 0; i < j; ++i) {
		cout << "11";
		for (int64_t k = n / 2 - 3; k >= 0; --k)
			cout << ((i & (uint64_t(1) << k)) ? "11" : "00");
		cout << "11";
		for (int i = 2; i <= 10; ++i)
			cout << " " << (i + 1);
		cout << "\n";
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int ti = 1; ti <= tc; ++ti) {
		cout << "Case #" << ti << ":\n";
		solve();
	}
	return 0;
}
