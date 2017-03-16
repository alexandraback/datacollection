#include <cstdio>
#include <algorithm>
using namespace std;
typedef long double LD;

int a, b;
LD r;


int main()
{
	int T; scanf("%d", &T);
	for (int t=1; t<=T; ++t) {
		scanf("%d%d", &a, &b); b -= a;
		
		r = a+b+2;
		LD now = 1, p;
		for (int i=1; i<=a; ++i) {
			scanf("%Lf", &p); now *= p;
			r = min(r, now*(2*a-2*i+b+1) + (1-now)*(3*a-2*i+2*b+2));
		}
		
		printf("Case #%d: %.6Lf\n", t, r);
	}
	
	return 0;
}
		
