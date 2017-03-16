#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll lolng long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int mod = 1000000007;
const int maxn = 111;

int n;
char s[maxn][maxn];
bool inside[maxn];
int beg[maxn], end[maxn], cnt[maxn];
bool used[maxn];
int g[maxn];
int fact[maxn];

void test() {
	//printf("\n");
	scanf("%d", &n);
	FOR(i,n) scanf("%s", s[i]);
	// po 1 literce z kazdego
	FOR(i,n) {
		int k = 1;
		for (int j = 1; s[i][j]; j++) if (s[i][j] != s[i][j-1]) s[i][k++] = s[i][j];
		s[i][k] = 0;
	}
	//FOR(i,n) printf("%s\n", s[i]);
	// wywal jesli cos jest zablokowane i jest cos jeszcze innego
	FOR(i,26) inside[i] = false;
	FOR(i,n) {
		int L, low = -1, high = -1;
		for (L = 0; s[i][L]; L++) ;
		for (int j = 1; j < L; j++) if (s[i][j] != s[i][j-1]) {
			high = j;
			if (low == -1) low = j;
		}
		for (int j = low; j < high; j++) {
			if (inside[s[i][j]-'a']) {
				printf("0\n");
				return;
			}
			inside[s[i][j]-'a'] = true;
			FOR(k,n) if (k != i) {
				for (int l = 0; s[k][l]; l++) if (s[k][l] == s[i][j]) {
					printf("0\n");
					return;
				}
			}
		}
	}
	// zrob 1l lub 2l
	FOR(i,n) {
		int L;
		for (L = 0; s[i][L]; L++) ;
		if (L > 1) {
			s[i][1] = s[i][L-1];
			s[i][L] = 0;
		}
	}
	// zostaw po 1 z kazdego i wskaz konce
	FOR(i,26) {
		cnt[i] = 0;
		beg[i] = end[i] = -1;
	}
	FOR(i,n) used[i] = false;
	FOR(i,n) {
		if (s[i][1]) {
			if (beg[s[i][1]-'a'] != -1 || end[s[i][0]-'a'] != -1) {
				printf("0\n");
				return;
			}
			beg[s[i][1]-'a'] = i;
			end[s[i][0]-'a'] = i;
		} else {
			cnt[s[i][0]-'a']++;
			used[i] = true;
		}
	}
	// wymnoz luzne konce i zrob graf
	int mult = 1, comp = 0;
	FOR(i,n) g[i] = -1;
	FOR(i,26) {
		mult = 1LL * mult * fact[cnt[i]] % mod;
		if (beg[i] != -1 || end[i] != -1) {
			if (beg[i] != -1 && end[i] != -1) g[beg[i]] = end[i];
		} else if (cnt[i] > 0) {
			comp++;
		}
	}
	//printf("%d %d\n", mult, comp);
	//FOR(i,n) printf("%d ", used[i]); printf("\n");
	//FOR(i,4) printf("%d ", beg[i]); printf("\n");
	// sprawdz graf
	FOR(i,n) if (!used[i]) if (beg[s[i][0]-'a'] == -1) {
		comp++;
		used[i] = true;
		int u = g[i];
		while (u != -1) {
			used[u] = true;
			u = g[u];
			if (u == i) {
				printf("0\n");
				return;
			}
		}
	}
	FOR(i,n) if (!used[i]) {
		printf("0\n");
		return;
	}
	mult = 1LL * mult * fact[comp] % mod;
	printf("%d\n", mult);
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < maxn; i++) {
		fact[i] = 1LL * fact[i-1] * i % mod;
	}
	int tt;
	scanf("%d", &tt);
	for (int te = 1; te <= tt; te++) {
		printf("Case #%d: ", te);
		test();
	}
}
