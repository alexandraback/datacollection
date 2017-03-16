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
        set<pair<int,int>> nums;
        int a, b;
        cin >> a >> b;
        int res = 0;
        for (int i = a; i <= b; ++i) {
            int num = i;
            int allSt = 1;
            while (allSt <= num) allSt *= 10;
            for (int st = 10; st < num; st *= 10) {
                if (num % st < st / 10) continue;
                int newNum = (num % st) * (allSt / st) + num / st;
                if (a <= newNum && newNum <= b && newNum < num) {
                    auto pair = make_pair(newNum, num);
                    if (nums.find(pair) != nums.end()) continue;
                    nums.insert(pair);
                    res += 1; 
                }
            }
        }
        cout << "Case #" << tt << ": " << res << "\n";
    }

    
    return 0;
}
