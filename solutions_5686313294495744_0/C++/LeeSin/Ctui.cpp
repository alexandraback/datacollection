#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#define N 2005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int tc, n, a[N], b[N], am, bm, d[N], ans, ac, bc;
char s[N], t[N];
map<string, int> qa, qb;
bool ua[N], ub[N];

void solve(int tt){
	scanf("%d", &n);
	qa.clear();
	qb.clear();
	am = 0;
	bm = 0;
	fi(i, 0, n){
		scanf("%s %s", s, t);
		if(!qa[s]) qa[s] = ++am;
		if(!qb[t]) qb[t] = ++bm;
		a[i] = qa[s];
		b[i] = qb[t];
	}
	
	ans = n;
	fi(i, 1, 1 << n){
		FI(j, 1, am) ua[j] = 0;
		FI(j, 1, bm) ub[j] = 0;
		fi(j, 0, n) if(i & 1 << j) ua[a[j]] = ub[b[j]] = 1;
		
		bool ok = 1;
		fi(j, 0, n) if(!(i & 1 << j) && !(ua[a[j]] && ub[b[j]])) ok = 0;
		
		if(ok) ans = min(ans, __builtin_popcount(i));
	}
	
	printf("Case #%d: %d\n", tt, n - ans);
}

int main(){
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-small-attempt2.out", "w", stdout);
	scanf("%d", &tc);
	FI(z, 1, tc) solve(z);
	scanf("\n");
}
