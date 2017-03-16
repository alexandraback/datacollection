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
//#define LARGE 1

int A,B,K;
int mask;
int cutoff; // less than or equal => don't care

int dp[100][2][2];

int f(int ind, bool e1, bool e2) {
	if(ind < 0) return 1;
	int& ans = dp[ind][e1][e2];
	if(ans != -1) return ans;
	int c1 = (A>>ind)&1;
	int c2 = (B>>ind)&1;
	int target = (mask>>ind)&1;
	ans = 0;
	for(int i=0;i<=1;i++) {
		for(int j=0;j<=1;j++) {
			if(i == 1 && c1 == 0 && e1)
				continue;
			if(j == 1 && c2 == 0 && e2)
				continue;
			if(ind > cutoff) {
				if(target == 1 && (i == 0 || j == 0))
					continue;
				if(target == 0 && (i == 1 && j == 1))
					continue;
			}
			ans += f(ind-1, e1 && (i==c1), e2 && (j==c2));
		}
	}
	return ans;
}

int main() {
#ifdef LARGE
	freopen("b_large.i", "rt", stdin);
	freopen("b_large.o", "wt", stdout);
#elif SMALL
	freopen("b_small.i", "rt", stdin);
	freopen("b_small.o", "wt", stdout);
#else
	freopen("b_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		cin>>A>>B>>K;
		A--;
		B--;
		K--;
		int ans = 0;
		mask = 0;
		for(int i=30;i>=0;i--) {
			if(K&(1<<i)) {
				memset(dp, -1, sizeof(dp));
				cutoff = i-1;
				ans += f(30, 1, 1);
				mask |= (1<<i);
			}
		}
		memset(dp, -1, sizeof(dp));
		cutoff = -1;
		ans += f(30, 1, 1);
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}

	return 0;
}
