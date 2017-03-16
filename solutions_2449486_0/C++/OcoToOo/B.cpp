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

int N;
int M;

string solve( vector<vector<int>> lawn) {
    vector<vector<int>> init;
    for (int n = 0; n < N; n++) {
        vector<int> v(M, 100);
        init.push_back(v);
    }

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            int h = lawn[n][m];

            bool ok = true;
            for (int x = 0; x < M; x++) {
                if (lawn[n][x] > h) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int x = 0; x < M; x++) {
                    init[n][x] = min(h, init[n][x]);
                }
            }

            ok = true;
            for (int y = 0; y < N; y++) {
                if (lawn[y][m] > h) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int y = 0; y < N; y++) {
                    init[y][m] = min(h, init[y][m]);
                }
            }
        }
    }

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            if (init[n][m] != lawn[n][m]) {
                return "NO";
            }
        }
    }
    return "YES";
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
        fscanf(in, "%d", &N);
        fscanf(in, "%d", &M);
        vector<vector<int>> lawn;
        for (int n = 0; n < N; n++) {
            vector<int> v(M);
            lawn.push_back(v);
            for (int m = 0; m < M; m++) {
                fscanf(in, "%d", &lawn[n][m]);
            }
        }
        string s = solve(lawn);
        printf("%s\n", s.c_str());
        fprintf(out, "Case #%d: %s\n", t + 1, s.c_str());
    }
    fclose(in);
    fclose(out);
    return 0;
}
