#include "cstdio"
#include "iostream"
#include "time.h"
#include "algorithm"
#include "cmath"
#include "cstring"
#include "cstdlib"
#include "vector"
#include "queue"
#include "set"
#include "map"
#include "climits"
#include "cassert"
#include "bitset"
#include "complex"
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define rep(i, n) for(int i=0; i<n; i++)
#define repp(i, a, b) for(int i=a; i<a+b; i++)
using namespace std;
#define SZ size()
#define PB push_back
#define MK make_pair
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define ITR iterator
#define LB lower_bound
#define UB upper_bound
#define PII pair<int, int>
#define CLR(a) memset(a, 0, sizeof(a))
int getint(){
    int s = 0, o = 1;
    char c;
    for(c = getchar(); c<'0'||c>'9';c = getchar()) if(c=='-') o = -1;
    for(;c>='0'&&c<='9'; c = getchar()) s *=10, s+=c-'0';
    return s*o;
}
const int maxn = 1001;
int a[maxn];

int main(int argc, char const *argv[])
{
	int cas = getint();
	rep(ca,cas){
		int n = getint();
		rep(i,n) a[i] = getint();
		int r = 1001;
		repp(i,1,1000){
			int rr = 0;
			rep(j,n){
				rr += (a[j] - 1) / i;
			}
			rr += i;
			if(rr<r) r = rr;
			// if(i<10) printf("%d %d \n", i, rr);
		}
		printf("Case #%d: %d\n", ca+1, r);
	}	
	return 0;
}