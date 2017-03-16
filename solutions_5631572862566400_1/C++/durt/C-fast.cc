#include <bits/stdc++.h>
using namespace std;

int N;
int bf[2000];

int longest[2000];
bool incycle[2000];

int maxCycle() {
	int ans = 0;
	bool hit[2000];
	for (int j = 1; j <= N; j++) {
		hit[j] = 0;
	}
		
	for (int i = 1; i <= N; i++) {
		hit[i] = 1;
		int k = bf[i];
		int cnt = 1;
		while (!hit[k]) {
			hit[k] = 1;
			k = bf[k];
			cnt++;
		}
		if (k == i) {
			incycle[i] = 1;
			ans = max(ans, cnt);
		}
		// reset
		for (int j = 1; j <= N; j++) {
			hit[j] = 0;
		}
	}
	return ans;
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> bf[i];
			longest[i] = 0;
			incycle[i] = 0;
		}
			
		// (1) longest cycle -- also fill in longest[]
		int ans1 = maxCycle();
		
		// traverse from those not incycle, to fill in longest incoming
		for (int i = 1; i <= N; i++) {
			if (!incycle[i]) {
				int k = bf[i];
				int cnt = 1;
				while (!incycle[k]) {
					k = bf[k];
					cnt++;
				}
				longest[k] = max(longest[k], cnt);
			}
		}
		
		// (2) sum of two longest chains into a diatom
		int ans2 = 0;
		for (int i = 1; i <= N; i++) {
			if (i == bf[bf[i]] && i < bf[i]) {
				assert(i != bf[i]);
				int a = i;
				int b = bf[i];
				assert(incycle[a] && incycle[b]);
				//cout << "found diatom: a=" << a << " b=" << b << endl;
				int cur = 2 + longest[a] + longest[b];
				ans2 += cur;
				//ans2 = max(ans2, cur);
			}
		}
		
		int ans = max(ans1, ans2);
		
		cout << "Case #" << icase << ": " << ans << endl;
	}
	return 0;
}
