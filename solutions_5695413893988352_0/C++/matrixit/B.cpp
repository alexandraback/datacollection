#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi = acos(-1.0);
const double eps = 1e-11;
template<class T> inline void checkmin(T &a, T b) { if (b<a) a = b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a = b; }
template<class T> inline T sqr(T x) { return x*x; }
typedef pair<int, int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

int min_abs = 21421267;
int a, b;
string C, J;
bool ok(int n, string &N) {
    int len = N.size();
    for (int tmp = n; tmp; tmp/=10) {
        if (--len < 0) return false;
        if (N[len] == '?') {
            continue;
        }
        if (N[len] - '0' != (tmp % 10)) {
            return false;
        }
    }
    for (; len; --len) {
        if (N[len - 1] != '?' && N[len - 1] != '0') return false;
    }
    return true;
}
int main() {
    std::ios::sync_with_stdio(false);
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> C >> J;
        min_abs = 21421267;
        for (int i = 0; i < 1000; ++i) {
            for (int j = 0; j < 1000; ++j) {
                if (ok(i, C) && ok(j, J) && abs(i-j) <= min_abs) {
                    if (abs(i - j) < min_abs || abs(i - j) == min_abs && (i < a || i == a && j < b)) {
                        min_abs = abs(i - j);
                        a = i;
                        b = j;
                    }
                }
            }
        }
        string ans_a = to_string(a);
        string ans_b = to_string(b);

        if (ans_a.size() < C.size()) {
            ans_a = string(C.size() - ans_a.size(), '0') + ans_a;
        }
        if (ans_b.size() < C.size()) {
            ans_b = string(C.size() - ans_b.size(), '0') + ans_b;
        }
        cout << "Case #" << t << ": ";
        cout << ans_a << " " << ans_b << endl;
    }
    return 0;
}

