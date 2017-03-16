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

ll ways[51];
ll bp[51];
int adj[51][51];
int vis[51];
int b;

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
	for(int i=0;i <= 50;i++) {
		ways[i] = 1; 
		for (int j=1;j<i;j++) ways[i] += ways[j];
	}
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		ll m;
		cin>>b>>m;
		ll sum = 0;
		for (int i=0;i<b-1;i++) sum += ways[i];
		if (sum < m) {
			cout << "IMPOSSIBLE";
		} else {
			cout << "POSSIBLE";
			for (int i=0;i<b;i++) for(int j=0;j<b;j++) adj[i][j] = 0;
			ll oldm = m;
			for (int i=1;i<b-1;i++) if (m > 1) {
				adj[0][i] = 1;
				if (m > ways[i]) {
					adj[i][b-1] = 1;
					for (int j=1;j<i;j++) adj[i][j] = 1;
					m -= ways[i];
				}
				else {
					for (int j=i-1; j>=1; j--) {
						if (m >= ways[j]) {
							adj[i][j] = 1;
							m -= ways[j];
						}
					}
					if (m >= 1) {
						adj[i][b-1] = 1;
						m--;
					}
					break;
				}
			}
			if (m >= 1) {
				adj[0][b-1] = 1;
				m--;
			}
			for(int i=0;i<b;i++) vis[b] = 0;
			//ll x = dfs(0);
			assert(m == 0);
			//assert(x == oldm);
			for (int i=0;i<b;i++) {
				cout << endl;
				for(int j=0;j<b;j++) cout << adj[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}
