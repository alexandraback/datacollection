


/*
    Prob:   Google code jam Round 1B 2013 B
    Author: peanut
    Time:   05/05/13 01:23
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

int T, n, x, y;

inline double calc() {
    int c = abs(x) + abs(y) + 1;
    if (c * (c + 1) / 2 <= n) return 1.0;
    if ((c - 2) * (c - 1) / 2 >= n) return 0.0;
    
    if (x == 0) return 0.0;
    int m = n - (c - 2) * (c - 1) / 2, p = y + 1;
    if (m < p) return 0.0;
    if (m - (c - 1) >= p) return 1.0;
    double cnt = 1.0, ans = 0.0;
    for (int k = 1; k <= m - p; ++ k)
        cnt /= 2.0;
    for (int k = 1; k <= p; ++ k)
        cnt *= (k + m - p) * 1.0 / (k * 1.0) / 2.0;
    for (int k = p; k <= m; ++ k) {
        ans += cnt;
        cnt *= ((m - k) * 1.0) / ((k + 1) * 1.0);
    }
    return ans;
}

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        string input_file  = string(argv[1]) + ".in",
               output_file = string(argv[1]) + ".out";
        freopen(input_file.c_str(), "r", stdin);
        freopen(output_file.c_str(), "w", stdout);
    }
    
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        scanf("%d %d %d", &n, &x, &y);
        printf("Case #%d: %.8lf\n", testcase, calc());
    }
    
    return 0;
}
