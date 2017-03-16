#include <iostream>
#include <string>
#include <limits>

using namespace std;

int diff;
string result_c, result_j;

void solve(string C, string J, int idx) {
    if (idx == C.size()) {
        auto tmp = abs(stoi(C) - stoi(J));
        if (tmp > diff)
            return;

        if (tmp < diff) {
            diff = tmp;
            result_c = C;
            result_j = J;
            return;
        }

        if (C > result_c)
            return;

        if (C < result_c) {
            result_c = C;
            result_j = J;
            return;
        }

        if (result_j > J) {
            result_c = C;
            result_j = J;
            return;
        }

        return;
    }

    if (C[idx] != '?' && J[idx] != '?') {
        solve(C, J, idx+1);
        return;
    }

    if (C[idx] == '?') {
        for (char c = '0'; c <= '9'; ++c) {
            C[idx] = c;
            solve(C, J, idx);
        }
    }

    if (J[idx] == '?') {
        for (char c = '0'; c <= '9'; ++c) {
            J[idx] = c;
            solve(C, J, idx);
        }
    }
}

int main() {
    int N;
    cin >> N;

    for (int t = 1; t <= N; ++t) {
        string C, J;
        cin >> C >> J;

        result_c = result_j = "";
        diff = numeric_limits<int>::max();

        solve(C, J, 0);

        auto r = result_c + " " + result_j;

        printf("Case #%d: %s\n", t, r.data());
    }

    return 0;
}
