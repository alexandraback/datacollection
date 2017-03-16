#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define FOR(i, s, e) for (int i=(s); i<(e); i++)
#define CLR(x, a) memset(x, a, sizeof(x))

int TC;
double C, F, X;

void solve(int tc){
	scanf("%lf%lf%lf", &C, &F, &X);
	int mx = (int)(X + X);
	double ret = 1e20, rate = 2.0, tim = 0.0;
	
	FOR(i, 0, mx){
		ret = min(ret, X / rate + tim);
		tim += C / rate;
		rate += F;
	}
	printf("Case #%d: %.7lf\n", tc, ret);
}


int main(){
	scanf("%d", &TC);
	FOR(i, 0, TC) solve(i + 1);
}
