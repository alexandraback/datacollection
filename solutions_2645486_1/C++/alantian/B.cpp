#include <iostream>
#include <cassert>

using namespace std;

typedef long long ll;

ll N;
ll E,R,V[10000+10];
ll M;
ll X[10000+10];
ll solve(){
	if ( R > E ) R = E;
	ll ans = 0;
	ll C = E;
	
	for( ll i = 0; i < N; i++ ){
		M = 0;
		X[M++] = i;
		for( ll j = i + 1; j < N; j++ )
			if ( V[j] > V[ X[M-1] ] )
				X[M++] = j;
		ll NC = 0;
		for( ll j = 1; j < M; j++ ){
			ll x = X[j];
			ll low = min(C+(x-i)*R,E)-(x-i)*R;
			NC = max(NC,low);
		}
		
		ans += (C-NC)*V[i];
		C = NC + R;
	}
	
	return ans;
}

int main(){
	int T; cin >> T;
	for(int t = 1; t <= T; t++ ){
		cin >> E >> R >> N;
		for( int i = 0; i < N; i++ )
			cin >> V[i];
		ll ans = solve();
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}