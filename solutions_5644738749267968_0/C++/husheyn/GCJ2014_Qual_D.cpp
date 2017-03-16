#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
double a[1000], b[1000];

int main() {
    freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> a[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        sort(a, a + N);
        sort(b, b + N);
        int ans1 = 0, p1 = 0, p2 = 0;
        while (p1 < N && p2 < N) {
            if (a[p1] > b[p2]) {
                ans1++;
                p1++;
                p2++;
            } else {
                p1++;
            }
        }
        int ans2 = 0;
        for(int i = N - 1; i >= 0; i--) {
            bool flag = 0;
            for(int j = N - 1; j >= 0; j--)
                if (b[j] > a[i]) {
                    b[j] = -1;
                    flag = 1;
                    break;
                }
            if (!flag) ans2++;
        }
        cout << "Case #" << t << ": " << ans1 << " " << ans2 << endl;
    }
    //system("pause");
    return 0;
}
