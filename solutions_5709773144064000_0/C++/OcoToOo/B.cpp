#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <float.h>
#include <fstream>

using namespace std;

typedef long long ll;

//#define LARGE

double C;
double F;
double X;

double solve() {
    double p = 2.0;
    double min = X / p;
    double total = 0.0;
    while (1) {
        double time = total + X / p;
        if (time > min) {
            break;
        }
        min = time;
        total += C / p;
        p += F;
    }
    return min;
}

int main() {
#ifndef LARGE
    ifstream in("B-small-attempt0.in");
    FILE *out = fopen("B-small-attempt0.out", "w");
#else
    ifstream in("B-large.in");
    FILE *out = fopen("B-large.out", "w");
#endif
    int T; in >> T;
    for (int t = 0; t < T; t++) {
        in >> C >> F >> X;
        fprintf(out, "Case #%d: %.7f\n", t + 1, solve());
    }
    return 0;
}
