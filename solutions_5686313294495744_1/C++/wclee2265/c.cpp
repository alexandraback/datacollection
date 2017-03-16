#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <memory.h>

using namespace std;

#define N 1005

int n;
int n1, n2;
bool check[2005];

vector<int> r[2005];

struct data
{
	string x;
	string y;
}a[N];

bool dfs(int x)
{
	if (x == n1 + n2 + 1) return true;
	check[x] = true;
	
	for (int i = 0; i < r[x].size(); i++) {
		int y = r[x][i];
		if (!check[y] && dfs(y)) {
			r[y].push_back(x);
			r[x][i] = r[x][r[x].size() - 1];
			r[x].pop_back();
			return true;
		}
	}

	return false;
}

void process()
{
	cin >> n;
	map<string, int> m1, m2;

	n1 = n2 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
		if (!m1[a[i].x]) m1[a[i].x] = ++n1;
		if (!m2[a[i].y]) m2[a[i].y] = ++n2;
	}
	for (int i = 0; i <= n1 + n2 + 1; i++) r[i].clear();
	for (int i = 1; i <= n1; i++) r[0].push_back(i);
	for (int i = 1; i <= n2; i++) r[n1 + i].push_back(n1 + n2 + 1);
	for (int i = 1; i <= n; i++) r[m1[a[i].x]].push_back(n1 + m2[a[i].y]);

	int flow = 0;
	memset(check, 0, sizeof(check));
	while (dfs(0)) {
		flow++;
		memset(check, 0, sizeof(check));

	}

	printf("%d\n", n - flow - r[0].size() - (n2 - r[n1 + n2 + 1].size()));
}

int main()
{
	freopen("C-large.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		process();
	}

	return 0;
}