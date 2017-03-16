#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
using namespace std;
int t;
int r;
int c;
int w;
int dp[1 << 10];
bool use[1 << 10];
inline int dfs(int a){
	if (use[a]){
		return dp[a];
	}
	use[a] = true;
	dp[a] = INT_MAX;
	int countt = 0;
	int kk = 0;
	bool ok = false;
	for (int i = 0; i < c; i++){
		if ((a >> i) & 1){
			countt = 0;
		}
		else{
			countt++;
		}
		if (countt > w){
			ok = true;
		}
		if (countt&&countt% w == 0){
			kk++;
		}
	}
	if (kk == 1 && ok == false){
		dp[a] = w;
		return w;
	}
	if (kk == 1 && ok){
		dp[a] = w + 1;
		return w + 1;
	}
	for (int i = 0; i < c; i++){
		if ((a >> i) & 1){

		}
		else{
			int k = 1 + dfs(a | (1 << i));
			int space = 0;
			for (int j = i; j >= 0; j--){
				if ((a >> j) & 1){
					break;
				}
				else{
					space++;
				}
			}
			for (int j = i + 1; j<c; j++){
				if ((a >> j) & 1){
					break;
				}
				else{
					space++;
				}
			}
			int res = 0;
			if (space < w){
				res = -1;
			}
			else{
				if (space == w){
					res = w;
				}
				else{
					res = w + 1;
				}
			}
			k = max(k, res);
			dp[a] = min(dp[a], k);
		}
	}
	return dp[a];
}
int main(){
	scanf("%d", &t);
	int ca = 0;
	while (t--){
		memset(use, false, sizeof(use));
		ca++;
		scanf("%d%d", &r, &c);
		scanf("%d", &w);
		int ans = dfs(0);
		cout << "Case #" << ca << ": " << ans << endl;
	}
	return 0;
}