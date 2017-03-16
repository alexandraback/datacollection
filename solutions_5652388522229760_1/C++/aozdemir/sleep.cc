#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        bool ds [10] = {0,0,0,0,0,0,0,0,0,0};
        long N, n;
        int c = 0;
        cin >> N;
        cout << "Case #" << t << ": ";
        if (N == 0) {
            cout << "INSOMNIA" << endl;
            continue;
        }
        while (true) {
            c++;
            n = N * c;
            while (n > 0) {
                ds[n%10] = 1;
                n /= 10;
            }
            bool acc = true;
            for (bool b : ds) {
                acc = acc && b;
            }
            if (acc) {
                break;
            }
        }
        cout << N*c << endl;
    }
}
