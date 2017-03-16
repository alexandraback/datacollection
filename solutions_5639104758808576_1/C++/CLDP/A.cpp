#include <iostream>
using namespace std;



int main() {
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        int N;
        string S;
        cin >> N >> S;
        int sum = S[0] - '0', ans = 0;
        for (int i = 1; i <= N; ++i) {
            ans = max(ans, i - sum);
            sum += S[i] - '0';
        }
        cout << "Case #" << times << ": " << ans << endl;
    }
    return 0;
}
