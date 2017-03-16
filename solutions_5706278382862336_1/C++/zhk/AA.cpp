#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include <vector>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>inline string to_str(const T& v) {
    ostringstream os; os << v; return os.str();
}
template<typename T>inline T to_obj(const string& v) {
    istringstream is(v); T r; is>>r; return r;
}
template<class T>inline int cMin(T& a, T b) {return b<a ? a=b,1 : 0;}
template<class T>inline int cMax(T& a, T b) {return a<b ? a=b,1 : 0;}

#define CLR(A,v) memset(A, v, sizeof(A))
#define MP(a,b)  make_pair(a, b)
#define F0(i, n) for(int i=0; i<(n); ++i)
#define F1(i, n) for(int i=1; i<=(n); ++i)


template<class T>inline T iabs(T v) {return v<0 ? -v : v;}

typedef long long int64;
struct Fract {
	int64  top, low;
	Fract():top(0), low(1){}
	Fract(int64 Top, int64 Low=1):top(Top), low(Low) {normal();}
	int64  gcd(int64 a, int64 b) {
		if(!a || !b) return 1;
		int64  t; while(b) {t = a%b; a=b; b=t;}
		return a;
	}
	void normal() {
		if(!top) {low=1; return;}
		if(low < 0) {low=-low; top=-top;}
		int64  g=gcd(iabs(top), iabs(low));
		if(g>1) {top /= g;  low /= g;}
	}
	bool operator <(const Fract& v)const {return top*v.low < low*v.top;}
	bool operator >(const Fract& v)const {return low*v.top < top*v.low;}
	bool operator==(const Fract& v)const {return top==v.top && low==v.low;}
	bool operator<=(const Fract& v)const {return top*v.low <= low*v.low;}
	bool operator>=(const Fract& v)const {return low*v.top <= top*v.low;}
	bool operator!=(const Fract& v)const {return top!=v.top || low!=v.low;}
	Fract operator +(const Fract& v)const {return Fract(top*v.low+low*v.top, low*v.low);}
	Fract operator -(const Fract& v)const {return Fract(top*v.low-low*v.top, low*v.low);}
	Fract operator *(const Fract& v)const {return Fract(top*v.top, low*v.low);}
	Fract operator /(const Fract& v)const {return Fract(top*v.low, low*v.top);}
	Fract& operator -() {top = -top; return *this;}
	Fract& operator +=(const Fract& v) {
		top = top*v.low + low*v.top;  low *= v.low;
		normal();  return *this;
	}
	Fract& operator -=(const Fract& v) {
		top = top*v.low - low*v.top;  low *= v.low;
		normal();  return *this;
	}
	Fract& operator *=(const Fract& v) {
		top *= v.top;  low *= v.low;
		normal();  return *this;
	}
	Fract& operator /=(const Fract& v) {
		top *= v.low;  low *= v.top;
		normal();  return *this;
	}
};

typedef long long i64;

void gen(int n) {
    set<Fract> A;
    A.insert(Fract(0, 1));
    A.insert(Fract(1, 1));
    for(int i=1; i<n; ++i) {
        set<Fract> B;
        typedef set<Fract>::iterator it_t;
        for(it_t j=A.begin(); j!=A.end(); ++j) {
            for(it_t k=A.begin(); k!=A.end(); ++k) {
                B.insert( ((*j) + (*k))*Fract(1,2));
            }
        }
        cout << i << ": \n";
        for(it_t j=B.begin(); j!=B.end(); ++j) {
            cout << ", " << j->top << "/" << j->low;
        }
        cout << endl;
        A = B;
    }
}

int level(i64 a) {
    int cnt = 0;
    for(i64 b = a; (b&1) == 0; b>>=1)
        ++cnt;
    return cnt;
}

int calc(i64 P, i64 Q) {
    if(P == 1) {
        return level(Q);
    }
    if(Q == 1) return 0;
    if (P*2 > Q) {
        // Fract tmp(P*2-Q, Q);
        // if(level(tmp.low) < M)
        return 1;
        // return -1;
    }
    return calc(P, Q/2) + 1;
    // Fract tmp(P, Q/2);
    // int t = level(tmp.low);
    // if(t > M) return -1;
    // return t;
}

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    for(int iT=1; iT<=T; ++iT) {
        long long a, b;
        scanf("%lld/%lld", &a, &b);
        Fract tmp(a, b);
        printf("Case #%d: ", iT);
        if ((tmp.low - 1) & tmp.low) {
            printf("impossible\n");continue;
        }
        int ret = calc(tmp.top, tmp.low);
        int  cnt = ret;
        // for(; (1LL<<cnt) < tmp.low; ++cnt);
        printf("%d\n", cnt);
    }
    return 0;
}
