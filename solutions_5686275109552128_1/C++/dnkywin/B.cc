#include <iostream>
using namespace std;

int T, D;
int P[1000];

void solve_case(int t) {
    cout << "Case #" << t << ": ";
    cin >> D;
    for (int i=0; i < D; ++i) {
        cin >> P[i];
    }
    int best_ans = 2015;
    for (int i=1; i <= 1000; ++i) {
        int current_ans = i;
        for (int j = 0; j < D; ++j) {
            current_ans += (P[j] - 1) / i;
        }
        if (current_ans < best_ans) best_ans = current_ans;
    }
    cout << best_ans << "\n";
}

int main() {
    cin >> T;
    for (int i=1; i <= T; ++i) solve_case(i);
    return 0;
}
