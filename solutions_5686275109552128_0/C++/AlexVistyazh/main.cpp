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

int n, p[1111];

bool can(int x, int cnt) {
    int rem = x - cnt;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += (p[i] + rem - 1) / rem - 1;
    return sum <= cnt;
}

bool foo(int x) {
    for (int cnt = 0; cnt < x; cnt++) {
        if (can(x, cnt)) return true;
    }
    return false;
}

void solve(int tc) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    int l = 0, r = 1010;
    while (r - l > 1) {
        int mid = (l + r + 1) >> 1;
        if (foo(mid)) r = mid;
        else l = mid;
    }
    cout << "Case #" << tc << ": " << r << "\n";
}

int main()
{
    srand(time(0));
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;

    cin >> T;

    for (int i = 1; i <= T; i++)
        solve(i);

    return 0;
}
