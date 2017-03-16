#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

template<class T> T nextInt() {
    T x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool solve() {
    int X, R, C;
    cin >> X >> R >> C;
    if ((R * C) % X != 0) return false;
    if (max(R, C) < X) return false;
    //if (min(R, C) < (X + 1) / 2) return false;
    return true;
}

int main()
{
    srand(time(0));
    freopen("D-small-attempt2.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;

    cin >> T;

    for (int i = 1; i <= T; i++)
        cout << "Case #" << i << ": " << (solve() ? "GABRIEL" : "RICHARD") << "\n";

    return 0;
}
