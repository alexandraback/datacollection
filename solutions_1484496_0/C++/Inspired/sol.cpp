#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <ctime>
#include <stack>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <list>
using namespace std;
 
#define C(_a, _v) memset(_a,_v,sizeof(_a))
#define ALL(_obj) (_obj).begin(),(_obj).end()
#define FORB(_i,_a,_b) for((_i)=(_a);(_i)<(_b);++(_i))
#define FOR(_i,_n) FORB(_i,0,_n)
#define FORS(_i,_obj) FOR(_i,(_obj).size())
 
typedef long long i64;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<i64, i64> pii64;
typedef vector<pii> vpii;
 
template<typename T>inline bool remin(T&c,const T&n){if(n<c){c=n;return 1;}return 0;}
template<typename T>inline bool remax(T&c,const T&n){if(c<n){c=n;return 1;}return 0;}
template<typename T>inline void addmod(T& c,const T&n,const T&m){c=(c+n)%m;}
 
int _in;int in(){scanf("%d",&_in);return _in;}

// stuff cutline

int main() {
	freopen("C:\\Users\\anonymous\\Downloads\\C-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	bool done;
	int t = in(), it, n, i, m, sum, val[20], j, p, un, k;
	FOR (it, t) {
		printf("Case #%d:\n", it + 1);
		n = in();
		sum = 0;
		FOR (i, n) sum += val[i] = in();
		un = 1 << n;
		done = false;
		FOR (i, un) {
			sum = 0;
			FOR (j, n)
				if (((1 << j) & i) != 0)
					sum += val[j];
			if (sum % 2 != 0) continue;
			for (k = i; k != 0; k = (k - 1) & i) {
				p = 0;
				FOR (j, n)
					if (((1 << j) & k) != 0)
						p += val[j];
				if (p == sum / 2) {
					FOR (j, n)
						if (((1 << j) & i) != 0 && ((1 << j) & k) != 0)
							printf("%d ", val[j]);
					putchar('\n');
					FOR (j, n)
						if (((1 << j) & i) != 0 && ((1 << j) & k) == 0)
							printf("%d ", val[j]);
					putchar('\n');
					done = true;
					break;
				}
			}
			if (done) break;
		}
		if (!done) puts("Impossible");
	}
	return 0;
}