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

const int64 MOD = 1000000007;
vector<int64> fact;

bool isWhole(const std::string& str) {
    bool all = true;
    for (int j = 0; j + 1 < str.size(); ++j) {
        if (str[j] != str[j + 1]) {
            all = false;
        }
    }
    return all;
}

int main()
{
    initialize();

    fact.pb(1);
    for (int i = 1; i < 200; ++i) {
        fact.pb((fact.back() * i) % MOD);
    }

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        cout << "Case #" << tt << ": ";

        int n;
        cin >> n;
        vector<string> words;
        for (int i = 0; i < n; ++i) {
            string word;
            cin >> word;
            words.pb(word);
        }

        int64 mult = 1;
        
        vector<vector<string>> whole(26);
        vector<bool> wholeUsed(26);

        vector<bool> visited(n);
        for (int i = 0; i < n; ++i) {
            if (isWhole(words[i])) {
                whole[words[i][0] - 'a'].push_back(words[i]);
            } else {
                visited[i] = true;
            }
        }

        vector<string> newWords;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                newWords.pb(words[i]);
            }
        }

        words = newWords;
        bool ok = true;
        while (ok) {
            ok = false;
            for (int i = 0; i < words.size() && !ok; ++i) {
                wholeUsed[words[i].back() - 'a'] = true;
                wholeUsed[words[i].front() - 'a'] = true;
                for (int j = 0; j < words.size() && !ok; ++j) {
                    if (i == j) {
                        continue;
                    }
                    if (words[i].back() == words[j].front()) {
                        words[i] += words[j];
                        words.erase(words.begin() + j);
                        ok = true;
                    }
                }
            }
        }


        string bigString;
        int count = words.size();
        for (const auto& str : words) {
            bigString += str;
        }

        for (int i = 0; i < 26; ++i) {
            mult = (mult * fact[whole[i].size()]) % MOD;
            if (!wholeUsed[i] && !whole[i].empty()) {
                bigString += whole[i].front();
                count += 1;
            }
        }


        //cerr << "BIG STRING: " << bigString  << endl;

        bool hasSolution = true;
        for (int i = 0; i + 1 < bigString.size(); ++i) {
            if (bigString[i] == bigString[i + 1]) {
                continue;
            }
            for (int j = i + 2; j < bigString.size(); ++j) {
                if (bigString[i] == bigString[j]) {
                    hasSolution = false;
                }
            }
        }

        if (hasSolution) {
            cout << (mult * fact[count]) % MOD << "\n";
        } else {
            cout << 0 << "\n";
        }

    }
    
    return 0;
}
