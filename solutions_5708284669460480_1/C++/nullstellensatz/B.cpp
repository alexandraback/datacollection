


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
using namespace std;

const int MaxN = 105;

int T, k, l, s;
int c[MaxN];
string key, str;

bool check(int pos) {
    if (pos == str.length()) return true;
    for (int t = 0; t + pos < str.length(); ++ t)
        if (str[t] != str[t + pos]) return false;
    return true;
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
    
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        cin >> k >> l >> s;
        cin >> key >> str;
        memset(c, 0, sizeof c);
        for (int t = 0; t < key.length(); ++ t)
            ++ c[key[t] - 'A'];
        
        int ans = 0;
        for (int t = 0; t < l; ++ t)
            if (check(t + 1)) {
                ans = (s - l) / (t + 1) + 1;
                break;
            }
        double E = s - l + 1;
        if (s < l) ans = 0;
        for (int t = 0; t < str.length(); ++ t) {
            if (c[str[t] - 'A'] == 0) ans = 0;
            E *= c[str[t] - 'A'] * 1.0 / k;
        }
        
        printf("Case #%d: %.6f\n", testcase, ans - E);
    }
    
    return 0;
}
