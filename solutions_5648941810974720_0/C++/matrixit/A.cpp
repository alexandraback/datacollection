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

string S;
const char *D[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
void sub(int cnt[], int digit, int times) {
    for (int i = 0; D[digit][i]; ++i) {
        cnt[D[digit][i]] -= times;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> S;
        int cnt[256];
        memset(cnt, 0, sizeof(cnt));
        for (auto c : S) {
            cnt[c]++;
        }
        int ans[10];
        memset(ans, 0, sizeof(ans));
        ans[0] = cnt['Z'];
        sub(cnt, 0, ans[0]);
        ans[2] = cnt['W'];
        sub(cnt, 2, ans[2]);
        ans[4] = cnt['U'];
        sub(cnt, 4, ans[4]);
        ans[6] = cnt['X'];
        sub(cnt, 6, ans[6]);
        ans[8] = cnt['G'];
        sub(cnt, 8, ans[8]);

        ans[1] = cnt['O'];
        sub(cnt, 1, ans[1]);
        ans[3] = cnt['R'];
        sub(cnt, 3, ans[3]);
        ans[5] = cnt['F'];
        sub(cnt, 5, ans[5]);
        ans[7] = cnt['S'];
        sub(cnt, 7, ans[7]);


        ans[9] = cnt['I'];
        sub(cnt, 9, ans[9]);
        cout << "Case #" << t << ": ";

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < ans[i]; ++j) {
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}

