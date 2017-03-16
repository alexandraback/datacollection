#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-8
#define oo 1<<29
#define LL long long

using namespace std;

int T, m, n, w, mi, ma, cnt, t, fi, cc, e, r, z;
double c, f, x, an, q, s;

int main(){
	scanf("%d", &T);
	for (int rr = 1; rr <= T; rr++){
		printf("Case #%d: ", rr);
		scanf("%lf%lf%lf", &c, &f, &x);
		an = oo;
		for (int i=0; i<=x; i++){
			s = 2; q = 0;
			for (int j=0; j<i; j++){
				q += c/s;
				s += f;
			}
			q += x/s;
			if (q < an)
				an = q;
			if (q > x/2 + eps)
				break;
		}
		printf("%.7f\n", an);
	}
	return 0;
}
