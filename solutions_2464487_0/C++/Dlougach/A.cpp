#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int T;
    cin >> T;
    for (int testNo = 1; testNo <= T; ++testNo) {
        unsigned long long r, t;
        cin >> r >> t;
        //++r;
        unsigned long long left = 0, right = min(t / (2*r + 1), (unsigned long long)1e9) + 1;
        while (right - left != 1) {
            unsigned long long mid = (left + right) / 2;
            unsigned long long val = (2 * r + 1) * mid + mid * (mid - 1) * 2;
            if (val > t) {
                right = mid;
            } else
                left = mid;
        }
        cout << "Case #" << testNo << ": " << left << endl;
    }
}

