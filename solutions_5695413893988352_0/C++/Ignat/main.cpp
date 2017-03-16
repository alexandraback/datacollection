#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define PRINT(x)
#define PRINT_CONT(x)
#define PRINT_MSG(x)
#endif

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
#include <iomanip>
using namespace std;


// Enlarge MSVS stack size
#pragma comment(linker, "/STACK:16777216")

#define pb push_back
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define sz(x) static_cast<int>(x.size())
typedef long long int64;

template<class T> T sqr(const T& t) {return t * t;}
template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}

void initialize()
{
    freopen("0.in", "r", stdin);
    freopen("0.out", "w", stdout);
}

bool check(const string& str, int num) {
    for (int k = 0; k < str.length(); ++k) {
        if (str[str.length() - k - 1] != '?' && str[str.length() - k - 1] != ('0' + (num % 10))) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main()
{
    initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        string strA, strB;
        cin >> strA >> strB;
        int limit = 1;
        for (int i = 0; i < strA.length(); ++i) {
            limit *= 10;
        }
        int bestDiff = limit; 
        int bestFirst = limit;
        int bestSecond = limit; 
        for (int i = 0; i < limit; ++i) {
            if (!check(strA, i)) {
                continue;
            }
            for (int j = 0; j < limit; ++j) {
                if (!check(strB, j)) {
                    continue;
                }

                int diff = abs(j - i);
                if (diff < bestDiff) {
                    bestDiff = diff;
                    bestFirst = i;
                    bestSecond = j;
                }
            }
        }

        cout << "Case #" << tt << ": " << setfill('0') << setw(strA.length()) << bestFirst << " " << setfill('0') << setw(strB.length()) << bestSecond << std::endl;
    }


    
    return 0;
}
