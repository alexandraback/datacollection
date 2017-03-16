#include <iostream>
#include <string>

using namespace std;

int solve(int N, string S) {
    int res = 0;
    int k = 0;
    for (int i = 0; i <= N; ++i) {
        if (k < i) {
            res += i - k;
            k = i;
        }
        k += (S[i] - '0');
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int testId = 1; testId <= T; ++testId) {
        int N;
        string S;
        cin >> N >> S;
        cout << "Case #" << testId << ": " << solve(N, S) << "\n";
    }
    return 0;
}

