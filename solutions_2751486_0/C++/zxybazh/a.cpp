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

int n, m, k, t, x, y, p, T, l, ans;
string s;
bool a['z'+11];

int calc(int l, int r) {
    int c = 0, ans = 0;
    for (int i = l; i <= r; i++)
        if (a[s[i]]) c = 0;
        else {
            c++;
            ans = max(c, ans);
        }
    return ans;
}

void Solution_Production(int _) {
    cin >> s >> n;
    ans = 0; l = s.length();
    for (int i = 0; i < l; i++)
        for (int j = i; j < l; j++)
            if (calc(i, j) >= n) ans++;
    printf("Case #%d: %d\n", _, ans);
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("ou.txt", "w", stdout);
    memset(a, 0, sizeof(a));
    a['a'] = 1;
    a['e'] = 1;
    a['i'] = 1;
    a['o'] = 1;
    a['u'] = 1;
    scanf("%d", &T);
    kep(_, T) {
        Solution_Production(_);
    }
    return 0;
}

