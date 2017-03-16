#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const double EPS = 1e-10;

double solve() {
    double C, F, X;
    scanf("%lf %lf %lf", &C, &F, &X);
    double sol = X/2;
    double t = 0;
    int have = 0;
    while (t < sol-EPS) {
        double tX = X/(have*F+2);
        sol = min(sol, t+tX);
        if (tX < EPS) {
            return sol;
        }
        double tC = C/(have*F+2);
        ++have;
        t += tC;
    }
    return sol;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; ++t) {
        printf("Case #%d: %.7f\n", t, solve());
    }
	return 0;
}
