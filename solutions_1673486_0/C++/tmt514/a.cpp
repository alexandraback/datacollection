#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

double p[100005];
double c[100005];

void solve() {
	int A, B;
	scanf("%d%d", &A, &B);
	c[0] = 1.0;
	for(int i=1;i<=A;i++) scanf("%lf", &p[i]);
	for(int i=1;i<=A;i++) c[i] = p[i] * c[i-1];
	double ans = B+2;
	for(int i=0;i<=A;i++)
		ans = min(ans, (A-i)+(B-i)+1+(1-c[i])*(B+1));
	static int cs=0;
	printf("Case #%d: %.9f\n", ++cs, ans);
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
