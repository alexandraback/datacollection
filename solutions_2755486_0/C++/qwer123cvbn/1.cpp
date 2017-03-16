#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <fstream>
using namespace std;

int n, wall[10000], w[1000], e[1000], s[1000], d[1000], num[1000], deltap[1000], deltas[1000], deltad[1000];
int main() {
	freopen("gcj_c.in", "r", stdin);
	freopen("gcj_c.out", "w", stdout);
	int t;
	cin >> t;
	for (int l = 1; l <= t; l++) {
		cin >> n;
		memset(wall, 0, sizeof(wall));
		for (int i = 0; i < n; i++) {
			cin >> d[i] >> num[i] >> w[i] >> e[i] >> s[i] >> deltad[i] >> deltap[i] >> deltas[i];
			w[i] += 1000;
			e[i] += 1000;
		}
		int res = 0;
		for (int i = 0; i < 700000; i++) {
			int list[10000], delta[10000];
			list[0] = 0;
			for (int j = 0; j < n; j++) {
				if (d[j] == i && num[j] > 0) {
					bool cando = false;
					for (int k = w[j] + 1; k <= e[j]; k++) {
						if (wall[k] < s[j]) {
							list[0]++;
							list[list[0]] = k;
							delta[list[0]] = s[j];
							cando = true;
						}
					}
					if (cando) res++;
					d[j] += deltad[j];
					w[j] += deltap[j];
					e[j] += deltap[j];
					s[j] += deltas[j];
					num[j]--;
				}
			}
			for (int j = 1; j <= list[0]; j++) wall[list[j]] = max(wall[list[j]], delta[j]);
		}
		cout << "Case #" << l << ": " <<  res << "\n";
	}
	return 0;
}
	
