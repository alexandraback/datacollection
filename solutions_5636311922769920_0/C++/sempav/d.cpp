#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long ceildiv(long long a, long long b) {
    long long res = a / b;
    if (a % b != 0) {
        res++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int testCase = 1; testCase <= t; ++testCase) {
        long long k, c, s;
        cin >> k >> c >> s;
        cout << "Case #" << testCase << ":";
        if (s < ceildiv(k, c)) {
            cout << " IMPOSSIBLE";
        } else {
            int total = 0;
            vector<long long> ans;
            for (int iter = 0; iter < ceildiv(k, c); ++iter) {
                long long mul = 1;
                long long pos = 0;
                for (long long i = iter * c; i < iter * c + c && total < k; ++i, ++total) {
                    pos += i * mul;
                    mul *= k;
                }
                ans.push_back(pos + 1);
            }
            sort(begin(ans), end(ans));
            cout << " " << ans[0];
            for (int i = 1; i < (int) ans.size(); ++i) {
                if (ans[i] != ans[i - 1]) {
                    cout << " " << ans[i];
                }
            }
        }
        cout << endl;
    }
    return 0;
}
