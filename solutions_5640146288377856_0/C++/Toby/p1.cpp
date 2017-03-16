#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, W;

int solve() {
    int first = C / W;
    if (first == 0) {
        first = 1;
    }
    first *= R;

    int second;
    if (C % W == 0) {
        second = W - 1;
    } else {
        second = W;
    }

    return first + second;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cin >> R >> C >> W;

        int ans = solve();


        cout << "Case #" << testcase << ": ";
        cout << ans;
        cout << endl;
    }
    return 0;
}
