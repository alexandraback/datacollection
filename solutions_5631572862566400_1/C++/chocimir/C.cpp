#include<algorithm>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

typedef long long LL;
typedef long double LD;

#define dprintf(...) fprintf(stderr, __VA_ARGS__)

int cond = 0;
#define DB(X) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = "<<X<<endl;}}
int t[3000];
vector<int> g[3000];
int dfs(int v, int j) {
	if (g[v].empty()) {
		return 1;
	}
	int res = 0;
	DB(v); DB(j);
	for(int i = 0; i < g[v].size(); ++i) {
		DB(i);
		if (g[v][i] != j)
			res = max(res, dfs(g[v][i], j));
	}
	return res + 1;
}
int solve() {
	for(int i = 0; i < 3000; ++i) {
		t[i] = 0;
	}
	int n; cin >> n;
	vector<int> next;
	for(int i = 0; i < n; ++i) {
		int a; cin >> a;
		next.push_back(a - 1);
		g[i].clear();
	}
	DB(n);
	for(int i = 0; i < n; ++i) {
		g[next[i]].push_back(i);
	}
	int c = 0;
	int res = 0;
	DB(res);
	for(int i = 0; i < n; ++i) {
		if (t[i] == 0) {
			c += 1;
			int st = i, cur = i;
			while (t[cur] == 0) {
				DB(cur);
				t[cur] = c;
				cur = next[cur];
			}
			if (t[cur] != c) {
				continue;
			}
			int tmp = 1;
			st = next[cur];
			while (st != cur) {
				DB(st);
				st = next[st];
				tmp += 1;
			}
			res = max(res, tmp);
		}
	}
	int res2 = 0;
	DB(res);
	for(int i = 0; i < n; ++i) {
		if (next[next[i]] == i && next[i] < i) {
			DB(i);
			res2 += dfs(i, next[i]) + dfs(next[i], i);
		}
	}

	return max(res, res2);
}

int main() {
	int t; cin >> t;
	for(int x = 1; x <= t; ++x){
		cout << "Case #" << x << ": " << solve() << endl;//result 
	}
	return 0;
}
