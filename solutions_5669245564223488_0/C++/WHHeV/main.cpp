//
//  main.cpp
//  r13.b
//
//  Created by Zhu Haifan on 14-5-11.
//  Copyright (c) 2014年 Zhu Haifan. All rights reserved.
//

#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_map>


using namespace std;

int ans = 0;

inline bool check(string &s) {
    set<char> st;
    st.insert(s[0]);
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i-1]) {
            if (st.find(s[i]) != st.end()) {
                return false;
            }
            st.insert(s[i]);
        }
    }
    return true;
}

void dfs(vector<string> &vs, vector<bool> &flag, unordered_map<char, int> &um, char prec, int dep) {
    if (dep == 1) {
        ++ans;
        return;
    }
    for (int i = 0; i < flag.size(); ++i) {
        if (!flag[i]) {
            int j = 0;
            for (; j < vs[i].size(); ++j) {
                if (vs[i][j] != prec) {
                    break;
                }
            }
            bool connect = true;
            for (; j < vs[i].size(); ++j) {
                if (um.find(vs[i][j]) != um.end() && um[vs[i][j]] > 0) {
                    connect = false;
                    break;
                }
            }
            if (connect) {
                for (auto &c : vs[i]) {
                    ++um[c];
                }
                flag[i] = true;
                dfs(vs, flag, um, vs[i].back(), dep-1);
                flag[i] = false;
                for (auto &c : vs[i]) {
                    --um[c];
                }
            }
        }
    }
}

int main() {
    freopen("/Users/whshev/Dropbox/Programs/GCJ2014/Data/R13/B-small-attempt3.in", "r", stdin);
    freopen("/Users/whshev/Dropbox/Programs/GCJ2014/Data/R13/B-small-attempt3.out", "w", stdout);
    int T, prob=1;
    for (cin >> T; T--;) {
        int n;
        ans = 0;
        cin >> n;
        string s;
        vector<string> vs;
        vector<bool> flag(n, false);
        for (int i = 0; i < n; ++i) {
            cin >> s;
            string s1 = "1";
            s1[0] = s[0];
            for (int j = 1; j < s.size(); ++j) {
                if (s[j] != s[j-1]) {
                    s1 += s[j];
                }
            }
            vs.push_back(s1);
        }
//        int modulo = 1000000007;
        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> um{};
            bool right = true;
            for (auto &c : vs[i]) {
                if (um.find(c) != um.end()) {
                    right = false;
                    break;
                }
                ++um[c];
            }
            if (!right) {
                continue;
            }
            flag[i] = true;
            dfs(vs, flag, um, vs[i].back(), n);
            flag[i] = false;
        }
        cout << "Case #" << prob++ << ": " << ans;
        
        
        cout << endl;
    }
    return 0;
}
