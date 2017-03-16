#include <iostream>
#include <set>
using namespace std;

int solve(int n) {
    if (n == 0) {
        return -1;
    }

    set<int> digits;
    int cur = n;
    int count = 0;

    while (true) {
        int tmp = cur;
        while (tmp != 0) {
            digits.insert(tmp % 10);
            tmp /= 10;
        }

        if (digits.size() == 10) {
            break;
        }

        cur += n;
        count++;

        if (count >= 100) {
            cerr << "error: count too big; aborting" << endl;
            cerr << "N=" << n << "; cur=" << cur << endl;
            cerr << "digits size " << digits.size() << ": ";
            for (int d : digits) {
                cerr << d << " ";
            }
            cerr << endl;
            return -1;
        }
    }

    return cur;
}

int main() {
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int n; cin >> n;
        cout << "Case #" << i << ": ";

        int res = solve(n);
        if (res == -1) {
            cout << "INSOMNIA" << endl;
        } else {
            cout << res << endl;
        }
    }
}
