#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
typedef long long ll;
using namespace std;

void solve() { 
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            mp[temp]++;
        }
    }

    vector<int> res;
    for (auto pair : mp) {
        if (pair.second % 2 == 1) {
            res.push_back(pair.first);
        }
    }
    sort(res.begin(), res.end());
    cout << res[0];
    for (int i = 1; i < res.size(); i++) {
        cout << " " << res[i];
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cout << "Case #" << (t + 1) << ": ";
        solve();
    }    
    return 0;
}
