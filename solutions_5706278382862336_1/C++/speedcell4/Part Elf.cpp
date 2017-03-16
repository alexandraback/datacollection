/*
 Author : Speedcell
 Update : 2013-10-16
Version : soppYcell 2.4
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <memory>
#include <complex>
#include <numeric>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#include <locale.h>

using namespace std;

#pragma pack(4)

#ifndef __CONSTANT__
#define __CONSTANT__

typedef long long LONG;

const double pi = acos(-1.0);
const int   inf = 0x7f7f7f7f;
const LONG  INF = 0x7f7f7f7f7f7f7f7fll;

const int go[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

#endif // __CONSTANT__

#ifndef __IO__
#define __IO__

inline bool RD(int    & a) {return scanf("%d",&a)!=EOF;}
inline bool RD(char   & a) {return scanf("%c",&a)!=EOF;}
inline bool RD(char   * a) {return scanf("%s", a)!=EOF;}
inline bool RD(double & a) {return scanf("%lf",&a)!=EOF;}
inline bool RD(LONG   & a) {return scanf("%I64d",&a)!=EOF;}

template<class T1> inline bool
	IN(T1 & a) {return RD(a);}
template<class T1,class T2> inline bool
	IN(T1 & a,T2 & b) {return RD(a)&&RD(b);}
template<class T1,class T2,class T3> inline bool
	IN(T1 & a,T2 & b,T3 & c) {return RD(a)&&RD(b)&&RD(c);}
template<class T1,class T2,class T3,class T4> inline bool
	IN(T1 & a,T2 & b,T3 & c,T4 & d) {return RD(a)&&RD(b)&&RD(c)&&RD(d);}
template<class T1,class T2,class T3,class T4,class T5> inline bool
	IN(T1 & a,T2 & b,T3 & c,T4 & d,T5 & e) {return RD(a)&&RD(b)&&RD(c)&&RD(d)&&RD(e);}
template<class T1,class T2,class T3,class T4,class T5,class T6> inline bool
	IN(T1 & a,T2 & b,T3 & c,T4 & d,T5 & e,T6 & f) {return RD(a)&&RD(b)&&RD(c)&&RD(d)&&RD(e)&&RD(f);}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> inline bool
	IN(T1 & a,T2 & b,T3 & c,T4 & d,T5 & e,T6 & f,T7 & g) {return RD(a)&&RD(b)&&RD(c)&&RD(d)&&RD(e)&&RD(f)&&RD(g);}

inline void PT(int    	a) {printf("%d",a);}
inline void PT(char   	a) {printf("%c",a);}
inline void PT(char   * a) {printf("%s",a);}
inline void PT(double 	a) {printf("%f",a);}
inline void PT(unsigned a) {printf("%u",a);}
inline void PT(LONG   	a) {printf("%I64d",a);}
inline void PT(string 	a) {printf("%s",a.c_str());}
inline void PT(const char a[]) {printf("%s",a);}

template<class T1> inline void
	OT(T1 a) {PT(a);}
template<class T1,class T2> inline void
	OT(T1 a,T2 b) {PT(a),PT(' '),PT(b);}
template<class T1,class T2,class T3> inline void
	OT(T1 a,T2 b,T3 c) {PT(a),PT(' '),PT(b),PT(' '),PT(c);}
template<class T1,class T2,class T3,class T4> inline void
 	OT(T1 a,T2 b,T3 c,T4 d) {PT(a),PT(' '),PT(b),PT(' '),PT(c),PT(' '),PT(d);}
template<class T1,class T2,class T3,class T4,class T5> inline void
	OT(T1 a,T2 b,T3 c,T4 d,T5 e) {PT(a),PT(' '),PT(b),PT(' '),PT(c),PT(' '),PT(d),PT(' '),PT(e);}
template<class T1,class T2,class T3,class T4,class T5,class T6> inline void
	OT(T1 a,T2 b,T3 c,T4 d,T5 e,T6 f) {PT(a),PT(' '),PT(b),PT(' '),PT(c),PT(' '),PT(d),PT(' '),PT(e),PT(' '),PT(f);}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> inline void
	OT(T1 a,T2 b,T3 c,T4 d,T5 e,T6 f,T7 g) {PT(a),PT(' '),PT(b),PT(' '),PT(c),PT(' '),PT(d),PT(' '),PT(e),PT(' '),PT(f),PT(' '),PT(g);}

template<class T1> inline void
	OL(T1 a) {OT(a),PT('\n');}
template<class T1,class T2> inline void
	OL(T1 a,T2 b) {OT(a,b),PT('\n');}
template<class T1,class T2,class T3> inline void
	OL(T1 a,T2 b,T3 c) {OT(a,b,c),PT('\n');}
template<class T1,class T2,class T3,class T4> inline void
	OL(T1 a,T2 b,T3 c,T4 d) {OT(a,b,c,d),PT('\n');}
template<class T1,class T2,class T3,class T4,class T5> inline void
	OL(T1 a,T2 b,T3 c,T4 d,T5 e) {OT(a,b,c,d,e),PT('\n');}
template<class T1,class T2,class T3,class T4,class T5,class T6> inline void
	OL(T1 a,T2 b,T3 c,T4 d,T5 e,T6 f) {OT(a,b,c,d,e,f),PT('\n');}
template<class T1,class T2,class T3,class T4,class T5,class T6,class T7> inline void
	OL(T1 a,T2 b,T3 c,T4 d,T5 e,T6 f,T7 g) {OT(a,b,c,d,e,f,g),PT('\n');}

#endif // __IO__

#ifndef __MACRO__
#define __MACRO__

#define ML(times) int tcase; IN(tcase); FOR(times,1,tcase)

#define FOR(i,a,b) for(int i=int(a),_##i=int(b);i<=_##i;i++)
#define DWN(i,b,a) for(int i=int(b),_##i=int(a);_##i<=i;i--)
#define ECH(i,u,pre,next) for(int i=int(pre[u]);i!=-1;i=int(next[i]))

#define MEM(a,v) memset(a,v,sizeof(a))
#define CLR(a,v) FOR(_i##a,0,sizeof(a)/sizeof(a[0])-1) a[_i##a]=v

#define LOOP(a,n)                                               \
    FOR(_i##a,0,(n)-1)                                          \
        OT(a[_i##a]),OT(_i##a!=__i##a?' ':'\n')
#define LOOP2(a,n,m)                                            \
    FOR(_i##a,0,(n)-1) FOR(_j##a,0,(m)-1)                       \
        OT(a[_i##a][_j##a]),OT(_j##a!=__j##a?' ':'\n')
#define LOOPG(G,n,pre,next)                                     \
    FOR(_i##a,0,(n)-1) ECH(_j##a,_i##a,pre,next)                \
        OL(_i##a,G[_j##a].v,G[_j##a].w)

#endif // __MACRO__

#ifndef __BIT__
#define __BIT__

template<class T> inline T lb(T i) {return i&-i;}
template<class T> inline T lc(T i) {return i<<1;}
template<class T> inline T rc(T i) {return i<<1|1;}
template<class T> inline T at(T a,int i) {return a& (T(1)<<i);}
template<class T> inline T nt(T a,int i) {return a^ (T(1)<<i);}
template<class T> inline T s1(T a,int i) {return a| (T(1)<<i);}
template<class T> inline T s0(T a,int i) {return a&~(T(1)<<i);}

#endif // __BIT__

#ifndef __NUMBER__
#define __NUMBER__

template<size_t RANGE>
class Prime
{
private:
	int _cnt,_prime[RANGE],_factor[RANGE];
public:
	Prime(void) {
		_cnt=0; CLR(_factor,1);
		FOR(i,2,RANGE-1) if(_factor[i]==1) {
			_prime[_cnt++]=i;
			for(int j=i+i;RANGE>j;j+=i) _factor[j]=i;
		}
	}
	inline int operator [](int i) {
		return _prime[i];
	}
	inline size_t size(void) {
		return _cnt;
	}
	inline int factor(int val) {
		if(val<RANGE)
			return _factor[val];
		else {
			FOR(i,0,_cnt-1) if(val%_prime[i]==0)
				return _prime[i];
			return 1;
		}
	}
};

template<typename type> inline
type pow(type a,size_t b)
{
	if(!b) return 1;
	else
	{
		type ans=pow(a,b/2);
		if(b%2==0) return ans*ans;
		else return ans*ans*a;
	}
}

template<typename type> inline
type pow(type a,size_t b,type MOD)
{
	if(!b) return 1;
	else
	{
		type ans=pow(a,b/2);
		if(b%2==0) return (ans*ans)%MOD;
		else return (((ans*ans)%MOD)*a)%MOD;
	}
}

#endif // __NUMBER__

#ifndef __COMPARER__
#define __COMPARER__

const double eps = 1e-8;

inline int cmp(double a,double b=0) {return fabs(b-a)<eps?0:((b-a)<eps?+1:-1);}
template<typename type> inline int cmp(type a,type b=0) {return a==b?0:(b<a?+1:-1);}

template<typename type> inline bool gt(type a,type b) {return cmp(a,b)> 0;}
template<typename type> inline bool ge(type a,type b) {return cmp(a,b)>=0;}
template<typename type> inline bool eq(type a,type b) {return cmp(a,b)==0;}
template<typename type> inline bool ne(type a,type b) {return cmp(a,b)!=0;}
template<typename type> inline bool le(type a,type b) {return cmp(a,b)<=0;}
template<typename type> inline bool ls(type a,type b) {return cmp(a,b)< 0;}

template<typename type> inline type smax(type a,type b) {return gt(a,b)?a:b;}
template<typename type> inline type smin(type a,type b) {return ls(a,b)?a:b;}

#endif // __COMPARER__

LONG gcd(LONG a,LONG b)
{
	if(!b) return a;
	else return gcd(b,a%b);
}
bool check(LONG val)
{
	while(val!=1)
	{
		if(val%2!=0) return false;
		else val/=2;
	}
	return true;
}

LONG p,q;

int main(int argc,char const *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    #else
    #endif

    ML(times)
    {
    	scanf("%lld/%lld",&p,&q);
    	LONG _gcd=gcd(p,q);
    	p/=_gcd;
    	q/=_gcd;
    	printf("Case #%d: ",times);
    	if(check(q))
		{
			int cnt=0;
			while(p<q) p*=2,cnt++;
			OL(cnt);
		}
		else OL("impossible");
    }

    return 0;
}
