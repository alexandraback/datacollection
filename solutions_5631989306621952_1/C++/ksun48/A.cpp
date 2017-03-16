#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

main() {
	FILE *fin = freopen("A-large.in", "r", stdin);
	FILE *fout = freopen("A-large.out", "w", stdout);
	assert( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		string r;
		cin >> r;
		char c = 'A';
		string s2;
		string s1;
		for(int i = 0; i < r.size(); i++){
			if(r[i] >= c){
				s2 += r[i];
				c = r[i];
			} else {
				s1 += r[i];
			}
		}
		for(int i = s2.size()-1; i >= 0; i--){
			cout << s2[i];
		}
		cout << s1 << endl;
	}
	exit(0);
}