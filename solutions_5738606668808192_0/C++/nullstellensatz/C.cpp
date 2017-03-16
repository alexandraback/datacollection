


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

const int MaxN = 15;

int T, n, L;
long long d[MaxN], m[MaxN];

long long div(long long t) {
    for (long long k = 3; k * k <= t; k += 2)
        if (t % k == 0) return k;
    return -1;
}

bool check(long long t) {
    memset(m, 0, sizeof m);
    for (int k = 2; k <= 10; ++ k) {
        long long tmp = t;
        while (tmp) {
            m[k] = m[k] * k + (tmp & 1);
            tmp >>= 1;
        }
        d[k] = div(m[k]);
        if (d[k] < 0) return false;
    }
    
    printf("%lld", m[10]);
    for (int k = 2; k <= 10; ++ k)
        printf(" %lld", d[k]);
    puts("");
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
        scanf("%d %d", &L, &n);
        printf("Case #%d:\n", testcase);
        long long s = (1 << (L - 1)) + 1;
        while (n) {
            if (check(s)) -- n;
            s += 2;
        }
    }
    
    return 0;
}
