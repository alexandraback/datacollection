#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		int N;
		cin >> N;
		vector<int> a(N), b(N);
		for (int i = 0; i < N; ++ i) {
			cin >> a[i] >> b[i];
		}
		map<vector<int>, int> M;
		queue<vector<int> > Q;
		M[vector<int>(N, 0)] = 0;
		Q.push(vector<int>(N,0));
		while (!Q.empty()) {
			vector<int> v = Q.front();
			Q.pop();
			int s = 0;
			for (int i = 0; i < N; ++ i) {
				s += v[i];
			}
			for (int i = 0; i < N; ++ i) {
				if (v[i] <= 0 && a[i] <= s) {
					vector<int> vv = v;
					vv[i] = 1;
					if (M.count(vv) == 0) {
						M[vv] = M[v] + 1;
						Q.push(vv);
					}
				}
				if (v[i] <= 1 && b[i] <= s) {
					vector<int> vv = v;
					vv[i] = 2;
					if (M.count(vv) == 0) {
						M[vv] = M[v] + 1;
						Q.push(vv);
					}
				}
			}
		}
		int r = M[vector<int>(N, 2)];
		if (r <= 0) {
			printf("Case #%d: Too Bad\n", tt);
		} else {
			printf("Case #%d: %d\n", tt, r);
		}
	}
}
