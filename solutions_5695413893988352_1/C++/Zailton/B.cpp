#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORR(i,b) FOR(i, 0, b)
#define sz(e) (int)e.size()
#define CLR(x,v) memset (x, v, sizeof x)
#define pb push_back
#define all(e) e.begin(), e.end()

typedef unsigned long long ll;
typedef pair<int, int> ii;

const int MAXN = 2000006;
const int INF = 1000000000;

string s, t;

string preenche (string x, int v) {
	FORR (i, sz(x)) if (x[i]=='?') x[i] = v+'0';
	return x;
}

vector< pair <string, string> > solutions;

void completa () {
	int pref = 0; //0: igual, 1: menor
	int n = sz(s);
	//cout << s << " " << t << endl;
	FORR (i, n) {
		//cout << i << "-> " << pref << endl;
		if (pref==0) {
			string saux = preenche (s.substr(i+1, n-i-1), 0), taux = preenche (t.substr(i+1, n-i-1), 9);
			if (s[i]=='?' && t[i]!='?') {
				if (saux.compare (taux) <= 0) {
					if (t[i]!='0') {
						s[i] = t[i]-1;
						solutions.pb (make_pair (preenche (s, 9), preenche (t, 0)));
					}

					s[i] = t[i];
				} else {
					pref = 1;
					s[i] = t[i]-1;
				}
			} else if (s[i]!='?' && t[i]=='?') {
				if (saux.compare (taux) <= 0) {
					if (s[i]!='9') {
						t[i] = s[i]+1;
						solutions.pb (make_pair (preenche (s, 9), preenche (t, 0)));
					}
					
					t[i] = s[i];
				} else {
					pref = 1;
					t[i] = s[i]+1;
				}
			} else if (s[i]=='?' && t[i]=='?') {
				if (saux.compare (taux) <= 0) {
					s[i] = '0', t[i] = '1';
					solutions.pb (make_pair (preenche (s, 9), preenche (t, 0)));
					
					s[i] = '0', t[i] = '0';
				} else {
					pref = 1;
					s[i] = '0', t[i] = '1';
				}
			} else {
				if (s[i]<t[i]) pref = 1;
			}
		} else {
			if (s[i]=='?') s[i] = '9';
			if (t[i]=='?') t[i] = '0';
		}
		//cout << s << " " << t << endl;
	}
	solutions.pb (make_pair(s,t));
	//cout << endl;
}

ll diferenca (string x, string y) {
	if (x.compare (y) < 0) swap(x, y);
	ll b = 1;
	ll r = 0;
	for (int i = sz(x)-1; i >=0; i--) {
		r += (x[i] - y[i]) * b;
		b *= 10;
	}
	return r;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int T;
	cin>>T;
	FORR (c, T) {
		cout << "Case #" << c+1 << ": ";
		string A, B; cin>>A>>B;
		solutions.clear();
		
		s = A, t = B;
		string s1 = "" , s2 = "", t1 = "", t2 = "";
		vector< pair<string, string> > melhores;
		if (preenche (s, 0).compare (preenche(t, 9)) <= 0) {
			completa ();
			melhores = solutions;
		}
		s = B, t = A;
		if (preenche (s, 0).compare (preenche(t, 9)) <= 0) {
			completa ();
			FORR (i, sz(solutions)) melhores.pb (make_pair(solutions[i].second, solutions[i].first));
		}
		
		/*FORR (i, sz(melhores)) {
			cout << melhores[i].first << " " << melhores[i].second << endl;
		}*/
		
		int k = 0;
		FOR (i, 1, sz(melhores)) {
			string a0 = melhores[i].first, a1 =melhores[i].second;
			string b0 = melhores[k].first, b1 =melhores[k].second;
			ll D1 = diferenca(a0, a1), D2 = diferenca (b0, b1);
			if (D1 < D2) {
				 k = i;
			} else if (D1>D2) {
				continue;
			} else {
				if (a0.compare(b0)<0) {
					k = i;
				} else if (b0.compare(a0) <0) {
					continue;
				} else {
					if (a1.compare (b1)<=0) {
						k = i;
					} else {
						continue;	
					}
				}
			}
		}		
		cout << melhores[k].first << " " << melhores[k].second << endl;
		//cout << s1 << " " << t1 << endl;
		//cout << s2 << " " << t2 << endl;
		
	}
    
}
