#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <bitset>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int)1e9;

int foo(int C, int W) {
    if (C % W == 0) return (C / W) + W - 1;
    return (C / W) + W;
}

void solve(int tc) {
    int R, C, W;
    cin >> R >> C >> W;
    cout << "Case #" << tc << ": " << foo(C, W) * R << "\n";
}

int main () {
    srand(time(0));
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);

    int T;

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        solve(tc);
    }
}
