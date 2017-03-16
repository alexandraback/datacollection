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
	int d;
	cin >> d;
	vector<int> cakes(d);
	assert(d > 0);
	for (auto &v: cakes)
		cin >> v;
	int best = *max_element(all(cakes));
	for (int tgt = 1; tgt <= best; ++tgt) {
		int sum = tgt;
		for (int v: cakes) if (v > tgt) {
			sum += (v - 1) / tgt; 
		}
		best = min(best, sum);
	}
	cout << best;
}

int main() {
	ios_base::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	for (int t = 0; t < tcase; ++t) {
		cout << "Case #" << (t + 1) << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}

