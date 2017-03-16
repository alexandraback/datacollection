//#pragma comment(linker,"/STACK:102400000,102400000")
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
 
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef unsigned long long ULL;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; ch < '0' || ch > '9'; ch = getchar())    if (ch == '-')  positive = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())    x = x * 10 + ch - '0';
    return positive ? x : -x;
}

inline char RC (){
    char c = getchar ();
    while (c == ' '||c == '\n')     c = getchar ();
    return c;
}

inline LL gcd(LL a, LL b) {return b?gcd(b, a%b):a;}

inline LL lcm(LL a, LL b) {return a * b / gcd(a, b);}

inline LL Sub(LL x, LL y, LL mod){
    LL res = x - y;
    while(res < 0) res += mod; 
    return res;
}

inline LL Add(LL x, LL y, LL mod){
    LL res = x + y;
    while(res >= mod)  res -= mod;
    return res;
}

inline LL POW_MOD(LL x, LL y, LL mod){
    LL ret = 1;
    while(y > 0){
        if(y & 1)  ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}

/****************************define***************************************/

const int N = 1005 + 100;
const int M = 400000 + 100;
const LL INF = 9e18;
const int inf = 0x7fffffff;
const LL MOD = 1000000007;
const double PI = acos(-1.0);
const double G = 9.8;
const double eps = 1e-3;

int smax;
string num;

void solve(){
    int cnt = 0, ans = 0;
    for(int i = 0; i <= smax; ++ i){
        if(i == 0) cnt += num[i] - '0';
        else{
            if(cnt < i) ans += i - cnt, cnt = i;
            cnt += num[i] - '0';
        }
    }
    cout << ans << endl;
}

int main(){
    freopen("/Users/w/Desktop/in.txt", "r", stdin);
    freopen("/Users/w/Desktop/out.txt", "w", stdout);
    int Cas = 1;
    int T;
    cin >> T;
    while(T --){
        smax = read();
        cin >> num;
        printf("Case #%d: ", Cas++);
        solve();
    }
    return 0;
}