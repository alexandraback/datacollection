#include <iostream>
#include <vector>

using namespace std;

int add_digits(int n, vector<bool> &digits) {
    int cnt = 0;
    if (n == 0) {
        cnt += !digits[0];
        digits[0] = true;
    }
    while (n) {
        cnt += !digits[n % 10];
        digits[n % 10] = true;
        n /= 10;
    }
    return cnt;
}

int solve(int n) {
    vector<bool> digits(10);
    int cnt = 0;
    for (int mul = 1; mul <= 100; ++mul) {
        cnt += add_digits(n * mul, digits);
        if (cnt == 10) {
            return n * mul;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int testCase = 0; testCase < t; ++testCase) {
        int n;
        cin >> n;
        int ans = solve(n);
        cout << "Case #" << testCase + 1 << ": ";
        if (ans == -1) {
            cout << "INSOMNIA";
        } else {
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}
