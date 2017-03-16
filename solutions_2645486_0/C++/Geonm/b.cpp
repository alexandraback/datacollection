#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#include<string.h>
#include<math.h>

using namespace std;

#define MAXN 109
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long

int E,R,N,v[MAXN],dp[MAXN][MAXN];

void Read() {
	scanf("%d %d %d",&E,&R,&N);
	
	for (int i=1;i<=N;i++) {
		scanf("%d",&v[i]);
	}
}

void Solve(int kase) {
	
	if (R>E)
		R=E;
	
	for (int i=1;i<=N;i++) {
		for (int e=0;e<=E;e++) {
			dp[i][e]=-1;
			for (int j=max(e-R,0);j<=E-R;j++) {
				dp[i][e]=max(dp[i][e],dp[i-1][j]+v[i]*(j+R-e));
			}
		}
	}
	
	int ans=0;
	
	for (int i=0;i<=E;i++) {
		ans=max(dp[N][i],ans);
	}
	
	printf("Case #%d: %d\n",kase,ans);
}

int main () {
	freopen("codejam.in","r",stdin);
	freopen("codejam.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	
	for (int i=1;i<=t;i++) {
		Read();
		Solve(i);
	}
	
	return 0;
}
