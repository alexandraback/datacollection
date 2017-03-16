#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

bool Solve()
{
    int x, r, c;
    cin >> x >> r >> c;
    if (r * c % x) {
        return true;
    }
    if (r > c) {
        swap(r, c);
    }
    if (r * 2 + 1 <= x) {
        return true;
    }
    if (2 < x && r * 2 <= x) {
        return true;
    }
    return false;
}

int main(int /* argc */, char** /* argv */)
{
    assert(freopen("inp", "r", stdin));
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        cout << (Solve()? "RICHARD" : "GABRIEL") << "\n";
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
