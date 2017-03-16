#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

main() {
	FILE *fin = freopen("B-small-attempt0.in", "r", stdin);
	FILE *fout = freopen("B-small-attempt0.out", "w", stdout);
	assert( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ":";
		int n;
		cin >> n;
		set<int> c;
		for(int i = 0; i < n*(2*n-1); i++){
			int a;
			cin >> a;
			if(c.find(a) != c.end()){
				c.erase(a);
			} else {
				c.insert(a);
			}
		}
		for(set<int>::iterator it = c.begin(); it != c.end(); it++){
			cout << " " << *it;
		}
		cout << endl;
	}
	exit(0);
}