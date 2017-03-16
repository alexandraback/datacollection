#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

const int MAXTYPE = 210;
const int MAXN = 21;

const int MAXMASK = 1<<MAXN;

int curKeys[MAXTYPE];
int initKeys[MAXTYPE];
int need[MAXN];
vector< int > inside[MAXN];
vector< int > path[MAXMASK];


void solve() {
	int k, n;
	memset(initKeys, 0, sizeof(initKeys));

	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		x--;
		initKeys[x]++;
	}

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d%d", &need[i], &num);
		need[i]--;
		inside[i].resize(num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &inside[i][j]);
			inside[i][j]--;
		}
	}
	for (int i = 0; i < MAXMASK; i++)
	{
		path[i].clear();
		path[i].reserve(MAXN);
	}
	int maxmask = 1<<n;
	for (int mask = 0; mask < maxmask; mask ++) {
		if (mask && path[mask].empty())
			continue;
		memcpy(curKeys, initKeys, sizeof(initKeys));
		for (int i = 0; i < n; i++) {
			if ((mask >> i) & 1) {
				curKeys[need[i]]--;
				for (int j = 0; j < inside[i].size(); j++)
					curKeys[inside[i][j]]++;
			}
		}

		for (int take = 0; take < n; take++) {
			if (((mask >> take) & 1) == 0) {
				if (curKeys[need[take]] > 0) {
					int newmask = mask | (1 << take);
					vector< int > newpath = path[mask];
					newpath.push_back(take);
					if (path[newmask].empty() || path[newmask] > newpath) {
						path[newmask] = newpath;
					}
				}
			}
		}
	}

	if (path[maxmask - 1].empty()) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	vector<int> *r = &path[maxmask -1];
	for (int i = 0; i < r->size(); i++)
		printf("%d ", (*r)[i] + 1);
	printf("\n");
	return;
}


int main() {
	freopen("D-small-attempt1.in","r", stdin);
	freopen("C_output.txt","w", stdout);
	int T;
	scanf("%d\n", &T);
	for (int i = 0; i < T; i++) {
		printf("Case #%d: ", i + 1);
		solve();
	}
}
