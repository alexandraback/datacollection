#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <cstring>
#include <set>
#include <iomanip>
#include <list>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long LL;
typedef pair<int,int>PII;
const int maxn = 2111111;
int dp[maxn];
int reverse(int n){
	int k=0;
	while(n){
		k=k*10+n%10;
		n/=10;
	}
	return k;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(false);
	const int N=(int)(1e6);
	memset(dp,0x7f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=N;++i){
		dp[i]=min(dp[i],dp[i-1]+1);
		int k=reverse(i);
		if(k>i&&i<=N){
			dp[k]=min(dp[k],dp[i]+1);
		}
	}
	int T;
	cin>>T;
	for(int cas=1;cas<=T;++cas){
		int x;
		cin>>x;
		cout<<"Case #"<<cas<<": "<<dp[x]<<endl;
		cerr<<dp[x]<<endl;
	}

	return 0;
}
