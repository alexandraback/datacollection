#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

string names[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector<int> ans;

bool rec(vector<int>& ar, int d) {
    int j;
    for (int i = d; i < 10; i++) {
        string s = names[i];
        for (j = 0; j < s.length(); j++) {
            if (ar[s[j] - 'A'] == 0) break;
        }
        if (j != s.length()) continue;
        for (j = 0; j < s.length(); j++) {
            ar[s[j]-'A']--;
        }
        ans.push_back(i);
        if (rec(ar, i)) return true;
        ans.pop_back();
        for (j = 0; j < s.length(); j++) {
            ar[s[j]-'A']++;
        }
    }
    int s = 0;
    for (int i = 0; i < 26; i++) {
        s += ar[i];
    }
    return (s == 0);
}

int main() {
    freopen("A-small-attempt1.in", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s; cin >> s;
        vector<int> ar(26);
        for (int i = 0; i < s.length(); i++) {
            ar[s[i] - 'A'] ++;
        }
        ans.clear();
        rec(ar, 0);
        cout << "Case #" << t << ": ";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
