#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

int test, ll, rr, total, n;
int a[300];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cout << "Case #" << t << ": ";
        cin >> n; total = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]); total += a[i];
        }
        for (int i = 0; i < n; i++) {
            ll = 0; rr = 100000001;
            while (ll + 1 < rr) {
                int mid = (ll + rr) / 2;
                double now = double(mid) * double(total)/ 100000000, sum = 0, ty = now + a[i];
                for (int j = 0; j < n; j++) {
                    if (j != i && a[j] < ty) {
                        sum += ty - a[j];
                    }
                }
                //cout << mid << ' ' << now << ' ' << ty<< ' ' << sum << endl;
                if (sum > total - now) rr = mid; else ll = mid;
            }

            printf("%.6lf ", double(rr) / 1000000);
        }
        printf("\n");
    }
}
