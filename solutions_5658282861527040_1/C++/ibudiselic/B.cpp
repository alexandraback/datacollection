#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int MAXBITS = 32;
char A[MAXBITS], B[MAXBITS], K[MAXBITS];
void bin(int num, char *arr) {
    for (int i=0; i<MAXBITS; ++i) {
        arr[MAXBITS-1-i] = num&1;
        num /= 2;
    }
}
long long dp[MAXBITS+1][2][2][2];
long long go(int pos, bool ltA, bool ltB, bool ltK) {
    long long &ret = dp[pos][ltA][ltB][ltK];
    if (ret != -1) {
        return ret;
    }
    if (pos == MAXBITS) {
        if (ltA && ltB && ltK) {
            ret = 1;
        } else {
            ret = 0;
        }
    } else {
        ret = 0;
        int limA = (ltA ? 1 : int(A[pos]));
        int limB = (ltB ? 1 : int(B[pos]));
        int limK = (ltK ? 1 : int(K[pos]));
        for (int bA=0; bA<=limA; ++bA) {
            for (int bB=0; bB<=limB; ++bB) {
                int bK = bA & bB;
                if (bK > limK) continue;
                ret += go(pos+1, ltA||(bA<A[pos]), ltB||(bB<B[pos]), ltK||(bK<K[pos]));
            }
        }
    }
    return ret;
}
long long solve(int a, int b, int k) {
    bin(a, A);
    bin(b, B);
    bin(k, K);
    memset(dp, 0xff, sizeof dp);
    return go(0, 0, 0, 0);
}
long long solve() {
    int a, b, k;
    cin >> a >> b >> k;
    return solve(a, b, k);
}

int main() {
    /*
    for (int i=1; i<100; ++i) {
        for (int j=1; j<100; ++j) {
            for (int k=1; k<100; ++k) {
                int correct = 0;
                for (int a=0; a<i; ++a) {
                    for (int b=0; b<j; ++b) {
                        if ((a&b)<k) ++correct;
                    }
                }
                assert(correct == solve(i, j, k));
            }
        }
    }
    */
    int T;
    cin >> T;
    cerr << T << " cases total\n";
    for (int t=1; t<=T; ++t) {
        long long sol = solve();
        cout << "Case #" << t << ": " << sol << '\n';
        cerr << "Case #" << t << ": " << sol << '\n';
    }
	return 0;
}
