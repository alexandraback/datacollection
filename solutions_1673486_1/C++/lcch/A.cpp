#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

typedef long long LL;

const int maxn = 1000000;
int A, B;
double p[maxn], f[maxn];

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A_L.out", "w", stdout);

	int TextN, TT = 0;
	double Ans;
	scanf("%d", &TextN);
	while (TextN--) {
		scanf("%d%d", &A, &B);
		f[0] = 1.0;
		for (int i = 1; i <= A; i++) {
			scanf("%lf", &p[i]);
			f[i] = f[i-1] * p[i];
		}

		B-=A;
		Ans = 2+A+B;
		Ans = min(Ans, f[A]*(B+1)+(1.0-f[A])*(A+2*B+2));
		for (int k = 1; k <= A; k++) {
			Ans = min(Ans, f[A-k]*(2*k+B+1) + (1.0-f[A-k])*(2*k+2+A+B+B));
		}
		printf("Case #%d: %.6lf\n", ++TT, Ans);
	}
	return 0;
}