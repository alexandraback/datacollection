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
	string s;
	cin >> s;
	reverse(all(s));
	int ans = 0;
	for (char c: s)
		ans += c == '+' == (ans & 1);
	cout << ans << '\n';
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
