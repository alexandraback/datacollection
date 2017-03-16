//#include "testlib.h"
//#include <spoj.h>

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <memory.h>
#include <set>
#include <numeric>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
//#include <unordered_map>

using namespace std;

int n;
long long diff;
string r1, r2;
string s1, s2;

void better() {
    long long v1 = atoll(s1.c_str());
    long long v2 = atoll(s2.c_str());
    if (diff > abs(v1-v2) || (diff == abs(v1-v2) && (r1 > s1 || (r1 == s1 && r2 > s2)))) {
        diff = abs(v1-v2);
        r1 = s1;
        r2 = s2;
    }
}

void brf(int pos, int eq = 0) {
    //cout << s1 << " " << s2 << " " << pos << " " << eq << "\n";
    if (pos == n) {
        better();
        return;
    }

    if (s1[pos] == '?' && s2[pos] == '?') {
        if (eq == 0) {
            s1[pos] = '1'; s2[pos] = '0';
            brf(pos+1, -1);

            s1[pos] = '0'; s2[pos] = '1';
            brf(pos+1, 1);

            s1[pos] = s2[pos] = '0';
        }
        else if (eq == -1)
            s1[pos] = '0', s2[pos] = '9';
        else
            s2[pos] = '0', s1[pos] = '9';
        brf(pos+1, eq);
        s1[pos] = s2[pos] = '?';
    }
    else if (s1[pos] == '?') {
        if (eq == -1) {
            s1[pos] = '0';
            brf(pos+1, eq);
            s1[pos] = '?';
        }
        else if (eq == 1) {
            s1[pos] = '9';
            brf(pos+1, eq);
            s1[pos] = '?';
        }
        else {
            s1[pos] = s2[pos];
            brf(pos+1, eq);
            if (s1[pos] != '9') {
                s1[pos] = s2[pos]+1;
                brf(pos+1, -1);
            }
            if (s2[pos] != '0') {
                s1[pos] = s2[pos]-1;
                brf(pos+1, 1);
            }
            s1[pos] = '?';
        }
    }
    else if (s2[pos] == '?') {
        if (eq == 1) {
            s2[pos] = '0';
            brf(pos+1, eq);
            s2[pos] = '?';
        }
        else if (eq == -1) {
            s2[pos] = '9';
            brf(pos+1, eq);
            s2[pos] = '?';
        }
        else {
            s2[pos] = s1[pos];
            brf(pos+1, eq);
            if (s1[pos] != '9') {
                s2[pos] = s1[pos]+1;
                brf(pos+1, 1);
            }
            if (s1[pos] != '0') {
                s2[pos] = s1[pos]-1;
                brf(pos+1, -1);
            }
            s2[pos] = '?';
        }
    }
    else {
        if (s1[pos] == s2[pos] || eq != 0)
            brf(pos+1, eq);
        else if (s1[pos] > s2[pos])
            brf(pos+1, -1);
        else
            brf(pos+1, 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tt;
    cin >> tt;
    for(int i = 0; i < tt; ++i) {
        cerr << i << "\n";
        cin >> s1 >> s2;
        n = s1.size();
        r1 = r2 = "";
        for(int i = 0; i < n; ++i) {
            r1 += '9';
            r2 += '0';
        }
        diff = abs(atoll(r1.c_str()) - atoll(r2.c_str()));
        cout << "Case #" << i+1 << ": ";
        brf(0);

        cout << r1 << " " << r2 << "\n";
    }

    return 0;
}
