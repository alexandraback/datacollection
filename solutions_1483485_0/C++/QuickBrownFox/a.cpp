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
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;

void print_case(int tc) { printf("Case #%d: ", tc); }
#define gc getchar
int getint() { unsigned int c; int x = 0; while (((c = gc()) - '0') >= 10) { if (c == '-') return -getint(); if (!~c) exit(0); } do { x = (x << 3) + (x << 1) + (c - '0'); } while (((c = gc()) - '0') < 10); return x; }

const char *code = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
const char *text = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

int rev[256], used[256];
void gen() {
    int i, j, k;
    rev[0 + 'q'] = 'z';
    used[0 + 'z'] = 1;
    for (i = 0; code[i]; i++) rev[code[i]] = text[i], used[text[i]] = 1;

    for (i = 'a'; i <= 'z'; i++) if (!rev[i]) {
        for (j = 'a'; j <= 'z'; j++) if (!used[j]) {
            rev[i] = j;
            break;
        }
    }
}

int n;
char in[200];

void solve_case() {
    int i, j;
    fgets(in, 200, stdin);
    n = strlen(in);
    for (i = 0; i < n - 1; i++) {
        putchar(rev[in[i]]);
    }
    puts("");
}

int main () {
    int tcc, tc = getint();
    gen();
    for (tcc = 1; tcc <= tc; tcc++) {
        print_case(tcc);
        solve_case();
    }
    return 0;
}
