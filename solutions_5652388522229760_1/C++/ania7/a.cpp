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

int c, d[22];

void add(long long n) {
	while (n) {
		if (d[n%10] == 0) {
			d[n%10] = 1;
			c--;
		}
		n /= 10;
	}
}

void test() {
	int n;
	scanf("%d", &n);
	if (n==0) {
		printf("INSOMNIA\n");
		return;
	}
	FOR(i,10) d[i]=0;
	c = 10;
	int res;
	for (res = 1; c; res++) {
		add(1LL*res*n);
	}
	printf("%lld\n", 1LL*(res-1)*n);
	fprintf(stderr, "%d %d\n", res, res/n);
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
