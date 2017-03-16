#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isvow(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void solve() { 
    
    string str;
    int n;
    cin >> str >> n;
    
    vector<int> goodEnds;

    int conseq = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (!isvow(str[i])) ++conseq;
        else conseq = 0;
        conseq = min(n,conseq);
        if (conseq == n) {
            goodEnds.push_back(i);
        }
    }

    long long ans = 0;
    for (int i = 0; i < str.size(); ++i) {
        vector<int>::iterator it = lower_bound(goodEnds.begin(), goodEnds.end(), i+n-1);
        if (it == goodEnds.end()) continue;
        ans += (str.size()-(*it));
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #"<<i+1<<": ";
        solve();
    }
}
