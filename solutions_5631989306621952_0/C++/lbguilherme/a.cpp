#include <bits/stdc++.h>
using namespace std;

void solve() {
    string w;
    cin >> w;
    vector<deque<char>> words;
    for (char c : w) {
        if (words.size() == 0) {
            words.push_back({});
            words[0].push_back(c);
            continue;
        }
        int ws = words.size();
        for (int i = 0; i < ws; ++i) {
            words.push_back(words[i]);
            words[i].push_back(c);
            words[i + ws].push_front(c);
        }
    }
    string best = "";
    for (auto& dq : words) {
        string s(dq.begin(), dq.end());
        best = max(best, s);
    }
    cout << best << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Case #" << (i + 1) << ": ";
        solve();
    }
}
