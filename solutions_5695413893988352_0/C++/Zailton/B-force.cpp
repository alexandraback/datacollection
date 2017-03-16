#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORR(i,b) FOR(i, 0, b)
#define sz(e) (int)e.size()
#define CLR(x,v) memset (x, v, sizeof x)
#define pb push_back
#define all(e) e.begin(), e.end()

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2000006;
const int INF = 1000000000;

int f[30], aux[30];

string s, t;

string preenche (string x, int v) {
	FORR (i, sz(x)) if (x[i]=='?') x[i] = v+'0';
	return x;
}

ll diferenca (string x, string y) {
	ll b = 1;
	ll r = 0;
	for (int i = sz(x)-1; i >=0; i--) {
		r += (x[i] - y[i]) * b;
		b *= 10;
	}
	return abs(r);
}


pair< ll, pair<string, string> > btrack (int p, string A, string B) {
	if (p==sz(A)) {
		return make_pair (diferenca(A, B), make_pair (A, B)); 
	}
	pair< ll, pair<string, string> > mp (1LL*INF*INF, make_pair("", ""));
	if (A[p]=='?') {
		FORR (i, 10) {
			A[p] = i+'0';
			if (B[p]=='?') {
				FORR (j, 10) {
					B[p] = j+'0';
					pair< ll, pair<string, string> > aux = btrack (p+1, A, B);
					if (aux<mp) mp = aux;
				}
				B[p] = '?';
			} else {
				pair< ll, pair<string, string> > aux = btrack (p+1, A, B);
				if (aux<mp) mp = aux;			
			}
		}
		A[p] = '?';
	} else {
		if (B[p]=='?') {
			FORR (j, 10) {
				B[p] = j+'0';
				pair< ll, pair<string, string> > aux = btrack (p+1, A, B);
				if (aux<mp) mp = aux;
			}
			B[p] = '?';
		} else {
			pair< ll, pair<string, string> > aux = btrack (p+1, A, B);
			if (aux<mp) mp = aux;			
		}
	}
	return mp;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int T;
	cin>>T;
	FORR (c, T) {
		cout << "Case #" << c+1 << ": ";
		string A, B; cin>>A>>B;
		
		
		pair< ll, pair<string, string> > tmp = btrack (0, A, B);
		cout << tmp.second.first << " " << tmp.second.second << endl;
		//cout << s1 << " " << t1 << endl;
		//cout << s2 << " " << t2 << endl;
		
	}
    
}
