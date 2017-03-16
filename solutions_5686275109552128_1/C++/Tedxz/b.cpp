#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_P = 1007;

int T, ans;
int a[MAX_P];
int d, p;
int spcnt, wtcnt;

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("b.txt", "w", stdout);
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        ans = MAX_P;
        memset(a, 0, sizeof a);
        spcnt = wtcnt = 0;

        cin >> d;
        while (d--) {
            cin >> p;
            ++a[p];
        }

        for (int i = 1; i < MAX_P; ++i) {
            int tmp = 0;
            for (int j = i + 1; j < MAX_P; ++j) {
                if (a[j])
                    tmp += a[j] * ((j - 1) / i);
            }
            ans = min(ans, tmp + i);
        }


        cout << "Case #" << cs << ": " << ans << endl;
    }

    return 0;
}
