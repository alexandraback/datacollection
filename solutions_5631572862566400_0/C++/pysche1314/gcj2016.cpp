#include "StdAfx.h"
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#include <ctime>
#include <unordered_map>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
using namespace std;

int dfs(int cur, unordered_map<int, vector<int> > &tree, unordered_map<int, int> &mark) {
	if (mark[cur]) return 0;
	mark[cur] = 1;
	vector<int> next = tree[cur];
	int res = 1;
	int maxv = 0;
	for (int i = 0; i < next.size(); i++) {
		int rest = dfs(next[i], tree, mark);
		maxv = max(maxv, rest);
	}
	mark[cur] = 0;
	return res + maxv;
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	//freopen("C_large.in", "r", stdin);
	//freopen("C_large.out", "w", stdout);
	ll T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int num;
		cin >> num;
		unordered_map<int, vector<int> > tree;
		unordered_map<int, int> mark;
		for (int i = 0; i < num; i++) {
			vector<int> tmp;
			tree[i] = tmp;
			mark[i] = 0;
		}
		int bff[2000];
		memset(bff, -1, sizeof(bff));
		for (int i = 0; i < num; i++) {
			int tmp;
			cin >> tmp;
			tree[tmp-1].push_back(i);
			//bff[i] = tmp - 1;
			bff[tmp - 1] = i;
		}
		int res = 0;
		for (int i = 0; i < num; i++) {
			mark.clear();
			vector<int> ch = tree[i];
			mark[i] = 1;
			
			int cmax = 0;
			int solo = 0;
			if (bff[i] != -1)
				solo = dfs(bff[i], tree, mark);
				mark[bff[i]] = 1;
			for (int j = 0; j < ch.size(); j++) {
				if (ch[j] == bff[i]) continue;
				int pb = dfs(ch[j], tree, mark);
				//cout << i << " " << ch[j] << " " << pb << " " << bff[i] << endl;
				cmax = max(cmax, pb);
			}
			res = solo + cmax + 1;
		}

		cout << "Case #" << (t + 1) << ": " << res << endl;
	}
	return 0;
}

