


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


int T, n, K, C, S;

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
        scanf("%d %d %d", &K, &C, &S);
        printf("Case #%d: ", testcase);
        if (C * S >= K) {
            S = (K - 1) / C + 1;
            for (int k = 0; k < S; ++ k) {
                long long ans = 0;
                for (int t = k * C; t < (k + 1) * C; ++ t)
                    ans = ans * K + min(t, K - 1);
                printf("%lld%c", ans + 1, (k < S - 1 ? ' ' : '\n'));
            }
        }
        else puts("IMPOSSIBLE");
    }
    
    return 0;
}
