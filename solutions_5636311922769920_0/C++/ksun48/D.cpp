#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

main() {
	FILE *fin = freopen("D-small-attempt0.in", "r", stdin);
	FILE *fout = freopen("D-small-attempt0.out", "w", stdout);
	assert( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ":";

		LL k, c, s;
		cin >> k >> c >> s;
		LL d = (k-1)/c+1;
		if(d > s){
			cout << " IMPOSSIBLE" << endl;
			continue;
		}
		for(int i = 0; i < d; i++){
			LL tile = 0;
			for(int j = 0; j < c; j++){
				LL r = (i*c+j)%k;
				tile *= k;
				tile += r;
			}
			cout << " " << tile+1;
		}
		cout << endl;

	}
	exit(0);
}