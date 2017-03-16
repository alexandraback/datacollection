#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define REP(x,y) for(x=0;x<y;x++)
#define REPI(x,y) for(x=1;x<=y;x++)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back

using namespace std;

int N,M,n,m,k,i;
int dp[105];
int dp2[105];
int s[105];

int main()
{
    int a,b,c,d,R;
	cin >> R;
	for(int xx=0;xx<R;xx++){
		cin >> k >> N;
		REPI(a, N){
			cin >> s[a];
		}
		if(k==1){
			printf("Case #%d: %d\n",xx+1,N);
			continue;
		}
		sort(s, s+N+1);
		REP(a, N+1)dp[a]=dp2[a]=0;
		REPI(a, N){
			dp2[a]=dp[a-1]+N-a+1;
			dp[a]=dp[a-1];
			while(k<=s[a]){
				k+=k-1;
				dp[a]++;
			}
			k+=s[a];
		}
		int mn=dp[N];
		REPI(a, N){
			mn = min(mn, dp2[a]);
		}
		printf("Case #%d: %d\n",xx+1,mn);
	}
    return 0;
}
