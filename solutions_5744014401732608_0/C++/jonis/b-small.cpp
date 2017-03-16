#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int b, vis[7], adj[7][7], bp[7];

ll dfs(int i) {
	vis[i] = 1;
	ll sum = 0;
	if (adj[i][b-1]) sum++;
	for(int j=0;j<b-1;j++) if (adj[i][j]) {
		if (vis[j] == 1) return -1;
		ll k = dfs(j);
		if (k == -1) return -1;
		sum += k;
	}
	vis[i] = 2;
	bp[i] = sum;
	return sum;
}

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		ll m;
		cin>>b>>m;
		bool found = false;
		for (int i=0;i<b;i++) for(int j=0;j<b;j++) adj[i][j]=0;
		for (int i=1;i<b-1;i++) adj[0][i] = 1;
		int k=0;
		for (int i=1;i<b-1;i++) for (int j=i+1;j<b-1;j++) k++;
		for (int i=0;i<b-1;i++) k++;
		for (int mask=0;mask<1<<k;mask++) {
			int c=0;
			for (int i=1;i<b-1;i++) for (int j=i+1;j<b-1;j++) {
				adj[i][j] = ((1<<c) & mask) != 0;
				c++;
			}
			for (int i=0;i<b-1;i++) {
				adj[i][b-1] = ((1<<c) & mask) != 0;
				c++;
			}
			for(int i=0;i<b;i++) vis[i]=0;
			int ans = dfs(0);
			if (ans == m) {
				found = 1;
				break;
			}
		}
		if (!found) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << "POSSIBLE" << endl;
			for (int i=0;i<b;i++) {
				for(int j=0;j<b;j++) cout << adj[i][j];
				cout << endl;
			}
		}
	}
	return 0;
}
