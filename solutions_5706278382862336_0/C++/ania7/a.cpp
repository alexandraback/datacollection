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

void test() {
	long long p,q;
	scanf("%lld/%lld", &p, &q);
	long long g = __gcd(p,q);
	p /= g;
	q /= g;
	long long w = q;
	while (w > 1) {
		if (w & 1) {
			printf("impossible\n");
			return;
		}
		w /= 2;
	}
	int res = 0;
	while (p < q) {
		q /= 2;
		res++;
	}
	printf("%d\n", res);
}

int main() {
	int tt;
	scanf("%d", &tt);
	for (int te = 1; te <= tt; te++) {
		printf("Case #%d: ", te);
		test();
	}
}
