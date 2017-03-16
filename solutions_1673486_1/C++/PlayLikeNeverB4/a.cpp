#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 2000000000
#define MAXN 100000
int i, t, T, A, B;
double p[MAXN], pRight[MAXN], ans;

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out","w", stdout);
	
	scanf("%d", &T);
	
	for(t = 1; t <= T; t++) {
		scanf("%d %d", &A, &B);
		for(i = 1; i <= A; i++)
			scanf("%lf", &p[i]);
		pRight[0] = 1.0;
		for(i = 1; i <= A; i++)
			pRight[i] = pRight[i - 1] * p[i];
		
		ans = INF;
		
		// keep typing
		ans = pRight[A] * (B - A + 1) + (1.0 - pRight[A]) * (B - A + 1 + B + 1);
		
		// enter right away
		ans = min(ans, (double)1 + B + 1);
		
		// backspace i times
		for(i = 1; i <= A; i++)
			ans = min(ans, i + pRight[A - i] * (B - (A - i) + 1) + (1.0 - pRight[A - i]) * (B - (A - i) + 1 + B + 1));
		
		printf("Case #%d: %.7lf\n", t, ans);
	}
	
	return 0;
}
