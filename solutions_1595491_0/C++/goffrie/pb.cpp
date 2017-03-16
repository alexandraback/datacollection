#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        int N, S, p;
        cin >> N >> S >> p;
        int total = 0;
        for (int j = 0; j < N; ++j) {
            int t;
            cin >> t;
            int a = (t - p) / 2;
            int b = t - p - a;
//            cout << j << ' ' << p << ' ' << a << ' ';
            if (a >= 0 && b >= 0) {
                if (p - a < 2) {
                    ++total;
                } else if (p - a == 2 && S > 0) {
                    ++total;
                    --S;
                }
            }
        }
        cout << total << endl;
    }
}