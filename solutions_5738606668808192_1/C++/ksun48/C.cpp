#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

main() {
	FILE *fin = freopen("C-large.in", "r", stdin);
	FILE *fout = freopen("C-large.out", "w", stdout);
	assert( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		int n, j;
		cin >> n >> j;
		int k = n/2;
		cout << endl;
		for(int i = 0; i < j; i++){
			cout << "11";
			int r = i;
			for(int d = 0; d < k-2; d++){
				if(r % 2){
					cout << "11";
				} else {
					cout << "00";
				}
				r /= 2;
			}
			cout << "11";
			for(int c = 2; c <= 10; c++){
				cout << " " << c+1;
			}
			cout << endl;
		}
	}
	exit(0);
}