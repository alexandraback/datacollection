/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/4/9 9:17:57
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

const int maxn = 110;

char s[maxn];

int main() {
    freopen("heroming.out", "w", stdout);
    int cas;
    scanf("%d", &cas);
    form (l, 1, cas) {
        scanf("%s", s);
        int n = strlen(s);
        int cnt = 0;
        int k = 0;
        while (k < n) {
            if (s[k] == '-') ++ cnt;
            while (k < n && s[k] == '-') ++ k;
            while (k < n && s[k] == '+') ++ k;
        }
        printf("Case #%d: %d\n", l, s[0] == '-' ? (cnt << 1) - 1 : (cnt << 1));
    }
    return 0;
}
