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
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

long long best_diff;
int n;
char s[33], t[33], bs[33], bt[33];
char ts[33], tt[33];

void chk(int pos) {
	FOR(i,n) ts[i]=s[i];
	FOR(i,n) tt[i]=t[i];
	for (int i = pos+1; i < n; i++) {
		if (ts[i]=='?') ts[i] = '0' + (s[pos]<t[pos] ? 9 : 0);
		if (tt[i]=='?') tt[i] = '0' + (s[pos]>t[pos] ? 9 : 0);
	}
	ts[n] = tt[n] = 0;
	ll A, B;
	sscanf(ts, "%lld", &A);
	sscanf(tt, "%lld", &B);
	ll diff = A<B ? B-A : A-B;
	if (diff < best_diff) {
		best_diff = diff;
		FOR(i,n+1) {
			bs[i] = ts[i];
			bt[i] = tt[i];
		}
	} else if (best_diff == diff) {
		int cmp = -1;
		FOR(i,n) if (ts[i] != bs[i]) {
			cmp = ts[i] < bs[i];
			break;
		}
		if (cmp == -1) FOR(i,n) if (tt[i] != bt[i]) {
			cmp = tt[i] < bt[i];
			break;
		}
		if (cmp) {
			FOR(i,n+1) {
				bs[i] = ts[i];
				bt[i] = tt[i];
			}
		}
	}
}

void go(int pos) {
	if (pos==n) {
		ll A, B;
		sscanf(s, "%lld", &A);
		sscanf(t, "%lld", &B);
		ll diff = A<B ? B-A : A-B;
		if (diff < best_diff) {
			best_diff = diff;
			FOR(i,n+1) {
				bs[i] = s[i];
				bt[i] = t[i];
			}
		} else if (diff == best_diff) {
			bool cmp = -1;
			FOR(i,n) if (s[i] != bs[i]) {
				cmp = s[i] < bs[i];
				break;
			}
			if (cmp == -1) FOR(i,n) if (t[i] != bt[i]) {
				cmp = t[i] < bt[i];
				break;
			}
			if (cmp) {
				FOR(i,n+1) {
					bs[i] = s[i];
					bt[i] = t[i];
				}
			}
		}
		return;
	}
	if (s[pos] == t[pos] && s[pos] != '?') return;
	if (s[pos] != '?' && t[pos] != '?') {
		chk(pos);
		return;
	}
	if (s[pos] == '?' && t[pos] == '?') {
		for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) {
			s[pos] = '0'+i;
			t[pos] = '0'+j;
			chk(pos);
		}
		s[pos] = '?';
		t[pos] = '?';
		return;
	}
	if (s[pos] == '?') {
		for (int i = 0; i < 10; i++) {
			s[pos] = '0' + i;
			chk(pos);
		}
		s[pos] = '?';
		return;
	}
	if (t[pos] == '?') {
		for (int i = 0; i < 10; i++) {
			t[pos] = '0' + i;
			chk(pos);
		}
		t[pos] = '?';
		return;
	}
}

void test() {
	scanf("%s%s", s, t);
	for (n=0; s[n]; n++) ;
	best_diff = pow(10,n)+1;
	FOR(i,n) {
		bs[i] = '9';
		bt[i] = '9';
	}
	FOR(i,n+1) {
		go(i);
		if (s[i] != '?' && t[i] != '?' && s[i] != t[i]) break;
		if (t[i] == '?') t[i] = s[i];
		if (s[i] == '?') s[i] = t[i];
		if (s[i] == '?') s[i] = t[i] = '0';
	}
	printf("%s %s\n", bs, bt);
}

int main() {
	int ttn;
	scanf("%d", &ttn);
	for (int i = 1; i <= ttn; i++) {
		printf("Case #%d: ", i);
		test();
	}
	return 0;
}
