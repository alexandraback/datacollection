#include <iostream>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdlib>

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define X first
#define Y second

using namespace std;

int a[1111][1111];
int b[1111][1111];
int q[1111];
int w[1111];
int n, m;
int sz;

void add(int x, int y){
	if (x < 0) return ;
	if (y < 0) return ;

	if (x >= n) return ;
	if (y >= m) return ;

	if (b[x][y]) return ;

	b[x][y] = 1;
	sz++;
	q[sz] = x;
	w[sz] = y;

}

int main(){
	freopen("inputC.in","r",stdin);
	freopen("outputC.out","w",stdout);
	int T;
	cin >> T;
	for (int TT = 1; TT <= T; TT++){
		printf("Case #%d: ", TT);
		int k;
		cin >> n >> m >> k;

		int t = 0;

		int ans = n * m;

		for (int mask = 0; mask < (1 << (n*m)); mask++){
			int c = 0;
			int t = 0;
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){					
					if (mask & (1 << t)) {
						a[i][j] = 1; 
						c++;
					} else a[i][j] = 0;
					t++;
				}
			}

			if (c >= ans) continue;

			sz = 0;

			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					b[i][j] = a[i][j];

					if ((i == 0) || (j == 0) || (i == n - 1) || (j == m - 1)){
						add(i, j);
					}
				}
			}

			int ii = 1;
			while (ii <= sz) {
				add(q[ii] - 1, w[ii]);
				add(q[ii] + 1, w[ii]);
				add(q[ii], w[ii] - 1);
				add(q[ii], w[ii] + 1);

				ii++;
			}

			
			if (n * m - sz >= k) ans = min(ans, c);
		}

		cout << ans << endl;

	}
    return 0;
}
