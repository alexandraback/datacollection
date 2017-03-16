#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<bool> v, bool expected_last_val) {
    if (v.size() == 0) return 0;
    if (v.back() == expected_last_val) {
        return dfs(vector<bool>(v.begin(), v.end()-1), expected_last_val);
    }
    else {
        return dfs(vector<bool>(v.begin(), v.end()-1), !expected_last_val) + 1;
    }
}

int solve(const string& s) {
    vector<bool> v;
    for (int i=0; i<s.length(); i++) {
        v.push_back(s[i] == '+');
    }
    return dfs(v, true);
}


int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T; scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
        string s; cin >> s;
        printf("Case #%d: %d\n", tc, solve(s));
    }
}