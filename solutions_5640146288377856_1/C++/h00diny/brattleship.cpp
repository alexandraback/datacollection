#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int R, C, W;
        cin >> R >> C >> W;
        int result = R * (C / W) + W - 1;

        if (C % W > 0) result++;

        cout << "Case #" << t << ": " << result << endl;
    }

    return 0;
}
