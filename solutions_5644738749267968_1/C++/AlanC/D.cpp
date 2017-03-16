#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define FOR(i, s, e) for (int i=(s); i<(e); i++)
#define CLR(x, a) memset(x, a, sizeof(x))
#define N 1005

int TC, n;
double a[N], b[N];

int test(int x1, int y1, int x2, int y2){
	int Q = 0, p = x2;
	FOR(i, x1, y1){
		if (a[i] > b[p]) p++, Q++;
		if (p == y2) break;
	}
	return Q;
}

void solve(int tc){
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%lf", &a[i]);
	FOR(i, 0, n) scanf("%lf", &b[i]);
	sort(a, a + n);
	sort(b, b + n);
	//FOR(i, 0, n) printf("%.3lf ", a[i]); printf("\n");
	//	FOR(i, 0, n) printf("%.3lf ", b[i]); printf("\n");
	
	int B = n, A = 0, p = 0;
	
	FOR(i, 0, n){
		if (b[i] > a[p]) p++, B--;
		if (p == n) break;
	}
	
	FOR(i, 0, n)
		A = max(A, test(i, n, 0, n - i));
	printf("Case #%d: %d %d\n", tc, A, B);
}


int main(){
	scanf("%d", &TC);
	FOR(i, 0, TC) solve(i + 1);
}
