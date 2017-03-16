#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int k,c,s;

int main() {
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cin >> k >> c >> s;

        vector<long long> ans;
        int x = 0;
        while (x < k) {
            long long cur = 0;
            for (int i = 0; i < c; i++) {
                cur = cur * k;
                cur += min(x, k-1);
                x++;
            }
            ans.push_back(cur + 1);
        }

        cout << "Case #" << TC << ":";
        
        if (ans.size() > s) {
            cout << " IMPOSSIBLE\n";
        } else {
            for (long long a : ans) {
                cout << ' ' << a;
            }
            cout << '\n';
        }
    }
}
