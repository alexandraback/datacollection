#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <string>
#include <fstream>

#include <omp.h>

using namespace std;

struct state {
    bool neg;
    long long type;
    state() : neg(false), type(1) {}
    state(long long _type) : neg(false), type(_type) {}
    state(bool _neg, long long _type) : neg(_neg), type(_type) {}
    bool operator<(const state &s) const {
        if (neg < s.neg) {
            return true;
        }
        if (neg > s.neg) {
            return false;
        }
        return type < s.type;
    }
    state operator*(const state &s) const {
        state r;
        r.neg = neg ^ s.neg;
        if (type == 1) {
            r.type = s.type;
        } else if (s.type == 1) {
            r.type = type;
        } else if (s.type == type) {
            r.neg ^= true;
            r.type = 1;
        } else if ((type == 2) && (s.type == 3)) {
            r.type = 4;
        } else if ((type == 3) && (s.type == 2)) {
            r.neg ^= true;
            r.type = 4;
        } else if ((type == 2) && (s.type == 4)) {
            r.neg ^= true;
            r.type = 3;
        } else if ((type == 4) && (s.type == 2)) {
            r.type = 3;
        } else if ((type == 3) && (s.type == 4)) {
            r.type = 2;
        } else if ((type == 4) && (s.type == 3)) {
            r.neg ^= true;
            r.type = 2;
        }
        return r;
    }
    bool operator==(const state &s) const {
        return (neg == s.neg) && (s.type == type);
    }
    bool operator!=(const state &s) const {
        return (neg != s.neg) || (s.type != type);
    }
};

ostream &operator<<(ostream &os, const state &s) {
    if (s.neg) {
        os << "-";
    }
    if (s.type == 1) {
        os << "1";
    }
    if (s.type == 2) {
        os << "i";
    }
    if (s.type == 3) {
        os << "j";
    }
    if (s.type == 4) {
        os << "k";
    }
    return os;
}

bool solve(long long L, long long X, const string &s) {
    vector<state> a(L);
    for (long long i = 0; i < L; ++i) {
        if (s[i] == 'i') {
            a[i] = state(2);
        }
        if (s[i] == 'j') {
            a[i] = state(3);
        }
        if (s[i] == 'k') {
            a[i] = state(4);
        }
    }
    state all_state;
    for (long long i = 0; i < L; ++i) {
        all_state = all_state * a[i];
    }
    state all_states[4];
    all_states[0] = state();
    for (long long i = 1; i < 4; ++i) {
        all_states[i] = all_states[i - 1] * all_state;
    }
    vector<state> prefix_states(L);
    vector<state> postfix_states(L);
    set<pair<long long, long long> > state_cache;
    state cur;
    for (long long i = 0; i < L; ++i) {
        cur = cur * a[i];
        prefix_states[i] = cur;
    }
    cur = state();
    for (long long i = L - 1; i >= 0; --i) {
        cur = a[i] * cur;
        postfix_states[i] = cur;
    }
    for (long long x1 = 0; x1 < 4; ++x1) {
        long long Xrem1 = X - x1;
        if (Xrem1 < 0) {
            break;
        }
        state l1_state = all_states[x1];
        for (long long i = 0; i < L; ++i) {
            if (l1_state == state(2)) {
                for (long long x2 = 0; x2 < 4; ++x2) {
                    long long Xrem2 = Xrem1 - x2;
                    if (Xrem2 < 0) {
                        break;
                    }
                    state l2_state = all_states[x2];
                    for (long long j = L - 1; j >= 0; --j) {
                        if (l2_state == state(4)) {
                            if ((i == 0) && (j == L - 1)) {
                                if (all_states[Xrem2 % 4] == state(3)) {
                                    return true;
                                }
                            } else if (!Xrem2) {
                                if (i <= j) {
                                    if (!state_cache.count(make_pair(i, j))) {
                                        state l3_state;
                                        for (long long k = i; k <= j; ++k) {
                                            l3_state = l3_state * a[k];
                                        }
                                        if (l3_state == state(3)) {
                                            return true;
                                        }
                                        state_cache.insert(make_pair(i, j));
                                    }
                                }
                            } else {
                                state l3_state = all_states[(Xrem2 - 1) % 4];
                                l3_state = postfix_states[i] * l3_state * prefix_states[j];
                                if (l3_state == state(3)) {
                                    return true;
                                }
                            }
                        }
                        if ((j == (L - 1)) && (i == 0)) {
                            --Xrem2;
                            if (Xrem2 < 0) {
                                break;
                            }
                        }
                        l2_state = a[j] * l2_state;
                    }
                }
            }
            if (i == 0) {
                --Xrem1;
                if (Xrem1 < 0) {
                    break;
                }
            }
            l1_state = l1_state * a[i];
        }
    }
    return false;
}

int main() {
    long long t;
    cin >> t;
    vector<long long> L(t);
    vector<long long> X(t);
    vector<string> S(t);
    for (long long i = 0; i < t; ++i) {
        cin >> L[i] >> X[i] >> S[i];
    }
    vector<bool> ans(t);
    long long solved = 0;
    #pragma omp parallel for schedule(dynamic)
    for (long long i = 0; i < t; ++i) {
        ans[i] = solve(L[i], X[i], S[i]);
        #pragma omp critical
        {
            ++solved;
            cerr << "Solved " << solved << " / " << t << endl;
        }
    }
    for (long long i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": " << (ans[i] ? "YES" : "NO") << endl;
    }
    return 0;
}
