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
template<class T> inline void checkmin(T &a, T b) { if (b < a) a = b; }
template<class T> inline void checkmax(T &a, T b) { if (b > a) a = b; }
template<class T> inline T sqr(T x) { return x*x; }
typedef pair<int, int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

#define MAX 2510
int T;
int N;
int h[MAX];


int main() {
    std::ios::sync_with_stdio(false);
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        memset(h, 0, sizeof(h));
        for (int i = 0; i < 2 * N - 1; ++i) {
            for (int j = 0; j < N; ++j) {
                int tmp;
                cin >> tmp;
                h[tmp]++;
            }
        }
        vector<int> ans;
        for (int i = 0; i < MAX; ++i) {
            if (h[i] % 2) {
                ans.push_back(i);
            }
        }
        cout << "Case #" << t << ":";
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); ++i) {
            cout << " " << ans[i];
        }
        cout << endl;
    }
    return 0;
}

