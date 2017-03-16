#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <hash_map>
#include <string>
#include <map>
#include <set>
#include <queue>

#if 0
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
typedef int256_t lll;
typedef uint256_t ulll;
#endif

using namespace std;
using namespace std::tr1;
using namespace stdext;

typedef __int64 ll;
typedef unsigned __int64 ull;

int T;
char C[100];
char* J;

ll diff(string cc, string jj) {
    ll d = 0;
    for (int i = 0; i < cc.size(); ++i) {
        d = d * 10 + (cc[i] - jj[i]);
    }
    return d < 0 ? -d : d;
}

struct cmp {
    bool operator()(const pair<string, string>& a,
                    const pair<string, string>& b) const {

        ll d1 = diff(a.first, a.second);
        ll d2 = diff(b.first, b.second);
        if (d1 < d2) {
            return true;
        }
        if (d2 < d1) {
            return false;
        }
        for (int i = 0; i < a.first.size(); ++i) {
            if (a.first[i] != b.first[i]) return a.first[i] < b.first[i];
            if (a.second[i] != b.second[i]) return a.second[i] < b.second[i];
        }
        return false;
    }
};

pair<string , string> solve_lt(string cc, string jj, int i) {
    if (i == cc.size()) return make_pair(cc, jj);
    if (cc[i] == '?') {
        cc[i] = '9';
    }
    if (jj[i] == '?') {
        jj[i] = '0';
    }
    return solve_lt(cc, jj, i + 1);
}

pair<string , string> solve_gt(string cc, string jj, int i) {
    if (i == cc.size()) return make_pair(cc, jj);
    if (cc[i] == '?') {
        cc[i] = '0';
    }
    if (jj[i] == '?') {
        jj[i] = '9';
    }
    return solve_gt(cc, jj, i + 1);
}

pair<string , string> solve_eq(string cc, string jj, int i) {
    if (i == cc.size()) return make_pair(cc, jj);
    vector<pair<string, string> > a;
    if (cc[i] == '?' && jj[i] == '?') {
        cc[i] = jj[i] = '0';
        a.push_back(solve_eq(cc, jj, i + 1));
        cc[i] = '0'; jj[i] = '1';
        a.push_back(solve_lt(cc, jj, i + 1));
        cc[i] = '1'; jj[i] = '0';
        a.push_back(solve_gt(cc, jj, i + 1));
    } else if (cc[i] == '?') {
        cc[i] = jj[i];
        a.push_back(solve_eq(cc, jj, i + 1));
        if (jj[i] != '0') {
            cc[i] = jj[i] - 1;
            a.push_back(solve_lt(cc, jj, i + 1));
        }
        if (jj[i] != '9') {
            cc[i] = jj[i] + 1;
            a.push_back(solve_gt(cc, jj, i + 1));
        }
    } else if (jj[i] == '?') {
        jj[i] = cc[i];
        a.push_back(solve_eq(cc, jj, i + 1));
        if (cc[i] != '0') {
            jj[i] = cc[i] - 1;
            a.push_back(solve_gt(cc, jj, i + 1));
        }
        if (cc[i] != '9') {
            jj[i] = cc[i] + 1;
            a.push_back(solve_lt(cc, jj, i + 1));
        }
    } else if (cc[i] == jj[i]) {
        return solve_eq(cc, jj, i + 1);
    } else if (cc[i] < jj[i]) {
        return solve_lt(cc, jj, i + 1);
    } else {
        return solve_gt(cc, jj, i + 1);
    }

    sort(a.begin(), a.end(), cmp());
    return a.front();
}

int main(int argc, char* argv[]) {
    cin >> T;
    cin.getline(C, 99);
    for (int t = 0; t < T; ++t) {
        cout << "Case #" << (t + 1) << ": ";
        cin.getline(C, 99);
        J = C; while (*J != ' ') ++J; ++J;
        string cc(C, C + strlen(J));
        string jj(J, J + strlen(J));
        pair<string , string > a = solve_eq(cc, jj, 0);
//        cout << cc << ' ' << jj << "  =  " << a.first << ' ' << a.second << "\n";
        cout << a.first << ' ' << a.second << "\n";
    }
    return 0;
}
