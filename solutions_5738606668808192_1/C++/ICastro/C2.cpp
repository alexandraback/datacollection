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

int main(void) {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": " << endl;
		int n, j;
		cin >> n >> j;

		string s;
		for (int i = 0; i < n-2; ++i) s.pb('0');
		s.pb('1');
		s.pb('1');
		//ll v = (1<<(n-1)) + 1;
		ll v = 1;
		for (int i = 0; i < j; ++i){
			ll v2 = v;
			int j = 0;
			while(v2 > 0) {
				if (v2 % 2 == 1){
					s[j] = '1';
					s[j + 1] = '1';
				} else {
					s[j] = '0';
					s[j + 1] = '0';
				}
				v2 /= 2;
				j += 2;
			}
			cout << s << " 3 4 5 6 7 8 9 10 11" << endl;
			v += 2;
		}

		//ll v = powDI(10, n-1) + 1;
		/*ll v = (1<<(n-1)) + 1;
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
		}*/
	}
	//cout << "maxprime " << maxprime << endl;
	return 0;
}
/*
2 	1
4 	1
6 	2
8 	4
10 	8
12 	16
14 	32
16 	64
18 	128
20 	256
22 	512
24 	1024
26 	2048
28 	4096
30 	8192
32 	16384
*/