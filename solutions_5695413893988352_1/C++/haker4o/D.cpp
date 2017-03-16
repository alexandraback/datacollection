#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int l;
string b1, b2;
string s1, s2;
ull i1, i2;

ull best = -1;

ull stol(string str) {
    istringstream ss(str);
    ull res;
    ss>>res;
    return res;
}

inline ull calc(const ull &a1, const ull &a2) {
    return (max(a1, a2) - min(a1, a2));
}

bool fail;
int diffPos, diff;

void rec(int cur) {
    if (fail) return;
    if (cur == l) {
        ull a1, a2;
        a1 = stol(s1);
        a2 = stol(s2);
        ull t = calc(a1, a2);
        if (t < best ||
            t == best && a1 < i1 ||
            t == best && a1 == i1 && a2 < i2) {

            b1 = s1;
            b2 = s2;
            best = t;
            i1 = a1;
            i2 = a2;
        }

        return;
    }

    if (cur < diffPos) {
        if (s1[cur] != '?' && s2[cur] != '?') {
            if (s1[cur] == s2[cur])
                rec(cur+1);
            else
                fail = true;
            return;
        }
        if (s1[cur] != '?') {
            s2[cur] = s1[cur];
            rec(cur+1);
            s2[cur] = '?';
        } else if (s2[cur] != '?') {
            s1[cur] = s2[cur];
            rec(cur+1);
            s1[cur] = '?';
        } else {
            s1[cur] = s2[cur] = '0';
            rec(cur+1);
            s1[cur] = s2[cur] = '?';
        }
        return;
    }

    if (cur == diffPos) {
        if (s1[cur] != '?' && s2[cur] != '?') {
            if (s1[cur] < s2[cur] && diff < 0 ||
                s1[cur] > s2[cur] && diff > 0)
                rec(cur+1);
            else
                fail = true;
            return;
        }
        if (s1[cur] != '?') {
            if (diff < 0 && s1[cur] != '9') {
                s2[cur] = s1[cur]+1;
                rec(cur+1);
                s2[cur] = '?';
            } else if (diff > 0 && s1[cur] != '0') {
                s2[cur] = s1[cur]-1;
                rec(cur+1);
                s2[cur] = '?';
            } else
                fail = true;

        } else if (s2[cur] != '?') {
            if (diff < 0 && s2[cur] != '0') {
                s1[cur] = s2[cur]-1;
                rec(cur+1);
                s1[cur] = '?';
            } else if (diff > 0 && s2[cur] != '9') {
                s1[cur] = s2[cur]+1;
                rec(cur+1);
                s1[cur] = '?';
            } else
                fail = true;

        } else {
            if (diff < 0) {
                s1[cur] = '0';
                s2[cur] = '1';
                rec(cur+1);
                s1[cur] = s2[cur] = '?';
            } else {
                s1[cur] = '1';
                s2[cur] = '0';
                rec(cur+1);
                s1[cur] = s2[cur] = '?';
            }
        }
        return;
    }

    // cur > diffPos
    if (s1[cur] != '?' && s2[cur] != '?') {
        rec(cur+1);
    } else if (s1[cur] != '?') {
        if (diff < 0) {
            s2[cur] = '0';
            rec(cur+1);
            s2[cur] = '?';
        } else {
            s2[cur] = '9';
            rec(cur+1);
            s2[cur] = '?';
        }
    } else if (s2[cur] != '?') {
        if (diff < 0) {
            s1[cur] = '9';
            rec(cur+1);
            s1[cur] = '?';
        } else {
            s1[cur] = '0';
            rec(cur+1);
            s1[cur] = '?';
        }
    } else {
        if (diff < 0) {
            s1[cur] = '9';
            s2[cur] = '0';
            rec(cur+1);
            s1[cur] = s2[cur] = '?';
        } else {
            s1[cur] = '0';
            s2[cur] = '9';
            rec(cur+1);
            s1[cur] = s2[cur] = '?';
        }
    }
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T, NT;
    int i, j;
    cin>>NT;
    for(T=1; T<=NT; ++T) {
        cin>>s1>>s2;
        l = s1.size();
        best = -1;
        for(diffPos=0; diffPos<=l; ++diffPos) {
            for(diff=-1; diff <= 1; diff += 2) {
                fail = false;
                rec(0);
            }
        }
        cout<<"Case #"<<T<<": "<<b1<<" "<<b2<<endl;
    }
    return 0;
}
