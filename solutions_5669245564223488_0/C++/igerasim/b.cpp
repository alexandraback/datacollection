#include <iostream>
#include <iomanip>
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

int T, N;
string s[128];

bool unistr(string s1) {
    char ch = s1.front();
    for (string::iterator it = s1.begin(); it != s1.end(); ++it)
        if (*it != ch) return false;
    return true;
}

ll factor(ll cnt1) {
    ll res = 1;
    for (ll i = 2; i <= cnt1; ++i) {
        res *= i;
    }
    return res;
}

struct comp {
    list<string> lst;
    set<char> chars;

    bool add(string s1) {
        if (lst.empty()) {
            lst.push_back(s1); return true;
        } else if (lst.back().back() == s1.front()) {
            lst.push_back(s1); return true;
        } else if (lst.front().front() == s1.back()) {
            lst.push_front(s1); return true;
        }
        return false;
    }
    
    void init_chars() {
        if (chars.empty()) {
            for (list<string>::iterator it = lst.begin(); it != lst.end(); ++it) {
                chars.insert(it->begin(), it->end());
            }
        }
    }

    bool intersect(comp& x) {
        init_chars();
        x.init_chars();
        for (set<char>::iterator it = chars.begin(); it != chars.end(); ++it) {
            if (x.chars.find(*it) != x.chars.end()) {
                return true;
            }
        }
        return false;
    }

    bool valid() {
        string s1;
        for (list<string>::iterator it = lst.begin(); it != lst.end(); ++it) {
            s1 += *it;
        }
        s1.erase(unique(s1.begin(), s1.end()), s1.end());
        int size1 = s1.size();
        sort(s1.begin(), s1.end());
        s1.erase(unique(s1.begin(), s1.end()), s1.end());
        return s1.size() == size1;
    }

    ll count() {
        ll res = 1;
        for (list<string>::iterator it = lst.begin(); it != lst.end();) {
            if (it->front() == it->back()) {
                ll cnt1 = 1;
                list<string>::iterator jt = it; 
                for (++jt; jt != lst.end(); ++jt, ++cnt1) {
                    if (it->back() != jt->back()) {
                        goto loop1;
                    }
                }
loop1: {}       
                it = jt;
                res *= factor(cnt1);
            }
            else {
                ++it;
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    cin >> dec >> T;
    for (int t = 0; t != T; ++t) {
        cout << "Case #" << (t + 1) << ": ";
        cin >> N;
        for (int n = 0; n != N; ++n)
            cin >> s[n];
        list<string> lst(s, s + N);
        list<comp> cmps;
        while (!lst.empty()) {
            cmps.push_back(comp());
            again1: for (list<string>::iterator it = lst.begin(); it != lst.end(); ++it) {
                if (unistr(*it) && cmps.back().add(*it)) {
                    lst.erase(it);
                    goto again1;
                }
            }
            again2: for (list<string>::iterator it = lst.begin(); it != lst.end(); ++it) {
                if (cmps.back().add(*it)) {
                    lst.erase(it);
                    goto again2;
                }
            }
        }
        bool ok = true;
        for (list<comp>::iterator it = cmps.begin(); ok && it != cmps.end(); ++it) {
            if (!it->valid()) ok = false;
            else {
                list<comp>::iterator jt = it;
                for (++jt; ok && jt != cmps.end(); ++jt) {
                    ok = !it->intersect(*jt);
                }
            }
        }
        if (ok) {
            ll res = factor(cmps.size());
            for (list<comp>::iterator it = cmps.begin(); ok && it != cmps.end(); ++it) {
                res *= it->count();
            }
            cout << res << "\n"; 
        } else {
            cout << 0 << "\n"; 
        }
    }
    return 0;
}
