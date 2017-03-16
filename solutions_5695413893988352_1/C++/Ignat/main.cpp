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
    freopen("large.in", "r", stdin);
    freopen("large.out", "w", stdout);
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

int64 fill(const string& str, int pos, char c) {
    string newStr = str;
    for (int i = pos; i < str.size(); ++i) {
        if (newStr[i] == '?') {
            newStr[i] = c;
        }
    }

    int64 res = 0;
    for (int i = 0; i < str.size(); ++i) {
        res = res * 10 + (newStr[i] - '0');
    }
    return res;
}

int main()
{
    initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        cerr << "TEST: " << tt << endl;
        string strA, strB;
        cin >> strA >> strB;

        vector<pair<int64, int64>> solutions;

        bool breaked = false;
        int n = strA.length();
        for (int i = 0; i < n; ++i) {
            if (strA[i] != '?' && strB[i] != '?') {
                if (strA[i] == strB[i]) {
                    continue;
                }
                if (strA[i] > strB[i]) {
                    solutions.pb(mp(fill(strA, i, '0'), fill(strB, i, '9')));
                } else {
                    solutions.pb(mp(fill(strA, i, '9'), fill(strB, i, '0')));
                }
                breaked = true;
                break;
            } else if (strA[i] == '?' && strB[i] == '?') {
                strA[i] = '0';
                strB[i] = '1';
                solutions.pb(mp(fill(strA, i + 1, '9'), fill(strB, i + 1, '0')));
                strA[i] = '1';
                strB[i] = '0';
                solutions.pb(mp(fill(strA, i + 1, '0'), fill(strB, i + 1, '9')));

                strA[i] = '0';
                strB[i] = '0';
            } else if (strA[i] == '?') {
                for (int diff = -1; diff <= 1; diff += 2) {
                    int num = strB[i] - '0' + diff;
                    if (num < 0 || num >= 10) {
                        continue;
                    }
                    strA[i] = '0' + num;
                    if (diff < 0) {
                        solutions.pb(mp(fill(strA, i + 1, '9'), fill(strB, i + 1, '0')));
                    } else {
                        solutions.pb(mp(fill(strA, i + 1, '0'), fill(strB, i + 1, '9')));
                    }
                }
                strA[i] = strB[i];
            } else {
                for (int diff = -1; diff <= 1; diff += 2) {
                    int num = strA[i] - '0' + diff;
                    if (num < 0 || num >= 10) {
                        continue;
                    }
                    strB[i] = '0' + num;
                    if (diff < 0) {
                        solutions.pb(mp(fill(strA, i + 1, '0'), fill(strB, i + 1, '9')));
                    } else {
                        solutions.pb(mp(fill(strA, i + 1, '9'), fill(strB, i + 1, '0')));
                    }
                }
                strB[i] = strA[i];
            }
        }

        if (!breaked) {
            solutions.pb(mp(fill(strA, n, '0'), fill(strB, n, '0')));
        }

        int64 INF = (int64)1e18;
        auto bestRes = mp(INF, mp(INF, INF));
        for (int i = 0; i < solutions.size(); ++i) {
            int64 a = solutions[i].first;
            int64 b = solutions[i].second;
            auto res = mp(abs(a - b), mp(a, b));
            bestRes = min(bestRes, res);
        }

        cout << "Case #" << tt << ": " << setfill('0') << setw(strA.length()) << bestRes.second.first << " " << setfill('0') << setw(strB.length()) << bestRes.second.second << std::endl;
    }



    return 0;
}
