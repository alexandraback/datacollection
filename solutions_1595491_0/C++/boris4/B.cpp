#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct Triplet {
    int a, b, c;

    Triplet(int na = 0, int nb = 0, int nc = 0) {
        a = na; b = nb; c = nc;
    }

    int getMax() {
        return max(a, max(b, c));
    }

    bool operator<(const Triplet& other) const {
        return max(a, max(b, c)) > max(other.a, max(other.b, other.c));
        /* return getMax() > other.getMax(); */
    }
};

int n, s, f, t[105], p[105], p2[105];
vector<Triplet> sur[35];
vector<Triplet> nor[35];

int myabs(int a) { return a < 0 ? -a : a; }

bool normal(int a, int b, int c) {
    return myabs(a - b) <= 2 && myabs(a - c) <= 2 && myabs(b - c) <= 2;
}

bool surprising(int a, int b, int c) {
    return normal(a, b, c) && (myabs(a - b) == 2 || myabs(a - c) == 2 || myabs(b - c) == 2);
}

int main() {
    for (int i = 0; i < 30; ++i) sur[i].clear();
    for (int i = 0; i < 30; ++i) nor[i].clear();
    for (int a = 0; a <= 10; ++a)
        for (int b = 0; b <= 10; ++b)
            for (int c = 0; c <= 10; ++c)
                if (surprising(a, b, c)) sur[a + b + c].push_back(Triplet(a, b, c));
                else if (normal(a, b, c)) nor[a + b + c].push_back(Triplet(a, b, c));
    for (int i = 0; i < 30; ++i) sort(sur[i].begin(), sur[i].end());
    for (int i = 0; i < 30; ++i) sort(nor[i].begin(), nor[i].end());
    int tests; scanf("%d", &tests);
    for (int testId = 1; testId <= tests; ++testId) {
        scanf("%d%d%d", &n, &s, &f);
        for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
        memset(p, 0, sizeof(p));
        memset(p2, 0, sizeof(p2));
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int a = t[i];
            if (p[a] < nor[a].size()) {
                if (nor[a][p[a]].getMax() >= f) {
                    ++res;
                    t[i] = -1;
                }
            } else {
                if (p2[a] == sur[a].size()) continue;
                --s;
                t[i] = -1;
                if (sur[a][p2[a]].getMax() >= f) ++res;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (t[i] == -1) continue;
            int a = t[i];
            if (s == 0 || p2[a] == sur[a].size()) continue;
            if (sur[a][p2[a]].getMax() >= f) {
                ++res;
                --s;
            }
        }
        printf("Case #%d: %d\n", testId, res);
    }
    return 0;
}
