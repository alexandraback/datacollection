


/*
    Prob:
    Author: 
    Time:   
    Description:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MaxN = 1005;
int T, n;
vector<string> dict[2];
bool v[MaxN], f[MaxN][MaxN];
int b[MaxN];

bool dfs(int cur) {
    for (int k = 0; k < dict[1].size(); ++ k)
        if (f[cur][k] && !v[k]) {
            v[k] = true;
            if (b[k] < 0 || dfs(b[k])) {
                b[k] = cur;
                return true;
            }
        }
    return false;
}

int main(int argc, char* argv[]) { 
    if (argc >= 2) {
        string post = argv[1][0] == 's' ? 
                      "-small-attempt" + string(argv[2]):
                      "-large";  
        string input_file  = string(argv[0]) + post + ".in",
               output_file = string(argv[0]) + post + ".out";
        freopen(input_file.c_str(), "r", stdin);
        freopen(output_file.c_str(), "w", stdout);
    }
    
    cin >> T;
    for (int testcase = 1; testcase <= T; ++ testcase) {
        cin >> n;
        dict[0].clear(); dict[1].clear();
        memset(f, 0, sizeof f);
        for (int k = 0; k < n; ++k) {
            string tmp[2];
            cin >> tmp[0] >> tmp[1];
            int pos[2];
            for (int q = 0; q < 2; ++ q) {
                pos[q] = -1;
                for (int t = 0; t < dict[q].size(); ++ t)
                    if (tmp[q] == dict[q][t]) {
                        pos[q] = t; break;
                    }
                if (pos[q] < 0) {
                    pos[q] = dict[q].size();
                    dict[q].push_back(tmp[q]);
                }
            }
            f[pos[0]][pos[1]] = true;
        }
        
        memset(b, -1, sizeof b);
        int ans = n - (dict[0].size() + dict[1].size());
        for (int k = 0; k < dict[0].size(); ++ k) {
            memset(v, 0, sizeof v);
            if (dfs(k)) ++ ans;
        }
        printf("Case #%d: %d\n", testcase, ans);
    }
    
    return 0;
}
