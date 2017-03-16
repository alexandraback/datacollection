// Author: Zhang Kai (hapsunday@gmail.com)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <climits>
#include <cfloat>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <bitset>
#include <valarray>
#include <complex>
#include <numeric>
#include <iterator>
#include <functional>
#include <algorithm>
using namespace std;


#define ALL(A)		(A).begin(), (A).end()
#define CLR(A, v)	memset(A, v, sizeof(A));
#define FOR(i, N)	for(int i=0; i<(N); ++i)
#define MP(A, B)	make_pair(A, B)
#define TWO(i)		(i<32 ? 1U<<(i) : 1ULL<<(i))
#define CONTAIN(S,i)  (((S)&TWO(i)) != 0)
#define LEN(str)	((int)(str).length())
#define SIZE(v)		((int)(v).size())

#define VAR(v,t)	__typeof__(t) v=(t)
#define F0(i, n)	for(int i=0; i<(int)(n); ++i)
#define F1(i, n)	for(int i=1; i<=(int)(n); ++i)
#define F2(i, s, e)	for(int i=(int)(s); i<(int)(e); ++i)
#define FE(it, s)	for(VAR(it,(s).begin()); it!=(s).end(); ++it)

#define DEBUG_PRINT(x) fprintf(stderr, "%s:%d -->  %s = [%s]\n",        \
                               __FUNCTION__,__LINE__, #x, to_str(x).c_str());
// debug
#define debug(x)	DEBUG_PRINT(x)
#define trace(x)	fprintf(stderr, "%s:%d --> %s\n", __FUNCTION__,__LINE__, #x);


template<class T>inline int cMin(T& a, T b) {return b<a ? a=b,1 : 0;}
template<class T>inline int cMax(T& a, T b) {return a<b ? a=b,1 : 0;}
template<class T>inline string to_str(T v){ostringstream os;os<<v;return os.str();}


const double EPS=1e-8;
const double PI=acos(-1.0);

template<class T>inline T   isqr(T v) {return v*v;}
template<class T>inline T   iabs(T v) {return v<0 ? -v : v;}
template<class T>inline int isgn(T v) {return (v>EPS) - (v<-EPS);}


/////////////////////////////////////////////
const int NN = 256;

int  A, N;
int  mote[NN];

int calc(int& A, int L) {
    if(A > L) return 0;
    int cc = 0;
    while(A <= L) {
        ++cc;
        A += A-1;
    } return cc;
}

int go() {
    if(A <= 1) return N;
    sort(mote, mote+N);
    int idx = 0;
    for(; idx<N && mote[idx]<A; ++idx)
        A += mote[idx];
    if(idx == N) return 0;
    int  ans = 0;
    while(idx < N) {
        int  B = A;
        int  cur = calc(B, mote[idx]);
        if(cur < N-idx) {
            A = B + mote[idx];
            ans += cur;
            ++idx;
        }
        else {
            ans += N-idx;
            break;
        }
    }
    return ans;
}


int main(int argc, char* argv[]) {
    int  num_case;
    scanf("%d", &num_case);
    for(int case_idx=1; case_idx<=num_case; ++case_idx) {
        scanf("%d%d", &A, &N);
        F0(i, N) scanf("%d", mote+i);
        printf("Case #%d: %d\n", case_idx, go());
    }
    return 0;
}
