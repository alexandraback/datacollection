#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define DO(n) for ( int ____n ## __line__ = n; ____n ## __line__ -- ; )

#define ALL(A) A.begin(), A.end()
#define BSC(A, x) (lower_bound(ALL(A), x) - A.begin())
#define CTN(T, x) (T.find(x) != T.end())
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define fi first
#define se second

typedef long long LL;


typedef vector<int> VI;
typedef map<int, int> MII;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;



template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T> inline void CLR(T &A){A.clear();}

//}

/** Constant List .. **/ //{

const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};

const int dx8[] = {-1, 0, 1, 0 , -1 , -1 , 1 , 1};
const int dy8[] = {0, 1, 0, -1 , -1 , 1 , -1 , 1};

const int dxhorse[] = {-2 , -2 , -1 , -1 , 1 , 1 , 2 , 2};
const int dyhorse[] = {1 ,  -1 , 2  , -2 , 2 ,-2 , 1 ,-1};

const int MOD = 1000000007;
//int MOD = 99990001;
const int INF = 0x3f3f3f3f;
const LL INFF = 1LL << 60;
const double EPS = 1e-9;
const double OO = 1e15;
const double PI = acos(-1.0); //M_PI;

//}

template<class T> inline void checkMin(T &a,const T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a,const T b){if (a<b) a=b;}
//}
template<class T> inline T low_bit(T x) {return x & -x;}
/*****************************************************************/
int Case;
int X , Y , n;
const int N = 4009;
long double C[N][N];
void init(){
    C[0][0] = 1;
    C[1][0] = C[1][1] = .5;
    for (int i = 2 ; i < N ; ++i){
        C[i][0] = C[i][i] = C[i - 1][0] / 2.;
        for (int j = 1 ; j < i ; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) / 2.;
    }
//    cout << C[3][3] << endl;
}
LL gao(LL x){
    LL y = x + 1;
    return (1 + 4ll * x + 1) * y / 2;
}
void solve(){
    scanf("%d%d%d" , &n , &X , &Y);
//    printf("%d %d %d\n" , n , X , Y);
    LL level = abs(X) + abs(Y);
    level /= 2;
    if (level == 0){
        printf("Case #%d: 1.00000000000000000000\n" , ++Case);
        return;
    }
    LL sum = gao(level);
    if (n >= sum){
        printf("Case #%d: 1.00000000000000000000\n" , ++Case);
        return;
    }
    if (X == 0){
        printf("Case #%d: 0.0000000000000000\n" , ++Case);
        return;
    }
    LL pre = gao(level - 1);
    if (n <= pre){
        printf("Case #%d: 0.00000000000000\n" , ++Case);
        return;
    }
    n -= pre;
    long double ans = 0;
//    cout << n << endl;
    LL now = 2 * level + 1;
    long double all = 0;
    for (int i = 0 ; i <= n && i < now ; ++i) if (n - i < now) all += C[n][i];
    for (int i = abs(Y) + 1; i <= n && i < now ; ++i)if (n - i < now) ans += C[n][i];
    double out = ans / all;
//    cout << ans << endl;
    printf("Case #%d: " , ++Case);
    cout << setprecision (15) << ans << endl;
//    LL all =


}
int main(){
    freopen("B-small-attempt2.in" , "r" , stdin);
    freopen("B.out" , "w" , stdout);
    init();
    int _;
    Case = 0;
    cin >> _;
    while(_--) solve();
}
