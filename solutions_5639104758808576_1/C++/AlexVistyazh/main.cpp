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

void solve(int tc) {
    int smax;
    string s;
    cin >> smax >> s;
    int cur = 0;
    int res = 0;
    for (int i = 0; i <= smax; i++) {
        int cnt = s[i] - '0';
        if (cur < i) res = max(res, i - cur);
        cur += cnt;
    }
    cout << "Case #" << tc << ": " << res << "\n";
}

int main()
{
    srand(time(0));
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;

    cin >> T;

    for (int i = 1; i <= T; i++)
        solve(i);

    return 0;
}
