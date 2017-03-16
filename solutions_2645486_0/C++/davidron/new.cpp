#include<iostream>
#include<string>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<stack>
#include<vector>
#include<ctime>
#include<map>
#include<set> 
#include<cctype>
#include<cstdlib>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const int maxn = 1e5;
const int maxe = 2*maxn*maxn;
typedef unsigned long long ULL;
///////////////////////////////////////////////////////////////////////////////////
int E,R,N,x[maxn],best;
void dfs(int e,int n,int ans){
	if(n == N){
		best = max(best,ans);
		return;
	}
	for(int i = 0; i <= e; ++i){
		int ans2 = ans + i * x[n];
		dfs(e-i+R>E?E:e-i+R,n+1,ans2);
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	freopen("B-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T;scanf("%d",&T);
	for(int ci = 1; ci <= T; ++ci){
		printf("Case #%d: ",ci);
		scanf("%d%d%d",&E,&R,&N);
		for(int j = 0; j < N; ++j){
			scanf("%d",x+j);
		}
		best = 0;dfs(E,0,0);
		printf("%d\n",best);
	}
	return 0;
}