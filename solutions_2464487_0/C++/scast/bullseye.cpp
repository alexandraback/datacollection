#include<cstdio>
#include<cmath>
using namespace std;
#define MAXR 1000
#define MAXT 1000
#define PI 3.141592653589793
// 1 mm of paint is required for pi cm2 area

inline double area(int r) {
    return PI*r*r;
}

int T, r;
double t;
int ans;
int main() {
    scanf("%d", &T);
    for (int tt=0; tt<T; tt++) {
	ans = 0;
	scanf("%d%lf", &r, &t);

	while (r>0&&t>0) {
	    double needed = 2*r + 1;
	    // printf("%d %lf --- %lf\n", r, t, needed);
	    if (needed > t) break;
	    t -= needed;
	    r += 2;
	    ans++;
	}
	// while (r > 0 && t > 0) {
	// double a1 = area(r+1), a2 = area(r);
	// printf("%lf-%lf=%lf\n", a1, a2, a1-a2);
	    // double needed = a1-a2;
	    // if (needed > t) break;
	    // t -= needed;
	    // r -= 2;
	    // ans++;
	// }
	printf("Case #%d: %d\n", tt+1, ans);
    }
    return 0;
}
