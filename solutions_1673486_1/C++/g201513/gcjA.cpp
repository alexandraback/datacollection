#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

const int maxn = 100000 + 50;

int ntest;
int A, B;
double p[maxn];
double s[maxn];

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d%d", &A, &B);
		s[0] = 1.0;
		for(int i=1; i<=A; i++) {
			scanf("%lf", &p[i]);
			s[i] = s[i-1] * p[i];
		}

		double ans = min((B-A+1) + (1-s[A]) * (B+1), B+2.0);

		for(int i=1; i<A; i++) {
			double tmp = (A-i+(B-i)+1) + (1-s[i]) * (B+1);

		//	printf("%d %lf\n", i, tmp);

			if(ans > tmp) ans = tmp;
		}

		printf("Case #%d: %.10lf\n", test, ans);
	}
	return 0;
}