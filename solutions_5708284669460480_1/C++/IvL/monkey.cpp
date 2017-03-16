#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) for (int _rep = 0, _for = (n); _rep < _for; ++_rep)
#define pb push_back
#define x first
#define y second
#define ll long long
#define pii pair < int, int >
#define all(x) (x).begin(), (x).end()

using namespace std;

int k, l, s;
char mon[105], rijec[105];
int kmp[105];

double memo[105][105];
bool bio[105][105];
double dp(int pref, int left){
	if (pref == l - 1) return 1 + dp(kmp[pref], left);
	if (left == 0) return 0;
	double &r = memo[pref + 1][left];
	if (bio[pref + 1][left]++) return r;
	r = 0;
	FOR(0, k, i){
		char c = mon[i];
		int t = pref;
		while (t != -1){
			if (rijec[t + 1] == c) break;
			t = kmp[t];
		}
		if (rijec[t + 1] == c) r += dp(t + 1, left - 1) / k;
		else r += dp(-1, left - 1) / k;
	}
	return r;
}

double Solve(){
	scanf("%d%d%d", &k, &l, &s);
	scanf("%s", mon);
	scanf("%s", rijec);
	if (s < l) return 0;
	FOR(0, l, i){
		bool x = true;
		FOR(0, k, j)
			if (mon[j] == rijec[i])
				x = false;
		if (x) return 0;
	}
	kmp[0] = -1;
	FOR(1, l, i){
		int t = kmp[i - 1];
		while (t != -1){
			if (rijec[i] == rijec[t + 1]) break;
			t = kmp[t];
		}
		if (rijec[i] == rijec[t + 1]) kmp[i] = t + 1;
		else kmp[i] = -1;
	}
	int MaxNum = 1 + (s - l) / (l - 1 - kmp[l - 1]);
	memset(memo, 0, sizeof memo);
	memset(bio, 0, sizeof bio);
	return MaxNum - dp(-1, s) + 1e-12;
}

int main(){
	int t;
	scanf("%d", &t);
	FOR(1, t + 1, i)
		printf("Case #%d: %.9lf\n", i, Solve());
	return 0;
}

