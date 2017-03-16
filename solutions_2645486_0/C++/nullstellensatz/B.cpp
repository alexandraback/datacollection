


/*
    Prob:   Google code jam Round 1A 2013 B
    Author: peanut
    Time:   27/04/13 09:40
    Description:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

const int MaxN = 100005;

int T, E, R, n;
long long ans;
int v[MaxN], idx[MaxN];

void build(int c, int l, int r) {
    if (l == r) {
        idx[c] = r;
        return;
    }
    int m = (l + r) >> 1, p = c << 1, q = p ^ 1;
    build(p, l, m);
    build(q, m + 1, r);
    if (v[idx[p]] > v[idx[q]]) idx[c] = idx[p]; else idx[c] = idx[q];
}

int query(int c, int l, int r, int x, int y) {
    if (l == x && r == y) return idx[c];
    int m = (l + r) >> 1, p = c << 1, q = p ^ 1;
    if (y <= m) return query(p, l, m, x, y);
    if (x > m)  return query(q, m + 1, r, x, y);
    int s = query(p, l, m, x, m), t = query(q, m + 1, r, m + 1, y);
    if (v[s] > v[t]) return s; else return t;
}

void calc(int l, int r, int init, int left) {
    if (l > r) return;
    int m = query(1, 1, n, l, r);
    long long H = E, L = R;
    if ((H - init) / R > m - l) H = init + (m - l) * R;
    if ((left - L) / R > r - m) L = left - (r - m) * R;
    ans += (H - L + R) * v[m];
    calc(l, m - 1, init, H);
    calc(m + 1, r, L, left);
}

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        string input_file  = string(argv[1]) + ".in",
               output_file = string(argv[1]) + ".out";
        freopen(input_file.c_str(), "r", stdin);
        freopen(output_file.c_str(), "w", stdout);
    }
    
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        scanf("%d %d %d", &E, &R, &n);
        for (int k = 1; k <= n; ++ k)
            scanf("%d", v + k);
        memset(idx, 0, sizeof idx);
        build(1, 1, n);

        ans = 0;
        calc(1, n, E, R);
        cout << "Case #" << testcase << ": " << ans << endl;
    }
    
    return 0;
}
