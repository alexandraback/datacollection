#define MAXN 100

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int n;
string words[MAXN];
vector<int> g[MAXN];
bool visited[MAXN];
int path[MAXN];
long total;
int ch[26];

void init() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> words[i];
		g[i].clear();
	}

	memset(visited, 0 ,sizeof(visited));
	memset(ch, 0, sizeof(ch));
	total = 0;
}

bool check() {
	for (int i = 0; i < n; i++) {
		string w = words[i];
		int len = w.length();
		for (int j = 0; j < len; j++) {
			int index = w[j] - 'a';
			ch[index]++;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (ch[i] > 1) {
			for (int j = 0; j < n; j++) {
				string w = words[j];
				int len = w.length();
				
				for (int k = 1; k < len; k++) {
					if (w[k] - 'a' == i) {
						if (w[k] != w[k - 1]) {
							int t = k + 1;
							while (t < len && w[t] - 'a' == i) t++;
							if (t == len) {
								break;
							}
							if (t - k == ch[i]) {
								break;
							}
							
							return false;
						}
					}
				}
			}
		}
	}

	return true;
}

void makeGraph() {
	for (int i = 0; i < n ; i++) {
		for (int j = i + 1; j < n; j++) {
			if (*(words[i].rbegin()) == *(words[j].begin())) {
				g[i].push_back(j);
			}

			if (*(words[j].rbegin()) == *(words[i].begin())) {
				g[j].push_back(i);
			}			
		}
	}
}

void search(int k, int index, int depth) {
	visited[k] = true;
	path[k] = index;
	
	int m = g[k].size();

	bool shouldNew = true;
	for (int i = 0; i < m; i++) {
		int l = g[k][i];

		if (visited[l] == false) {
			shouldNew = false;
			break;
		} else if (path[l] != index) {
			visited[k] = false;
			return;
		}
	}

	if (depth == n - 1) {
		total += 1;

		visited[k] = false;
		return;
	}

	if (shouldNew) {
		for (int i = 0; i < n; i++)  {
			if (visited[i] == false) {
				search(i, index + 1, depth + 1);
			}
		}

	} else {
		for (int i = 0; i < m; i++) {
			int l = g[k][i];

			if (visited[l] == false) {
				search(l, index, depth + 1);	
			}
		}
	}

	visited[k] = false;
}

void solve() {
	for (int i = 0; i < n; i++) {
		search(i, 1, 0);
	}
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	string line;
	
	for (int x = 1; x <= t; x++) {
		init();
		if (check() == false) {
			printf("Case #%d: 0\n", x);	
			continue;
		}

		makeGraph();
		solve();
		printf("Case #%d: %ld\n", x, total);
	}

	return 0;
}