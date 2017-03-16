#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long int64;
typedef long double ldouble;

#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)

#define PROBLEM "A"

const int MAXN = 100100;
double p[MAXN], q[MAXN];

const int MNOGO = 0x3fffffff;

int main() {
	freopen(PROBLEM ".in", "rt", stdin);
	freopen(PROBLEM ".out", "wt", stdout);

	int T;
	scanf("%d\n", &T);

	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);

		int a, b;
		scanf("%d %d", &a, &b);
		
		q[0] = 1.0;
		for (int i = 1; i <= a; i++) {
			scanf("%lf", &p[i]);
			q[i] = q[i-1] * p[i];
		}

        double minim = MNOGO;

        // typing
        double t1 = (q[a]) * (b-a+1) + (1 - q[a]) * (b-a+1 + b+1);
        minim = min(minim, t1);

        // giving up
        double t2 = 1 + b + 1;
        minim = min(minim, t2);

        // backspacing
        for (int i = 1; i <= a; i++) {
        	double t3 = q[a-i] * (i + i + b-a + 1) + (1-q[a-i]) * (i + i + b-a + 1 + b + 1);
        	minim = min(minim, t3);
        }
		
		printf("%0.7lf", minim);
		printf("\n");
	}

	return 0;
}
