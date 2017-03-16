#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

void solve(){
	ll k, c, s;
	cin >> k >> c >> s;
	if(c*s < k) {cout << "IMPOSSIBLE" << endl; return;}
	
	ll power = 1; for(int i=0; i<c; i++) power *= k; //power = k^c = total number of tiles
	
	ll a = k;
	while(a > 0){
		ll num = 1;
		ll pot = power / k;
		while(pot > 0 && a > 0){
			a--;
			num += a*pot;
			pot /= k;
		}
		cout << num << ' ';
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	for(int i=1; i<=t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
