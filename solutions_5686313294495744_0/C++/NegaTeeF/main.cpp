//
//  main.cpp
//  A
//
//  Created by Misha Babenko on 3/28/15.
//  Copyright (c) 2015 Misha Babenko. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <cassert>
#include <unordered_set>

using namespace std;

typedef long long ll;

int solve(vector<pair<string, string>> a) {
    int n = (int)a.size();
    for (int res = n; res >= 1; --res) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) 
                if ((mask >> i) & 1)
                    cnt++;
            if (cnt != res) continue;
            
            set<string> first;
            set<string> second;
            vector<string> first_faked;
            vector<string> second_faked;
            
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    first_faked.push_back(a[i].first);
                    second_faked.push_back(a[i].second);
                } else {
                    first.insert(a[i].first);
                    second.insert(a[i].second);
                }
            }
            
            bool ok = true;
            for (int i = 0; i < first_faked.size(); ++i) {
                if (first.find(first_faked[i]) == first.end()) {
                    ok = false;
                    break;
                }
                if (second.find(second_faked[i]) == second.end()) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) 
                return res;
        }
    }
    return 0;
}

void Test() {
//    srand(time(0));
}

int main(int argc, const char * argv[]) {
//    Test();
    int tt;
    cin >> tt;
    for (int t = 0; t < tt; ++t) {
        int n;
        cin >> n;
        vector<pair<string, string>> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        cout << "Case #" << t + 1 << ": " << solve(a) << endl;
    }
    return 0;
}
