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
	vector<int> bff(n);
	for (auto &b: bff) {
		cin >> b;
		--b;
	}
	vector<char> used(n);
	vector<int> circle(n);
	vector<int> circlen;
	for (int i = 0; i < n; ++i) if (!used[i]) {
		int p;
		for (p = i; !used[p]; p = bff[p]) {
			used[p] = true;
		}
		if (!circle[p]) {
			circlen.emplace_back(0);
			for (int q = p; !circle[q]; q = bff[q]) {
				++circlen.back();
				circle[q] = int(circlen.size());
			}
		}
		for (p = i; !circle[p]; p = bff[p])
			circle[p] = -1;
	}
	vector<int> maxd(n);
	for (int i = 0; i < n; ++i) if (circle[i] < 0) {
		int d = 0, p;
		for (p = i; circle[p] < 0; p = bff[p])
			++d;
		if (circlen[circle[p] - 1] != 2)
			continue;
		maxd[p] = max(maxd[p], d);
	}
	int ans = accumulate(all(maxd), 0);
	ans += 2 * int(count(all(circlen), 2));
	ans = max(ans, *max_element(all(circlen)));
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
