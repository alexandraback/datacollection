//
//  main.cpp
//  С
//
//  Created by Andrey Cherevko on 4/30/16.
//  Copyright © 2016 Andrey Cherevko. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

set <string> fset;
set <string> sset;
int n;

pair <string, string> data[20];
vector <pair <string, string> > bad;

int check () {
    bool f = true;
    for (int i = 0; i < bad.size(); i++) {
        if (fset.find(bad[i].first) != fset.end() &&
            sset.find(bad[i].second) != sset.end()) {
            continue;
        } else {
            f = false;
        }
    }
    return (f) ? (int)bad.size() : 0;
}

int main(int argc, const char * argv[]) {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int ans = 0;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> data[i].first >> data[i].second;
        }

        for (int i = 0; i < (1<<n); i++) {
            bad.clear();
            fset.clear();
            sset.clear();
            int step = i;
            for (int j = 0; j < n; j++) {
                if (step % 2 == 0) {
                    bad.push_back(data[j]);
                } else {
                    fset.insert(data[j].first);
                    sset.insert(data[j].second);
                }
                step /= 2;
            }
            if (ans > bad.size()) {
                continue;
            } else {
                int cur_ans = check();
                if (cur_ans > ans) {
                    ans = cur_ans;
                }
            }
        }

        cout << "Case #" << tt + 1 << ": " << ans << endl;
    }
    return 0;
}
