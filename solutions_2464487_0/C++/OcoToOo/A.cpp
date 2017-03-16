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

int r;
int t;

void solve() {
}

int main() {

#ifndef LARGE
    FILE *in = fopen("A-small-attempt0.in", "r");
    FILE *out = fopen("A-small-attempt0.out", "w");
#else
    FILE *in = fopen("A-large.in", "r");
    FILE *out = fopen("A-large.out", "w");
#endif

    int T;
    fscanf(in, "%d", &T);
    for (int c = 0; c < T; c++) {
        fscanf(in, "%d", &r);
        r += 1;
        fscanf(in, "%d", &t);
        int cnt = 0;
        double sum = 0.0;
        for (double i = r; ; i += 2) {
            double a = (i - 1) * (i - 1);
            double b = i * i;
            sum += b - a;
            if (sum > t) {
                break;
            }
            cnt++;
        }
        fprintf(out, "Case #%d: %d\n", c + 1, cnt);
    }
    fclose(in);
    fclose(out);
    return 0;
}
