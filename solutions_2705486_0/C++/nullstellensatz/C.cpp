


/*
    Prob:   Google code jam Round 1B 2013 C
    Author: peanut
    Time:   05/05/13 00:37
    Description:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

const int MaxN = 521205;
const int MaxL = 4005;

int n, T;
string words[MaxN];
string email;
int ans[MaxN][5];

inline int check(int i, int j, int &pos) {
    int cnt = 0;
    if (i + words[j].length() > n) return -1;
    for (int k = 0; k < words[j].length(); ++ k)
        if (email[i + k] != words[j][k]) {
            if (k - pos < 5) return -1;
            ++ cnt; pos = k;
        }
    return cnt;
}

int main(int argc, char* argv[]) {
    ifstream dict("C.txt");
    for (int k = 0; k < 521196; ++ k)
        dict >> words[k];
    dict.close();
    
    if (argc >= 2) {
        string input_file  = string(argv[1]) + ".in",
               output_file = string(argv[1]) + ".out";
        freopen(input_file.c_str(), "r", stdin);
        freopen(output_file.c_str(), "w", stdout);
    }
    
    cin >> T;
    for (int testcase = 1; testcase <= T; ++ testcase) {
        cin >> email;
        n = email.length();
        memset(ans, -1, sizeof ans);
        memset(ans[0], 0, sizeof ans[0]);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < 5; ++ j) {
                if (ans[i][j] < 0) continue;
                for (int k = 0; k < 521196; ++ k) {
                    int pos = j - 5, tmp = check(i, k, pos);
                    if (tmp >= 0) {
                        pos = words[k].length() - pos;
                        pos = max(0, 5 - pos);
                        int o = i + words[k].length();
                        if (ans[o][pos] < 0 || ans[o][pos] > ans[i][j] + tmp)
                            ans[o][pos] = ans[i][j] + tmp;
                    }
                }
            }
        }
        
        int answer = -1;
        for (int k = 0; k < 5; ++ k) {
            if (ans[n][k] < 0) continue;
            if (answer < 0 || answer > ans[n][k]) answer = ans[n][k];
        }
        printf("Case #%d: %d\n", testcase, answer);
    }
    
    return 0;
}
