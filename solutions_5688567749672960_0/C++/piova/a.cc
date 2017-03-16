#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <set>
#include <queue>

#define mk make_pair
#define pb push_back
typedef  long long  LL;

using namespace std;
int dp[1023450];
queue<int> Q;
int a[8];
int rev(int x){
	int tmp=0;
	while(x){
		a[++tmp]=x%10;
		x/=10;
	}
	int cnt=0;
	for(int i=1;i<=tmp;i++)
		cnt=cnt*10+a[i];
	return cnt;
}
void dfs(int x){
	while(Q.size()){
		int x=Q.front();
		Q.pop();
		if(x>1000000)	continue;
		int tmp=dp[x]+1;
		if(dp[x+1]>tmp){
			dp[x+1]=tmp;
			Q.push(x+1);
		}
		int res=rev(x);
		if(dp[res]>tmp){
			dp[res]=tmp;
			Q.push(res);
		}
		
	}
	return ;
}
int main(){
	int T,n;
	scanf("%d",&T);
	memset(dp,127,sizeof(dp));
	dp[1]=1;
	Q.push(1);
	dfs(1);
	for(int cas=1;cas<=T;cas++){
		printf("Case #%d: ",cas);
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
	return 0;
}