#include <cstdio>
#include <vector>
#include <algorithm>

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

double solve()
{
	double C, F, X;
	scanf("%lf%lf%lf", &C, &F, &X);
	//printf("%f\n", (X*F-2*C)/(F*C));

	double T = 0.0;
	double ans = 1e300;
	for(int i=0; i<500000; ++i){
		double t = T + X/(2+i*F);
		ans = min(ans, t);
		T += C/(2+i*F);
	}

	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	rep(i, T){
		printf("Case #%d: %.15f\n", i+1, solve());
	}

	return 0;
}
