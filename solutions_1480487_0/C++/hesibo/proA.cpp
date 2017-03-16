#include <iostream>
using namespace std;

#define epsi 1e-7

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int task;
    cin >> task;
    for (int t = 1; t <= task; t++) {
        int s[100], n, sum;
        sum = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> s[j];
            sum += s[j];
        }
        cout << "Case #" << t << ":";
        for (int j = 0; j < n; j++) {
            double l = 0, r = 100;
            while (r - l > epsi) {
                double mid = (l + r) / 2;
                double left = 100 - mid;
                double news = s[j] + sum * mid / 100;
                for (int k = 0; k < n; k++) {
                    if (k != j && news - s[k] > epsi) {
                        left -= (news - s[k] + epsi) * 100 / sum;
                    }
                    if (epsi > left) {
                        break;
                    }
                }
                if (left > epsi) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            printf(" %f", l);
        }
        cout << endl;
    }
    return 0;
}
