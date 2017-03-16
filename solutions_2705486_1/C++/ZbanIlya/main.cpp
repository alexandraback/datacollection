#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

struct node {
	int next[26];
	bool leaf;

	node() {
		memset(next, 0, sizeof(next));
		leaf = 0;
	}
};

FILE * file;

node t[(int)4e6];
int sz;

string s;
vector<vector<int> > d;

void bfs(int x, int y) {
	int X = x, Y = y;
	queue<pair<int, pair<int, int> > > q, q1;
	q.push(make_pair(0, make_pair(y, 0)));
	while (1) {
		while (!q.empty() && x < s.length()) {
			int v = q.front().first, y = q.front().second.first, sum = q.front().second.second;
			q.pop();
			if (y < 4) {
				v = t[v].next[s[x] - 'a'];
				if (!v) continue;
				if (t[v].leaf) d[x + 1][y + 1] = min(d[x + 1][y + 1], d[X][Y] + sum);
				q1.push(make_pair(v, make_pair(y + 1, sum)));
			} else {
				for (int i = 0; i < 26; i++) {
					int nv = t[v].next[i], ny = (i == (s[x] - 'a') ? 5 : 0);
					if (!nv) continue;
					if (t[nv].leaf) d[x + 1][ny] = min(d[x + 1][ny], d[X][Y] + (ny == 0) + sum);
					q1.push(make_pair(nv, make_pair(ny, sum + (ny == 0))));
				}
			}
		}
		if (q1.empty()) break;
		q = q1;
		q1 = queue<pair<int, pair<int, int> > >();
		x++;
	}
}

char str[10000];

void solve() {
	//cin >> s;
	fscanf(file, "%s", str);
	s = str;
	d.assign(s.length() + 1, vector<int>(6, inf));
	d[0][5] = 0;
	for (int i = 0; i < s.length(); i++)
		for (int j = 0; j < 6; j++)
			if (d[i][j] < inf)
				bfs(i, j);
	int ans = inf;
	for (int i = 0; i < 6; i++)
		ans = min(ans, d[s.length()][i]);
	cout << ans;
}

void add(string s) {
	int cur = 0;
	for (int i = 0; i < s.length(); i++) {
		if (!t[cur].next[s[i] - 'a']) {
			t[cur].next[s[i] - 'a'] = ++sz;
		}
		cur = t[cur].next[s[i] - 'a'];
	}
	t[cur].leaf = 1;
}

void presolve() {
	freopen("garbled_email_dictionary.txt", "r", stdin);
	string s;
	while (cin >> s) {
		add(s);
	}
	fclose(stdin);
}

int main() {
	presolve();
	//freopen("input.txt", "r", stdin);
	//freopen("input.txt", "r", file);
	file = fopen("input.txt", "r");
	freopen("output.txt", "w", stdout);

    int tests;
	//cin >> tests;
	fscanf(file, "%d\n", &tests);
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";
		solve();
		cout << endl;
	}
	return 0;
}