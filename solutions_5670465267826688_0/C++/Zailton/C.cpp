#include<bits/stdc++.h>
 
using namespace std;
 
// Typedefs
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
 
// Macros
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, a) FOR(i, 0, a)
#define sz(e) (int)e.size()
#define all(e) e.begin(), e.end()
#define pb(e) push_back(e)

const int MAXN = 1000006;

#define cc pair<char, char>


#define _one 1
#define _i 2
#define _j 3
#define _k 4

#define number pair<int, int>

number mult (number a, number b) {
	number x = number (a.first ^ b.first, 0);
	int v1 = a.second, v2 = b.second;
	if (v1==_one) {
		x.second = v2;
	} else if (v1==_i) {
		if (v2==_one) x.second = _i;
		else if (v2==_i) x.first ^= 1, x.second = _one;
		else if (v2==_j) x.second = _k;
		else x.first ^= 1, x.second = _j;
	} else if (v1==_j) {
		if (v2==_one) x.second = _j;
		else if (v2==_i) x.first ^= 1, x.second = _k;
		else if (v2==_j) x.first ^= 1, x.second = _one;
		else x.second = _i;
	} else {
		if (v2==_one) x.second = _k;
		else if (v2==_i) x.second = _j;
		else if (v2==_j) x.first ^= 1, x.second = _i;
		else x.first ^= 1, x.second = _one;
	}
	return x; 
}

number get_number (char c) {
	if (c=='i') return number (0, _i);
	if (c=='j') return number (0, _j);
	return number (0, _k);
}

number fast_exp (number x, ll e) {
	number r = number (0, _one);
	while (e) {
		if (e&1) r = mult (r, x);
		x = mult (x, x);
		e >>= 1;
	}
	return r;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int testes;
	cin>>testes;
	FORR (caso, testes) {
		ll L, X;
		cin>>L>>X;
		string s;
		cin>>s;
		
		number tot = number (0, _one);
		FORR (i, L) tot = mult (tot, get_number (s[i]));
		number et = fast_exp (tot, X);
		bool res = false;
		if (et.first==1 && et.second==_one) {
			number now = number (0, _one);
			ll ifound = X*L+1, kfound = -1;
			set<number> ms;
			FORR (i, X) {
				FORR (j, L) {
					now = mult (now, get_number (s[j]));
					if (now.first==0 && now.second==_i) {
						ifound = min (ifound, (L * (ll)i) + (j + 1));
					}
				}
				if (ms.find(now)!=ms.end()) break;
				ms.insert (now);
			}		
			//Lembrar de fazer na posicao oposta
			ms.clear();
			now = number (0, _one);
			for (int i = X-1; i>= 0; i--) {
				for (int j = L-1; j>= 0; j--) {
					now = mult (get_number (s[j]), now);
					if (now.first==0 && now.second==_k) {
						kfound = max (kfound, (L * (ll)i) + (j + 1));
					}
				}
				if (ms.find(now)!=ms.end()) break;
				ms.insert (now);
			}
			
			if (kfound-ifound>1) res = true;
		}	
		cout << "Case #" << caso + 1 << ": " << (res?"YES":"NO") << endl;
	}
	
}
