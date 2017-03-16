/*
  ID: nigo1
  LANG: C++
  TASK: A
*/
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>

#define TIME pf("%f", (double)clock()/CLOCKS_PER_SEC);

using namespace std;

int T;
int A, B;
double p[100002];

double min (double a, double b) {
    if (a < b + 1e-9) return a;
    return b;
}
int main()
{
	freopen ("A-large.in", "r", stdin);
	freopen ("A.out", "w", stdout);

	scanf ("%d", &T);

	for (int test = 1; test <= T; test++) {
        scanf ("%d%d", &A, &B);

        printf ("Case #%d: ", test);

        double maxp = 1.0;
        for (int i = 0; i < A; i++) {
            scanf ("%lf", p + i);
        }
        double ans = B + 2;

        for (int len = A; len >= 0; len--) {
           ans = min (ans, maxp*(len + B - (A - len) + 1) + (1.0 - maxp)*(len + B - (A - len) + 1 + B + 1));

           //cout << maxp << " " << maxp*(len + B - (A - len) + 1) + (1.0 - maxp)*(len + B - (A - len) + 1 + B + 1) << endl;
           maxp *= p[A - len];
        }
        printf ("%.6lf\n", ans);
	}


    return 0;
}
