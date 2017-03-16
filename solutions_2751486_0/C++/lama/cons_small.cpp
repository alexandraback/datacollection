#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;

int T;

bool is_cons(char c) {
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

int n_cons(string s) {
    vector<int> vowel_pos;
    vowel_pos.push_back(-1);
    for(int i = 0; i < s.size(); i++)
        if(!is_cons(s[i]))
            vowel_pos.push_back(i);
    vowel_pos.push_back(s.size());
    int res = 0;
    for(int i = 0; i < vowel_pos.size() - 1; i++) {
        res = max(res, vowel_pos[i + 1] - vowel_pos[i] - 1);
    }
    return res;
}

int count(string s, int n) {
    int res = 0;
    for(int i = n; i <= s.size(); i++)
        for(int j = 0; j + i <= s.size(); j++) {
            // cout << s.substr(j, i) << ": " << n_cons(s.substr(j, i)) << endl;
            res += n_cons(s.substr(j, i)) >= n;
        }
    return res;
}

int main() {
    cin >> T;

    for(int Ti = 1; Ti <= T; Ti++) {
        int n;
        string s;
        cin >> s >> n;
        cout << "Case #" << Ti << ": " << count(s, n) << endl;;
    }
}