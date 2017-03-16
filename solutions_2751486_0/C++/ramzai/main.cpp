#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <memory>
#include <cassert>
#include <climits>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define FORD(i, a, b) for(int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) for (int (i) = 0; (i) < n; (i)++)
#define SIZE(a) (int)(a).size()
#define ALL(a) (a).begin(), (a).end()

typedef long long LL;
typedef vector<pair<int, int> > vpii;

#define DBG(x) cout << #x << " = " << x << endl
// #define DBG(x) ;
template<typename T>
void dbg_vector(const vector<T>& v, const string& name) {
    cout << name << " = ";
    REP(i, SIZE(v)) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

const string VOWELS = "aeiou";

bool is_vowel(char c) {
    return (VOWELS.find(c) != string::npos);
}

void cons_split(string& s, vpii& res, int n) {
    bool in_cons = false;
    int start = -1;
    REP(i, SIZE(s)) {
        if (is_vowel(s[i])) {
            in_cons = false;
        } else {
            if (!in_cons) {
                start = i;
            }
            in_cons = true;
            if (i - start + 1 >= n) {
                res.push_back(make_pair(i - n + 1, i));
            }
        }
    }

    /*
    REP(i, SIZE(res)) {
        cout << res[i].first << ' ' << res[i].second << endl;
    }
    */

    return;
}

LL doit(string& s, int n) {
    LL res = 0;
    vpii parts;
    cons_split(s, parts, n);

    LL arr_pos = 0;
    LL L = SIZE(s);
    REP(i, SIZE(parts)) {
        LL pos_start = parts[i].first;
        LL end_pos = parts[i].second;
        res += (pos_start - arr_pos + 1) * (L - end_pos);
        arr_pos = pos_start + 1;
    }
    return res;
}

LL doit2(string& s, int n) {
    LL res = 0;
    REP(i, SIZE(s)) {
        FOR(j, i, SIZE(s) - 1) {
            int seq_len = 0;
            FOR(k, i, j) {
                if (is_vowel(s[k])) {
                    seq_len = 0;
                } else {
                    ++seq_len;
                    if (seq_len >= n) {
                        ++res;
                        break;
                    }
                }
            }
        }
    }
    return res;
}

int main() {
    int tests;
    cin >> tests;
    REP(zzz, tests) {
        string name;
        int n;
        cin >> name >> n;
        LL res = doit(name, n);
        cout << "Case #" << zzz + 1 << ": " << res << endl;
        // LL res2 = doit2(name, n);
        // cout << "Case #" << zzz + 1 << ": " << res << ' ' << res2 << endl;
    }

    return 0;
}
