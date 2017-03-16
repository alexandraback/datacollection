#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int tot;
    cin >> tot;
    for (int task = 1; task <= tot; task++) {
        long long r, t;
        cin >> r >> t;
        long long left = 0, right = t;
        while (left < right) {
            long long mid = (left + right) >> 1;
            double signal = ((double)mid + 1) * (2 * r + 1 + 2 * mid);
            if (signal > t) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        cout << "Case #" << task << ": " << left << endl;
    }
}
