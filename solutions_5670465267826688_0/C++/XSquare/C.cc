#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

ll m[][4] = {{1, 2, 3, 4}, {2, -1, 4, -3}, {3, -4, -1, 2}, {4, 3, -2, -1}};

ll nx(char x){
	if (x == 'i') return 2;
	else if (x == 'j') return 3;
	return 4;
}

ll mult (ll a, ll b){
	ll sig1, sig2;
	if (a > 0) sig1 = 1;
	else{
		sig1 = -1;
		a = -a;
	}
	if (b > 0) sig2 = 1;
	else {
		sig2 = -1;
		b = -b;
	}
	return sig1*sig2*m[a-1][b-1];
}

const ll result = -1;

int main(){
	ll T;
	cin >> T;
	for (ll t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		ll L, X;
		cin >> L >> X;
		string s;
		cin >> s;
		string S;
		ll ff = 4;
		ll N = min(ff, X);
		ll prod = 1;
		for (ll i = 0; i < N; ++i) S += s;
		for (ll i = 0; i < L; ++i){
			prod = mult(prod, nx(s[i]));
		}
		//cout << prod << endl;
		ll superprod = 1;
		for (ll i = 0; i < X%4; ++i) superprod = mult(superprod, prod);
		if (superprod != result) cout << "NO" << endl;
		else{
			ll M = 1;
			ll cont1 = 0, cont2 = 0;
			for (ll i = 0; i < (ll) S.size(); ++i){
				++cont1;
				M = mult(M, nx(S[i]));
				if (M == 2) break;
			}
			M = 1;
			for (ll i = S.size() -1; i >= 0; --i){
				++cont2;
				M = mult(nx(S[i]), M);
				if (M == 4) break;
			}
			if (cont1 < S.size() and cont2 < S.size() and cont1 + cont2 < L*X) cout << "YES" << endl;
			else cout << "NO" << endl;
			
		}
	} 
		
		
}
