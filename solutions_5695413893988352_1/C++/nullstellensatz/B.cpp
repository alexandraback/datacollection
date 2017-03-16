


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
#include <string>
using namespace std;

int T, n;
string C, J;

bool check() {
    for (int k = 0; k < n; ++ k) {
        if (C[k] == '?' || J[k] == '?') continue;
        if (C[k] != J[k]) return false;
    }
    return true;
}

long long change(string number) {
    long long res = 0;
    for (int k = 0; k < number.length(); ++ k)
        res = res * 10 + number[k] - '0';
    return res;
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
        cin >> C >> J;
        n = C.length();
        long long ans_dist = -1;
        string ans_C = C, ans_J = J;
        if (check()) {
            ans_dist = 0;
            for (int k = 0; k < n; ++ k) {
                ans_C[k] = ans_J[k] = '0';
                if (C[k] != '?') ans_C[k] = ans_J[k] = C[k];
                if (J[k] != '?') ans_C[k] = ans_J[k] = J[k];
            }
        }
        
        for (int k = 0; k < n; ++ k) {
            // C > J
            if ((C[k] != '0' && J[k] != '9') && (C[k] == '?' || J[k] == '?' || C[k] > J[k])) {
                string tmp_C = C, tmp_J = J;
                if (tmp_J[k] == '?') {
                    if (tmp_C[k] == '?') tmp_J[k] = '0';
                    else tmp_J[k] = tmp_C[k] - 1;
                }
                if (tmp_C[k] == '?') tmp_C[k] = tmp_J[k] + 1;
                for (int t = k + 1; t < n; ++ t) {
                    if (C[t] == '?') tmp_C[t] = '0';
                    if (J[t] == '?') tmp_J[t] = '9';
                }
                long long tmp_dist = change(tmp_C) - change(tmp_J);
                if (ans_dist == -1 || ans_dist > tmp_dist) {
                    ans_C = tmp_C; ans_J = tmp_J;
                    ans_dist = tmp_dist;
                } else
                if (ans_dist == tmp_dist) {
                    if (tmp_C < ans_C || (tmp_C == ans_C && tmp_J < ans_J)) {
                        ans_C = tmp_C; ans_J = tmp_J;
                        ans_dist = tmp_dist;
                    }
                }
            }

            // C < J
            if ((C[k] != '9' && J[k] != '0') && (C[k] == '?' || J[k] == '?' || C[k] < J[k])){
                string tmp_C = C, tmp_J = J;
                if (tmp_C[k] == '?') {
                    if (tmp_J[k] == '?') tmp_C[k] = '0';
                    else tmp_C[k] = tmp_J[k] - 1;
                }
                if (tmp_J[k] == '?') tmp_J[k] = tmp_C[k] + 1;
                for (int t = k + 1; t < n; ++ t) {
                    if (C[t] == '?') tmp_C[t] = '9';
                    if (J[t] == '?') tmp_J[t] = '0';
                }
                long long tmp_dist = change(tmp_J) - change(tmp_C);
                if (ans_dist == -1 || ans_dist > tmp_dist) {
                    ans_C = tmp_C; ans_J = tmp_J;
                    ans_dist = tmp_dist;
                } else
                if (ans_dist == tmp_dist) {
                    if (tmp_C < ans_C || (tmp_C == ans_C && tmp_J < ans_J)) {
                        ans_C = tmp_C; ans_J = tmp_J;
                        ans_dist = tmp_dist;
                    }
                }
            }
                
            if (C[k] != '?' && J[k] != '?' && C[k] != J[k]) break;
            if (C[k] != '?') J[k] = C[k];
            if (J[k] != '?') C[k] = J[k];
            if (C[k] == '?' && J[k] == '?') C[k] = J[k] = '0';
        }
        
        cout << "Case #" << testcase << ": " << ans_C << " " << ans_J << endl;
    }
    
    return 0;
}
