#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

typedef long long LL;

#define N 1001

using namespace std;

vector <int> Inheri[N];

bool beIh[N], visted[N];

bool DFS(int x) {
	if(visted[x]) {
		return true;
	}
	visted[x] = true;
	for(int i = 0; i < Inheri[x].size(); ++i) {
		if(DFS(Inheri[x][i])) {
			return true;
		}
	}
	return false;
}

bool solve(int n) {
	for(int i = 1; i <= n; ++i) {
		if(!beIh[i]) {
			memset(visted, 0, sizeof(visted));
			if(DFS(i)) {
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int T;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cin >> T;
	for(int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
		int n, m, x;
		cin >> n;
		memset(beIh, 0, sizeof(beIh));
		for(int i = 1; i <= n; ++i) {
			Inheri[i].clear();
			cin >> m;
			for(int j = 0; j < m; ++j) {
				cin >> x;
				beIh[x] = true;
				Inheri[i].push_back(x);
			}
		}
		if(solve(n)) {
			cout << "Yes" <<endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
