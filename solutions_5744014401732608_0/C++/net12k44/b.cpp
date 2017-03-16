#include <bits/stdc++.h>

using namespace std;

int n;
long long m;
long long c[55];
int a[55][55];

void solve(){
	cin >> n >> m;
	c[1] = 1; c[2] = 1;
	for(int i = 3; i <= n; ++i)
		c[i] = c[i-1] << 1;
	
	if (c[n] < m){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	else cout << "POSSIBLE" << endl;
	
	memset(a, 0, sizeof a);
	for(int i = 2; i <= n; ++i)
		if (c[i] <= m)
			for(int j = 1; j<i; ++j)
				a[j][i] = 1;
		
	for(int i = 2; i < n; ++i)
		if ( (1LL<<(i-2)) & m) a[i][n] = 1;
		
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j) cout << a[i][j];
		cout << endl;
	}
	
}

int main(){
	int test; cin >> test;
	for(int t = 1; t<= test; ++t){
		printf("Case #%d: ", t);
		solve();
	}
	
}