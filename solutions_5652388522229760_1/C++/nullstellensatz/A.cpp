


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

const int MaxN = 10;

int T, n;
bool c[MaxN];

bool check(int t) {
    while (t > 0) {
        c[t % 10] = true;
        t /= 10;
    }
    for (int k = 0; k < 10; ++ k)
        if (!c[k]) return false;
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
        scanf("%d", &n);
        if (n > 0) {
            memset(c, 0, sizeof c);
            int tmp = n;
            while (!check(tmp)) tmp += n;
            printf("Case #%d: %d\n", testcase, tmp);
        }
        else printf("Case #%d: INSOMNIA\n", testcase);
    }
    
    return 0;
}
