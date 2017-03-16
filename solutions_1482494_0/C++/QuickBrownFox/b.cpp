#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unistd.h>
#include <utility>
#include <vector>
#include <omp.h>

using namespace std;
typedef long long ll;

#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }

const int TESTCASE = 100;
const int NUMTHREAD = 1;

const int N = 1024;

struct Input {
    int n, a[N], b[N];
    void operator()() {
        int i, j;
        n = getint();
        for (i = 0; i < n; i++) a[i] = getint(), b[i] = getint();
    }
};

struct Output {
    int res;
    void operator()(int id) {
        printf("Case #%d: ", id + 1);
        if (res >= 0) {
            printf("%d\n", res);
        } else {
            puts("Too Bad");
        }
    }
};


struct CaseSolve {
    int n, a[N], b[N];
    int progress[N], curr, played;

    bool is_done() {
        for (int i = 0; i < n; i++) if (progress[i] != 2) return 0;
        return 1;
    }

    bool search_second() {
        for (int i = 0; i < n; i++) if (progress[i] != 2) {
            if (b[i] <= curr) {
                if (progress[i] == 0) {
                    curr += 2;
                }
                if (progress[i] == 1) {
                    curr += 1;
                }
                progress[i] = 2;
                played++;
                return 1;
            }
        }
        return 0;
    }

    bool search_first() {
        int mx = -1, pos = ~0;
        for (int i = 0; i < n; i++) if (progress[i] == 0) {
            if (a[i] <= curr) {
                if (mx < b[i]) {
                    mx = b[i], pos = i;
                }
            }
        }
        if (mx < 0) return 0;
        progress[pos] = 1;
        played++;
        curr++;
        return 1;
    }

    void main(Input* in, Output *out, int test_case) {
        int i, j;

        n = in->n;
        for (i = 0; i < n; i++) a[i] = in->a[i], b[i] = in->b[i];
        for (i = 0; i < n; i++) progress[i] = 0;
        curr = played = 0;

        bool done = 0;
        for (; ; ) {
            done = is_done();
            if (done) break;
            if (search_second()) continue;
            if (search_first()) continue;
            break;
        }

        if (done) out->res = played;
        else out->res = -1;

        fprintf(stderr, "-->%d done at %d.\n", test_case, omp_get_thread_num());
    }
};

Input in[TESTCASE];
Output out[TESTCASE];
CaseSolve sol[NUMTHREAD];

int main () {
    int i, j, t = getint();
    omp_set_num_threads(NUMTHREAD);
    for (i = 0; i < t; i++) in[i]();
#pragma omp parallel for schedule(dynamic, 1)
    for (i = 0; i < t; i++) sol[omp_get_thread_num()].main(in + i, out + i, i);
    for (i = 0; i < t; i++) out[i](i);
    return 0;
}
