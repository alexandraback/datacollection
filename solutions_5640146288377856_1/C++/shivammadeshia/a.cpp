#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int t, r, c, w;

    freopen("A-large.in", "r", stdin);
    freopen("Answers", "w", stdout);

    cin >> t;

    for(int i = 1; i <= t; i++) {
        cin >> r >> c >> w;
        if(r < c) {
            int temp = r;
            r = c;
            c = temp;
        }

        int countRow, countColumn, Count, ans = 0;
        for(int j = 1; ; j += w) {
            countRow = j - r; if(countRow < 0) countRow = 0;
            countColumn = j - c; if(countColumn < 0) countColumn = 0;

            Count = j - countRow - countColumn;
            if(Count <= 0) break;
            ans += Count;
        }
        if(c >= w && w != 1) ans = ans + 1;
        ans = ans + w - 1;
        cout << "Case #" << i << ": " << ans << "\n";
    }

    return 0;
}
