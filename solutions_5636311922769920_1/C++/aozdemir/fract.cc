#include <iostream>
#include "BigIntegerLibrary.hh"

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t<=T; t++) {
        cout << "Case #" << t << ":";
        int K,C,S;
        cin >> K >> C >> S;
        if (K > S * C) {
            cout << " IMPOSSIBLE" << endl;
            continue;
        }
        long d = 0;
        while (d < K) {
            BigInteger acc = 0;
            for (int count = 0; count < C; count++) {
                if (d == K) break;
                acc = acc * K + d;
                d++;
            }
            BigInteger u = 1;
            acc += u;
            cout << " " << acc;
        }
        cout << endl;
    }
}
