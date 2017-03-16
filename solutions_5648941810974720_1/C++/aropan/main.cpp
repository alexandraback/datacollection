#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>

using namespace std;

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

const string C[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

set <string> hs;

int perm[10] = {6, 8, 0, 7, 5, 4, 3, 2, 9, 1};

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        hs.clear();
        map <char, int> s;
        {
            string c;
            //c = "";
            //for (int i = 0; i < 50; ++i) {
                //c += C[rand() % 10];
            //}
            //cerr << c.size() << endl;
            cin >> c;
            for (auto& i : c) {
                s[i] += 1;
            }
        }
        string answer;
        for (auto& i : perm) {
            while (true) {
                bool ok = true;
                for (auto&j : C[i]) {
                    ok &= --s[j] >= 0;
                }
                if (ok) {
                    answer += (char)(i + '0');
                    continue;
                }
                for (auto&j : C[i]) {
                    ++s[j];
                }
                break;
            }
        }
        sort(answer.begin(), answer.end());
        cout << answer;
        cout << endl;
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
