#include <bits/stdc++.h>

using namespace std;

const int N = 20;

map<string, int> d;

int n;

int stupid(string s) {
    int ans = 0;
    for (int i = 0, j; i < s.size(); i = j + 1) {
        j = i;
        while (j + 1 < s.size() && s[i] == s[j + 1]) ++j;
        ++ans;
    }
    if (s[s.size() - 1] == '+') --ans;
    return ans;
}


int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int ntest; cin >> ntest;
    for (int it = 1; it <= ntest; ++it) {
        string str; cin >> str;
        cout << "Case #" << it << ": " << stupid(str) << endl;
    }
    return 0;
}
