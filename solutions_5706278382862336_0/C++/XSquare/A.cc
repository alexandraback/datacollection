#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector <ll> VI;
typedef vector <VI> VVI;
typedef vector <double> VD;
typedef vector <VD>  VVD;
typedef vector <bool> VB;
typedef vector <VB> VVB;

ll mcd (ll a, ll b){
	if (b == 0) return a;
	return mcd (b, a%b);
}

int main(){
	ll T;
	cin >> T;
	for (int i = 0; i < T; ++i){
		ll P, Q;
		char c;
		cin >> P >> c >> Q;
		ll d = mcd(P,Q);
		P/= d;
		Q /= d;
		ll s = 1;
		ll g = 0;
		while (s < Q){
			s*= 2;
			++g;
		}
		cout << "Case #" << i+1 << ": ";
		if (s != Q) cout << "impossible" << endl;
		else{
			while (P >= 2){
				P /= 2;
				--g;
			}
			cout << g << endl;
		}
		
	}
		
}
