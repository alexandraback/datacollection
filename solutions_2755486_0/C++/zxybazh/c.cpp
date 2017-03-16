#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <utility>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> PII;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef set<int> SI;
typedef long double LD;
typedef long long LL;
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
const int inf = 1073741823;
const int maxint = 0x7fffffff;
const LL  INF = 1152921504606846976ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define kep(i, n) for (int i = 1; i<= n; i++)
template <class T> inline T _sqr(T a) {return (a*a);}
template <class T> inline T _abs(T a) {return (a>=0?a:-a);}
template <class T> inline T _lbt(T a) {return (a&(a^(a-1)));}
template <class T> inline T _max(T a, T b) {return (a>b?a:b);}
template <class T> inline T _min(T a, T b) {return (a<b?a:b);}
template <class T> inline T _smax(T a, T b, T c) {return _max(_max(a,b),c);}
template <class T> inline T _smin(T a, T b, T c) {return _min(_min(a,b),c);}
template <class T> inline T _sqrt(T a) {T b,c;for(b = sqrt(a),c=b-2;c<=b+2;c++)if(_sqr(c)<=a)b=c;return b;}

int n, m, k, t, x, y, p, T, num, d, s, dd, dp, ds, ans;
struct attack{
    int l, r, s, day;
}a[1111111];

MII wall;

bool cmp(attack a, attack b) {
    return a.day < b.day;
}

void Solution_Production() {
    scanf("%d", &n); num = 0;
    rep(i, n) {
        scanf("%d%d%d%d%d%d%d%d", &d, &m, &x, &y, &s, &dd, &dp, &ds);
        rep(j, m) {
            num++;
            a[num].day = d + j * dd;
            a[num].l = x + j * dp;
            a[num].r = y + j * dp-1;
            a[num].s = s + j * ds;
        }
    }
    sort(a + 1, a + num + 1, cmp);
    //kep(i, num) cout << a[i].day << ":" << a[i].l << ":" << a[i].r << ":" << a[i].s << endl;return;
    ans = 0; int j; bool flag; wall.clear();
    for (int i = 0; i < num; i = j) {
        for (j = i+1; j < num && a[j+1].day == a[j].day; j++);
        for (int k = i+1; k <= j; k++) {
            flag = false;
            for (int t = a[k].l; t <= a[k].r; t++)
                if (wall[t] < a[k].s) {
                    flag = true;break;
                }
            ans += flag;
            //if (flag) cout << a[k].l << ":" << a[k].r << endl;
        }
        for (int k = i+1; k <= j; k++) {
            for (int t = a[k].l; t <= a[k].r; t++)
                if (wall[t] < a[k].s) wall[t] = a[k].s;
        }
    }
    printf("%d\n", ans);
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("ou.txt", "w", stdout);
    scanf("%d", &T);
    kep(_, T) {printf("Case #%d: ", _);
    Solution_Production();
    }
    return 0;
}

