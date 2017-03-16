#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int t;
	cin >> t;
	for (int l = 1; l <= t; l++) {
		int n;
		cin >> n;
		int hei[10000], w[1000], e[1000], s[1000], d[1000], num[1000], deltap[1000], deltas[1000], deltad[1000];
		memset(hei, 0, sizeof(hei));
		for (int i = 0; i < n; i++) {
			cin >> d[i] >> num[i] >> w[i] >> e[i] >> s[i] >> deltad[i] >> deltap[i] >> deltas[i];
			w[i] += 1000;
			e[i] += 1000;
		}
		int res = 0;
		for (int i = 0; i < 700000; i++) {
			int list[100000], ssss[100000];
			list[0] = 0;
			for (int j = 0; j < n; j++) {
				if (d[j] == i && num[j] > 0) {
					bool kkkk = false;
					for (int k = w[j] + 1; k <= e[j]; k++) {
						if (hei[k] < s[j]) {
							list[0]++;
							list[list[0]] = k;
							ssss[list[0]] = s[j];
							kkkk = true;
						}
					}
					if (kkkk) res++;
					d[j] += deltad[j];
					w[j] += deltap[j];
					e[j] += deltap[j];
					s[j] += deltas[j];
					num[j]--;
				}
			}
			for (int j = 1; j <= list[0]; j++) hei[list[j]] = max(hei[list[j]], ssss[j]);
		}
		cout << "Case #" << l << ": " <<  res << "\n";
	}
	return 0;
}
 
			
					
						
						 
		
	
