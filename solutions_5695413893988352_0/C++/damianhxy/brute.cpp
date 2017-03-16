#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int T;
string S1, S2;

string pad(string S, size_t sz) {
    while (S.size() < sz) {
        S = '0' + S;
    }
    return S;
}

bool can(string S, string CMP) {
    for (int a = 0; a < (int)S.size(); ++a) {
        if (S[a] != CMP[a] && CMP[a] != '?') return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int a = 1; a <= T; ++a) {
        cerr << "TC: " << a << "\n";
        cin >> S2 >> S1; // !!SWAPPED
        int mini = 1e9;
        string A1, A2;
        int lim = pow(10, S1.size());
        for (int b = 0; b < lim; ++b)
            for (int c = 0; c < lim; ++c) {
                string T1 = pad(to_string(b), S1.size()), T2 = pad(to_string(c), S1.size());
                if (can(T1, S1) && can(T2, S2) &&
                    abs(b - c) < mini) {
                    mini = abs(b - c);
                    A1 = T1;
                    A2 = T2;
                }
            }
        cout << "Case #" << a << ": " << A2 << " " << A1 << "\n"; // !!SWAPPED
    }
    return 0;
}
