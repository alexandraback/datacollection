#include <iostream>
using namespace std;

typedef long long ll;

ll d[100];
ll h[100];
ll m[100];

void solve(){
	ll n; cin >> n;
	for(int i=0; i<n; i++) cin >> d[i] >> h[i] >> m[i];
	if(n == 1 && h[0] == 1){cout << 0 << endl;}
	
	ll d1, m1, d2, m2;
	if(n == 1){
		d1 = d2 = d[0];
		m1 = m[0];
		m2 = m[0]+1;
	}else{
		d1 = d[0]; m1 = m[0];
		d2 = d[1]; m2 = m[1];
	}
	
	int ans = 0;
	if((360-d1)*m1 >= (360-d2)*m2 + m2*360) ans++;
	if((360-d2)*m2 >= (360-d1)*m1 + m1*360) ans++;
	
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	
	int t; cin >> t;
	for(int i=1; i<=t; i++){
		cout << "Case #" << i << ": ";
		cout.flush();
		solve();
	}
	
	return 0;
}
