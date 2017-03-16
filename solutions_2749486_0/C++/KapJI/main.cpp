#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

const int P = 1000000;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char dir[] = {'E', 'W', 'N', 'S'};

map<long long, int> mem;
map<long long, pair<long long, char> > par;

long long getInd(int x, int y) {
	return 2LL * P * x + y + 2LL * P * P + P;
}

pair<int, int> getCord(long long ind) {
	int y = (ind % (2LL * P)) - P;
	ind /= (2LL * P);
	return make_pair(ind - P, y);
}

void solve() {
	//fprintf(stderr, "new test\n");
	mem.clear();
	par.clear();
	int x0, y0;
	cin >> x0 >> y0;
	queue<pair<long long, int> > q;
	q.push(make_pair(getInd(0, 0), 0));
	mem.insert(make_pair(getInd(0, 0), 0));
	par.insert(make_pair(getInd(0, 0), make_pair(-1, '-')));
	while (!q.empty()) {
		long long cur = q.front().first;
		int d = q.front().second;
		q.pop();
		pair<int, int> cord = getCord(cur);
		if (cord.first == x0 && cord.second == y0) {
			fprintf(stderr, "Found with d = %d\n", d);
			pair<long long, char> from = par[cur];
			string ans;
			while (from.second != '-') {
				ans += from.second;
				from = par[from.first];
			}
			reverse(ans.begin(), ans.end());
			cout << ans;
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = cord.first + dx[i] * (d + 1);
			int ny = cord.second + dy[i] * (d + 1);
			long long newInd = getInd(nx, ny);
			if (mem.count(newInd) && mem[newInd] <= d + 1) {
				continue;
			}
			q.push(make_pair(newInd, d + 1));
			mem.insert(make_pair(newInd, d + 1));
			par.insert(make_pair(newInd, make_pair(cur, dir[i])));
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
	return 0;
}