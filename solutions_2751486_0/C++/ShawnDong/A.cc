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
const int N = 1e6 + 9;
char A[N];
int n;
bool vowels(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o';
}
void solve(){
    LL ans = 0;
    scanf("%s%d" , A , &n);
    int len = strlen(A);
    int tail = 0 , head = 0;
    while(tail < len && !vowels(A[tail])) ++tail;
    for (int i = 0 ; i < len ; ++i){
        checkMax(head , i);
        if (tail - head  < n){
            for(;head < len && tail < len && tail - head < n;){
                head = tail;
                while(head < len && vowels(A[head])) ++ head;
                tail = head;
                while(tail < len && !vowels(A[tail])) ++tail;
            }
            if (tail - head < n) break;
        }
        ans += len - 1 - (head + n - 1) + 1;
    }
    printf("Case #%d: %lld\n" , ++Case , ans);
}
int main(){
    freopen("A-small-attempt0.in" , "r" , stdin);
    freopen("0.out" , "w" , stdout);
    int _;
    cin >> _; Case = 0;
    while(_--) solve();
}
