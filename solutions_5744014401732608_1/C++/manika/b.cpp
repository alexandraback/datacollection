#include<bits/stdc++.h>
using namespace std;

// written by: MANIKA AGARWAL
// TEMPLATE USED: FROM CODEFORCES
typedef long long ll ;

#define endl '\n'
#define  MP make_pair
#define PB push_back
#define F first
#define S second
#define fileio freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
#define boost  ios_base::sync_with_stdio(false);

bool mat[55][55];
ll ans[55] , v[55];
int main(){
	fileio;
	ans[0] = 1;
	for(int i = 1; i <= 53; i++)
		ans[i] = 2 * ans[i - 1];
		
	int i, j, t, tt;
	ll b, m;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		for(i = 1; i <= 50; i++)
			for(j = 1; j <= 50; j++)
				mat[i][j] = 0;
				
		cin >> b >> m;
		if( ans[b - 2] < m) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		else cout << "POSSIBLE\n";
		v[b] = 1;
		for(i = b - 1;i;i--) {
			v[i] = 0;
			for(j = i  + 1; j <= b; j++)
				if(v[i] + v[j] <= m) {
					v[i] += v[j];
					mat[i][j] = 1;
				}
		}
		for(i = 1; i <= b; i++) {
			for(j = 1; j <= b; j++)
				cout << mat[i][j];
			cout << endl;
		}
		
	}

	return 0 ;
}



