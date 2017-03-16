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
const int maxn = 20000;
int op[5][5];
int a[maxn], b[30][maxn];
char s[maxn];
int n;
long long m;

map<char, int> mp;

int OP(int a, int b){
	int r = 1;
	if(a<0) a = -a, r = -r;
	if(b<0) b = -b, r = -r;
	return r * op[a][b];
}

int pow(int a, long long n){
	int r = 1;
	for(int t=a; n; n>>=1, t = OP(t, t)){
		if(n&1) r = OP(r, t);
	}
	return r;
}

int main(int argc, char const *argv[])
{
	op[1][1] = 1, op[1][2] = 2, op[1][3] = 3, op[1][4] = 4;
	op[2][1] = 2, op[2][2] = -1, op[2][3] = 4, op[2][4] = -3;
	op[3][1] = 3, op[3][2] = -4, op[3][3] = -1, op[3][4] = 2;
	op[4][1] = 4, op[4][2] = 3, op[4][3] = -2, op[4][4] = -1;
	mp['1'] = 1, mp['i'] = 2, mp['j'] = 3, mp['k'] = 4;
	int cas = getint();
	rep(ca,cas){
		n = getint();
		scanf("%I64d", &m);
		scanf("%s", s);
		rep(i,n) a[i] = mp[s[i]];
		b[0][0] = a[0];
		rep(i,n-1) b[0][i+1] = OP(b[0][i], a[i+1]);

		// rep(i,n) printf("%d ", a[i]); printf("\n");
		// rep(i,n) printf("%d ", b[0][i]); printf("\n");

		int want = 0, out = 0;// 0 -> 'i':2, 1 -> 'ij': 4 
		for(int t=0; want < 2; ++t){
			rep(i,t) if(b[t][0] == b[i][0]) out++;
			// if(t<10){
				// rep(i,n) printf("%d ", b[t][i]); printf(" ~~\n");
			// }
			if(out>1 || t==m) break;
			rep(i,n){
				if(b[t][i]==2 && want==0) want = 1;
				if(b[t][i]==4 && want==1) want = 2;
			}
			b[t+1][0] = OP(b[t][n-1], a[0]);
			rep(i,n-1) b[t+1][i+1] = OP(b[t+1][i], a[i+1]);

		}

		fprintf(stderr, "%d\n", ca);
		int all = pow(b[0][n-1], m);
		printf("Case #%d: %s\n", ca+1, (all==-1 && want==2)? "YES":"NO");
	}	
	return 0;
}