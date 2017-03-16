#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
//#include <memory>
//#include <thread>
using namespace std;


#define INF 1e+9
#define mp make_pair
#define lint long long
#define pii pair<int, int>
#define BITS 33

lint dinam[BITS + 2][2][2][2];

int main() {
    ios_base::sync_with_stdio(false);
    freopen("inp", "r", stdin);
    freopen("outp", "w", stdout);
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        lint a, b, k; cin >> a >> b >> k;
        lint sum = 0;
        memset(dinam, 0, sizeof dinam);
        dinam[0][1][1][1] = 1;
        for (int i = 0; i < BITS; i++) {
            for (int am = 0; am < 2; am++) {
                for (int bm = 0; bm < 2; bm++) {
                    for (int andm = 0; andm < 2; andm++) {
                        for (int ar = 0; ar < 2; ar++) {
                            for (int br = 0; br < 2; br++) {
                                if (am != 0 && (a & (1LL << (BITS - i - 1))) == 0 && ar == 1) continue;
                                if (andm != 0 && (k & (1LL << (BITS - i - 1))) == 0 && ar == 1 && br == 1) continue;
                                if (bm != 0 && (b & (1LL << (BITS - i - 1))) == 0 && br == 1) continue;
                                int nam = 0, nbm = 0, nandm = 0;
                                if (am != 0 && ((1 & (a >> (BITS - i - 1))) == ar)) nam += 1;
                                if (bm != 0 && ((1 & (b >> (BITS - i - 1))) == br)) nbm += 1;
                                if (andm != 0 && (1 & (k >> (BITS - i - 1))) == (br & ar)) nandm += 1;
                                dinam[i + 1][nam][nbm][nandm] += dinam[i][am][bm][andm];
                            }
                        }
                    }
                }
            }
        }
        printf("Case #%d: %lld\n", i + 1, dinam[BITS][0][0][0]);
    }
}
