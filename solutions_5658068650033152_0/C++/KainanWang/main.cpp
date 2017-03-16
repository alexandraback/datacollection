#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int testCase;
	cin >> testCase;
	int caseNumber = 0;
	while (testCase--) {
		int n, m, k;
		cin >> n >> m >> k;
		int res = k;
		
		for (int mask = 0; mask < (1 << n * m); ++mask) {
			int tmp = 0;
			for (int i = 0; i < n * m; ++i)
				if (mask & (1 << i))  ++tmp;
			if (tmp >= res) continue;
			
			bool f[20], g[20];
			memset(f, 0, sizeof(f));
			memset(g, 0, sizeof(f));
			for (int i = 0; i < n; ++i)
					for (int j = 0; j < m; ++j)
						if ((mask & (1 << i * m + j)) == 0 && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) {
							g[i * m + j] = f[i * m + j] = true;
						}
			
			
			while (true) {
				bool update = false;
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < m; ++j) {
						if (f[i * m + j] == false) continue;
						for (int k = 0; k < 4; ++k) {
							int ti = i + di[k];
							int tj = j + dj[k];
							int p = ti * m + tj;
							j;
							if (f[p] || ti < 0 || ti >= n || tj < 0 || tj >= m || (mask & 1 << p)) continue;
							
							update = true;
							f[p] = true;
						}
					}	
				if (!update) break;			
			}
			
			int cnt = 0;
			for (int i = 0; i < n * m; ++i)
				if (!f[i]) ++cnt;	
						
			if (cnt >= k) {
				res = tmp;
			/*	if (tmp == 5) {
					for (int i =0 ; i < n; ++i) {
						for (int j = 0; j < m; ++j)
							cout << (int)f[i * m + j];
						cout << endl;
					}
					for (int i =0 ; i < n; ++i) {
						for (int j = 0; j < m; ++j)
							cout << (int)g[i * m + j];
						cout << endl;
					}
				}	*/
			}
		}
		printf("Case #%d: %d\n", ++caseNumber, res);
	}
} 
