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
const string PX = "WE" , PY = "SN";
const int N = 1e6 + 9;
int Case;
int P[N]  , rev[N];
void gao(int n , int x , int y){
    int sum = abs(x) + abs(y);
    int o = n * (n + 1) / 2;
    int oo = (o - sum) / 2;
    int sx = x < 0 , sy = y < 0;
    x = abs(x) , y = abs(y);
    memset(P , -1 , sizeof(P));
    P[oo] = rev[oo] = 0;
    x += oo;
    if (x > y)
        for (int i(n) ; i >= 1 ; --i)if (P[i] == -1){
            if (i <= x){
                P[i] = 0;
                rev[i] = 1;
                x -= i;
            }
            else P[i] = 1 , rev[i] = 1;
        }
    else
        for (int i(n) ; i >= 1 ; --i)if (P[i] == -1){
            if (i <= y){
                P[i] = 1 , rev[i] = 1;
                y -= i;
            }
            else P[i] = 0 , rev[i] = 1;
        }
    string ANS = "";
    for (int i = 1 ; i <= n ; ++i)
        if (P[i] == 0)
            ANS += PX[sx ^ rev[i]];
        else
            ANS += PY[sy ^ rev[i]];
    printf("Case #%d: ", ++Case);
    printf("%s\n" , ANS.c_str());
}
void solve(){
    int x , y;
    scanf("%d%d" , &x , &y);
    int sum = abs(x) + abs(y);
    int n;
    while((LL)n *(n + 1) / 2 < sum || (((LL)n *(n + 1) / 2 - sum) & 1)) n++;
    gao(n , x , y);
}
int main(){
    freopen("B-large.in" , "r" , stdin);
    freopen("Bout.out" , "w"  , stdout);
    int _;Case = 0;
    cin >> _;
    while(_--) solve();

}
