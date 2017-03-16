#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

long long R, t;

bool check(long long k) {
    double le = (double)t / k;
    if (2*k + 2*R - 1 <= le)
        return true;
    else
        return false;
}

int main() {

    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int T, cnt = 0;
    cin >> T;

    while (T > 0) {
        cin >> R >> t;
        cout << "Case #" << ++cnt << ": ";
        long long l = 1, r = 1000000000000000000LL;
        long long res = 1;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (check(mid)) {
                res = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cout << res << endl;
        --T;
    }
}
