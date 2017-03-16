#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        long long r, t;
        cin >> r >> t;
        long long low = 1, high = 10000000000LL;
        while (low < high) {
            long long pivot = (low + high + 1)/2;
            if (2 * pivot + 2 * r - 1 <= t / pivot) {
                low = pivot;
            } else {
                high = pivot - 1;
            }
        }
        cout << "Case #" << tt << ": " << low << endl;
    }
    return 0;
}
