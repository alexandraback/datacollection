#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
#include <numeric>

using namespace std;

const int MAXN = 1111;

int vis[MAXN], rel[MAXN], f[MAXN];

int main() {
	int task;
	scanf("%d", &task);
	for (int index = 1; index <= task; ++ index) {
		int ret = 0;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", f + i);
			vis[i] = 0;
			rel[i] = 0;
		}
		for (int i = 1; i <= n; ++ i) {
			if (vis[i] == 0) {
				vector<int> v;
				int p = i;
				for (; vis[p] == 0; p = f[p]) {
					vis[p] = -1;
					v.push_back(p);
				}
				if (vis[p] > 0) {
					int d = v.size();
					for (int j = 0; j < d; ++ j) {
						vis[v[j]] = d - j + vis[p];
						rel[v[j]] = rel[p];
					}
				}
				else if (vis[p] == -1) {
					int d = 0, it = 0;
					for (; v[it] != p; ++ it) {
						++ d;
					}
					for (it = 0; v[it] != p; ++ it) {
						vis[v[it]] = d - it;
						rel[v[it]] = p;
					}
					ret = max(ret, (int)v.size() - d);
					for (; it < (int)v.size(); ++ it) {
						vis[v[it]] = -2;
					}
				}
				else if (vis[p] == -2) {
					int d = v.size();
					for (int j = 0; j < d; ++ j) {
						vis[v[j]] = d - j;
						rel[v[j]] = p;
					}
				}
			}
		}
		for (int i = 1; i <= n; ++ i) {
			if (vis[i] > 0) {
				int ft = rel[i];
				rel[ft] = max(rel[ft], vis[i]);
			}
		}
		int _ret = 0;
		for (int i = 1; i <= n; ++ i) {
			if (i < f[i] && f[f[i]] == i) {
				_ret += rel[i] + rel[f[i]] + 2;
			}
		}
		ret = max(ret, _ret);
		printf("Case #%d: %d\n", index, ret);
	}
	return 0;
}

