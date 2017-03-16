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
    freopen("large.in", "r", stdin);
    freopen("large.out", "w", stdout);
}

int main()
{
    initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        if (tt % 10 == 0) {
            cerr << tt << endl;
        }
        int n;
        cin >> n;
        vector<int> arr;
        int m = 0;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            arr.pb(num);
            m = max(m, num);
        }

        bool ok = false;
        int res = -1;
        for (int p = 0; p <= m && !ok; ++p) {
            for (int inter = 0; inter < p && !ok; ++inter) {
                int pp = p - inter;
                int count = 0;
                for (int i = 0; i < arr.size(); ++i) {
                    count += (arr[i] - 1) / pp;
                }
                if (count <= inter) {
                    ok = true;
                    res = p;
                    break;
                }
            }
        }
        cout << "Case #" << tt << ": " << res << endl;
    }
    
    return 0;
}
