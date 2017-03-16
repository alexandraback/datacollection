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

const int N = 1000000 + 100;
const int M = 400000 + 100;
const LL INF = 9e18;
const int inf = 0x7fffffff;
const LL MOD = 100007;
const double PI = acos(-1.0);
const double G = 9.8;
const double eps = 1e-3;


int c, d, v;
vector<int> a;
int num[N];
bool create[N];

bool dfs(int x) {
    if(x == 0) {

        return true;
    }
    bool res = false;
    for(int i = 0; i < a.size(); ++ i) {
        if(x >= a[i] && num[a[i]] >= 1){
            num[a[i]] --;
            res |= dfs(x - a[i]);
            num[a[i]] ++;
        }
    }
    return res;
}

int main () {
    freopen("/Users/w/Desktop/in.txt", "r", stdin);
    freopen("/Users/w/Desktop/out.txt", "w", stdout);
    int Cas = 1;
    int T;
    cin >> T;
    while(T --) {
        a.clear();
        cin >> c >> d >> v;
        for (int i = 0; i < d; ++ i) {
            int tmp = read();
            a.PB(tmp);
            num[tmp] = c;
        }

        for (int i = 1; i <= v; ++ i) {
            if(dfs(i));
            else {a.PB(i); num[i] = c;}
        }
        printf("Case #%d: ", Cas++);
        cout << a.size() - d << endl;
    }
    return 0;
}