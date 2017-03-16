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

bool possible[6][6][6][128];

int main()
{
    int T, R, N, M, K;
    cin >> T >> R >> N >> M >> K;

    for (int i = 1; i <= 5; ++i) {
        for (int j = i; j <= 5; ++j) {
            for (int k = j; k <= 5; ++k) {
                for (int x = 0; x < 8; ++x) {
                    int p = 1;
                    if (x & 1) p *= i;
                    if (x & 2) p *= j;
                    if (x & 4) p *= k;
                    possible[i][j][k][p] = true;
                }
            }
        }
    }

    cout << "Case #1:" << endl;
    for (int i = 0; i < R; ++i) {
        int prod[7];
        for (int j = 0; j < K; ++j) {
            cin >> prod[j];
        }

        int ra = 1, rb = 1, rc = 1;
        for (int a = 1; a <= 5; ++a) {
            for (int b = a; b <= 5; ++b) {
                for (int c = b; c <= 5; ++c) {
                    bool pos = true;
                    for (int j = 0; j < K; ++j) {
                        pos &= possible[a][b][c][prod[j]];
                    }
                    if (pos) {
                        ra = a; rb = b; rc =c;
                    }
                }
            }
        }

        cout << ra << rb << rc << endl;
    }

    return 0;
}
