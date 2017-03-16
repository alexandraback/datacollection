#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int K, L, S;
string sk, sl;

int max_occur;
int give_away;

string state(100, ' ');

void check() {
    int occur = 0;
    for (int i = 0; i <= S - L; i++) {
        if (state.substr(i, L) == sl) {
            occur++;
            give_away++;
        }
    }
    if (max_occur < occur) {
        max_occur = occur;
    }
}

void search(int depth) {
    if (depth >= S) {
        check();
        return;
    }

    for (int i = 0; i < K; i++) {
        state[depth] = sk[i];
        search(depth + 1);
    }
}

double solve() {
    max_occur = 0;
    give_away = 0;
    search(0);

    int total = 1;
    for (int i = 0; i < S; i++) {
        total *= K;
    }
    // cout << give_away << ' ' << max_occur << ' ' << total << endl;
    return (double)max_occur - (double)give_away / (double)total;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cin >> K >> L >> S;
        cin >> sk;
        cin >> sl;
        double ans = solve();


        cout.precision(10);
        cout << "Case #" << testcase << ": ";
        cout << ans;
        cout << endl;
    }
    return 0;
}
