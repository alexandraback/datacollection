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


int n, a[1000], b[1000], stars;
bool resb[1000], resa[1000];
int process(){
	int result = 0;
	clr(a);
	clr(b);
	clr(resb);
	clr(resa);
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d %d", &a[i], &b[i]);
	}
	int stars = 0, passl = 0;
	bool passed = true;
	for (;passed && passl < n;) {
		passed = false;
		for(int i = 0; i < n && !passed; ++i) {
			if (stars >= b[i] && !resb[i]){
				if (!resa[i]) stars +=2;
				else ++stars;				
				resb[i] = true;
				++result;
				++passl;
				passed = true;
			}
		}

		if (!passed){
			for(int i = 0; i < n && !passed; ++i) {
				if (stars >= a[i]){
					++stars;				
					resa[i] = true;
					++result;
					passed = true;
				}
			}
		}
	}
	if (passed) return result;
	else return 0;
}

int main(void){
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc) {
		int result = process();
		if (result)
			printf("Case #%d: %d\n", tc, result);
		else 
			printf("Case #%d: Too Bad\n", tc);
	}	
}