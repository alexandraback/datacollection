#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

main() {
	FILE *fin = freopen("C-small-attempt0.in", "r", stdin);
	FILE *fout = freopen("C-small-attempt0.out", "w", stdout);
	assert( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		int a[n];
		int b[n];
		int c[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			a[i]--;
			c[i] = 0;
			b[i] = 0;
		}
		int ans2 = 0;
		int maxc = 0;
		for(int i = 0; i < n; i++){
			b[i] = 0;
			if(a[a[i]] == i) b[i] = 1;
		}
		for(int i = 0; i < n; i++){
			int r = i;
			int ns = 1;
			for(int d = 0; d < 5000; d++){
				if(b[r] == 1){
					c[r] = max(c[r], ns);
					break;
				}
				r = a[r];
				ns++;
			}
			ns = 0;
			r = i;
			for(int d = 0; d < 5000; d++){
				r = a[r];
				ns++;
				if(r == i){
					maxc = max(maxc,ns);
					break;
				}
			}
		}
		for(int i = 0; i < n; i++){
			ans2 += c[i];
		}
		cout << max(maxc,ans2) << endl;
	}
	exit(0);
}