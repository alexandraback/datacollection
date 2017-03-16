#include <iostream>
using namespace std;

const int N = 1000001;
const int M = (1 << 10) - 1;
int ans[N];

int get_mask(int x) {
    int mask = 0;
    do {
        mask |= 1 << (x % 10);
        x /= 10;
    } while (x);
    return mask;
}

int calc(int x) {
    int t = 0;
    int mask = 0;
    while (mask != M) {
        t += x;
        mask |= get_mask(t);
    }
    return t;
}

int main() {

    int T, Case = 1;
    cin >> T;
    int x;
    while (T--) {
        int ans = 0;
        cin >> x;
        if (x > 0) ans = calc(x);
        cout << "Case #" << Case++ << ": ";
        if (ans == 0) cout << "INSOMNIA" << endl;
        else cout << ans << endl;
    }
    return 0;
}
