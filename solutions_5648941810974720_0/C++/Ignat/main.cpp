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

std::map<string, int> digitToNumber = {
    {"SIX", 6},
    {"ZERO", 0},
    {"EIGHT", 8},
    {"TWO", 2},
    {"FOUR", 4},
    {"SEVEN", 7},
    {"FIVE", 5}, 
    {"ONE", 1},
    {"NINE", 9},
    {"THREE", 3}
};


int main()
{
    initialize();

    vector<string> goodOrder;
    goodOrder.pb("SIX");
    goodOrder.pb("ZERO");
    goodOrder.pb("EIGHT");
    goodOrder.pb("TWO");
    goodOrder.pb("FOUR");
    goodOrder.pb("SEVEN");
    goodOrder.pb("FIVE");
    goodOrder.pb("ONE");
    goodOrder.pb("NINE");
    goodOrder.pb("THREE");

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        string str;
        cin >> str;
        std::map<char, int> counts;
        for (auto c : str) {
            counts[c] += 1;
        }

        int sum = 0;
        map<int, int> numbers;
        for (auto digit : goodOrder) {
            int r = str.length();
            for (auto c : digit) {
                r = min(r, counts[c]);
            }
            numbers[digitToNumber[digit]] += r;
            sum += r;
            for (auto c : digit) {
                counts[c] -= r;
            }
        }

        for (auto p : counts) {
            assert(p.second == 0);
        }

        string res(sum, '0');
        int pos = 0;
        for (int d = 0; d < 10; ++d) {
            for (int i = 0; i < numbers[d]; ++i) {
                res[pos++] = ('0' + d);
            }
        }

        cout << "Case #" << tt << ": " << res << "\n";
    }
    
    return 0;
}
