#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int tests; cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int J, P, S, K; cin >> J >> P >> S >> K;
        cout << "Case #" << test << ": " << J * P * min(S, K) << "\n";
        if (P <= K) {
            for (int j = 1; j <= J; ++j)
                for (int p = 1; p <= P; ++p)
                    for (int s = 1; s <= min(S, K); ++s)
                        cout << j << " " << p << " " << s << "\n";
            continue;
        }

        // now the easy(hard) case
        S = P;
        for (int j = 1; j <= J; ++j)
            for (int p = 1; p <= P; ++p)
                for (int s = p + (j - 1); s < p + (j - 1) + K; ++s)
                    cout << j << " " << p << " " << (s - 1) % S + 1 << "\n";
    }
}
