#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

#define SMALL 1
#define LARGE 1

double dp[2010][4010];

double f(int level, int rem, int other) {
	if(rem < 0)
		return 0;
	if(level == 0)
		return 1;
	double& ans = dp[level][rem];
	if(ans == ans)
		return ans;
	if(other == 0)
		return ans = f(level-1, rem-1, other);
	double v1 = f(level, rem-1, other-1);
	double v2 = f(level-1, rem-1, other);
	return ans = 0.5 * (v1+v2);
}

int main() {
#ifdef LARGE
	freopen("b_large.i", "rt", stdin);
	freopen("b_large_2.o", "wt", stdout);
#elif SMALL
	freopen("b_small.i", "rt", stdin);
	freopen("b_small_2.o", "wt", stdout);
#else
	freopen("b_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int n,x,y;
		cin>>n>>x>>y;
		x = abs(x);
		y = abs(y);
		int level = (x+y)/2;
		int cur = 1;
		for(int i=0;i<level && n >= 0;i++) {
			n -= cur;
			cur += 4;
		}
		memset(dp,-1,sizeof(dp));
		cout.precision(9);
		cout.setf(ios::fixed);
		double ans;
		if(x == 0)
			ans = (n >= cur);
		else
			ans = f(y+1, min(n,4005), cur/2);
		cout << "Case #"<<tt<<": "<<ans<<endl;
	}

	return 0;
}
