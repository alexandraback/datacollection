
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#define MAXN 10000

using namespace std;

#define q1 0
#define qi 1
#define qj 2
#define qk 3
#define val(x) ((x) & 3)
#define sgn(x) (((x) & 4) ? -1 : 1)
#define neg(x) ((x) ^ 4)

int adj[4][4] = {
    // 1, i, j, k
    {q1, qi, qj, qk},
    // i, -1, k, -j
    {qi, neg(q1), qk, neg(qj)},
    // j, -k, -1, i
    {qj, neg(qk), neg(q1), qi},
    // k, j, -i -1
    {qk, qj, neg(qi), neg(q1)}
};

int mul(int v1, int v2) {
    int r = adj[val(v1)][val(v2)];
    if (sgn(v1) != sgn(v2))
        r = neg(r);
    return r;
}

int a[MAXN];
int L, X;
int prod[MAXN];

bool solve() {
    prod[0] = a[0];
    for (int i = 1; i < L; i++)
        prod[i] = mul(prod[i - 1], a[i]);

    int prodAll = q1;
    for (int i = 0; i < (X % 4); i++)
        prodAll = mul(prodAll, prod[L - 1]);

    // prodAll should be ijk = kk = -1
    if (prodAll != neg(q1))
        return false;

    for (int i = 0; i < L; i++) {
        int base = q1;
        int used = 1;
        bool found = false;
        for (int k = 0; k < 4; k++) {
            if (mul(base, prod[i]) == qi) {
                used += k;
                found = true;
                break;
            }
            base = mul(base, prod[L - 1]);
        }
        if (!found || used > X)
            continue;

        for (int j = 0; j < L; j++) {
            int baseNext = base;
            int usedNext = used;
            bool foundNext = false;
            if (j <= i) {
                baseNext = mul(baseNext, prod[L - 1]);
                usedNext++;
            }

            for (int k = 0; k < 4; k++) {
                if (mul(baseNext, prod[j]) == qk) {
                    usedNext += k;
                    foundNext = true;
                    break;
                }
                baseNext = mul(baseNext, prod[L - 1]);
            }
            if (foundNext && usedNext <= X)
                return true;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> L >> X;
        string s;
        cin >> s;
        assert(L == s.size());
        for (int i = 0; i < L; i++) {
            if (s[i] == 'i') a[i] = qi;
            else if (s[i] == 'j') a[i] = qj;
            else a[i] = qk;
        }
        cout << "Case #" << t << ": " << (solve() ? "YES" : "NO") << endl;
    }
}
