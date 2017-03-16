#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define DEBUG(x)
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
    freopen("_.out", "w", stdout);
}

int main()
{
    initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        int n, s, p;
        cin >> n >> s >> p;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            if (num == 0 && p > 0) continue;
            if (num - p >= 2 * (p - 1)) res += 1;
            else if (s > 0 && num - p >= 2 * (p - 2)) res += 1, s -= 1;
        }
        printf("Case #%d: %d\n", tt, res);
    }
    
    return 0;
}
