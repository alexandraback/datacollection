#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXK = 2824;
double P[MAXK+1][MAXK+1];
double solve(int N, int X, int Y) {
    int n = 1;
    while (n*(2*n-1) <= N) {
        ++n;
    }
    --n;
    int K = N - n*(2*n-1);
    int sgn = abs(X)+abs(Y);
    if (sgn <= 2*(n-1)) {
        return 1.0;
    }
    if (sgn>2*n || Y==2*n || K<Y+1) {
        return 0.0;
    }
    if (K-2*n >= Y+1) {
        return 1.0;
    }
    
    double ret = 0.0;
    for (int i=Y+1; i<=K; ++i) {
        ret += P[K][i];
    }
    return ret;
}
int main() {
    P[0][0] = 1.0;
    for (int n=1; n<=MAXK; ++n) {
        P[n][0] = P[n-1][0]/2;
        for (int k=1; k<=n; ++k) {
            P[n][k] = 0.5*(P[n-1][k-1] + P[n-1][k]);
        }
    }

    cin.sync_with_stdio(false);
    int ntestcases;
    scanf("%d", &ntestcases);
    for (int testcase=1; testcase<=ntestcases; ++testcase) {
        int N, X, Y;
        scanf("%d %d %d", &N, &X, &Y);
        printf("Case #%d: %.9f\n", testcase, solve(N, X, Y));
    }
	return 0;
}
