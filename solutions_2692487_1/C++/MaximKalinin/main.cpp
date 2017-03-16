#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long A;
        int N;
        cin >> A >> N;
        vector<int> s(N);
        for (int i = 0; i < N; ++i)
            cin >> s[i];
        sort(s.begin(), s.end());
        int res = N;
        int increases = 0;
        if (A > 1) {
            for (int i = 0; i < N; ++i) {
                while (A <= s[i]) {
                    A += (A-1);
                    increases++;
                }
                A += s[i];
                res = min(res, increases + N - i - 1);
            }
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}

