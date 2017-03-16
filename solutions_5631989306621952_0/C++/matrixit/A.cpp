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


int T;
string S;

int main() {
    std::ios::sync_with_stdio(false);
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> S;
        string ans;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] >= ans[0]) {
                ans = S.substr(i, 1) + ans;
            }
            else {
                ans.push_back(S[i]);
            }
        }
        cout << "Case #" << t << ": ";
        cout << ans << endl;
    }
    return 0;
}

