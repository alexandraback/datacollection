#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
//#define DEBUG
#ifdef DEBUG
	#define DEB printf
#else
	#define DEB(...)
#endif
#define VAR(x, v) __typeof(v) x = (v)
#define REP(x, n) for(int x = 0; x < (n); x++)
#define FOR(x, b, e) for(int x = (b); x <= (e); x++)
#define FORD(x, u, d) for(int x = (u); x >= (d); x--)
#define FOREACH(x, v) for(VAR(x, (v).begin()); x != (v).end(); x++)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define MIN(a, b) (a) < (b) ? (a) : (b)
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long double LD;

const int N = 200;

int t, n;
LD res;
int s[N], sum;

const LD eps = 1e-9;

LD frac(int i, LD val) {
	if((LD)s[i] >= val) return 0.0;
	return (val - (LD)s[i]) / (LD)sum;
}

LD bsearch(int i) {
	LD val;
	LD l = 0.0, r = 1.0, m;
	while(abs(l - r) > eps) {
		m = (l + r) / 2.0;
		val = (LD)s[i] + (LD)sum * m;
		LD csum = 0.0;
		REP(i, n) csum += frac(i, val);
		DEB("csum = %Lf\n", csum);
		if(csum >= 1.0) {
			r = m;
		} else {
			l = m;
		}
	}
	return l;
}

int main() {
	scanf("%d", &t);
	REP(xx, t) {
		sum = 0;
		scanf("%d", &n);
		REP(i, n) {
			scanf("%d", &s[i]);
			sum += s[i];
		}
		printf("Case #%d: ", xx + 1);
		REP(i, n) {
			printf("%.6Lf ", 100.0 * bsearch(i));
		}
		printf("\n");
	}
	return 0;
}

