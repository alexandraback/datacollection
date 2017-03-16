#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
double const eps = 1e-8;

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-out.txt", "w", stdout);
	int T, ca = 0; scanf("%d", &T);
	double c, f, x;
	while (T--) {
		scanf("%lf %lf %lf", &c, &f, &x);
		double ret = 0, v = 2.0;
		while (1) {
			double t1 = x / v;
			if (c + eps < x) {
				double nv = v + f;
				double t2 = c / v + x / nv;
			  	if (t2 < t1) {
					ret += c / v;
					v = nv;
					continue;
			  	}	   
			}
			ret += x / v; break;
		}
		printf("Case #%d: %.10lf\n", ++ca, ret);
	}
	return 0;
}

