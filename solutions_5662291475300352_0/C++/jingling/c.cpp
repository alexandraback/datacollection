
#include <algorithm>
#include <numeric>
#include <functional>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <unordered_set>
#include <unordered_map>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <ctime>
using namespace std;




#define PP_NARG(...)    PP_NARG_(__VA_ARGS__,PP_RSEQ_N())
#define PP_NARG_(...)   PP_ARG_N(__VA_ARGS__)

#define PP_ARG_N( \
        _1, _2, _3, _4, _5, _6, _7, _8, _9,_10,  \
        _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
        _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
        _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
        _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
        _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
        _61,_62,_63,N,...) N

#define PP_RSEQ_N() \
        63,62,61,60,                   \
        59,58,57,56,55,54,53,52,51,50, \
        49,48,47,46,45,44,43,42,41,40, \
        39,38,37,36,35,34,33,32,31,30, \
        29,28,27,26,25,24,23,22,21,20, \
        19,18,17,16,15,14,13,12,11,10, \
        9,8,7,6,5,4,3,2,1,0


/* need extra level to force extra eval */
#define Paste(a,b) a ## b
#define XPASTE(a,b) Paste(a,b)

/* APPLYXn variadic X-Macro by M Joshua Ryan      */
/* Free for all uses. Don't be a jerk.            */
/* I got bored after typing 15 of these.          */
/* You could keep going upto 64 (PPNARG's limit). */
#define APPLYX1(a)           X_X(a)
#define APPLYX2(a,b)         X_X(a) X_X(b)
#define APPLYX3(a,b,c)       X_X(a) X_X(b) X_X(c)
#define APPLYX4(a,b,c,d)     X_X(a) X_X(b) X_X(c) X_X(d)
#define APPLYX5(a,b,c,d,e)   X_X(a) X_X(b) X_X(c) X_X(d) X_X(e)
#define APPLYX6(a,b,c,d,e,f) X_X(a) X_X(b) X_X(c) X_X(d) X_X(e) X_X(f)
#define APPLYX7(a,b,c,d,e,f,g) \
    X_X(a) X_X(b) X_X(c) X_X(d) X_X(e) X_X(f) X_X(g)
#define APPLYX8(a,b,c,d,e,f,g,h) \
    X_X(a) X_X(b) X_X(c) X_X(d) X_X(e) X_X(f) X_X(g) X_X(h)
#define APPLYX9(a,b,c,d,e,f,g,h,i) \
    X_X(a) X_X(b) X_X(c) X_X(d) X_X(e) X_X(f) X_X(g) X_X(h) X_X(i)
#define APPLYX10(a,b,c,d,e,f,g,h,i,j) \
    X_X(a) X_X(b) X_X(c) X_X(d) X_X(e) X_X(f) X_X(g) X_X(h) X_X(i) X_X(j)
#define APPLYX11(a,b,c,d,e,f,g,h,i,j,k) \
    X_X(a) X_X(b) X_X(c) X_X(d) X_X(e) X_X(f) X_X(g) X_X(h) X_X(i) X_X(j) X_X(k)
#define APPLYX12(a,b,c,d,e,f,g,h,i,j,k,l) \
    X_X(a) X_X(b) X_X(c) X_X(d) X_X(e) X_X(f) X_X(g) X_X(h) X_X(i) X_X(j) X_X(k) X_X(l)
#define APPLYX13(a,b,c,d,e,f,g,h,i,j,k,l,m) \
    X_X(a) X_X(b) X_X(c) X_X(d) X_X(e) X_X(f) X_X(g) X_X(h) X_X(i) X_X(j) X_X(k) X_X(l) X_X(m)
#define APPLYX14(a,b,c,d,e,f,g,h,i,j,k,l,m,n) \
    X_X(a) X_X(b) X_X(c) X_X(d) X_X(e) X_X(f) X_X(g) X_X(h) X_X(i) X_X(j) X_X(k) X_X(l) X_X(m) X_X(n)
#define APPLYX15(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) \
    X_X(a) X_X(b) X_X(c) X_X(d) X_X(e) X_X(f) X_X(g) X_X(h) X_X(i) X_X(j) X_X(k) X_X(l) X_X(m) X_X(n) X_X(o)
#define APPLYX_(M, ...) M(__VA_ARGS__)
#define APPLYXn(...) APPLYX_(XPASTE(APPLYX, PP_NARG(__VA_ARGS__)), __VA_ARGS__)

#define X_X(x) cerr<<#x<<" = "<<(x)<<" , ";

//#define debug(...)  do{APPLYXn(__VA_ARGS__);cerr<<endl;}while(0);
#define debug(...)  do{cerr<<__FILE__<<":"<<__LINE__<<": |Ddb|::: "; APPLYXn(__VA_ARGS__);cerr<<endl;}while(0);


template <typename T1, typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p);
template<typename T> inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v);
template<typename T> inline std::ostream &operator << (std::ostream & os,const std::set<T>& v);
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v);
template<typename T> inline std::ostream &operator << (std::ostream & os,const std::unordered_set<T>& v);
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os,const std::unordered_map<T1, T2>& v);

template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
{  return os << "(" << p.first << ", " << p.second << ")";}

template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
{ os<<"[ ";for(auto & x : v)os<<x<<", "; return os<<" ]";}

template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
{ os<<"[ ";for(auto & x : v)os<<x<<", "; return os<<" ]";}

template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
{ os<<"[ ";for(auto & x : v)os<<x<<", "; return os<<" ]";}

template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::unordered_set<T>& v)
{ os<<"[ ";for(auto & x : v)os<<x<<", "; return os<<" ]";}

template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::unordered_map<T1, T2>& v)
{ os<<"[ ";for(auto & x : v)os<<x<<", "; return os<<" ]";}


/*-------------your code should start blow---------------------------------*/

int main(int argc, char *argv[])
{
  std::ios::sync_with_stdio(false);

  int __T;
  cin>>__T;
  for(int __t = 1 ; __t <= __T; __t++){

    int n;cin>>n;
    vector<int> p(n), c(n), s(n);
    int total = 0;
    for(int i = 0 ; i < n; i++){
      cin>>p[i]>>c[i]>>s[i];
      total += c[i];
    }
    int ans = 0;
    if(total == 2){
      if(n==1){
        //(360 + 360 - p[0]) / (360 / s[0]) * (360 / (s[0]+1)) < 360 - p[0]
        auto a = (long long) (360 + 360 - p[0]) * s[0],
          b = (long long) (s[0]+1) * (360-p[0]);
        debug(a, b, a-b);
        if(a==b){
          ans = 2;
        }
        else if(a < b){
          ans = 1;
        }
      }else{
        if(s[0] > s[1]){
          swap(s[0], s[1]);
          swap(p[0], p[1]);
        }
        auto a = (long long) (360 + 360 - p[0]) * s[0], b = (long long) (s[1]) * (360-p[1]);
        debug(a, b, a-b);
        if(a==b){
          ans = 2;
        }
        else if( a <= b){
          ans = 1;
        }
      }
    }

    debug(p, c, s, ans);

    cout<<"Case #"<<__t<<": "<<setprecision(9)<<ans<<endl;
  }

    return 0;
}
