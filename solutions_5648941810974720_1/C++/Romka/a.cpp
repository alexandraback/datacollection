#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

char s[2010];

void solve() {
    scanf("%s", s);
    int n = strlen(s);
    map<char, int> mm;
    forn(i, n) mm[s[i]]++;

    string res = "";
    int z = mm['Z'];
    forn(i, z) {
        mm['Z']--;
        mm['E']--;
        mm['R']--;
        mm['O']--;
        res += "0";
    }

    z = mm['W'];
    forn(i, z) {
        mm['T']--;
        mm['W']--;
        mm['O']--;
        res += "2";
    }

    z = mm['U'];
    forn(i, z) {
        mm['F']--;
        mm['U']--;
        mm['R']--;
        mm['O']--;
        res += "4";
    }

    z = mm['X'];
    forn(i, z) {
        mm['S']--;
        mm['I']--;
        mm['X']--;
        res += "6";
    }

    z = mm['G'];
    forn(i, z) {
        mm['G']--;
        mm['E']--;
        mm['I']--;
        mm['H']--;
        mm['T']--;
        res += "8";
    }

    z = mm['H'];
    forn(i, z) {
        mm['E']-=2;
        mm['R']--;
        mm['H']--;
        mm['T']--;
        res += "3";
    }

    z = mm['O'];
    forn(i, z) {
        mm['E']--;
        mm['O']--;
        mm['N']--;
        res += "1";
    }

    z = mm['F'];
    forn(i, z) {
        mm['F']--;
        mm['I']--;
        mm['V']--;
        mm['E']--;
        res += "5";
    }

    z = mm['I'];
    forn(i, z) {
        mm['N']-=2;
        mm['I']--;
        mm['E']--;
        res += "9";
    }

    z = mm['S'];
    forn(i, z) {
        mm['E']-=2;
        mm['S']--;
        mm['V']--;
        mm['N']--;
        res += "7";
    }

    for (const auto& p : mm)
        assert(p.second == 0);

    sort(res.begin(), res.end());
    printf("%s\n", res.c_str());

}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int q = 1; q <= tc; q++) {
        printf("Case #%d: ", q);
        solve();
    }
    return 0;
}
