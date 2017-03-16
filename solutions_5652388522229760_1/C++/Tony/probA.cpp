
#include <iostream>
#include <string>

using namespace std;

int digit_mask(int k) {
    int mask = 0;
    while (k) {
        mask |= 1 << (k % 10);
        k /= 10;
    }
    return mask;
}

string solve(int n) {
    int m = 0;
    int mask = 0;
    for (int i = 0; i < 1000; i++) {
        m += n;
        mask |= digit_mask(m);
        if (mask == 1023)
            return to_string(m);
    }
    return "INSOMNIA";
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        cout << "Case #" << t << ": " << solve(n) << endl;
    }
}
