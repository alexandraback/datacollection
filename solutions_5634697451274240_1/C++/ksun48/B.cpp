#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

main() {
	FILE *fin = freopen("B-large.in", "r", stdin);
	FILE *fout = freopen("B-large.out", "w", stdout);
	assert( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		string r;
		cin >> r;
		r += '+';
		int d = 0;
		for(int i = 0; i < r.size()-1; i++){
			if(r[i] != r[i+1]) d++;
		}
		cout << d << endl;

	}
	exit(0);
}