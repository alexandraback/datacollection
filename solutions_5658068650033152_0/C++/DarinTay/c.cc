#include <iostream>

#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

/*

.......
.xxxxx.


*/
int main() {
	int T;
	cin>>T;
	for (int t=1;t<=T;++t) {
		int n, m, k;
		cin>>n>>m>>k;
		int ans = k;
		for (int r=3;r<=n;++r) for (int c=3;c<=m;c++) {
			int st = (c-2)*2 + (r-2)*2;
			int cov = st + (c-2)*(r-2);	
			int hl = m-c;
			for (int rf = r-2; rf > 2; rf -= 2) {
				if (hl) {
					cov += rf-2;	
					--hl;
				}
				if (hl) {
					cov += rf-2;	
					--hl;
				}
			}

			int wl = n-r;
			for (int cf = c-2; cf > 2; cf -= 2) {
				if (wl) {
					cov += cf-2;	
					--wl;
				}
				if (wl) {
					cov += cf-2;	
					--wl;
				}
			}

			if (cov < k) st += k - cov;
			ans = min(ans, st);
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
