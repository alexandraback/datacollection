#include <cstdio>
#include <algorithm>
#include <cassert>

#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define SZ(x) ((int)(x).size())
#define ALL(v) (v).begin() , (v).end()
#define CLR(v) memset(v, 0, sizeof(v));

using namespace std;

double v[250], r[250]; bool a[250];
int t, n;

void solve() {
	double target = 0, sum = 0;
	FOR(i,0,n) sum += v[i];
	target = 2*sum/((double)(n));
	CLR(a);
	int ct = 0; sum = 0; double sum2 = 0;
	FOR(i,0,n) if (v[i] > target) a[i] = true;
	
	FOR(i,0,n) sum += v[i], ct+=(!a[i]), sum2 += (a[i]?v[i]:0);
	target = (2*sum-sum2)/((double)(ct)) ;
//	printf("sum = %lg | target = %lg | ct = %d\n", sum, target, ct	);
	double s =0;
	FOR(i,0,n) r[i] = (a[i] ? 0:(target-v[i])/sum), s+=r[i];
//	FOR(i,0,n) r[i] = (target-v[i])/sum;
//	printf("SSS = %lg\n", s);
}

int main() {
	scanf("%d", &t);
	FOR(i,0,t) {
		scanf("%d", &n);
		FOR(j,0,n) scanf("%lg", &v[j]);
		solve();
		printf("Case #%d:", i+1);
		FOR(j,0,n) printf(" %.9lg", r[j]*100);
		puts("");
	}
	return 0;
}