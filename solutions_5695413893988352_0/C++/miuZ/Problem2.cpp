
// compile this with a compiler supporting C++11

#define USE_DEBUG
//#define USE_BIGINT
//#include "../../../Template/Common.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <random>
#include <cstdint>
#ifdef USE_BIGINT
  #include <gmpxx.h>
#endif

#ifdef USE_DEBUG
  #define DBG
#else
  #define DBG if (0)
#endif

using namespace std;

int getNumDigitsBase2(int x) {
    return x ? 32 - __builtin_clz(x) : 0;
}

int g_tenToThe[] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
};

int getNumDigitsBase10(int x) {
    int guess[33] = {
        0, 0, 0, 0, 1, 1, 1, 2, 2, 2,
        3, 3, 3, 3, 4, 4, 4, 5, 5, 5,
        6, 6, 6, 6, 7, 7, 7, 8, 8, 8,
        9, 9, 9
    };
    int digits = guess[getNumDigitsBase2(x)];
    return digits + (x >= g_tenToThe[digits]);
}

inline int getDigit(int x, int i) {
    return (x / g_tenToThe[i]) % 10;
}


int main(int argc, char **argv) {
    //cout.unsetf(ios::floatfield);
    cout.precision(10);

#if 1
    #define IN cin
#else
    ifstream IN("A-small-practice.in");
    if (!IN) {
        cerr << "Can't open input file\n";
        exit(1);
    }
#endif

    int T;
    IN >> T;
    for (int tc = 0; tc < T; ++tc) {
        string C, J;
        IN >> C >> J;

        //if (tc != 12 - 1) continue;

        DBG cerr << C << " " << J << std::endl;

        string C2, J2;

        vector<int> questDigit;
        vector<int> questWhich;

        int len = (int) C.size();
        for (int i = 0; i < len; ++i) {
            if (C[i] == '?') {
                questDigit.push_back(i);
                questWhich.push_back(0);
            }
            if (J[i] == '?') {
                questDigit.push_back(i);
                questWhich.push_back(1);
            }
        }

        int numDig = (int) questDigit.size();
        int final = g_tenToThe[numDig];

        int bestDiff = 999999;
        int bestA = 9999;
        int bestB = 9999;
        string bestC, bestJ;

        DBG cerr << "numDig = " << numDig << ", final = " << final << "\n";
        for (int i = 0; i < final; ++i) {
            C2 = C;
            J2 = J;
            for (int j = 0; j < numDig; ++j) {
                int dig = getDigit(i, j);
                if (questWhich[j] == 0) {
                    C2[questDigit[j]] = '0' + dig;
                } else {
                    J2[questDigit[j]] = '0' + dig;
                }
            }
            //DBG cerr << C2 << " " << J2 << "\n";
            int a = atoi(C2.c_str());
            int b = atoi(J2.c_str());
            int diff = abs(a - b);
            if (diff < bestDiff) {
                bestDiff = diff;
                bestA = a;
                bestB = b;
                bestC = C2;
                bestJ = J2;
            } else if (diff == bestDiff) {
                if (a < bestA) {
                    bestDiff = diff;
                    bestA = a;
                    bestB = b;
                    bestC = C2;
                    bestJ = J2;
                } else if (a == bestA) {
                    if (b < bestB) {
                        bestDiff = diff;
                        bestA = a;
                        bestB = b;
                        bestC = C2;
                        bestJ = J2;
                    }
                }
            }
        }

        cout << "Case #" << (tc + 1) << ": ";
        for (int i = 0; i < len; ++i) {
            cout << bestC[i];
        }
        cout << " ";
        for (int i = 0; i < len; ++i) {
            cout << bestJ[i];
        }
        cout << std::endl;
    }
    return 0;
}

