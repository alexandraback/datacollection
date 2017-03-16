#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long ll;

bool solve2(int N, double w[2][1010], int m) {
	for (int i = 0; i < N-m; i++) {
		if (w[0][m+i] < w[1][i])
			return false;
	}
	return true;
}

pair<int, int> solve(int N, double w[2][1010]) {
	pair<int, int> ans = make_pair(0, 0);
	sort(w[0], w[0]+N);
	sort(w[1], w[1]+N);
	set<double> s(w[1], w[1]+N);
	for (int i = 0; i < N; i++) {
		set<double>::iterator it = s.lower_bound(w[0][i]);
		if (it == s.end()) {
			s.erase(s.begin());
			ans.second++;
		} else {
			s.erase(it);
		}
	}
	if (solve2(N, w, 0))
		ans.first = N;
	else {
		int l = 0;
		int r = N;
		for (int i = 0; i < 16; i++) {
			int m = (l+r)/2;
			if (solve2(N, w, m)) {
				r = m;
			} else {
				l = m;
			}
		}
		ans.first = N-r;
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		static double w[2][1010];
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < N; k++)
				cin >> w[j][k];
		}
		pair<int, int> ans = solve(N, w);
		cout << "Case #" << i+1 << ": " << ans.first << " " << ans.second << endl;
	}
}
