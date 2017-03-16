/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define MOD				1000000007
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
vector < int > adj[1005];
int bff[1005];
bool visited[1005];
vector < int > v;
int dfs(int nd) {
	visited[nd] = true;
	v.push_back(nd);
	for(int i = 0; i < (int)(adj[nd].size()); ++i) {
		int to = adj[nd][i];
		if(!visited[to]) {
			return dfs(to) + 1;
		}
	}
	return 1;
}
int main() {
	int t;
	cin >> t;
	for(int tcase = 1; tcase <= t; ++tcase) {
		int n;
		cin >> n;
		for(int i = 0; i <= n; ++i) {
			adj[i].clear();
		}
		for(int i = 0; i < n; ++i) {
			cin >> bff[i];
			bff[i] -= 1;
		}
		int res = 0;
		for(int i = 0; i < (1 << n); ++i) {
			vector < int > v;
			for(int j = 0; j < n; ++j) {
				if(i & (1 << j)) {
					v.push_back(j);
				}
			}
			bool check = false;
			do {
				bool check1 = true;
				for(int j = 0; j < (int)(v.size()); ++j) {
					int lft = (j - 1  + (int)(v.size())) % (int)(v.size());
					int rgt = (j + 1) % (int)(v.size());
					if(bff[v[j]] != v[lft] && bff[v[j]] != v[rgt]) {
						check1 = false;
						break;
					}
				}
				if(check1) {
					check = true;
					break;
				}
			} while(next_permutation(v.begin(), v.end()));
			if(check) {
				res = max(res, (int)(v.size()));
			}
		}
		cout << "Case #" << tcase << ": " << res << endl;
	}
	return 0;
}