#include <cstdio>
#include <cstring>
#include <tuple>
#include <cassert>
#include <vector>
using namespace std;

const int N = 25;
char A[N], B[N];

typedef long long llong;

llong X, Y;

llong pw10[N];

int l;

bool fill_same(int p) {
    X = Y = 0;
    for (int i = 0; i < p; i++) {
        llong val = 0;
        if (A[i] == '?' && B[i] == '?') {
            val = 0;
        } else if (A[i] == '?' && B[i] != '?') {
            val = (B[i] - '0');
        } else if (A[i] != '?' && B[i] == '?') {
            val = (A[i] - '0');
        } else if (A[i] != B[i]) {
            return false;
        } else {
            val = A[i] - '0';
        }
        X += val * pw10[l - i - 1];
        Y += val * pw10[l - i - 1];
    }
    return true;
}

llong aX = -1, aY = -1;

bool fill_diff(int p, bool greater) {
    assert(p < l);
    vector<int> possA, possB;
    if (A[p] == '?') {
        for (int i = 0; i < 10; i++)
            possA.push_back(i);
    } else {
        possA.push_back(A[p] - '0');
    }
    if (B[p] == '?') {
        for (int i = 0; i < 10; i++)
            possB.push_back(i);
    } else {
        possB.push_back(B[p] - '0');
    }
    int ax = -1, ay = -1;
    for (int x : possA) {
        for (int y : possB) {
            if (((greater && x > y) || (!greater && x < y))) {
                if (ax == -1 || make_tuple(abs(ax - ay), ax, ay) > make_tuple(abs(x - y), x, y)) {
                    ax = x;
                    ay = y;
                }
            }
        }
    }
    if (ax == -1)
        return false;
    X += ax * pw10[l - p - 1];
    Y += ay * pw10[l - p - 1];
    return true;
}

void fill(int p, char* S, llong& T, bool minimize) {
    for (int i = p + 1; i < l; i++) {
        if (S[i] != '?')
            T += (S[i] - '0') * pw10[l - i - 1];
        else if (minimize)
            T += 0;
        else
            T += 9 * pw10[l - i - 1];
    }
}

void relax() {
    if (aX == -1 || make_tuple(abs(X - Y), X, Y) < make_tuple(abs(aX - aY), aX, aY))
        aX = X, aY = Y;
}

void print(llong v) {
    char out[l + 1];
    out[l] = 0;
    int pt = l - 1;
    while (v) {
        assert(pt >= 0);
        out[pt--] = v % 10 + '0';
        v /= 10;
    }
    while (pt >= 0)
        out[pt--] = '0';
    printf(" %s", out);
}

void solve(int cs) {
    scanf("%s %s", A, B);
    l = strlen(A);
    assert(strlen(B) == l);
    aX = aY = -1;
    for (int i = 0; i < l; i++) {
        if (fill_same(i)) {
            if (fill_diff(i, true /* greater */)) {
                fill(i, A, X, true /* minimize */);
                fill(i, B, Y, false /* maximize */);
                relax();
            }
        }
        if (fill_same(i)) {
            if (fill_diff(i, false /* smaller */)) {
                fill(i, A, X, false /* maximize */);
                fill(i, B, Y, true /* minimize*/);
                relax();
            }
        }
    }
    if (fill_same(l)) {
        relax();
    }
    printf("Case #%d:", cs);
    assert(aX != -1);
    print(aX);
    print(aY);
    printf("\n");
}

int main() {
    pw10[0] = 1;
    for (int i = 1; i < N; i++)
        pw10[i] = pw10[i - 1] * 10;
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
