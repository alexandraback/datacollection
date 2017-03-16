#include <bits/stdc++.h>

using namespace std;

int depth(int cur, int par, vector<vector<int>> &rev) {
	int best = 0;
	for (auto c : rev[cur]) {
		if (par == c) continue;
		best = max(best, 1+depth(c, cur, rev));
	}
	return best;
}

void doCase(int t) {
	int N;
	cin >> N;
	vector<int> F(N);
	for (int i=0; i<N; i++) cin >> F[i];
	for (int i=0; i<N; i++) F[i]--;
	
	vector<vector<int>> rev(N);
	for (int i=0; i<N; i++) rev[F[i]].push_back(i);
	
	vector<bool> seen(N,false);
	vector<pair<int, int>> circ2s;
	vector<int> circSizes;
	for (int i=0; i<N; i++) {
		if (seen[i]) continue;
		
		int cur = i;
		int l = 1;
		vector<int> stackPos(N,-1);
		stackPos[cur] = 0;
		seen[cur] = true;
		while (true) {
			cur = F[cur];
			if (seen[cur]) {
				if (stackPos[cur] != -1) {
					circSizes.push_back(l-stackPos[cur]);
					if (l-stackPos[cur] == 2) {
						circ2s.push_back({cur,F[cur]});
					}
				}
				break;
			}
			stackPos[cur] = l;
			l++;
			seen[cur] = true;
		}
	}
	
	int c2sum = 0;
	for (auto c2 : circ2s) {
		c2sum += 2 + depth(c2.first, c2.second, rev) + depth(c2.second, c2.first, rev);
	}
	
	int msize = 0;
	for (auto c : circSizes) msize = max(msize, c);
	
	cout << "Case #" << t << ": " << max(c2sum, msize) << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i=0; i<t; i++) doCase(i+1);
	return 0;
}
