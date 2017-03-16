/*
 * main.cpp
 *
 *  Created on: 9 Apr 2016
 *      Author: ljchang
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int n, num[1000], vis[1000], opt[1000], tid[1000];

void input() {
	scanf("%d", &n);
	for(int i = 0;i < n;i ++) {
		scanf("%d", &num[i]);
		-- num[i];
	}
}

void solve() {
	memset(vis, -1, sizeof(int)*n);
	memset(opt, -1, sizeof(int)*n);
	for(int i = 0;i < n;i ++) if(num[num[i]] == i) {
		opt[i] = opt[num[i]] = 1;
		tid[i] = i; tid[num[i]] = num[i];
		vis[i] = vis[num[i]] = 0;
	}

	int largest_cycle = 0;
	for(int i = 0;i < n;i ++) if(vis[i] == -1) {
		int cnt = 1;
		vis[i] = 1;

		vector<int> V;
		V.push_back(i);
		for(int j = 0;j < (int)V.size();j ++) {
			int id = num[V[j]];
			if(vis[id] == -1) {
				vis[id] = (++ cnt);
				V.push_back(id);
			}
			else if(opt[id] == 0) {
				for(int k = 0;k <= j;k ++) opt[V[k]] = 0;
			}
			else if(opt[id] > 0) {
				opt[V[j]] = opt[id] + 1; tid[V[j]] = tid[id];
				for(int k = j-1;k >= 0;k --) {
					opt[V[k]] = opt[V[k+1]] + 1;
					tid[V[k]] = tid[id];
				}
			}
			else {
				for(int k = 0;k <= j;k ++) opt[V[k]] = 0;
				if(cnt - vis[id] + 1 > largest_cycle) largest_cycle = cnt - vis[id]+1;
			}
		}
	}

	int longest[1000];
	for(int i = 0;i < n;i ++) longest[i] = 0;
	for(int i = 0;i < n;i ++) if(opt[i] > 0&&opt[i] > longest[tid[i]]) longest[tid[i]] = opt[i];

	int longest_path = 0;
	for(int i = 0;i < n;i ++) if(num[num[i]] == i&&num[i] < i) {
		longest_path += longest[i] + longest[num[i]];
	}

	if(largest_cycle > longest_path) printf(" %d\n", largest_cycle);
	else printf(" %d\n", longest_path);
}

int main() {
	int t;
	scanf("%d", &t);
	for(int cas = 0; cas < t;cas ++) {
		input();
		printf("Case #%d:", cas+1);
		solve();
	}
	return 0;
}
