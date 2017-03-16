#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#if !defined(ID)
#define ID(x)
#endif
using namespace std;
void E(){}template<class A,class...B>void E(A _,B...$){ID(cerr<<' '<<_;E($...);)}
#define E($...) E(#$,'=',$,'\n')

int n;

int solve0(vector<double> a, vector<double> b) {
	deque<double> bs(all(b));
	int ans = 0;
	for (auto e: a) {
		if (e < bs.front()) {
			bs.pop_back();
		} else {
			++ans;
			bs.pop_front();
		}
	}
	return ans;
}

int solve1(vector<double> a, vector<double> b) {
	set<double> bs(all(b));
	int ans = 0;
	for (auto e: a) {
		auto it = bs.lower_bound(e);
		if (it == end(bs)) {
			bs.erase(begin(bs));
			++ans;
		} else {
			bs.erase(it);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	int tn;
	scanf("%d", &tn);
	for (int tc = 1; tc <= tn; ++tc) {
		scanf("%d", &n);
		vector<double> a(n), b(n);
		for (auto &e: a) scanf("%lf", &e);
		for (auto &e: b) scanf("%lf", &e);
		sort(all(a));
		sort(all(b));
		if (0) {
			for (auto ae: a) {
				int v = 0;
				for (auto be: b) { if (ae > be) ++v; }
				cout << v << " ";
			} cout << "\n";
			continue;
		}
		int ans0 = solve0(a, b);
		int ans1 = solve1(a, b);
		reverse(all(a));
		int ans2 = solve1(a, b);
		assert(ans1 == ans2);
		printf("Case #%d: %d %d\n", tc, ans0, ans1);
	}
	return 0;
}
