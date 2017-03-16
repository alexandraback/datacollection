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
    freopen("0.in", "r", stdin);
    freopen("0.out", "w", stdout);
}

int64 gcd(int64 p, int64 q) {
    if (p == 0) {
        return q;
    }
    if (q == 0) {
        return p;
    }
    return gcd(q, p % q);
}

int main()
{
    initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        string str;
        cin >> str;
        int pos = str.find("/");
        str[pos] = ' ';
        istringstream is(str);

        int64 p, q;
        is >> p >> q;

        int64 d = gcd(p, q);
        p /= d;
        q /= d;
        
        int64 k = 0;
        int64 q_ = q;
        while (q_ % 2 == 0) {
            q_ /= 2;
            k += 1;
        }

        cout << "Case #" << tt << ": ";
        if (q_ > 1) {
            cout << "impossible";
        }
        else {
            while (p > 1) {
                p /= 2;
                k -= 1;
            }
            cout << k;
        }

        cout << "\n";
    }
    
    return 0;
}
