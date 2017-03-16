#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

int digs[5], cnt, val[8];
bool obt[200];

int main() {
	int trash;
	cin >> trash;

	int r, n, m, k;
	cin >> r >> n >> m >> k;
	printf("Case #1:\n");
	for (int i = 0; i < r; i++) {
		for (int q = 0; q < k; q++) 
			cin >> val[q];		

		for (int j = 0; j < int(1e3); j++) {
			memset(obt, 0, sizeof(obt));
			int num = j;
			bool ok = 1;
			int cnt = 0;
			for (int q = 0; q < n; q++) {
				int dig = num % 10;
				if (dig < 2 || dig > 5) 
					ok = 0;					
				digs[cnt++] = dig;
				num /= 10;
			}
			if (!ok) continue;
			
			obt[1] = 1;
			for (int q = 0; q < 3; q++) {
				obt[digs[q]] = 1;
				obt[ digs[q] * digs[(q + 1) % 3] ] = 1;
			}
			obt[digs[0] * digs[1] * digs[2]] = 1;

			for (int q = 0; q < k; q++) {
				if (!obt[val[q]]) {
					ok = 0;
					break;
				}
			}

			if (ok) {
				printf("%d%d%d\n", digs[0], digs[1], digs[2]);
				break;				
			}

			if (j == 999) {
				cout << 222 << endl;
			}
		}
	}

	return 0;
}
