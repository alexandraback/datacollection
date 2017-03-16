#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>
#include <limits>
#include <tuple>
#include <complex>


using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = acos(-1.0l);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------


vector<string> f = {"ZERO", "TWO", "FOUR", "SIX", "EIGHT"};
vector<string> f2 = {"FIVE", "SEVEN"};
vector<string> f3 = {"ONE", "THREE", "NINE"};

map<string, int> w2n = {
        mp("ZERO", 0),
        mp("ONE", 1),
        mp("TWO", 2),
        mp("THREE", 3),
        mp("FOUR", 4),
        mp("FIVE", 5),
        mp("SIX", 6),
        mp("SEVEN", 7),
        mp("EIGHT", 8),
        mp("NINE", 9)
};

int main() {

#ifdef LOCAL
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif


    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        string s;
        cin >> s;

        int cnt[26];
        fill(cnt, cnt + 26, 0);

        for (char c : s) {
            cnt[c - 'A']++;
        }

        vector<int> ans;

        auto process = [&](const vector<string> &p) {
            while (true) {
                bool any = false;
                for (auto x : p) {
                    bool good = true;
                    for (char c : x) {
                        cnt[c - 'A']--;
                        good &= cnt[c - 'A'] >= 0;
                    }
                    if (good) {
                        any = true;
                        ans.pb(w2n[x]);
                        continue;
                    }
                    for (char c : x) {
                        cnt[c - 'A']++;
                    }
                }
                if (!any) {
                    break;
                }
            }
        };

        process(f);
        process(f2);
        process(f3);

        sort(ans.begin(), ans.end());

        cout << "Case #" << tt << ": ";
        for (int x : ans) {
            cout << x;
        }
        cout << endl;
    }



    return 0;
}
