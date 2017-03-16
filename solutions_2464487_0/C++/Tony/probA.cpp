
#include <iostream>

using namespace std;

int solve() {
    long long r, p;
    cin >> r >> p;

    long long low = 0, high = p;
    while (low < high) {
        long long mid = (low + high + 1) / 2;
        // r + ... + (r + k) <= p
        // r + ... + (r + k) < p + 1
        if (r + r + mid <= 2 * p / (mid + 1))
            low = mid;
        else
            high = mid - 1;
    }
    return (low + 1) / 2;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
        cout << "Case #" << t << ": " << solve() << endl;
}
