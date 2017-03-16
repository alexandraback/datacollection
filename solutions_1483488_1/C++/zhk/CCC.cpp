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

#define DEBUG_PRINT(x) fprintf(stderr, "%s:%d -->  %s = [%s]\n", \
					__FUNCTION__,__LINE__, #x, to_str(x).c_str());
// debug
#define debug(x)	DEBUG_PRINT(x)
#define trace(x)	fprintf(stderr, "%s:%d --> %s\n", __FUNCTION__,__LINE__, #x);


template<class T>inline int cMin(T& a, T b) {return b<a ? a=b,1 : 0;}
template<class T>inline int cMax(T& a, T b) {return a<b ? a=b,1 : 0;}
template<class T>inline string to_str(T v){ostringstream os;os<<v;return os.str();}

const double pi = acos(-1.0);
const double eps = 1e-9;

template<class T>inline T   isqr(T v) {return v*v;}
template<class T>inline T   iabs(T v) {return v<0?-v:v;}
template<class T>inline int isgn(T v) {return iabs(v)<=eps?0:(v<0?-1:1);}


typedef vector<int>		VI;
typedef vector<string>	VS;
typedef pair<int, int>	PII;

typedef long long i64;
typedef unsigned long long u64;
typedef int i32;
typedef unsigned int u32;

template<typename T>inline T next(){static char buf[64];scanf("%s",buf);
istringstream is(buf);T v;is>>v;return v;}
inline int nextInt(){int v=0;scanf("%d",&v);return v;}
/////////////////////////////////////////////


const int NN = 2000000 + 8;
bool  tag[NN] = {false};
//int  f[NN] = {0};

int init(int A, int B) {
	int  ten[10] = {1, 10, 100, 1000, 10000};
	for(int i=2; i<10; ++i) ten[i] = ten[i-1]*10;
	int  z[12] = {0,2,0}, zn=2;
	int  v[12] = {0};
	int  r[12] = {0}, rn = 0;

	int  tmp = A;
	zn = 0;
	for(; tmp; ++zn) {
		z[zn] = tmp%10;
		tmp /= 10;
	}
	int  cnt = 0;
	for(int i=A+1; i<=B; ++i) {

		int k=0, cur;
		for(;z[k]==9;++k)z[k]=0;
		++z[k];
		zn += (zn==k);

		v[0] = z[0];
		for(k=1; k<zn; ++k) {
			v[k] = z[k]*ten[k]+v[k-1];
			//printf("k=%d  v[k]=%d\n", k, v[k]);
		}
		int  t = 0;
		rn = 0;
		for(k=zn-1; k>0; --k) {
			t = t*10 + z[k];
			//printf("t=%d  z[\n", t);
			cur = t+v[k-1]*ten[zn-k];
			
			if(z[k-1] && cur>=A && cur<i && !tag[cur]) {
				++cnt;
				r[rn++] = cur;
				tag[cur] = true;
			}
		}
		for(k=0; k<rn; ++k) tag[r[k]] = false;
	}
	return  cnt;
}
int go() {
	return 0;
}
int  main(int argc, char* argv[]) {
	//long  st = clock();
	//init();
	//printf("%ld\n", st);
	int  T;scanf("%d", &T);
	for(int it=1; it<=T; ++it) {
		int  A, B;
		scanf("%d%d", &A, &B);
		printf("Case #%d: %d\n", it, init(A, B));
	}
	return 0;
}

