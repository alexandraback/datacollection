#include <iostream>
#include <vector>

using namespace std;

long long getNum (int num, int K, int C) {
    long long first = num * C;
    long long ans = 0;
    for (int i = 0; i < C; i++) {
        ans *= K;
        ans += (first + i) % K;
    }
    return ans + 1;
}

vector<long long> solve() {
    int K, C, S;
    cin >> K >> C >> S;
    
    if (S * C < K)
        return vector<long long>(0);
    
    vector<long long> ans;
    for (int num = 0; num * C < K; num++) {
        ans.push_back(getNum(num, K, C));
    }
    
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        vector<long long> ans = solve();
        if (ans.size() == 0) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (int i = 0; i < ans.size(); i++)
                cout << " " << ans[i];
            cout << endl;
        }
    }
}