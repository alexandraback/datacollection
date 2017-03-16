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
#include <unordered_set>
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

int main()
{
    initialize();

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        cerr << "TEST: " << tt << endl;
        int n;
        cin >> n;
        vector<pair<string, string>> topics;
        for (int i = 0; i < n; ++i) {
            string a, b;
            cin >> a >> b;
            topics.pb(mp(a, b));
        }

        int res = 0;
        for (int mask = 0; mask < (1 << topics.size()); ++mask) {
            int r = 0;
            std::unordered_set<string> first, second;
            for (int i = 0; i < topics.size(); ++i) {
                if ((mask & (1 << i)) == (1 << i)) {
                    r += 1;
                } else {
                    first.insert(topics[i].first);
                    second.insert(topics[i].second);
                }
            }

            bool ok = true;
            for (int i = 0; i < topics.size(); ++i) {
                if ((mask & (1 << i)) == (1 << i)) {
                    if (first.find(topics[i].first) == first.end() || second.find(topics[i].second) == second.end()) {
                        ok = false;
                        break;
                    }
                }
            }
            //cerr << "MASK: " << mask << ", OK: " << ok << endl;
            if (ok) {
                res = max(res, r);
            }
        }

        //int res = 0;
        //std::sort(all(topics));
        //do {
        //    int r = 0;
        //    std::unordered_set<string> first, second;
        //    for (const auto& topic : topics) { 
        //        if (first.find(topic.first) != first.end() && second.find(topic.second) != second.end()) {
        //            r += 1;
        //        }
        //        first.insert(topic.first);
        //        second.insert(topic.second);
        //    }
        //    res = max(res, r);
        //} while (next_permutation(all(topics)));

        cout << "Case #" << tt << ": " << res << endl;
    }
    
    return 0;
}
