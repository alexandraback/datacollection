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

using namespace std;
typedef long long ll;

void print_case(int tc) { printf("Case #%d: ", tc); }
#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }
int getc_str(char str[]) { unsigned int c, n = 0; while ((c = gc()) <= ' '); if (!~c) exit(0); do { str[n++] = c; } while ((c = gc()) > ' ' ); str[n] = '\0'; return n; }

int n;
char buf[333];
vector<int> perm;
vector<string> vstr;

int check() {
    int i, j;
    char used[1024] = {};
    char tail = '@';
    for (i = 0; i < n; i++) {
        for (j = 0; j < vstr[perm[i]].size(); j++) {
            if (tail != vstr[perm[i]][j]) {
                if (used[vstr[perm[i]][j]]) return 0;
                used[vstr[perm[i]][j]] = 1;
                tail = vstr[perm[i]][j];
            }
        }
    }
    return 1;
}

void solve_case() {
    int i, j, res = 0;
    n = getint();
    perm.clear(), vstr.clear();
    for (i = 0; i < n; i++) perm.push_back(i);
    for (i = 0; i < n; i++) {
        getc_str(buf);
        vstr.push_back(buf);
    }
    do {
        if (check()) res++;
    } while(next_permutation(perm.begin(), perm.end()));
    printf("%d\n", res);
}

int main () {
    int tcc, tc = getint();
    for (tcc = 1; tcc <= tc; tcc++) {
        print_case(tcc);
        solve_case();
    }
    return 0;
}
