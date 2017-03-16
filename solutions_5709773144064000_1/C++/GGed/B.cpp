#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

void solve(int tc){
	double ct, fm, tar;
	printf("Case #%d: ", tc);
	scanf("%lf%lf%lf", &ct, &fm, &tar);
	double ret = tar * .5;
	double t = 0, r = 2;
	FOE(i,0,tar){
		ret = min(ret, t + tar / r);
		t += ct / r;
		r += fm;
	}
	printf("%.9f\n", ret);
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
