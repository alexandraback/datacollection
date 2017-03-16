#include <bits/stdc++.h>
#define ll long long
#define int ll
#define mod 1000000007
using namespace std;

main(){
	ios::sync_with_stdio(0);
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, c = 1, n, m;
	int f[2510];
	cin >> t;
	while(t--) {
		memset(f, 0,sizeof(f));
		cin >> n;
		int lim = 2*n-1;
		for(int i = 0; i < lim; i++) {
			for(int j = 0; j < n; j++) {
				cin >> m;
				f[m]++;
			}
		}
		cout << "Case #" << c++ << ":";
		for(int i = 1; i <= 2500; i++)
			if(f[i]%2 == 1)
				cout << " " << i;
		cout << endl; 
	}
}

