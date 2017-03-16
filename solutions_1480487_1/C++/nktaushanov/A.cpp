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

#define TIME printf("%f", (double)clock()/CLOCKS_PER_SEC);

#define eps 1e-9

using namespace std;

int T;

int N;
double m[256];
double X;

double solve (int x) {
    double l = 0.0, r = 1.0;

    for (int k = 0; k < 100; k++) {
        double mid = (l + r)/2.0;

        double score = m[x] + mid*X;

        double tmp = 0.0;

        for (int i = 0; i < N; i++)
            if (i != x) {
                if (m[i] - score < eps)
                    tmp += (score - m[i])/X;
            }

        if (fabs(tmp - 1.0 + mid) < eps)
            r = mid;
        else {
            if (tmp - 1.0 + mid < eps)
                l = mid;
            else
                r = mid;
        }
    }
    //cout << fixed << l << " " << fixed << r << endl;
    return r;
}

int main()
{
	freopen ("A.in", "r", stdin);
	freopen ("A.out", "w", stdout);

	scanf ("%d", &T);

	for (int test = 1; test <= T; test++) {
        printf ("Case #%d:", test);

        scanf ("%d", &N);

        X = 0.0;

        for (int i = 0; i < N; i++)
            scanf ("%lf", m + i), X += m[i];

        for (int i = 0; i < N; i++)
            printf (" %lf", solve(i)*100.0);

        printf ("\n");
	}


    return 0;
}
