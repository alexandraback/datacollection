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

using namespace std;

typedef long long ll;

//#define LARGE

int E;
int R;
int N;

int dp[10][5];

vector<int> v;

int solve(int i, int e) {
    if (i >= N) {
        return 0;
    }
    if (e > E) {
        e = E;
    }
    int best = 0;
    for (int j = 0; j <= e; j++) {
        best = max(best, j * v[i] + solve(i + 1, e - j + R));
    }
    return best;
}

int main() {

#ifndef LARGE
    FILE *in = fopen("B-small-attempt0.in", "r");
    FILE *out = fopen("B-small-attempt0.out", "w");
#else
    FILE *in = fopen("B-large.in", "r");
    FILE *out = fopen("B-large.out", "w");
#endif

    int T;
    fscanf(in, "%d", &T);
    for (int t = 0; t < T; t++) {
        v.clear();
        fscanf(in, "%d%d%d", &E, &R, &N);
        for (int i = 0; i < N; i++) {
            int tmp;
            fscanf(in, "%d", &tmp);
            v.push_back(tmp);
        }
        fprintf(out, "Case #%d: %d\n", t + 1, solve(0, E));
    }
    fclose(in);
    fclose(out);
    return 0;
}
