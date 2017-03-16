#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> solve() {
    int n;
    cin >> n;
    map<int,int> freq;
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            freq[x]++;
        }
    }
    vector<int> ans;
    for (map<int,int>::iterator it = freq.begin(); it != freq.end(); it++) {
        if (it->second % 2 == 1)
            ans.push_back(it->first);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ":";
        vector<int> v = solve();
        for (int j = 0; j < v.size(); j++) {
            cout << " " << v[j];
        }
        cout << endl;
    }
}