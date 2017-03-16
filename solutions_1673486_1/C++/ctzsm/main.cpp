#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
int A,B;
double P[100005];
double dp[100005][2]; //0 for correct, 1 for now incorrect
double solve(){
	dp[0][0] = 1.0;dp[0][1] = 0.0;
	scanf("%d%d",&A,&B);
	double ans = 0.0 + B + 2;
	for(int i = 0;i < A; ++i) scanf("%lf",&P[i]);
	for(int i = 0;i <= A; ++i){
		double exp = dp[i][0] * (A - i + B - i + 1) + dp[i][1] * (A - i + B - i + 1 + B + 1);
//		printf("%f\n",exp);
		ans = min(ans,exp);
		dp[i+1][0] = dp[i][0] * P[i];
		dp[i+1][1] = 1.0 - dp[i+1][0];
	}
	return ans;
}
int main(int argc, char** argv) {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&T);
	for(int i = 1;i <= T; ++i){
		printf("Case #%d: %.6f\n",i,solve());
	}
	return 0;
}

