#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define N 110

using namespace std;

vector<int> adj[N];
string str[N];
int arr[N],ans[N];
int p[N];
int n,m,t;

bool check() {
	int u = arr[0];
	p[u] = -1;
	for(int k=0;k<n-1;k++) {
		bool found = false;
		while(true) {
			for(int i=0;i<adj[u].size();i++) {
				if(adj[u][i] == arr[k+1]) {
					found = true;
					break;
				}
			}
			if(found) break;
			if(p[u] == -1) return false;
			u = p[u];
		}
		p[arr[k+1]] = u;
		u = arr[k+1];
	}
	return true;
}
int main() {
	cin >> t;
	for(int Case = 1; Case <= t; Case++) {
		cin >> n >> m;
		for(int i=1;i<=n;i++) {
			cin >> str[i];
			adj[i].clear();
		}
		while(m--) {
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i=0;i<n;i++) {
			arr[i] = i+1;
		}
		ans[0] = -1;
		do {
			if(check()) {
				bool found = false;
				int e = 0;
				if(ans[0] == -1) {
					found = true;
				}else {
					for(int i=0;i<n;i++) {
						if(str[arr[i]] < str[ans[i]]) {
							found = true;
							break;
						}else if(str[arr[i]] > str[ans[i]]) {
							e = 1;
							break;
						}
					}
				}
				if(!e && found) {
					for(int i=0;i<n;i++) {
						ans[i] = arr[i];
					}
				}
			}
		}while(next_permutation(arr,arr+n));
		printf("Case #%d: ",Case);
		for(int i=0;i<n;i++) {
			cout << str[ans[i]];
		}
		printf("\n");
	}
	return 0;
}
