#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
/** Constant List .. **/ //{
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0 , -1 , -1 , 1 , 1};
const int dy8[] = {0, 1, 0, -1 , -1 , 1 , -1 , 1};
const int dxhorse[] = {-2 , -2 , -1 , -1 , 1 , 1 , 2 , 2};
const int dyhorse[] = {1 ,  -1 , 2  , -2 , 2 ,-2 , 1 ,-1};
const int inf = 0x3f3f3f3f;
const LL inff = 1LL << 60;
const double eps = 1e-9;
const double oo = 1e25;
const double pi = acos(-1.0); //M_PI;
//}
/** Add On .. **/ //{
// <<= '1. Bitwise Operation ., //{
namespace BO{
inline bool _1(int x, int i){return bool(x&1<<i);}
inline bool _1(LL x, int i){return bool(x&1LL<<i);}
inline LL _1(int i){return 1LL<<i;}
inline LL _U(int i){return _1(i) - 1;};
inline int reverse_bits(int x){x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);x = ((x >>16) & 0x0000ffff) | ((x <<16) & 0xffff0000);return x;}
inline LL reverse_bits(LL x){x = ((x >> 1) & 0x5555555555555555LL) | ((x << 1) & 0xaaaaaaaaaaaaaaaaLL);x = ((x >> 2) & 0x3333333333333333LL) | ((x << 2) & 0xccccccccccccccccLL);x = ((x >> 4) & 0x0f0f0f0f0f0f0f0fLL) | ((x << 4) & 0xf0f0f0f0f0f0f0f0LL);x = ((x >> 8) & 0x00ff00ff00ff00ffLL) | ((x << 8) & 0xff00ff00ff00ff00LL);x = ((x >>16) & 0x0000ffff0000ffffLL) | ((x <<16) & 0xffff0000ffff0000LL);x = ((x >>32) & 0x00000000ffffffffLL) | ((x <<32) & 0xffffffff00000000LL);return x;}
template<class T> inline bool odd(T x){return x&1;}
template<class T> inline bool even(T x){return !odd(x);}
template<class T> inline T low_bit(T x) {return x & -x;}
template<class T> inline T high_bit(T x) {T p = low_bit(x);while (p != x) x -= p, p = low_bit(x);return p;}
template<class T> inline T cover_bit(T x){T p = 1; while (p < x) p <<= 1;return p;}
template<class T> inline int cover_idx(T x){int p = 0; while (_1(p) < x ) ++p; return p;}
#ifdef __GNUC__
inline int clz(int x){return __builtin_clz(x);}
inline int clz(LL x){return __builtin_clzll(x);}
inline int ctz(int x){return __builtin_ctz(x);}
inline int ctz(LL x){return __builtin_ctzll(x);}
inline int lg2(int x){return !x ? -1 : 31 - clz(x);}
inline int lg2(LL x){return !x ? -1 : 63 - clz(x);}
inline int low_idx(int x){return !x ? -1 : ctz(x);}
inline int low_idx(LL x){return !x ? -1 : ctz(x);}
inline int high_idx(int x){return lg2(x);}
inline int high_idx(LL x){return lg2(x);}
inline int parity(int x){return __builtin_parity(x);}
inline int parity(LL x){return __builtin_parityll(x);}
inline int count_bits(int x){return __builtin_popcount(x);}
inline int count_bits(LL x){return __builtin_popcountll(x);}
#endif
} using namespace BO;//}
// <<= '2. Number Theory .,//{
namespace NT{
template<class T> inline T lowbit(T x) {return x & -x;}///lowbit(x)
template <class T>inline T GCD(T A,T B){T C;while(B!=0)C=B,B=A%B,A=C;return A;}///GCD(a,b)
template <class T>inline T LCM(T A,T B){return A*(B/GCD(A,B));}///LCM(a,b)
template<class T>inline T Mod(T a,T b){a%=b;return a<0?a+b:a;}///计算a%b,支持a<=0
template<class T>inline T MulMod(T a,T b,T c)/**二分计算a*b mod c 可以处理c+c不溢出的情况**/{if(c==1)return 0;if(c<=0)return -1;T ret=0,tmp;tmp=a=Mod(a,c);b=Mod(b,c);while(b){if(b&0x1)if((ret+=tmp)>=c)ret-=c;if((tmp<<=1)>=c)tmp-=c;b>>=1;}return ret;}
template<class T,class Tb> inline T PowMod(Tb a,T b,T c)/**a^b mod c 要求c*c不溢出**/{if(c==1)return 0;if(c<=0)return -1;a=Mod(a,(Tb)c);Tb ret(1L%c);while(b){if(b&0x1)ret=ret*a%c;a=a*a%c;b>>=1;}return (T)ret;}
template<class T> inline T HPowMod(T a,T b,T c)/**二分计算a^b mod c 要求c+c不溢出**/{if(c==1)return 0;if(c<=0)return -1;a=Mod(a,c);T ret(1L%c);while(b){if(b&0x1)ret=MulMod(ret,a,c);a=MulMod(a,a,c);b>>=1;}return ret;}
template<class T,class Tb> inline T Pow(T a, Tb b)/**a^b*/{T c(1); while (b){if (b&1) c *= a;a *= a, b >>= 1;}return c;}
template <class T>inline T EXT_GCD(T a,T b,T& x,T& y)/**ax+by=gcd(a,b)**/{T t,ret;if (!b){x=1,y=0;return a;}ret=EXT_GCD(b,a%b,x,y);t=x,x=y,y=t-a/b*y;return ret;}
template <class T>inline T Inv(T a,T n)/**返回一个数a对于n的乘法逆元**/{if(n<=0)return -1;T d,x,y;d=EXT_GCD(a,n,x,y);if(d!=1)return -1;return Mod(x,n);}
template<class T, int MAXN, T MOD=-1>class Matrix/**Matrix**/ {public:T m[MAXN][MAXN];Matrix(){}void init(T num[MAXN][MAXN]){for(int i = 0 ; i < MAXN ; i++){for(int j = 0 ; j < MAXN ; j++){m[i][j] = num[i][j];if (MOD!=-1)  m[i][j] %= MOD;}}}
friend Matrix operator*(const Matrix &m1 ,const Matrix &m2) {int i, j, k;Matrix ret;memset(ret.m, 0, sizeof(ret.m));for (i = 0; i < MAXN; i++) {for (j = 0; j < MAXN; j++)if ( m1.m[i][j] ){for(k = 0 ; k < MAXN ; k++){ret.m[i][k] += m1.m[i][j] * m2.m[j][k];if (MOD!=-1) ret.m[i][k] %= MOD;}}}return ret;}
friend Matrix operator+(const Matrix &m1 ,const Matrix &m2) {int i, j;Matrix ret;for (i = 0; i < MAXN; i++) {for (j = 0; j < MAXN; j++) {ret.m[i][j] = 0;ret.m[i][j] = m1.m[i][j]+m2.m[i][j];if (MOD!=-1)  ret.m[i][j] %= MOD;}}return ret;}
friend Matrix operator^(const Matrix &_M , LL nx){Matrix ret,M(_M);for(int i = 0 ; i < MAXN ; i++){for(int j = 0 ; j < MAXN ; j++){if(i == j)ret.m[i][j] = 1;else ret.m[i][j] = 0;}}while(nx){if(nx & 1)ret = ret * M;nx = nx >> 1;M = M * M;}return ret;}
};///end of matrix
} using namespace NT;//}

// <<= '3. Date .,//{
namespace Date{
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
struct date{int year,month,day;};
inline int leap(int year)/**判闰年**/{return (year%4==0&&year%100!=0)||year%400==0;}
inline int legal(date a)/**判合法性**/{if (a.month<0||a.month>12) return 0;if (a.month==2)return a.day>0&&a.day<=28+leap(a.year);return a.day>0&&a.day<=days[a.month-1];}
inline int datecmp(date a,date b)/**比较日期大小**/{if (a.year!=b.year)return a.year-b.year;if (a.month!=b.month)return a.month-b.month;return a.day-b.day;}
int weekday(date a)/**返回指定日期是星期几**/{int tm=a.month>=3?(a.month-2):(a.month+10);int ty=a.month>=3?a.year:(a.year-1);return (ty+ty/4-ty/100+ty/400+(int)(2.6*tm-0.2)+a.day)%7;}
int date2int(date a)/**日期转天数偏移**/{int ret=a.year*365+(a.year-1)/4-(a.year-1)/100+(a.year-1)/400,i;days[1]+=leap(a.year);for (i=0;i<a.month-1;ret+=days[i++]);days[1]=28;return ret+a.day;}
date int2date(int a)/**天数偏移转日期**/{date ret;ret.year=a/146097*400;for (a%=146097;a>=365+leap(ret.year);a-=365+leap(ret.year),ret.year++);days[1]+=leap(ret.year);for (ret.month=1;a>=days[ret.month-1];a-=days[ret.month-1],ret.month++);days[1]=28;ret.day=a+1;return ret;}
}//using namespace Date;//}


// <<= '4. io .,//{
namespace IO{
template<class T> inline T RD(T &x){
    char c; for (c = getchar(); c < '-'; c = getchar());
    if (c == '-'){x = '0' - getchar(); for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + '0' - c;}
    else {x = c - '0'; for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';}
    return x;
}
inline LL RD(){LL x; return RD(x);}
}using namespace IO;//}
//}
void run(){
    int N;
    cin>>N;
    vector< vector<int> > p(2*N-1, vector<int>(N,0) );
    map<int,int> h;
    for(int i=0; i<2*N-1; i++){
        for(int j=0; j<N; j++){
            cin>>p[i][j];
            h[ p[i][j] ]++;
        }
    }
    vector<int> s;

    for( auto t : h )
        if( t.second%2 == 1 ) s.push_back(t.first);

    sort(s.begin(), s.end() );
    for(int i=0; i<N; i++){
        cout<<s[i];
        if( i==N-1 ) cout<<endl;else cout<<" ";
    }

}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T,cas=0;
    cin>>T;
    while (T--){
        cout<<"Case #"<<++cas<<": ";
        run();
    }
	return 0;
}
//zck
