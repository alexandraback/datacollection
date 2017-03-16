


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

const int MaxN = 200;
const string digit_name[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR",
                             "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int T;
int c[MaxN], d[MaxN];
string S;

void calc(int p, char q) {
    d[p] = c[q];
    for (int k = 0; k < digit_name[p].length(); ++ k)
        c[digit_name[p][k]] -= d[p];
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
        cin >> S;
        memset(c, 0, sizeof c);
        memset(d, 0, sizeof d);
        printf("Case #%d: ", testcase);
        
        for (int k = 0; k < S.length(); ++ k)
            ++ c[S[k]];
        
        calc(0, 'Z');   
        calc(2, 'W');
        calc(4, 'U');
        calc(6, 'X');
        calc(8, 'G');
        calc(1, 'O');
        calc(3, 'R');
        calc(5, 'F');
        calc(7, 'V');
        calc(9, 'I');
        for (int k = 0; k < 10; ++ k)
            for (int t = 0; t < d[k]; ++ t)
                printf("%d", k);
        puts("");
    }
    
    return 0;
}
