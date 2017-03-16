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

void test() {
	int k,c,s;
	scanf("%d%d%d", &k, &c, &s);
	int bnd = (c+k-1)/c;
	if (s < bnd) {
		printf("IMPOSSIBLE\n");
		return;
	}
	FOR(i,bnd) {
		long long cur = 0;
		FOR(j,c) cur = cur * k + min(k-1, i*c+j);
		printf("%lld ", cur+1);
	}
	printf("\n");
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
