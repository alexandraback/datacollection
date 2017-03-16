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
const int N = 109;
const int M = 1e6 + 9;
map<int , int> dp[N];
int Case ;
int n , A[N] , m;
int judge(int x){
    if (x <= 1e6) return x;
    return 1e6 + 1;
}
void update(int i , int j , int y){
    if (!dp[i].count(j) || dp[i][j] > y)
        dp[i][j] = y;
}
void solve(){
    scanf("%d%d" , &m , &n);
    for (int i = 0 ; i < n ; ++i){
        scanf("%d" , &A[i]);

    }
    for (int i = 0 ; i <= n ; ++i) dp[i].clear();
//    dp.clear();
    dp[0][judge(m)] = 0;
    sort(A , A + n);
    for (int i = 0 ; i < n ; ++i){
//        vector<>
        for (MII :: iterator iter = dp[i].begin() ; iter != dp[i].end() ; iter++){
            int x = iter->fi;
            int y = iter-> second;
            if (x > A[i]) update(i + 1 , judge(x + A[i]) , y);
            else {
                    int res =  x , add = 0;
                    while(res > 1 && res <= A[i]){
                        ++add;
                        res = res * 2 - 1;
                    }
                    if (res > A[i])
                        update(i + 1 , judge(res + A[i]) , y + add);
                    update(i + 1 , judge(x) , y + 1);
            }
        }
    }
    int ans = n;
    for (MII :: iterator iter = dp[n].begin() ; iter != dp[n].end() ; iter++)
        checkMin(ans , iter -> second);
    printf("Case #%d: %d\n" , ++Case , ans);
}
int main(){
    freopen("A-large.in" ,"r" , stdin);
    freopen("A.out" , "w" , stdout);
    int _; Case = 0;
    cin >> _;
    while(_--) solve();
}
