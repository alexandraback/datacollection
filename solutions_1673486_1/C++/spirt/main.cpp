#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define re return
#define fi first
#define se second
#define rep(i, n) for(int (i)=0;(i)<(int)(n);++i)
#define repd(i, n) for(int (i)=(n)-1; (i)>=0; --(i))
#define rep2(i, st, en) for(int (i)=(st); (i)<=(int)(en); ++(i))
#define repd2(i, st, en) for(int (i)=(st); (i)>=(int)(en); --(i))
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

// Types
typedef long double ld;
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > si;
typedef vector < ld > vd;
typedef vector < int > vi;
typedef vector < bool > vb;
typedef vector < string > vs;
typedef map < string, int > msi;
typedef pair < int, int > pii;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;


int a, b;
float p[99999];

float process(){
	float r= 0, r1= 0, r2= 0, rtmp = 0;
	clr(p);
	scanf("%d %d", &a, &b);
	float c=1;
	rep(i, a) {
		scanf("%f", &p[i]);
		c*=p[i];
	}	
	r = c * (b - a  + 1) + (1-c)*(2 * b - a + 2);
	
	r1 = b + 2;
	r = min(r1,r);

	rep2(i, 1, a){
		c = 1;
		rep(j, a - i) {
			c*=p[j];
		}	
		rtmp = c * (i + b - a + i + 1) + (1 - c) * (i + b - a + i + 1 + b + 1);
		r = min(r, rtmp);
	}
	return r;
}

int main(void){
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc) {
		printf("Case #%d: %.6f\n", tc, process());
	}	
}