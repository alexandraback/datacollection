#include <bits/stdc++.h>

using namespace std;

string Solve(const string &s) {
    string ans;
    deque<char> d;
    d.push_back(s[0]);
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] < d.front()) {
            d.push_back(s[i]);
        } else {
            d.push_front(s[i]);
        }
    }
    while (!d.empty()){
        ans += d.front();
        d.pop_front();
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    size_t t;
    cin >> t;
    for (size_t i = 1; i<= t; ++i) {
        string s;
        cin >> s;
        cout << "Case #" << i << ": " << Solve(s) << endl;
    }
    return 0;
}
