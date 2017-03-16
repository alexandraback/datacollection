//{
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define clr(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (i = 0; i < (int)(n); ++i)
#define FOR(i, n) for (i = 1; i <= (int)(n); ++i)
#define LIN(i, u) for (i = head[u]; ~i; i = nxt[i])
#define MP make_pair
#define PB push_back
#define MAX(a, b, c) max(a, max(b, c))
#define MIN(a, b, c) min(a, min(b, c))
#define all(x) (x).begin(), (x).end()
#define ls(i) (i << 1)
#define rs(i) (i << 1 | 1)
//#define pi 3.1415926
#define pi (atan(1.0) * 4)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template <class T> void CIN(T &a) { cin >> a; }
template <class T> void CIN(T &a, T &b) { cin >> a >> b; }
template <class T> void CIN(T &a, T &b, T &c) { cin >> a >> b >> c; }
template <class T> void CIN(T &a, T &b, T &c, T &d) { cin >> a >> b >> c>> d; }
template <class T> void PI(T a) { cout << a << endl; }
template <class T> void PI(T a, T b) { cout << a << " " << b << endl; }
template <class T> void PIS(T a) { cout << a << " "; }
template <class T> T abs(T a) { return a < 0 ? -a : a; }

//}

int T;
double C, F, X;

int main() {
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    cin >> T;
    int ix = 0;
    while (T--)
    {
        printf("Case #%d: ", ++ix);
        scanf("%lf%lf%lf", &C, &F, &X);
        double ans = X / 2;
        double per = 2;
        double cost = 0;
        while (cost <= ans) {
            cost += C / per;
            per += F;
            ans = min(ans, cost + X / per);
        }
        printf("%.7lf\n", ans);
    }
    return 0;
}
