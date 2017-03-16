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
	string s, pref, suf;
	cin >> s;
	int64_t p = s.size();
	for (char c = 'Z'; c >= 'A'; --c) {
		auto pos = s.find(c);
		if (pos == string::npos)
			continue;
		for (; p > int64_t(pos); --p) {
			char d = s[p - 1];
			(d == c ? pref : suf).push_back(d);
		}
	}
	reverse(all(suf));
	cout << (pref + suf) << '\n';
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
