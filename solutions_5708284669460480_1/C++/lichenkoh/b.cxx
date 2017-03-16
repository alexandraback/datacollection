#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;

ll *fail;
ll **memo;
char *p;
// Walk the KMP DFA from state j with letter x
ll dfa(ll j, char x) {
	ll oldj = j;
	ll z = x - 'A';
	if (memo[j][z] != -1) {
		return memo[j][z];
	}
	while (j > 0 && x != p[j]) {
		j = fail[j];
	}
	j++;
	memo[oldj][z] = j;
	return j;
}

// Build KMP failure table
void buildfail(ll m)
{
	ll j = 0;
	for (ll i = 1; i <= m; i++) {
		fail[i] = j;
		while (j > 0 && p[i] != p[j]) {
			j = fail[j];
		}
		j++;
	}
	fail[m+1] = j;
}


int main() {
	cout.precision(300);
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	const ll LIM = 200;
	ll **g = new ll*[LIM+2];
	for (ll i = 0; i < LIM+2; i++) {
		g[i] = new ll[LIM+2];
		for (ll j = 0; j < LIM+2; j++) {
			g[i][j] = 0;
		}
	}

	long double **f = new long double*[LIM+2];
	for (ll i = 0; i < LIM+2; i++) {
		f[i] = new long double[LIM+2];
		for (ll j = 0; j < LIM+2; j++) {
			f[i][j] = 0;
		}
	}


	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll numkeys,l,s;
		cin >> numkeys; cin >> l; cin >> s;
		string key; string target;
		cin >> key; cin >> target;
		string pz = target;
		ll n = s; ll m = pz.length();
		memo = new ll*[m+2];
		for (ll i = 0; i <= m+1; i++) {
			memo[i] = new ll[26];
			for (ll j = 0; j < 26; j++) {
				memo[i][j] = -1;
			}
		}
		fail = new ll[m+2];
		for (ll i = 0; i <= m+1; i++) fail[i] = 0;
		p = new char[m+1];
		p[0] = '$';
		for (ll i = 0; i < m; i++) {p[i+1] = pz[i];}
		buildfail(m);

		for (ll i = 0; i < s+2; i++) {
			for (ll j = 0; j < m+2; j++) {
				g[i][j] = 0;
			}
		}

		g[1][1] = 1;
		ll maxg = 0;
		for (ll t = 1; t <= s; t++) {
			for (ll k = 1; k <= m+1; k++) {
				if (g[t][k] > 0) {
					for (ll i = 0; i < numkeys; i++) {
						//ll nextk = k;
						ll nextk = dfa(k,key[i]);
						if (nextk==m+1) {
							g[(t+1)][nextk] = max(g[(t+1)][nextk], g[t][k]+1);
							//cout << t << ":" << nextk << ":" << g[(t+1)][nextk] << endl;
						}
						else {
							g[(t+1)][nextk] = max(g[(t+1)][nextk], g[t][k]);
						}
						maxg = max(maxg, g[(t+1)][nextk]);
					}
				}
			}
		}
		maxg--;
		
		long double unif = ((long double)1.0)/numkeys;
		for (ll i = 0; i < s+2; i++) {
			for (ll j = 0; j < m+2; j++) {
				f[i][j] = 0;
			}
		}
		f[1][1] = 1;
		long double tosub = 0;
		for (ll t = 1; t <= s; t++) {
			for (ll k = 1; k <= m+1; k++) {
				for (ll i = 0; i < numkeys; i++) {
					ll nextk = dfa(k,key[i]);
					if (nextk == m+1) {
						tosub += (f[t][k]) * unif;
					}
					f[(t+1)][nextk] += (f[t][k]) * unif;
				}
			}
		}
		long double ans = maxg - tosub;
		cout << "Case #" << casenum << ": " << ans << endl;
		
	}
}
