/** Header .. **/ //{
#define LOCAL

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

#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define DWN(i, b, a) for (int i=int(b-1);i>=int(a);--i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define FOR_1(i, a, b) for (int i=int(a);i<=int(b);++i)
#define DWN_1(i, b, a) for (int i=int(b);i>=int(a);--i)
#define REP_C(i, n) for (int n____=int(n),i=0;i<n____;++i)
#define FOR_C(i, a, b) for (int b____=int(b),i=a;i<b____;++i)
#define DWN_C(i, b, a) for (int a____=int(a),i=b-1;i>=a____;--i)
#define REP_N(i, n) for (i=0;i<int(n);++i)
#define FOR_N(i, a, b) for (i=int(a);i<int(b);++i)
#define DWN_N(i, b, a) for (i=int(b-1);i>=int(a);--i)
#define REP_1_C(i, n) for (int n____=int(n),i=1;i<=n____;++i)
#define FOR_1_C(i, a, b) for (int b____=int(b),i=a;i<=b____;++i)
#define DWN_1_C(i, b, a) for (int a____=int(a),i=b;i>=a____;--i)
#define REP_1_N(i, n) for (i=1;i<=int(n);++i)
#define FOR_1_N(i, a, b) for (i=int(a);i<=int(b);++i)
#define DWN_1_N(i, b, a) for (i=int(b);i>=int(a);--i)
#define REP_C_N(i, n) for (int n____=(i=0,int(n));i<n____;++i)
#define FOR_C_N(i, a, b) for (int b____=(i=0,int(b);i<b____;++i)
#define DWN_C_N(i, b, a) for (int a____=(i=b-1,int(a));i>=a____;--i)
#define REP_1_C_N(i, n) for (int n____=(i=1,int(n));i<=n____;++i)
#define FOR_1_C_N(i, a, b) for (int b____=(i=1,int(b);i<=b____;++i)
#define DWN_1_C_N(i, b, a) for (int a____=(i=b,int(a));i>=a____;--i)

#define ECH(it, A) for (__typeof(A.begin()) it=A.begin(); it != A.end(); ++it)
#define REP_S(i, str) for (char*i=str;*i;++i)
#define REP_L(i, hd, nxt) for (int i=hd;i;i=nxt[i])
#define REP_G(i, u) REP_L(i,hd[u],suc)
#define DO(n) for ( int ____n ## __line__ = n; ____n ## __line__ -- ; )
#define REP_2(i, j, n, m) REP(i, n) REP(j, m)
#define REP_2_1(i, j, n, m) REP_1(i, n) REP_1(j, m)
#define REP_3(i, j, k, n, m, l) REP(i, n) REP(j, m) REP(k, l)
#define REP_3_1(i, j, k, n, m, l) REP_1(i, n) REP_1(j, m) REP_1(k, l)
#define REP_4(i, j, k, ii, n, m, l, nn) REP(i, n) REP(j, m) REP(k, l) REP(ii, nn)
#define REP_4_1(i, j, k, ii, n, m, l, nn) REP_1(i, n) REP_1(j, m) REP_1(k, l) REP_1(ii, nn)

#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define BSC(A, x) (lower_bound(ALL(A), x) - A.begin())
#define CTN(T, x) (T.find(x) != T.end())
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define PTT pair<T, T>
#define fi first
#define se second

#define Rush for(int ____T=RD(); ____T--;)

#define Display(A, n, m) {                      \
	REP(i, n){		                            \
        REP(j, m) cout << A[i][j] << " ";       \
        cout << endl;				            \
	}						                    \
}

#define Display_1(A, n, m) {				    \
	REP_1(i, n){		                        \
        REP_1(j, m) cout << A[i][j] << " ";     \
		cout << endl;		            		\
	}						                    \
}

#pragma comment(linker, "/STACK:36777216")
//#pragma GCC optimize ("O2")
#define Ruby system("ruby main.rb")
#define Haskell system("runghc main.hs")
#define Python system("python main.py")
#define Pascal system("fpc main.pas")

typedef long long LL;
//typedef long double DB;
typedef double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;

typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<LL> VL;
typedef vector<DB> VF;
typedef set<int> SI;
typedef set<string> SS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;

template<class T> inline T& RD(T &);
template<class T> inline void OT(const T &);
inline LL RD(){LL x; return RD(x);}
inline DB& RF(DB &);
inline DB RF(){DB x; return RF(x);}
inline char* RS(char *s);
inline char& RC(char &c);
inline char RC();
inline char& RC(char &c){scanf(" %c", &c); return c;}
inline char RC(){char c; return RC(c);}
//inline char& RC(char &c){c = getchar(); return c;}
//inline char RC(){return getchar();}

template<class T> inline T& RDD(T &x){
    char c; for (c = getchar(); c < '-'; c = getchar());
    if (c == '-'){x = '0' - getchar(); for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + '0' - c;}
    else {x = c - '0'; for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';}
    return x;
}

inline LL RDD(){LL x; return RDD(x);}

template<class T0, class T1> inline T0& RD(T0 &x0, T1 &x1){RD(x0), RD(x1); return x0;}
template<class T0, class T1, class T2> inline T0& RD(T0 &x0, T1 &x1, T2 &x2){RD(x0), RD(x1), RD(x2); return x0;}
template<class T0, class T1, class T2, class T3> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3){RD(x0), RD(x1), RD(x2), RD(x3); return x0;}
template<class T0, class T1, class T2, class T3, class T4> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4); return x0;}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5); return x0;}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6); return x0;}
template<class T0, class T1> inline void OT(const T0 &x0, const T1 &x1){OT(x0), OT(x1);}
template<class T0, class T1, class T2> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2){OT(x0), OT(x1), OT(x2);}
template<class T0, class T1, class T2, class T3> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3){OT(x0), OT(x1), OT(x2), OT(x3);}
template<class T0, class T1, class T2, class T3, class T4> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4, const T5 &x5){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4, const T5 &x5, const T6 &x6){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5), OT(x6);}
inline char& RC(char &a, char &b){RC(a), RC(b); return a;}
inline char& RC(char &a, char &b, char &c){RC(a), RC(b), RC(c); return a;}
inline char& RC(char &a, char &b, char &c, char &d){RC(a), RC(b), RC(c), RC(d); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e){RC(a), RC(b), RC(c), RC(d), RC(e); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e, char &f){RC(a), RC(b), RC(c), RC(d), RC(e), RC(f); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e, char &f, char &g){RC(a), RC(b), RC(c), RC(d), RC(e), RC(f), RC(g); return a;}
inline DB& RF(DB &a, DB &b){RF(a), RF(b); return a;}
inline DB& RF(DB &a, DB &b, DB &c){RF(a), RF(b), RF(c); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d){RF(a), RF(b), RF(c), RF(d); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e){RF(a), RF(b), RF(c), RF(d), RF(e); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e, DB &f){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e, DB &f, DB &g){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f), RF(g); return a;}
inline void RS(char *s1, char *s2){RS(s1), RS(s2);}
inline void RS(char *s1, char *s2, char *s3){RS(s1), RS(s2), RS(s3);}
template<class T0,class T1>inline void RDD(const T0&a, const T1&b){RDD(a),RDD(b);}
template<class T0,class T1,class T2>inline void RDD(const T0&a, const T1&b, const T2&c){RDD(a),RDD(b),RDD(c);}

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T> inline void CLR(T &A){A.clear();}

template<class T0, class T1> inline void RST(T0 &A0, T1 &A1){RST(A0), RST(A1);}
template<class T0, class T1, class T2> inline void RST(T0 &A0, T1 &A1, T2 &A2){RST(A0), RST(A1), RST(A2);}
template<class T0, class T1, class T2, class T3> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3){RST(A0), RST(A1), RST(A2), RST(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5), RST(A6);}
template<class T0, class T1> inline void FLC(T0 &A0, T1 &A1, int x){FLC(A0, x), FLC(A1, x);}
template<class T0, class T1, class T2> inline void FLC(T0 &A0, T1 &A1, T2 &A2, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x);}
template<class T0, class T1, class T2, class T3> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x);}
template<class T0, class T1, class T2, class T3, class T4> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x), FLC(A6, x);}
template<class T> inline void CLR(priority_queue<T, vector<T>, less<T> > &Q){while (!Q.empty()) Q.pop();}
template<class T> inline void CLR(priority_queue<T, vector<T>, greater<T> > &Q){while (!Q.empty()) Q.pop();}
template<class T0, class T1> inline void CLR(T0 &A0, T1 &A1){CLR(A0), CLR(A1);}
template<class T0, class T1, class T2> inline void CLR(T0 &A0, T1 &A1, T2 &A2){CLR(A0), CLR(A1), CLR(A2);}
template<class T0, class T1, class T2, class T3> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3){CLR(A0), CLR(A1), CLR(A2), CLR(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5), CLR(A6);}
template<class T> inline void CLR(T &A, int n){REP(i, n) CLR(A[i]);}

template<class T> inline T& SRT(T &A){sort(ALL(A)); return A;}
template<class T, class C> inline T& SRT(T &A, C B){sort(ALL(A), B); return A;}
template<class T> inline T& UNQ(T &A){A.resize(unique(ALL(SRT(A)))-A.begin());return A;}

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
const DB EPS = 1e-9;
const DB OO = 1e15;
const DB PI = acos(-1.0); //M_PI;

//}

/** Add On .. **/ //{
// <<= '0. Nichi Joo ., //{
template<class T> inline void checkMin(T &a,const T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a,const T b){if (a<b) a=b;}
template<class T> inline void checkMin(T &a, T &b, const T x){checkMin(a, x), checkMin(b, x);}
template<class T> inline void checkMax(T &a, T &b, const T x){checkMax(a, x), checkMax(b, x);}
template <class T, class C> inline void checkMin(T& a, const T b, C c){if (c(b,a)) a = b;}
template <class T, class C> inline void checkMax(T& a, const T b, C c){if (c(a,b)) a = b;}
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}
inline int ceil(int x, int y){return (x - 1) / y + 1;}
inline int sgn(DB x){return x < -EPS ? -1 : x > EPS;}
inline int sgn(DB x, DB y){return sgn(x - y);}
//}
// <<= '1. Bitwise Operation ., //{
namespace BO{

inline bool _1(int x, int i){return bool(x&1<<i);}
inline bool _1(LL x, int i){return bool(x&1LL<<i);}
inline LL _1(int i){return 1LL<<i;}
inline LL _U(int i){return _1(i) - 1;};

inline int reverse_bits(int x){
    x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);
    x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);
    x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);
    x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);
    x = ((x >>16) & 0x0000ffff) | ((x <<16) & 0xffff0000);
    return x;
}

inline LL reverse_bits(LL x){
    x = ((x >> 1) & 0x5555555555555555LL) | ((x << 1) & 0xaaaaaaaaaaaaaaaaLL);
    x = ((x >> 2) & 0x3333333333333333LL) | ((x << 2) & 0xccccccccccccccccLL);
    x = ((x >> 4) & 0x0f0f0f0f0f0f0f0fLL) | ((x << 4) & 0xf0f0f0f0f0f0f0f0LL);
    x = ((x >> 8) & 0x00ff00ff00ff00ffLL) | ((x << 8) & 0xff00ff00ff00ff00LL);
    x = ((x >>16) & 0x0000ffff0000ffffLL) | ((x <<16) & 0xffff0000ffff0000LL);
    x = ((x >>32) & 0x00000000ffffffffLL) | ((x <<32) & 0xffffffff00000000LL);
    return x;
}

template<class T> inline bool odd(T x){return x&1;}
template<class T> inline bool even(T x){return !odd(x);}
template<class T> inline T low_bit(T x) {return x & -x;}
template<class T> inline T high_bit(T x) {T p = low_bit(x);while (p != x) x -= p, p = low_bit(x);return p;}
template<class T> inline T cover_bit(T x){T p = 1; while (p < x) p <<= 1;return p;}

inline int low_idx(int x){return __builtin_ffs(x);}
inline int low_idx(LL x){return __builtin_ffsll(x);}
inline int high_idx(int x){return low_idx(reverse_bits(x));}
inline int high_idx(LL x){return low_idx(reverse_bits(x));}
inline int clz(int x){return __builtin_clz(x);}
inline int clz(LL x){return __builtin_clzll(x);}
inline int ctz(int x){return __builtin_ctz(x);}
inline int ctz(LL x){return __builtin_ctzll(x);}
inline int parity(int x){return __builtin_parity(x);}
inline int parity(LL x){return __builtin_parityll(x);}
inline int lg2(int a){return 31 - clz(a);}
inline int lg2(LL a){return 63 - clz(a);}
inline int count_bits(int x){return __builtin_popcount(x);}
inline int count_bits(LL x){return __builtin_popcountll(x);}

} using namespace BO;//}
// <<= '2. Number Theory .,//{
namespace NT{
inline LL __lcm(LL a, LL b){return a*b/__gcd(a,b);}
inline void INC(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
inline int sum(int a, int b){a += b; if (a >= MOD) a -= MOD; return a;}
inline void DEC(int &a, int b){a -= b; if (a < 0) a += MOD;}
inline int dff(int a, int b){a -= b; if (a < 0) a  += MOD; return a;}
inline void MUL(int &a, int b){a = (LL)a * b % MOD;}
inline int pdt(int a, int b){return (LL)a * b % MOD;}

inline int sum(int a, int b, int c){return sum(sum(a, b), c);}
inline int sum(int a, int b, int c, int d){return sum(sum(a, b), sum(c, d));}
inline int pdt(int a, int b, int c){return pdt(pdt(a, b), c);}
inline int pdt(int a, int b, int c, int d){return pdt(pdt(pdt(a, b), c), d);}

inline int pow(int a, int b){
    int c(1); while (b){
        if (b&1) MUL(c, a);
        MUL(a, a), b >>= 1;
    }
    return c;
}

inline int pow(int a, LL b){
    int c(1); while (b){
        if (b&1) MUL(c, a);
        MUL(a, a), b >>= 1;
    }
    return c;
}

template<class T> inline T pow(T a, LL b){
    T c(1); while (b){
        if (b&1) c *= a;
        a *= a, b >>= 1;
    }
    return c;
}

inline int _I(int b){
    int a = MOD, x1 = 0, x2 = 1, q;
    while (true){
        q = a / b, a %= b;
        if (!a) return (x2 + MOD) % MOD;
        DEC(x1, pdt(q, x2));

        q = b / a, b %= a;
        if (!b) return (x1 + MOD) % MOD;
        DEC(x2, pdt(q, x1));
    }
}

inline void DIV(int &a, int b){MUL(a, _I(b));}
inline int qtt(int a, int b){return pdt(a, _I(b));}

inline int phi(int n){
    int res = n; for (int i=2;sqr(i)<=n;++i) if (!(n%i)){
        DEC(res, qtt(res, i));
        do{n /= i;} while(!(n%i));
    }
    if (n != 1)
        DEC(res, qtt(res, n));
    return res;
}

} using namespace NT;//}
//}

/** Miscellaneous .. **/ //{
// <<= 'Random Event .. . //{
namespace RNG{
//srand((unsigned)time(NULL));
inline unsigned int rand16(){return ((rand()) << 15) ^ rand();}
inline unsigned int rand32(){return (rand16() << 16) | rand16();}
inline ULL rand64(){return ((LL)rand32() << 32) | rand32();}
inline ULL random(LL l, LL r){return l == r ? l : rand64() % (r - l) + l;}
int dice(){return rand() % 6;}
bool coin(){return bool(rand() % 2);}
} using namespace RNG;
//}
// <<= 'Clock .. . //{
namespace CLOCK{
DB s0, s1, rd, k, T;
inline DB getTime(){
#ifdef LOCAL
    return 1.0 * clock() / CLOCKS_PER_SEC;
#else
    timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec * 1e-6;
#endif
}

inline void st0(DB _T = 0.98){T = _T, s0 = getTime();}
inline void st1(DB _k = 1.618){k = _k, s1 = getTime();}
inline void ed1(){rd = getTime() - s1;}
inline DB elapsed(){return getTime() - s0;}
inline bool safe(){return elapsed() + rd * k < T;}
} //using namespace CLOCK;
//}
// <<= 'Temp .. . //{
namespace TMP{
template<class T> PTT operator+(const PTT &p1, const PTT &p2) {
	return PTT(p1.fi + p2.fi, p1.se + p2.se);
}

template<class T> PTT operator-(const PTT &p1, const PTT &p2) {
	return PTT(p1.fi - p2.fi, p1.se - p2.se);
}

template<class T> PTT operator*(const PTT &lhs, T k){
    return PTT(lhs.fi * k, lhs.se * k);
}
} using namespace TMP;
//}
//}

/** Algorithm    .. */ //{
// <<= '-. Math .,//{
namespace Math{
	typedef long long typec;
	///Lib functions
	typec GCD(typec a, typec b)
	{
		return b ? GCD(b, a % b) : a;
	}
	typec extendGCD(typec a, typec b, typec& x, typec& y)
	{
		if(!b) return x = 1, y = 0, a;
		typec res = extendGCD(b, a % b, x, y), tmp = x;
		x = y, y = tmp - (a / b) * y;
		return res;
	}
	///for x^k
	typec power(typec x, typec k)
	{
		typec res = 1;
		while(k)
		{
			if(k&1) res *= x;
			x *= x, k >>= 1;
		}
		return res;
	}
	///for x^k mod m
	typec powerMod(typec x, typec k, typec m)
	{
		typec res = 1;
		while(x %= m, k)
		{
			if(k&1) res *= x, res %= m;
			x *= x, k >>=1;
		}
		return res;
	}
	/***************************************
	Inverse in mod p^t system
	***************************************/
	typec inverse(typec a, typec p, typec t = 1)
	{
		typec pt = power(p, t);
		typec x, y;
	    y = extendGCD(a, pt, x, y);
		return x < 0 ? x += pt : x;
	}
	/***************************************
	Linear congruence theorem
	x = a (mod p)
	x = b (mod q)
	for gcd(p, q) = 1, 0 <= x < pq
	***************************************/
	typec linearCongruence(typec a, typec b, typec p, typec q)
	{
		typec x, y;
		y = extendGCD(p, q, x, y);
		while(b < a) b += q / y;
		x *= b - a, x = p * x + a, x %= p * q;
		if(x < 0) x += p * q;
		return x;
	}
	/***************************************
	prime table
	O(n)
	***************************************/
	const int PRIMERANGE = 1000000;
	int prime[PRIMERANGE + 1];
	int getPrime()
	{
		memset (prime, 0, sizeof (int) * (PRIMERANGE + 1));
		for (int i = 2; i <= PRIMERANGE; i++)
		{
			if (!prime[i]) prime[++prime[0]] = i;
			for (int j = 1; j <= prime[0] && prime[j] <= PRIMERANGE / i; j++)
			{
				prime[prime[j]*i] = 1;
				if (i % prime[j] == 0) break;
			}
		}
		return prime[0];
	}
	/***************************************
	get factor of n
	O(sqrt(n))
	factor[][0] is prime factor
	factor[][1] is factor generated by this prime
	factor[][2] is factor counter

	need: Prime Table
	***************************************/
	///you should init the prime table before
	int factor[100][3], facCnt;
	int getFactors(int x)
	{
		facCnt = 0;
		int tmp = x;
		for(int i = 1; prime[i] <= tmp / prime[i]; i++)
		{
			factor[facCnt][1] = 1, factor[facCnt][2] = 0;
			if(tmp % prime[i] == 0)
				factor[facCnt][0] = prime[i];
			while(tmp % prime[i] == 0)
				factor[facCnt][2]++, factor[facCnt][1] *= prime[i], tmp /= prime[i];
			if(factor[facCnt][1] > 1) facCnt++;
		}
		if(tmp != 1)
			factor[facCnt][0] = tmp, factor[facCnt][1] = tmp, factor[facCnt++][2] = 1;
		return facCnt;
	}
	typec combinationModP(typec n, typec k, typec p)
	{
		if(k > n) return 0;
		if(n - k < k) k = n - k;
		typec a = 1, b = 1, x, y;
		int pcnt = 0;
		for(int i = 1; i <= k; i++)
		{
			x = n - i + 1, y = i;
			while(x % p == 0) x /= p, pcnt++;
			while(y % p == 0) y /= p, pcnt--;
			x %= p, y %= p, a *= x, b *= y;
			b %= p, a %= p;
		}
		if(pcnt) return 0;
		extendGCD(b, p, x, y);
		if(x < 0) x += p;
		a *= x, a %= p;
		return a;
	}
};//using namespace Math;
//}
// <<= '-. Geo ,.//{
namespace Geo{
	#define typec double
    const typec eps=1e-8;
    int dblcmp(double d){
        if (fabs(d)<eps)return 0;
        return d>eps?1:-1;
    }
    int sgn(double a) {return a<-eps?-1:a>eps;}
    inline double sqr(double x){return x*x;}
    struct Point2D{
		typec x,y;
		Point2D(){}
		Point2D(typec _x,typec _y):x(_x),y(_y){};
		void input(){
			scanf("%lf%lf",&x,&y);
		}
		void output(){
			printf("%.2f %.2f\n",x,y);
		}
		bool operator==(Point2D a)const{
			return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
		}
		bool operator<(Point2D a)const{
			return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
		}
		typec len(){
			return hypot(x,y);
		}
		typec len2(){
			return x*x+y*y;
		}
		Point2D operator + (const Point2D &A) const{
			return Point2D(x + A.x , y + A.y);
		}
		Point2D operator - (const Point2D &A) const{
			return Point2D(x - A.x , y - A.y);
		}
		Point2D operator * (const typec _x) const{
			return Point2D(x * _x , y * _x);
		}
		typec operator * (const Point2D &A) const{
			return x * A.x + y * A.y;
		}
		typec operator ^ (const Point2D &A) const{
			return x * A.y - y * A.x;
		}
		Point2D operator / (const typec _p) const{
			return Point2D(x / _p , y / _p);
		}
		typec distance(Point2D p){
			return hypot(x-p.x,y-p.y);
		}
		Point2D add(Point2D p){
			return Point2D(x+p.x,y+p.y);
		}
		Point2D sub(Point2D p){
			return Point2D(x-p.x,y-p.y);
		}
		Point2D mul(typec b){
			return Point2D(x*b,y*b);
		}
		Point2D div(typec b){
			return Point2D(x/b,y/b);
		}
		typec dot(Point2D p){
			return x*p.x+y*p.y;
		}
		typec det(Point2D p){
			return x*p.y-y*p.x;
		}
		typec rad(Point2D a,Point2D b){
			Point2D p=*this;
			return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
		}
		Point2D trunc(typec r){
			typec l=len();
			if (!dblcmp(l))return *this;
			r/=l;
			return Point2D(x*r,y*r);
		}
		Point2D rotleft(){
			return Point2D(-y,x);
		}
		Point2D rotright(){
			return Point2D(y,-x);
		}
		Point2D rotate(Point2D p,typec angle)//绕点p逆时针旋转angle角度
		{
			Point2D v=this->sub(p);
			typec c=cos(angle),s=sin(angle);
			return Point2D(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
		}
	};

	typec cross(Point2D a,Point2D b,Point2D c){
		return (b.sub(a)).det(c.sub(a));
	}
}using namespace Geo;
//}
//}

/** I/O Accelerator Interface .. **/ //{
template<class T> inline T& RD(T &x){
    //cin >> x;
    //scanf("%d", &x);
    char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
    //char c; c = getchar(); x = c - '0'; for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';
    return x;
}

inline DB& RF(DB &x){
    //cin >> x;
    scanf("%lf", &x);
    /*char t; while ((t=getchar())==' '||t=='\n'); x = t - '0';
    while ((t=getchar())!=' '&&t!='\n'&&t!='.')x*=10,x+=t-'0';
    if (t=='.'){DB l=1; while ((t=getchar())!=' '&&t!='\n')l*=0.1,x += (t-'0')*l;}*/
    return x;
}

inline char* RS(char *s){
    //gets(s);
    scanf("%s", s);
    return s;
}

int Case; template<class T> inline void OT(const T &x){
    //printf("Case %d: %d\n", ++Case, x);
    //printf("%.2lf\n", x);
    //printf("%d\n", x);
    cout << x << endl;
}
//}

/* .................................................................................................................................. */
int ac[][3] = {{2,1,1},{2,1,1},{2,1,3},{2,3,1},{2,1,5},{2,5,1},{2,1,7},{2,7,1},{2,1,9},{2,9,1},{2,1,11},{2,11,1},{2,1,13},{2,13,1},{2,1,15},{2,15,1},{2,1,17},{2,17,1},{2,1,19},{2,19,1},{2,3,3},{2,3,3},{2,3,5},{2,5,3},{2,3,7},{2,7,3},{2,3,9},{2,9,3},{2,3,11},{2,11,3},{2,3,13},{2,13,3},{2,3,15},{2,15,3},{2,3,17},{2,17,3},{2,3,19},{2,19,3},{2,5,5},{2,5,5},{2,5,7},{2,7,5},{2,5,9},{2,9,5},{2,5,11},{2,11,5},{2,5,13},{2,13,5},{2,5,15},{2,15,5},{2,5,17},{2,17,5},{2,5,19},{2,19,5},{2,7,7},{2,7,7},{2,7,9},{2,9,7},{2,7,11},{2,11,7},{2,7,13},{2,13,7},{2,7,15},{2,15,7},{2,7,17},{2,17,7},{2,7,19},{2,19,7},{2,9,9},{2,9,9},{2,9,11},{2,11,9},{2,9,13},{2,13,9},{2,9,15},{2,15,9},{2,9,17},{2,17,9},{2,9,19},{2,19,9},{2,11,11},{2,11,11},{2,11,13},{2,13,11},{2,11,15},{2,15,11},{2,11,17},{2,17,11},{2,11,19},{2,19,11},{2,13,13},{2,13,13},{2,13,15},{2,15,13},{2,13,17},{2,17,13},{2,13,19},{2,19,13},{2,15,15},{2,15,15},{2,15,17},{2,17,15},{2,15,19},{2,19,15},{2,17,17},{2,17,17},{2,17,19},{2,19,17},{2,19,19},{2,19,19},{3,1,1},{3,1,1},{3,1,2},{3,2,1},{3,1,3},{3,3,1},{3,1,4},{3,4,1},{3,1,5},{3,5,1},{3,1,6},{3,6,1},{3,1,7},{3,7,1},{3,1,8},{3,8,1},{3,1,9},{3,9,1},{3,1,10},{3,10,1},{3,1,11},{3,11,1},{3,1,12},{3,12,1},{3,1,13},{3,13,1},{3,1,14},{3,14,1},{3,1,15},{3,15,1},{3,1,16},{3,16,1},{3,1,17},{3,17,1},{3,1,18},{3,18,1},{3,1,19},{3,19,1},{3,1,20},{3,20,1},{3,2,2},{3,2,2},{3,2,4},{3,4,2},{3,2,5},{3,5,2},{3,2,7},{3,7,2},{3,2,8},{3,8,2},{3,2,10},{3,10,2},{3,2,11},{3,11,2},{3,2,13},{3,13,2},{3,2,14},{3,14,2},{3,2,16},{3,16,2},{3,2,17},{3,17,2},{3,2,19},{3,19,2},{3,2,20},{3,20,2},{3,4,4},{3,4,4},{3,4,5},{3,5,4},{3,4,7},{3,7,4},{3,4,8},{3,8,4},{3,4,10},{3,10,4},{3,4,11},{3,11,4},{3,4,13},{3,13,4},{3,4,14},{3,14,4},{3,4,16},{3,16,4},{3,4,17},{3,17,4},{3,4,19},{3,19,4},{3,4,20},{3,20,4},{3,5,5},{3,5,5},{3,5,7},{3,7,5},{3,5,8},{3,8,5},{3,5,10},{3,10,5},{3,5,11},{3,11,5},{3,5,13},{3,13,5},{3,5,14},{3,14,5},{3,5,16},{3,16,5},{3,5,17},{3,17,5},{3,5,19},{3,19,5},{3,5,20},{3,20,5},{3,7,7},{3,7,7},{3,7,8},{3,8,7},{3,7,10},{3,10,7},{3,7,11},{3,11,7},{3,7,13},{3,13,7},{3,7,14},{3,14,7},{3,7,16},{3,16,7},{3,7,17},{3,17,7},{3,7,19},{3,19,7},{3,7,20},{3,20,7},{3,8,8},{3,8,8},{3,8,10},{3,10,8},{3,8,11},{3,11,8},{3,8,13},{3,13,8},{3,8,14},{3,14,8},{3,8,16},{3,16,8},{3,8,17},{3,17,8},{3,8,19},{3,19,8},{3,8,20},{3,20,8},{3,10,10},{3,10,10},{3,10,11},{3,11,10},{3,10,13},{3,13,10},{3,10,14},{3,14,10},{3,10,16},{3,16,10},{3,10,17},{3,17,10},{3,10,19},{3,19,10},{3,10,20},{3,20,10},{3,11,11},{3,11,11},{3,11,13},{3,13,11},{3,11,14},{3,14,11},{3,11,16},{3,16,11},{3,11,17},{3,17,11},{3,11,19},{3,19,11},{3,11,20},{3,20,11},{3,13,13},{3,13,13},{3,13,14},{3,14,13},{3,13,16},{3,16,13},{3,13,17},{3,17,13},{3,13,19},{3,19,13},{3,13,20},{3,20,13},{3,14,14},{3,14,14},{3,14,16},{3,16,14},{3,14,17},{3,17,14},{3,14,19},{3,19,14},{3,14,20},{3,20,14},{3,16,16},{3,16,16},{3,16,17},{3,17,16},{3,16,19},{3,19,16},{3,16,20},{3,20,16},{3,17,17},{3,17,17},{3,17,19},{3,19,17},{3,17,20},{3,20,17},{3,19,19},{3,19,19},{3,19,20},{3,20,19},{3,20,20},{3,20,20},{4,1,1},{4,1,1},{4,1,2},{4,2,1},{4,1,3},{4,3,1},{4,1,4},{4,4,1},{4,1,5},{4,5,1},{4,1,6},{4,6,1},{4,1,7},{4,7,1},{4,1,8},{4,8,1},{4,1,9},{4,9,1},{4,1,10},{4,10,1},{4,1,11},{4,11,1},{4,1,12},{4,12,1},{4,1,13},{4,13,1},{4,1,14},{4,14,1},{4,1,15},{4,15,1},{4,1,16},{4,16,1},{4,1,17},{4,17,1},{4,1,18},{4,18,1},{4,1,19},{4,19,1},{4,1,20},{4,20,1},{4,2,2},{4,2,2},{4,2,3},{4,3,2},{4,2,4},{4,4,2},{4,2,5},{4,5,2},{4,2,6},{4,6,2},{4,2,7},{4,7,2},{4,2,8},{4,8,2},{4,2,9},{4,9,2},{4,2,10},{4,10,2},{4,2,11},{4,11,2},{4,2,12},{4,12,2},{4,2,13},{4,13,2},{4,2,14},{4,14,2},{4,2,15},{4,15,2},{4,2,16},{4,16,2},{4,2,17},{4,17,2},{4,2,18},{4,18,2},{4,2,19},{4,19,2},{4,2,20},{4,20,2},{4,3,3},{4,3,3},{4,3,5},{4,5,3},{4,3,6},{4,6,3},{4,3,7},{4,7,3},{4,3,9},{4,9,3},{4,3,10},{4,10,3},{4,3,11},{4,11,3},{4,3,13},{4,13,3},{4,3,14},{4,14,3},{4,3,15},{4,15,3},{4,3,17},{4,17,3},{4,3,18},{4,18,3},{4,3,19},{4,19,3},{4,5,5},{4,5,5},{4,5,6},{4,6,5},{4,5,7},{4,7,5},{4,5,9},{4,9,5},{4,5,10},{4,10,5},{4,5,11},{4,11,5},{4,5,13},{4,13,5},{4,5,14},{4,14,5},{4,5,15},{4,15,5},{4,5,17},{4,17,5},{4,5,18},{4,18,5},{4,5,19},{4,19,5},{4,6,7},{4,7,6},{4,6,9},{4,9,6},{4,6,11},{4,11,6},{4,6,13},{4,13,6},{4,6,15},{4,15,6},{4,6,17},{4,17,6},{4,6,19},{4,19,6},{4,7,7},{4,7,7},{4,7,9},{4,9,7},{4,7,10},{4,10,7},{4,7,11},{4,11,7},{4,7,13},{4,13,7},{4,7,14},{4,14,7},{4,7,15},{4,15,7},{4,7,17},{4,17,7},{4,7,18},{4,18,7},{4,7,19},{4,19,7},{4,9,9},{4,9,9},{4,9,10},{4,10,9},{4,9,11},{4,11,9},{4,9,13},{4,13,9},{4,9,14},{4,14,9},{4,9,15},{4,15,9},{4,9,17},{4,17,9},{4,9,18},{4,18,9},{4,9,19},{4,19,9},{4,10,11},{4,11,10},{4,10,13},{4,13,10},{4,10,15},{4,15,10},{4,10,17},{4,17,10},{4,10,19},{4,19,10},{4,11,11},{4,11,11},{4,11,13},{4,13,11},{4,11,14},{4,14,11},{4,11,15},{4,15,11},{4,11,17},{4,17,11},{4,11,18},{4,18,11},{4,11,19},{4,19,11},{4,13,13},{4,13,13},{4,13,14},{4,14,13},{4,13,15},{4,15,13},{4,13,17},{4,17,13},{4,13,18},{4,18,13},{4,13,19},{4,19,13},{4,14,15},{4,15,14},{4,14,17},{4,17,14},{4,14,19},{4,19,14},{4,15,15},{4,15,15},{4,15,17},{4,17,15},{4,15,18},{4,18,15},{4,15,19},{4,19,15},{4,17,17},{4,17,17},{4,17,18},{4,18,17},{4,17,19},{4,19,17},{4,18,19},{4,19,18},{4,19,19},{4,19,19},{5,1,1},{5,1,1},{5,1,2},{5,2,1},{5,1,3},{5,3,1},{5,1,4},{5,4,1},{5,1,5},{5,5,1},{5,1,6},{5,6,1},{5,1,7},{5,7,1},{5,1,8},{5,8,1},{5,1,9},{5,9,1},{5,1,10},{5,10,1},{5,1,11},{5,11,1},{5,1,12},{5,12,1},{5,1,13},{5,13,1},{5,1,14},{5,14,1},{5,1,15},{5,15,1},{5,1,16},{5,16,1},{5,1,17},{5,17,1},{5,1,18},{5,18,1},{5,1,19},{5,19,1},{5,1,20},{5,20,1},{5,2,2},{5,2,2},{5,2,3},{5,3,2},{5,2,4},{5,4,2},{5,2,5},{5,5,2},{5,2,6},{5,6,2},{5,2,7},{5,7,2},{5,2,8},{5,8,2},{5,2,9},{5,9,2},{5,2,10},{5,10,2},{5,2,11},{5,11,2},{5,2,12},{5,12,2},{5,2,13},{5,13,2},{5,2,14},{5,14,2},{5,2,15},{5,15,2},{5,2,16},{5,16,2},{5,2,17},{5,17,2},{5,2,18},{5,18,2},{5,2,19},{5,19,2},{5,2,20},{5,20,2},{5,3,3},{5,3,3},{5,3,4},{5,4,3},{5,3,5},{5,5,3},{5,3,6},{5,6,3},{5,3,7},{5,7,3},{5,3,8},{5,8,3},{5,3,9},{5,9,3},{5,3,11},{5,11,3},{5,3,12},{5,12,3},{5,3,13},{5,13,3},{5,3,14},{5,14,3},{5,3,16},{5,16,3},{5,3,17},{5,17,3},{5,3,18},{5,18,3},{5,3,19},{5,19,3},{5,4,4},{5,4,4},{5,4,6},{5,6,4},{5,4,7},{5,7,4},{5,4,8},{5,8,4},{5,4,9},{5,9,4},{5,4,11},{5,11,4},{5,4,12},{5,12,4},{5,4,13},{5,13,4},{5,4,14},{5,14,4},{5,4,16},{5,16,4},{5,4,17},{5,17,4},{5,4,18},{5,18,4},{5,4,19},{5,19,4},{5,6,6},{5,6,6},{5,6,7},{5,7,6},{5,6,8},{5,8,6},{5,6,9},{5,9,6},{5,6,11},{5,11,6},{5,6,12},{5,12,6},{5,6,13},{5,13,6},{5,6,14},{5,14,6},{5,6,16},{5,16,6},{5,6,17},{5,17,6},{5,6,18},{5,18,6},{5,6,19},{5,19,6},{5,7,7},{5,7,7},{5,7,8},{5,8,7},{5,7,9},{5,9,7},{5,7,11},{5,11,7},{5,7,12},{5,12,7},{5,7,13},{5,13,7},{5,7,14},{5,14,7},{5,7,16},{5,16,7},{5,7,17},{5,17,7},{5,7,18},{5,18,7},{5,7,19},{5,19,7},{5,8,8},{5,8,8},{5,8,9},{5,9,8},{5,8,11},{5,11,8},{5,8,12},{5,12,8},{5,8,13},{5,13,8},{5,8,14},{5,14,8},{5,8,16},{5,16,8},{5,8,17},{5,17,8},{5,8,18},{5,18,8},{5,8,19},{5,19,8},{5,9,9},{5,9,9},{5,9,11},{5,11,9},{5,9,12},{5,12,9},{5,9,13},{5,13,9},{5,9,14},{5,14,9},{5,9,16},{5,16,9},{5,9,17},{5,17,9},{5,9,18},{5,18,9},{5,9,19},{5,19,9},{5,11,11},{5,11,11},{5,11,12},{5,12,11},{5,11,13},{5,13,11},{5,11,14},{5,14,11},{5,11,16},{5,16,11},{5,11,17},{5,17,11},{5,11,18},{5,18,11},{5,11,19},{5,19,11},{5,12,12},{5,12,12},{5,12,13},{5,13,12},{5,12,14},{5,14,12},{5,12,16},{5,16,12},{5,12,17},{5,17,12},{5,12,18},{5,18,12},{5,12,19},{5,19,12},{5,13,13},{5,13,13},{5,13,14},{5,14,13},{5,13,16},{5,16,13},{5,13,17},{5,17,13},{5,13,18},{5,18,13},{5,13,19},{5,19,13},{5,14,14},{5,14,14},{5,14,16},{5,16,14},{5,14,17},{5,17,14},{5,14,18},{5,18,14},{5,14,19},{5,19,14},{5,16,16},{5,16,16},{5,16,17},{5,17,16},{5,16,18},{5,18,16},{5,16,19},{5,19,16},{5,17,17},{5,17,17},{5,17,18},{5,18,17},{5,17,19},{5,19,17},{5,18,18},{5,18,18},{5,18,19},{5,19,18},{5,19,19},{5,19,19},{6,1,1},{6,1,1},{6,1,2},{6,2,1},{6,1,3},{6,3,1},{6,1,4},{6,4,1},{6,1,5},{6,5,1},{6,1,6},{6,6,1},{6,1,7},{6,7,1},{6,1,8},{6,8,1},{6,1,9},{6,9,1},{6,1,10},{6,10,1},{6,1,11},{6,11,1},{6,1,12},{6,12,1},{6,1,13},{6,13,1},{6,1,14},{6,14,1},{6,1,15},{6,15,1},{6,1,16},{6,16,1},{6,1,17},{6,17,1},{6,1,18},{6,18,1},{6,1,19},{6,19,1},{6,1,20},{6,20,1},{6,2,2},{6,2,2},{6,2,3},{6,3,2},{6,2,4},{6,4,2},{6,2,5},{6,5,2},{6,2,6},{6,6,2},{6,2,7},{6,7,2},{6,2,8},{6,8,2},{6,2,9},{6,9,2},{6,2,10},{6,10,2},{6,2,11},{6,11,2},{6,2,12},{6,12,2},{6,2,13},{6,13,2},{6,2,14},{6,14,2},{6,2,15},{6,15,2},{6,2,16},{6,16,2},{6,2,17},{6,17,2},{6,2,18},{6,18,2},{6,2,19},{6,19,2},{6,2,20},{6,20,2},{6,3,3},{6,3,3},{6,3,4},{6,4,3},{6,3,5},{6,5,3},{6,3,6},{6,6,3},{6,3,7},{6,7,3},{6,3,8},{6,8,3},{6,3,9},{6,9,3},{6,3,10},{6,10,3},{6,3,11},{6,11,3},{6,3,12},{6,12,3},{6,3,13},{6,13,3},{6,3,14},{6,14,3},{6,3,15},{6,15,3},{6,3,16},{6,16,3},{6,3,17},{6,17,3},{6,3,18},{6,18,3},{6,3,19},{6,19,3},{6,3,20},{6,20,3},{6,4,4},{6,4,4},{6,4,5},{6,5,4},{6,4,7},{6,7,4},{6,4,8},{6,8,4},{6,4,10},{6,10,4},{6,4,11},{6,11,4},{6,4,13},{6,13,4},{6,4,14},{6,14,4},{6,4,16},{6,16,4},{6,4,17},{6,17,4},{6,4,19},{6,19,4},{6,4,20},{6,20,4},{6,5,5},{6,5,5},{6,5,7},{6,7,5},{6,5,8},{6,8,5},{6,5,9},{6,9,5},{6,5,10},{6,10,5},{6,5,11},{6,11,5},{6,5,13},{6,13,5},{6,5,14},{6,14,5},{6,5,15},{6,15,5},{6,5,16},{6,16,5},{6,5,17},{6,17,5},{6,5,19},{6,19,5},{6,5,20},{6,20,5},{6,7,7},{6,7,7},{6,7,8},{6,8,7},{6,7,9},{6,9,7},{6,7,10},{6,10,7},{6,7,11},{6,11,7},{6,7,13},{6,13,7},{6,7,14},{6,14,7},{6,7,15},{6,15,7},{6,7,16},{6,16,7},{6,7,17},{6,17,7},{6,7,19},{6,19,7},{6,7,20},{6,20,7},{6,8,8},{6,8,8},{6,8,10},{6,10,8},{6,8,11},{6,11,8},{6,8,13},{6,13,8},{6,8,14},{6,14,8},{6,8,16},{6,16,8},{6,8,17},{6,17,8},{6,8,19},{6,19,8},{6,8,20},{6,20,8},{6,9,9},{6,9,9},{6,9,11},{6,11,9},{6,9,13},{6,13,9},{6,9,15},{6,15,9},{6,9,17},{6,17,9},{6,9,19},{6,19,9},{6,10,10},{6,10,10},{6,10,11},{6,11,10},{6,10,13},{6,13,10},{6,10,14},{6,14,10},{6,10,16},{6,16,10},{6,10,17},{6,17,10},{6,10,19},{6,19,10},{6,10,20},{6,20,10},{6,11,11},{6,11,11},{6,11,13},{6,13,11},{6,11,14},{6,14,11},{6,11,15},{6,15,11},{6,11,16},{6,16,11},{6,11,17},{6,17,11},{6,11,19},{6,19,11},{6,11,20},{6,20,11},{6,13,13},{6,13,13},{6,13,14},{6,14,13},{6,13,15},{6,15,13},{6,13,16},{6,16,13},{6,13,17},{6,17,13},{6,13,19},{6,19,13},{6,13,20},{6,20,13},{6,14,14},{6,14,14},{6,14,16},{6,16,14},{6,14,17},{6,17,14},{6,14,19},{6,19,14},{6,14,20},{6,20,14},{6,15,15},{6,15,15},{6,15,17},{6,17,15},{6,15,19},{6,19,15},{6,16,16},{6,16,16},{6,16,17},{6,17,16},{6,16,19},{6,19,16},{6,16,20},{6,20,16},{6,17,17},{6,17,17},{6,17,19},{6,19,17},{6,17,20},{6,20,17},{6,19,19},{6,19,19},{6,19,20},{6,20,19},{6,20,20},{6,20,20},{-1,-1,-1}};
bool AC[50][50][50];
int main(){
    freopen("D-large.in" , "r" , stdin);
    freopen("D.out" , "w" , stdout);
    RST(AC);
    for (int i = 0 ; ac[i][0] != -1 ; ++i)
        AC[ac[i][0]][ac[i][1]][ac[i][2]] = 1;
    Case = 0;
    Rush{
        int a , b , c;
        RD(a , b , c);
        printf("Case #%d: " , ++Case);
        if (AC[a][b][c]) puts("RICHARD");
        else puts("GABRIEL");
    }
}
