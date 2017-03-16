#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>
#include <iostream>

#define PI 3.14159265358979
#define EPS 1e-9

using namespace std;

#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, m, n) for (int i=m; i<=n; i++)
#define ABS(a) (((a)>0)?(a):(-(a)))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

#define MOD 1000000007

int seen[30];
int ex[30];
int cnt[30];
int back[30];
int next[30];
int bylo[30];
int multi[30];
ll fact[200];
vector<string> v;
int n;

bool process(string &s) {
	REP(i, s.size()) seen[s[i]-'a'] = 1;
	if (s.size()>1)
		FOR (i, 1, s.size()-2) if (s[0]!=s[i] && s[s.size()-1]!=s[i]) multi[s[i]-'a'] = 0;
	REP(i, s.size()-1) {
		if (s[i]!=s[i+1]) {
			int c = s[i]-'a';
			int d = s[i+1]-'a';
			if (next[c]==-1) next[c] = d;
			else return false;
			if (back[d]==-1) back[d] = c;
			else return false;
		}
	}
	bool b = true;
	REP(i, s.size()) {
		if (s[i]!=s[0]) { b = false; break; }
	}
	if (b)
		cnt[s[0]-'a']++;
	return true;
}

void solve() {
	v.clear();
	REP(i, 30) {
		multi[i] = 1;
		ex[i] = cnt[i] = seen[i] = 0;
		back[i] = next[i] = -1;
	}
	scanf("%d", &n);
	REP(i, n) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	REP(i, v.size()) {
		if(!process(v[i])) {
			printf("0\n");
			return ;
		}
	}
	REP(i, 26) {
		if (!multi[i] && cnt[i]>0) {
			printf("0\n");
			return ;
		}
	}
	vector<string> w;
	REP(i, n) {
		string s = "";
		REP(j, v[i].size()) {
			if (s.size()==0 || s[s.size()-1]!=v[i][j])
				s.push_back(v[i][j]);
		}
		w.push_back(s);
	}
	// permutace
	vector<int> perm;
	REP(i, n) {
		perm.push_back(i);
	}
	ll res = 0;
	do {
		string s = "";
		REP(j, n) {
			int i = perm[j];
			s += w[i];
		}
		REP(i, 26) seen[i] = 0;
		bool b = true;
		REP(i, s.size()) {
			if (seen[s[i]-'a']) {
				b = false; break;
			}
			seen[s[i]-'a'] = true;
			while (i+1<s.size() && s[i+1]==s[i]) i++;
		}
		if (b)
			res++;
	} while(next_permutation(perm.begin(), perm.end()));
	printf("%lld\n", res);
	/*ll res = 1;
	int cykly = 0;
	// Hadi
	REP(i, 26) bylo[i] = !seen[i];
	REP(i, 26) if (seen[i]==true && back[i]==-1) {
		int akt = i;
		ll sub = 1;
		//printf("ss\n");
		while (akt!=-1) {
			//printf("sub = %lld * %lld\n", sub, fact[cnt[akt]]);
			sub = (sub * fact[cnt[akt]])%MOD;
			//printf("%lld\n", sub);
			akt = next[akt];
		}
		//printf("res = %lld * %lld\n", res, sub);
		res = (res * sub)%MOD;
		//printf("res %lld\n", res);
		cykly++;
	}
	//printf("res = %lld * %lld\n", res, fact[cykly]);
	bool b = true; REP(i, 26) b |= bylo[i];
	if (!b) {
		printf("0\n");
		return ;
	}
	res = (res*fact[cykly])%MOD;
	printf("%lld\n", res);*/
}

int main()
{
	fact[0] = 1;
	FOR (i, 1, 110) fact[i] = (i * fact[i-1])%MOD;
	int t;
	scanf("%d", &t);
	REP (i, t) {
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}
