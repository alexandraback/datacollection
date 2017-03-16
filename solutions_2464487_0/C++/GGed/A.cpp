#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLU unsigned long long
using namespace std;

void solve(int tc){
	LLU r, m, p, ret;
	printf("Case #%d: ", tc);
	scanf("%llu%llu", &r, &m);
	
	ret = 0;
	for (LLU i=0, j=2000000000, k; j>=i; ){
		k = (i + j) / 2;
		p = k * 2 * r;
		if (p > m) j = k - 1;
		else{
			p += k * (2 * k - 1);
			if (p <= m) ret = k, i = k + 1;
			else j = k - 1;
		}
	}
	
	printf("%llu\n", ret);
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
