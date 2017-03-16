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
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
}

int mult(int x, int y) {
    int sign = 1;
    if (x < 0) {
        x = -x;
        sign *= -1;
    }
    if (y < 0) {
        y = -y;
        sign *= -1;
    }
    if (x == 1) return sign * y;
    if (y == 1) return sign * x;
    if (x == y) return -1 * sign;
    
    if (x == 2 && y == 3) {
        return 4 * sign;
    }
    if (x == 2 && y == 4) {
        return -3 * sign;
    }
    if (x == 3 && y == 2) {
        return -4 * sign;
    }
    if (x == 3 && y == 4) {
        return 2 * sign;
    }
    if (x == 4 && y == 2) {
        return 3 * sign;
    }
    if (x == 4 && y == 3) {
        return -2 * sign;
    }
    assert(false);
}

map<char, int> charToInt = {{'1', 1}, {'i', 2}, {'j', 3}, {'k', 4}};

int main()
{
    initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        int l, x;
        cin >> l >> x;
        string str;
        cin >> str;

        string resultStr = "";
        for (int i = 0; i < x; ++i) {
            resultStr += str;
        }

        int value = 1;
        int cur = 2;
        for (int i = 0; i < resultStr.size(); ++i) {
            value = mult(value, charToInt[resultStr[i]]);
            if (cur < 4 && value == cur) {
                cur += 1;
                value = 1;
            }
        }

        string res = (cur == 4 && value == 4) ? "YES" : "NO";
        cout << "Case #" << tt << ": " << res << endl;
    }
    
    return 0;
}
