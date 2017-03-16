#include<iostream>
using namespace std;
typedef long long ll;
ll n, tt;
ll s[100], deg[100];
ll t[100];

int main(){
	ios::sync_with_stdio(0);
	cin >> tt;
	for (ll ti=0 ; ti<tt ; ti++){
		n = 0;
		ll tg;
		cin >> tg;
		for (ll i=0 ; i<tg ; i++){
			ll x, y, z;
			cin >> x >> y >> z;
			for (ll j=0 ; j<y ; j++){
				deg[n] = x;
				s[n] = z + j;
				n++;
			}
		}
		ll J = n-1;
		for (ll i=0 ; i<n ; i++)
			t[i] = (360-deg[i]) * s[i];
		
		for (ll i=0 ; i<n ; i++)
			for (ll j=i-1 ; j>=0 ; j--)
				if (t[j] > t[j+1]){
					swap(t[j], t[j+1]);
					swap(s[j], s[j+1]);
					swap(deg[j], deg[j+1]);
				}	
		
		for (ll i=0 ; i<n ; i++){
			ll T = t[i];
			ll JJ = n-1-i;
			for (ll j=0 ; j<i ; j++){
				if (j==i) continue;
				ll z = t[j] + s[j] * 360;
				while(JJ<20 && z<=T){
					JJ++;
					z += s[j] * 360;
				}
			}	
			if (JJ < J) J = JJ;
		}
		cout << "Case #" << ti+1 << ": " << J << endl;
	}
}
