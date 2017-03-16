//By Lin
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 1000001
//#define N 101
#define MOD 1000000007

int dp[N];
bool in_que[N];
queue<int> que;

bool check(int x, int val) {
	if (x == 0 || x >= N) return false;
	if (dp[x] == -1 || dp[x] > val) {
		dp[x] = val;
		return true;
	}
	return false;
}

LL cal(LL x) {
	vector<int> v;
	for (LL tmp = x; tmp; tmp /= 10) {
		v.push_back(tmp % 10);
	}
	LL ret = 0;
	Rep(i, v.size()) ret = ret * 10 + v[i];
	return ret;
}
int main() {
	memset(dp, -1, sizeof dp);
	dp[1] = 1;
	que.push(1);
	while (!que.empty()) {
		int i = que.front();
		que.pop();
		if (check(i+1,dp[i]+1)) 
			que.push(i+1);
		int j = cal(i);
		if (check(j, dp[i]+1)) 
			que.push(j);
	}
	int cas, tt = 0;
	scanf("%d", &cas);
	while (cas --) {
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", ++tt, dp[n]);
	}
		
	return 0;
}
