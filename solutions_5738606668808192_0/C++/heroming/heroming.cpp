/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/4/9 9:33:18
 */
#include <vector>
#include <list>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

#define px first
#define py second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define clr(v, e) memset(v, e, sizeof(v))
#define rep(it, v) for (auto it : v)
#define forn(i, n) for (int i = 0; i < (n); ++ i)
#define form(i, a, b) for (int i = (a); i <= (b); ++ i)
#define forv(i, v) for (int i = 0; i < sz(v); ++ i)
#define iter(it, v) for (auto it = v.begin(); it != v.end(); ++ it)

typedef long long lint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int N = 16;
const int J = 50;
const int maxn = 12;
const int maxm = 36;

int vis[maxn];
int bit[maxm];

int prime(const lint x) {
    for (int s = 2; s * s <= x; ++ s) {
        if (x % s == 0) {
            return s;
        }
    }
    return -1;
}

bool solve(const lint x) {
    for (int i = 0; i < N; ++ i) {
        bit[N - i - 1] = (x >> i) & 1;
    }
    for (int base = 2; base <= 10; ++ base) {
        lint s = 0;
        for (int k = 0; k < N; ++ k) {
            s = s * base + bit[k];
        }
        vis[base] = prime(s);
        if (vis[base] == -1) return 0;
    }
    return 1;
}

int main() {
    freopen("heroming.out", "w", stdout);
    int cnt = 0;
    printf("Case #1:\n");
    for (lint x = 0; x < (1LL << (N - 2)); ++ x) {
        lint s = (1LL << (N - 1)) | (x << 1) | 1;
        if (solve(s)) {
            ++ cnt;
            for (int i = N - 1; i >= 0; -- i) {
                printf("%d", bit[i]);
            }
            for (int i = 2; i <= 10; ++ i) {
                printf(" %d", vis[i]);
            }
            printf("\n");
        }
        if (cnt == J) break;
    }
    return 0;
}
