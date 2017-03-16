
#include <cstdint>
#include <iostream>

using namespace std;

int main() {

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {

        uint64_t N;
        cin >> N;

        uint64_t M = N;
        
        if (N > 0) {
            int k = 1;
            bool ds[10];
            int c = 0;
            for (int d = 0; d < 10; d++) ds[d] = false;
            while (c < 10) {
                uint64_t L = N*k;
                M = L;
                while (L > 0) {
                    int d = L % 10;
                    L = L / 10;
                    if (!ds[d]) {
                        ds[d] = true;
                        c ++;
                    }
                }
                k ++;
            }
        }

        cout << "Case #" << (t+1) << ": ";
        if (M == 0) {
            cout << "INSOMNIA\n";
        }
        else {
            cout << M << '\n';
        }

    }

}

