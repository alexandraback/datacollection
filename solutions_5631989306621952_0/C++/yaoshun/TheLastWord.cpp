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
    string s;
    cin >> s;
    string res;
    for (int i = 0; i < s.size(); i++) {
        if(res.empty() || s[i] >= res[0]) {
            res.insert(0, 1, s[i]);
        } else {
            res.push_back(s[i]);
        }
    }
    cout << res << endl;
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
