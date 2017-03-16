#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair


int solve(int N, int M, int K)
{
    if (N > M) swap(N, M);

    int ret = 0;
    if (N <= 2) {
        ret = K;
    }
    else if (N == 3) {
        if (K <= 4) ret = K;
        else if (K <= 7) ret = K - 1;
        else if (K <= 10){
            ret = K - 2;
            if (M == 3) ++ret;
        }
        else if (K <= 13) {
            ret = K - 3;
            if (M == 4) ++ret;
        }
        else if (K <= 16) {
            ret = K - 4;
            if (M == 5) ++ret;
        }
        else if (K <= 18) {
            ret = K - 4;
        }
    }
    else if (N == 4) {
        if (K <= 4) ret = K;
        else {
            if (K <= 7) ret = K - 1;
            else if (K <= 9) ret = K - 2;
            else if (K <= 11) ret = K - 3;
            else
            {
                if (M == 4) {
                    ret = K - 4;
                }
                else {
                    if (K <= 13) ret = K - 4;
                    else if (K <= 15) ret = K - 5;
                    else ret = K - 6;
                }
            }
        }
    }
    return ret;
}


int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    // FOR(n, 1, 5){
    //     int m = n;
    //     while(m * n <= 20) {
    //         cout << "(m,n) = " << m << ", " << n << endl;
    //         FOR(k, 1, n*m+1) {
    //             cout << "  k " << k << ": " << solve(n, m, k) << endl;
    //         }
    //         ++m;
    //     }
    // }
    

    for(int test = 0; test < TEST_NUM; ++test){
        int N, M, K;
        cin >> N >> M >> K;

        int ret = solve(N, M, K);

        cout << "Case #" << (test+1) << ": " << ret << endl;
    }

    return 0;
}
