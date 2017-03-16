/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : 1.cpp

* Purpose : SPOJ

* Creation Date : 12-05-2013

* Last Modified : Sunday 12 May 2013 02:42:34 PM IST

* Created By : npsabari

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iterator>
#include <cctype>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <climits>
#include <limits>
#include <string>
using namespace std;

//Macros
#define dbl double
#define fl float
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define vi vector<int>
#define vll vector<ll>

#define abs(x) ((x)<0?-(x):(x))
#define sqr(x) ((x)*(x))

#define MOD 1000000007
#define MAXN 100010
#define MAXBUF 5000000
#define EPS 1e-9
#define NIL 0
#define INF (INT_MAX/2)
#define LLINF (LONG_LONG_MAX/2LL)
#define NEWLINE '\n'

#define SET(A) memset(A, 1,sizeof(A));                     //NOTE: Works only for x = 0 and -1. Only for integers.
#define CLR(A) memset(A, 0,sizeof(A));
#define MEM(A,x) memset(A,x,sizeof(A));
#define CPY(A,B) memcpy(A,B,sizeof(A));

#define SIZE(A) ((int)(A.size()))
#define ALL(x)  x.begin(),x.end()
#define FILL(A,x) fill(ALL(A),x)
#define REP(i,N) for(int i=0;i<(int)(N); ++i)
#define FORab(i,a,b) for(int i=(int)(a);i<=(int)(b); ++i)
#define RFORab(i,a,b) for(int i=(int)(a);i>=(int)(b); --i)
#define FOR1(i,n) FORab(i,1,(n))
#define RFOR1(i,n) RFORab(i,(n),1)
#define FOR(i,n) FORab(i,0,(n)-1)
#define RFOR(i,n) RFORab(i,(n)-1,0)
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define SORTV(x) sort(ALL(x))
#define REVV(x) reverse(ALL(x))

#define GI ({int t;scanf("%d",&t);t;})                  //NOTE: Don't comma separate two inputs.
#define GLL ({long long t;scanf("%lld",&t);t;})          //NOTE: Don't comma separate two inputs.
#define GLD ({double t;scanf("%lf",&t);t;})              //NOTE: Don't comma separate two inputs.

#define MP make_pair
#define PB push_back
#define ff first
#define ss second

#define nbits(n) __builtin_popcount(n)                  //NOTE: Works only for int. Write your own function for long long :-/
#define atbit(x,i) (((x)>>(i))&1)
#define FIXMOD(a) (((a)%MOD+MOD)%MOD)

#define   debug(x)              if(!SUBMIT){ cout<<"-> "<<#x<<" = "<<x<<"\n";}
#define   debugv(x)             if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x))cout<<x[i]<<" ";cout<<"\n";}
#define   debugvv(x)            if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x)){REP(j,SIZE(x[i])){cout<<x[i][j]<<" ";}cout<<"\n";}}
#define   debug1(A,N)           if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,N)cout<<A[i]<<" ";cout<<"\n";}
#define   debug2(A,R,C)         if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,R){REP(j,C){cout<<A[i][j]<<" ";}cout<<"\n";}}

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

//template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (a > b ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
//template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool BTW(T a, T b, T c) { return a<=b && b<=c; }         // To check whether b is in [a,c]
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }                 // set max(a,b) to a
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }                 // set min(a,b) to b

#define SUBMIT false                                    //NOTE: Set this to true before submitting

// Fast IO

char *fstart;
char buf[MAXBUF];
char outbuf[MAXBUF];
int outat;
bool sign;

template <class T> inline void GETNUM(T& n){
     /* for skipping whitespaces - code */
    sign = false;
    while (*fstart != 0 && !('0' <= *fstart && *fstart <= '9')){
        if( *fstart == '-' )
            sign = true;
        fstart++;
    }
    n=0;
    while ('0' <= *fstart && *fstart <= '9')
        n = n*10 + *fstart-'0', ++fstart;
    n *= sign ? -1 : 1;
}

/* For getting uppercase letter only */
inline void GETCHAR(char& c){
    while(*fstart != 0 && !('A' <= *fstart && *fstart <= 'Z'))
        fstart++;
    c = *fstart;
    fstart++;
}

inline void GETSTR(char* c, int& len){
    while(!fstart != 0 && !('A' <= *fstart && *fstart <= 'Z'))
        fstart++;
    len = 0;
    while(*fstart != '\n' && *fstart != 32 && *fstart != '\0'){
        c[len++] = *fstart;
        ++fstart;
    }
}

inline void OUTC(char c){
    outbuf[outat++] = c;
}

template <class T> inline void OUTNUM(T x) {
    if(x < 0){
        x *= -1;
        OUTC('-');
    }
    char s[100];
    int at = 0;
    do{
        s[at++] = x%10;
        x/=10;
    }
    while(x>0);
    for (int i = at-1;i>=0;--i)
        outbuf[outat++] = s[i]+'0';
}

void flushoutbuf() {
    fwrite(outbuf,sizeof(char),outat, stdout);
    outat = 0;
}

void take_input() { // Take input using fast I/O
    int sz=fread(buf, sizeof(char), MAXBUF, stdin);
    buf[sz]=0;
    fstart=buf;
    outat = 0;
}

int main(){
    int c;
    cin>>c;
    int pos = 1;
    while(c--){
        string s;
        int n;
        cin>>s>>n;
        vi lst;
        for(int i = 0; i < s.length(); ++i){
            lst.PB( (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') ? 0 : 1);
        }
        int maincnt = 0;
        for(int i = 0; i < lst.size()-n+1; ++i){
            for(int j = i+n-1; j < lst.size(); ++j){
                int cnt = 0;
                bool flag = false;
                for(int k = i; k <= j; ++k){
                    if(lst[k] == 1)
                        cnt++;
                    else
                        cnt = 0;
                    if(cnt >= n){
                        flag = true;
                        break;
                    }
                }
                if(flag)
                    maincnt++;
            }
        }
        cout<<"Case #"<<pos<<": "<<maincnt<<endl;
        pos++;
    }
    return 0;
}
