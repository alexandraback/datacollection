#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

char s[2222];
char cnt[256];

void dec(string s) {
    for (char c : s) {
        cnt[c]--;
    }
}

void solve() {
    scanf("%s", s);
    memset(cnt, 0, sizeof(cnt));
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    vector<int> ans;
    while (cnt['Z'] > 0) {
        ans.push_back(0);
        dec("ZERO");
    }
    while (cnt['G'] > 0) {
        ans.push_back(8);
        dec("EIGHT");
    }
    while (cnt['X'] > 0) {
        ans.push_back(6);
        dec("SIX");
    }
    while (cnt['H'] > 0) {
        ans.push_back(3);
        dec("THREE");
    }
    while (cnt['U'] > 0) {
        ans.push_back(4);
        dec("FOUR");
    }
    while (cnt['S'] > 0) {
        ans.push_back(7);
        dec("SEVEN");
    }
    while (cnt['F'] > 0) {
        ans.push_back(5);
        dec("FIVE");
    }
    while (cnt['W'] > 0) {
        ans.push_back(2);
        dec("TWO");
    }
    while (cnt['O'] > 0) {
        ans.push_back(1);
        dec("ONE");
    }
    while (cnt['N'] > 0) {
        ans.push_back(9);
        dec("NINE");
    }
    sort(ans.begin(), ans.end());
    for (int i : ans) {
        printf("%d", i);
    }
    printf("\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scid(t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }


    return 0;
}