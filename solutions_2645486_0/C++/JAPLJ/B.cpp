#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int N;
Int E, R, V[10050];

Int solve_small()
{
    Int dp[12][12] = {{}};
    dp[0][E] = 0;

    for (int i = 0; i < N; ++i) {
        for (int e = 0; e <= E; ++e) {
            for (int f = 0; f <= e; ++f) {
                chmax(dp[i + 1][min(e - f + R, E)], dp[i][e] + f * V[i]);
            }
        }
    }

    return dp[N][min(E, R)];
}

int main()
{
    int T;
    cin >> T;

    for (int CN = 1; CN <= T; ++CN) {
        cin >> E >> R >> N;
        for (int i = 0; i < N; ++i) {
            cin >> V[i];
        }

        Int res = solve_small();

        cout << "Case #" << CN << ": " << res << endl;
    }

    return 0;
}
