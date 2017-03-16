#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>

using namespace std;

int n, k;
int st[222];
vector<int> in[222];
vector<vector<int> > adj;

struct state {
	int par;
	int opened;
	vector<int> keys;
	bitset<222> vis;
	bool operator <(const state &b) const {
		if(vis.count() == b.vis.count()) {
			if(opened == b.opened) {
				return keys.size() < b.keys.size();
			}
			return (opened < b.opened);
		}
		return vis.count() < b.vis.count();
	}
};

bool cmp(const state &a, const state &b) {
	return a.opened < b.opened;
}

void bfs() {

	set<state> S;
	vector<state> Q;
	state tmp;
	tmp.par = tmp.opened = -1;
	tmp.vis = bitset<222>();
	for(int i = 0; i < k; ++i) {
		tmp.keys.push_back(st[i]);
	}
	Q.push_back(tmp);
	int sz, node, key;
	for(int i = 0; i < (int)Q.size();) {
		sz = Q.size() - i;
		while(sz--) {
			tmp = Q[i];
			vector<state> tmpQ;
			for(int k = 0; k < (int)tmp.keys.size(); ++k) {
				key = tmp.keys[k];
				for(int j = 0; j < (int)adj[key].size(); ++j) {
					node = adj[key][j];
					if(tmp.vis[node]) continue;
					tmp.par = i;
					tmp.opened = node;
					tmp.vis[node] = 1;
					tmp.keys.erase(tmp.keys.begin() + k);
					for(int q = 0; q < (int)in[node].size(); ++q) {
						tmp.keys.push_back(in[node][q]);
					}
					if(!S.count(tmp)) {
						S.insert(tmp);
						tmpQ.push_back(tmp);
					}
					if((int)tmp.vis.count() == n) {
						Q.push_back(tmp);
						goto eshta;
					}
					for(int q = 0; q < (int)in[node].size(); ++q) {
						tmp.keys.pop_back();
					}
					tmp.keys.insert(tmp.keys.begin() + k, key);
					tmp.vis[node] = 0;
				}
			}
			sort(tmpQ.begin(), tmpQ.end(), cmp);
			for(int r = 0; r < (int)tmpQ.size(); ++r) {
				Q.push_back(tmpQ[r]);
			}
			++i;
		}
	}
	printf("IMPOSSIBLE\n");
	return;
	eshta:
	tmp = Q.back();
	stack<int> res;
	while(tmp.par != -1) {
		res.push(tmp.opened + 1);
		tmp = Q[tmp.par];
	}
	while(res.size()) {
		printf("%d", res.top());
		res.pop();
		if(res.size())
			printf(" ");
	}
	printf("\n");
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif
	
	int t;
	int ti, ki, kk;
	scanf("%d", &t);

	for(int tst = 1; tst <= t; ++tst) {
		adj = vector<vector<int> >(222);
		scanf("%d %d", &k, &n);
//		cout << k << " " << n << endl;
		for(int i = 0; i < k; ++i) {
			scanf("%d", &st[i]);
//			cout << st[i] << " \n"[i == k - 1];
		}
		for(int i = 0; i < n; ++i) {
			in[i].clear();
			scanf("%d %d", &ti, &ki);
//			cout << ti << " " << ki;
			adj[ti].push_back(i);
			while(ki--) {
				scanf("%d", &kk);
//				cout << " " << kk;
				in[i].push_back(kk);
			}
//			cout << endl;
		}
		printf("Case #%d: ", tst);
		bfs();
	}

	return 0;
}
