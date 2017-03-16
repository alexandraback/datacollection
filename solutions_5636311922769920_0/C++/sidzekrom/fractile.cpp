#include <bits/stdc++.h>
using namespace std;

int main_help(int casenum) {
    long long K;
    long long C;
    long long S;
    cin >> K >> C >> S;
    long long numtries = (K / C) + (!(!(K % C)));
    if (numtries > S) {
        cout << "Case #" << casenum << ": IMPOSSIBLE" << endl;
        return 0;
    }
    vector<long long> powersofk(C+1);
    powersofk[0] = 1;
    for (int i = 1; i < C+1; i++) {
        powersofk[i] = powersofk[i-1] * K;
    }
    long long genum = 0;
    long long acc = 0;
    cout << "Case #" << casenum << ": ";
    for (int i = 0; i < S; i++) {
        genum = 0;
        for (int j = 0; j < C; j++) {
            if (acc < K) {
                genum += acc * powersofk[j];
                acc++;
            }
            else {
                cout << genum + 1 << endl;
                return 0;
            }
        }
        cout << genum + 1 << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        main_help(i+1);
    }
    return 0;
}
