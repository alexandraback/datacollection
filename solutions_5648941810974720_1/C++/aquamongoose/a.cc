#include <bits/stdc++.h>
using namespace std;

const string words[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    for (int cas=1; cas<=cases; cas++) {
        cout << "Case #" << cas << ": ";
        vector<int> counts(256);
        string s; cin >> s;
        for (int i=0; i<s.size(); i++)
            counts[s[i]]++;
        string ans;
        while (counts['Z'] > 0) {
            ans += '0';
            for (int i=0; i<words[0].size(); i++) {
                counts[words[0][i]]--;
            }
        }
        while (counts['X'] > 0) {
            ans += '6';
            for (int i=0; i<words[6].size(); i++) {
                counts[words[6][i]]--;
            }
        }
        while (counts['G'] > 0) {
            ans += '8';
            for (int i=0; i<words[8].size(); i++) {
                counts[words[8][i]]--;
            }
        }
        while (counts['W'] > 0) {
            ans += '2';
            for (int i=0; i<words[2].size(); i++) {
                counts[words[2][i]]--;
            }
        }
        while (counts['U'] > 0) {
            ans += '4';
            for (int i=0; i<words[4].size(); i++) {
                counts[words[4][i]]--;
            }
        }
        while (counts['H'] > 0) {
            ans += '3';
            for (int i=0; i<words[3].size(); i++) {
                counts[words[3][i]]--;
            }
        }
        while (counts['S'] > 0) {
            ans += '7';
            for (int i=0; i<words[7].size(); i++) {
                counts[words[7][i]]--;
            }
        }
        while (counts['O'] > 0) {
            ans += '1';
            for (int i=0; i<words[1].size(); i++) {
                counts[words[1][i]]--;
            }
        }
        while (counts['V'] > 0) {
            ans += '5';
            for (int i=0; i<words[5].size(); i++) {
                counts[words[5][i]]--;
            }
        }
        while (counts['I'] > 0) {
            ans += '9';
            for (int i=0; i<words[9].size(); i++) {
                counts[words[9][i]]--;
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans << '\n';
    }
    return 0;
}
