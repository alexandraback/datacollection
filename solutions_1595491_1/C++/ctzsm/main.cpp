#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
	int a[3];
	bool f;
	node(){}
	node(int _x,int _y,int _z,bool _f){
		a[0] = _x,a[1] = _y,a[2] = _z,f = _f;
	}
	void print(){
		printf("(%d,%d,%d,%d) ",a[0],a[1],a[2],f);
	}
};
vector<node> state[35];
int T,N,S,p;
int t[105];
int dp[105][105];
int solve(){
	scanf("%d%d%d",&N,&S,&p);
	for(int i = 1;i <= N; ++i) scanf("%d",&t[i]);
	memset(dp,0,sizeof(dp));
//	for(int i = 1;i <= N; ++i){
//		bool flag = false;
//		for(int k = 0;k < state[t[i]].size(); ++k){
//			node& now = state[t[i]][k];
//			for(int l = 0;l < 3; ++l) if(now.a[l] >= p && !now.f){ flag = true;break; }
//			if(flag) break;
//		}
//		if(flag) dp[i][0] = 1;
//	}
	for(int i = 1;i <= N; ++i){
		for(int j = 0;j <= S; ++j){
			dp[i][j] = max(dp[i][j],dp[i-1][j]);
			bool flag = false;
			for(int k = 0;k < state[t[i]].size(); ++k){
				node now = state[t[i]][k];
				for(int l = 0;l < 3; ++l) if(now.a[l] >= p && !now.f){ flag = true;break; }
				if(flag) break;
			}
			if(flag) dp[i][j] = max(dp[i][j],dp[i-1][j] + 1);
			flag = false;
			for(int k = 0;k < state[t[i]].size(); ++k){
				node now = state[t[i]][k];
				for(int l = 0;l < 3; ++l) if(now.a[l] >= p && now.f){ flag = true;break; }
				if(flag) break;
			}
			if(flag && j > 0) dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
//			printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
		}
	}
	int ans = 0;
	for(int i = 0;i <= S; ++i) ans = max(ans,dp[N][i]);
	return ans;
}
int main(int argc, char** argv) {
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	for(int i = 0;i <= 10; ++i){
		for(int j = 0;j <= 10; ++j){
			for(int k = 0;k <= 10; ++k){
				int sum = i + j + k;
				int a = abs(i - j),b = abs(i - k),c = abs(j - k);
				if(a <= 2 && b <= 2 && c <= 2){
					if(a == 2 || b == 2 || c == 2){
						state[sum].push_back(node(i,j,k,true));
					}else{
						state[sum].push_back(node(i,j,k,false));
					}
				}
			}
		}
	}
//	for(int i = 0;i <= 30; ++i){
//		for(int j = 0;j < state[i].size(); ++j){
//			state[i][j].print();
//		}
//		printf("\n");
//	}
	scanf("%d",&T);
	for(int cas = 1;cas <= T; ++cas){
		printf("Case #%d: %d\n",cas,solve());
	}
	return 0;
}

