#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ulint unsigned long long int
#define lint long long int
#define ll long long
#define INF numeric_limits<int>::max()
#define LINF numeric_limits<ll>::max()
#define mp make_pair
#define mt make_tuple
#define getH(T) get<0>(T)
#define getD(T) get<1>(T)
#define getC(T) get<2>(T)
#define pb push_back
#define st first
#define nd second
#define contOnes __builtin_popcountl
#define powDI __builtin_powi
#define sz(v) int(v.size())
//cuidado parametro duplicados
#define all(X) (X).begin(), (X).end()
#define logLow(X) (X <= 0 ? 0 : 31 - __builtin_clz(X))
#define logUpper(X) (X <= 1 ? 0 : 32 - __builtin_clz(X-1))
#define pow2(X) ((X)*(X))

//const double PI = atan(1.0)*4;
const double PI = 2*acos(0.0);

ll minFactor(ll n) {
	if (n%2 == 0) return 2;
	for (ll i = 3; i*i <= n; i += 2){
		if (n%i == 0) return i;
	}
	return n;
}

bool isPrime(ll n) {
	return minFactor(n) == n;
}

int main(void) {
	ll T;
	cin >> T;
	for (ll t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": " << endl;
		ll n, j;
		cin >> n >> j;
		//ll v = powDI(10, n-1) + 1;
		ll v = (1<<(n-1)) + 1;
		ll contT = 0;
		while (true){
			bool prime = false;
			ll aux;
			for (ll i = 2; i <= 10; ++i){
				ll v2 = v;
				aux = 0;
				ll pi = 1;
				while (v2 > 0){
					if (v2 % 2 == 1){
						aux += pi;
					}
					v2 /= 2;
					pi *= i;
				}
				if (isPrime(aux)){
					prime = true;
					break;
				}
				//cout << aux << endl;
			}
			if (!prime) {
				cout << aux;
				for (ll i = 2; i <= 10; ++i){
					ll v2 = v;
					aux = 0;
					ll pi = 1;
					while (v2 > 0){
						if (v2 % 2 == 1){
							aux += pi;
						}
						v2 /= 2;
						pi *= i;
					}
					cout << " " << minFactor(aux);
				}
				cout << endl;
				contT++;
				if (contT == j) break;
			}
			v += 2;
		}
	}
	return 0;
}
