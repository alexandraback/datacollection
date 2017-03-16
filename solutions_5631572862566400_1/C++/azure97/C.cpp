#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int nex[N];
int deg[N];
int dp[N];
int n;

void read() {
	cin >> n;

	memset(deg,0,sizeof deg);
	for(int i = 1 ; i <= n ; i++) {
		cin >> nex[i];
		dp[i] = 1;
		deg[nex[i]]++;
	}
}

int solve() {
	queue<int> q;
	for(int i = 1 ; i <= n ; i++) {
		if(deg[i] == 0)
			q.push(i);
	}
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		dp[nex[cur]] = max(dp[nex[cur]],dp[cur] + 1);
		deg[nex[cur]]--;
		if(deg[nex[cur]] == 0)
			q.push(nex[cur]);
	}
	int ans = 0;
	int cyc2 = 0;
	for(int i = 1 ; i <= n ; i++)
		if(deg[i] == 1) {
			int cyc = 0;
			int tot = 0;
			int now = i;
			do {
				deg[now] = 0;
				cyc++;
				tot += dp[now];
				now = nex[now];
			} while(now != i);

			if(cyc > 2)
				ans = max(ans,cyc);
			else
				cyc2 += tot;
		}
	ans = max(ans,cyc2);	
	return ans;	
}

int main() {
	int t; cin >> t;
	for(int tc = 1 ; tc <= t ; tc++) {
		read();
		printf("Case #%d: %d\n",tc,solve());
	}
	return 0;
}