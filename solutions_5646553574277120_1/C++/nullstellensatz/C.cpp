


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

int T, C, D, V;
int dom[MaxN];

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
        scanf("%d %d %d", &C, &D, &V);
        for (int k = 0; k < D; ++ k)
            scanf("%d", dom + k);
        
        dom[D] = V + 1;
        int ans = 0;
        long long cnt = 0;
        for (int k = 0; k <= D; ++ k) {
            long long tmp = 0;
            while (cnt < dom[k] - 1) {
                tmp = cnt + 1;
                cnt += tmp * C;
                ++ ans;
            }
            cnt += dom[k] * C;
        }
        printf("Case #%d: %d\n", testcase, ans);
    }
    
    return 0;
}
