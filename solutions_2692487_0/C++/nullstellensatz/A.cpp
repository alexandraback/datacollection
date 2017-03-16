


/*
    Prob:   Google code jam Round 1B 2013 A
    Author: peanut
    Time:   05/05/13 00:12
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

const int MaxN = 105;

int n, T, A;
int size[MaxN], op[MaxN];

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        string input_file  = string(argv[1]) + ".in",
               output_file = string(argv[1]) + ".out";
        freopen(input_file.c_str(), "r", stdin);
        freopen(output_file.c_str(), "w", stdout);
    }
    
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        scanf("%d %d", &A, &n);
        for (int k = 0; k < n; ++ k)
            scanf("%d", size + k);
        sort(size, size + n);
        memset(op, 0, sizeof op);
        
        for (int k = 0; k < n; ++ k) {
            op[k] = k > 0 ? op[k - 1] : 0;
            if (A > 1) {
                while (A <= size[k]) {
                    A += A - 1;
                    ++ op[k];
                }
                A += size[k];
            }
            else ++ op[k];
        }
        
        int ans = min(n, op[n - 1]);
        for (int k = 0; k < n; ++ k)
            ans = min(ans, op[k] + n - 1 - k);
        printf("Case #%d: %d\n", testcase, ans);
    }
    
    return 0;
}
