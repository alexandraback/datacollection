#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <ll> VI;
typedef vector <VI> VVI;
typedef vector <VVI> VVVI;
typedef vector <ld> VD;
typedef vector <VD> VVD;
typedef vector <string> VS;
typedef vector <char> VC;
typedef vector <VC> VVC;
typedef pair <ll, ll> PII;
typedef pair <ll, PII> PIII;
typedef pair <ld, ld> PD;
typedef map <ll, ll> MII;
typedef map <string, ll> MSI;
typedef queue <ll> QI;
typedef queue <PII> QPI;
typedef set <ll> SI;
typedef SI::iterator IT;

#define F first
#define S second
#define pb push_back

ll pot(ll a){
	if (a == 0) return 1;
	ll x = pot(a/2);
	if (a%2 == 1) return 2*x*x;
	return x*x;
}

int main(){
	ll T;
	cin >> T;
	for (ll t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		ll B, M;
		cin >> B >> M;
		if (pot(B-2) < M) cout << "IMPOSSIBLE" << endl;
		else{
			VVI X = VVI(B, VI(B, 0));
			cout << "POSSIBLE" << endl;
			for (ll i = B-1; i > 0; --i){
				for (ll j = i+1; j <B; ++j) X[i][j] = 1;
			}
			ll h = 2;
			if (M > 0){
				--M;
				X[0][B-1] = 1;
			}
			while (M > 0){
				X[0][B-h] = M%2;
				M/= 2;
				++h;
			}
			for (ll i = 0; i < B; ++i){
				for (ll j = 0; j < B; ++j) cout << X[i][j];
				cout << endl;
			}
		}
	}
    
}
