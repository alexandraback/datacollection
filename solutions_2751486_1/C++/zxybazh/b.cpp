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

int n, m, k, t, x, y, p, T;
string s;

void Solution_Production() {
    scanf("%d%d", &x, &y);
    s.clear();
    while (x!=0) {
        if (x < 0) {
            x++;
            s.insert(s.length(), "EW");
        } else {
            x--;
            s.insert(s.length(), "WE");
        }
    }
    while (y!=0) {
        if (y < 0) {
            y++;
            s.insert(s.length(), "NS");
        } else {
            y--;
            s.insert(s.length(), "SN");
        }
    }
    cout << s << endl;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("ou.txt", "w", stdout);
    scanf("%d", &T);
    kep(_, T) {
        printf("Case #%d: ", _);
        Solution_Production();
    }
    return 0;
}

