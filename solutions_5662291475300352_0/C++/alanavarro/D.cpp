#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define se second
#define fi first

using namespace std;
typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
const int MAX = 1e6+6;

vector < pii > all;

int solve( int v ){
	double x;
	int ret = 0;
	for( int i = 0 ; i < all.size();i++ ){
		x = all[i].fi * 1.0;
		x += (v * 1.0) * ( 360.0 / (all[i].se * 1.0) );
		if( x-360.0 < 1e-8 ) ret ++;
	}
	return ret;
}

int main(){
	
	freopen("a.in","r", stdin);
	freopen("a.out","w", stdout);
	
	int t;
	cin >> t;
	int n, ntc = 1;
	int a,b , c;
	while( t-- ){
		cin >> n;
		all.clear();
		for( int i = 0 ; i < n ;i++ ){
			cin >> a >> b >> c;
			for( int j = 0; j < b ;j++ ){
				all.pb( mp(a,c+i) );
			}
		}
		int ans = 1e9+9;
		for( int i = 0 ; i < all.size();i++ ){
			ans = min(ans, solve(all[i].se));
		}
		printf("Case #%d: %d\n", ntc, ans );
		ntc++;
	}


	return 0;
}
