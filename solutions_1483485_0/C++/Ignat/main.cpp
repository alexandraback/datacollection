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
    
    vector<string> initial = {
        "ejp mysljylc kd kxveddknmc re jsicpdrysi",
        "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
        "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
    vector<string> result = {
        "our language is impossible to understand",
        "there are twenty six factorial possibilities",
        "so it is okay if you want to just give up"};

    map<char, char> mapping;
    mapping['q'] = 'z';
    mapping['z'] = 'q';
    for (size_t i = 0; i < result.size(); ++i) {
        assert(result[i].length() == initial[i].length());
        for (int j = 0; j < result[i].length(); ++j) {
            char to = result[i][j];
            char from = initial[i][j];
            assert(mapping.count(from) == 0 || mapping.find(from)->second == to);
            mapping[from] = to;
        }
    }

    int T;
    cin >> T;
    string line;
    getline(cin, line);
    for (int tt = 1; tt <= T; ++tt) {
        printf("Case #%d: ", tt);
        getline(cin, line);
        for (int i = 0; i < line.length(); ++i) {
            printf("%c", mapping[line[i]]);
        }
        printf("\n");
    }
    
    return 0;
}
