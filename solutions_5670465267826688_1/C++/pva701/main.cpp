#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef double db;
int to[8][8] = {{0, 1, 2, 3}, {1, 4, 3, 6}, {2, 7, 4, 1}, {3, 2, 5, 4}};

int getV(char c) {
    if (c == 'i')
        return 1;
    if (c == 'j')
        return 2;
    return 3;
}
pair <int,int> nextIndex(const string& concat, int i, int expect) {
    int now = 0;
    for (; i < concat.size() && now != expect; ++i)
        now = to[now][getV(concat[i])];
    return make_pair(i, now);
}

bool solve(const string& s, long long x) {
    string concat;
    long long len = x * s.size();
    long long mn = min(10LL, x);
    for (int i = 1; i <= mn; ++i)
        concat += s;
    pair <int, int> res = nextIndex(s, 0, -1);
    pair <int, int> i = nextIndex(concat, 0, 1);
    if (i.second != 1)
        return false;
    pair <int, int> j = nextIndex(concat, i.first, 2);
    if (j.second != 2)
        return false;
    pair <int, int> k = nextIndex(concat, j.first, -1);
    if (concat.size() == len)
        return k.second == 3;
    x = (x - 10) % 4;
    int now = k.second;
    for (int i = 1; i <= x; ++i)
        now = to[now][res.second];
    return now == 3;
}

void precalc() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if (i >= 4 || j >= 4) {
                int r = (i >= 4) + (j >= 4);
                int xi = i % 4;
                int xj = j % 4;
                to[i][j] = (to[xi][xj] + r *  4) % 8;
            }
}

int main() {
    precalc();
    freopen("C-large.in", "r", stdin);
    freopen("outputC.out", "w", stdout);
    int t;
    cin >> t;
    for (int it = 1; it <= t; ++it) {
        int l;
        long long x;
        string s;
        cin >> l >> x >> s;
        printf("Case #%d: %s\n", it, (solve(s, x) ? "YES" : "NO"));
    }
    return 0;
}
