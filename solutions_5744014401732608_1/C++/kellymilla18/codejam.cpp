#include <bits/stdc++.h>
#define ll long long
#define int ll
#define mod 1000000007
using namespace std;

int ans[55][55];
int mx[55];

main(){
	ios::sync_with_stdio(0);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	
	int t, b, m, c = 1;
	cin >> t;
	
	
	
	mx[1] = 1;
	mx[2] = 1;
	
	for(int i = 3; i <= 54; i++)
		mx[i] = mx[i-1] * 2;
	
	while(t--) {
		cin >> b >> m;
		cout << "Case #" << c++ << ": ";
		if(mx[b] < m)
			cout << "IMPOSSIBLE\n";
		else {
			cout << "POSSIBLE\n";
			
			memset(ans, 0, sizeof(ans));
			// ------- start of computation --------//
			int it;
			for(it = 2; ; it++) {
				if(mx[it] > m) {
					it--;
					break;
				}
			}
			it--;
			
			for(int i = 1; i <= it; i++) {
				for(int j = i-1; j >= 1; j--)
					ans[j][i] = 1;
				ans[i][b] = 1;
			}
			m -= mx[it+1];
			
			if(m != 0) {
				for(int i = 0; i < 52; i++) {
					if((m&(1LL<<i)))
						ans[i+2][it+1] = 1;
				}
				ans[it+1][b] = 1;
			}
			// ------- end of omputation --------//
			
			for(int i = 1; i <= b; i++) {
				for(int j = 1; j <= b; j++) 
					cout << ans[i][j];
				cout << endl;
			}
		}
	}
}

