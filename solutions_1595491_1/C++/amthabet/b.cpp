#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<memory.h>
using namespace std;

int n;
int p;
int score[110];
int dp[110][110];
int INF = 100000000;

int f(int ind, int rem) {
	if(ind == n) return rem == 0 ? 0 : -INF;
	int& ans = dp[ind][rem];
	if(ans != -1) return ans;
	ans = 0;
	for(int i=0;i<=10 && i<=score[ind]; i++)
		for(int j=max(0, i-2); j<=i && i+j<=score[ind]; j++)
			for(int k=max(0, max(i-2, j-2)); k<=j && i+j+k<=score[ind]; k++) {
				if(i+j+k != score[ind]) continue;
				int nrem = rem;
				if(abs(i-j) == 2 || abs(j-k) == 2 || abs(i-k) == 2) {
					if(!rem) continue;
					nrem--;
				}
				ans = max(ans, f(ind+1, nrem)+(i>=p||j>=p||k>=p));
			}
	return ans;
}

int main()	{

	//freopen("b_sample.in","rt",stdin);
	//freopen("b_small.in","rt",stdin);
	//freopen("b_small.out","wt",stdout);
	freopen("b_large.in","rt",stdin);
	freopen("b_large.out","wt",stdout);
	
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int s;
		cin>>n>>s>>p;
		for(int i=0;i<n;i++) cin>>score[i];
		memset(dp,-1,sizeof(dp));
		cout<<"Case #"<<tt<<": "<<f(0,s)<<endl;
	}

	return 0;
}