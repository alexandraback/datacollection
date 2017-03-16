#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <list>
#include <map>
#include <deque>
#include <fstream>
#include <string>
using namespace std;

int N;
bool visited[1001];
bool visited1[1001];
vector<int> connected[1001];

bool dfs1(int n) {
	visited1[n] = true;

	for (int i = 0; i < connected[n].size(); i++) {
		if (visited1[connected[n][i]])
			return true;
		else if (dfs1(connected[n][i]))
			return true;
	}

	return false;
}

bool dfs(int n) {
	memset(visited1, 0, sizeof(visited1));

	for (int i = 0; i < connected[n].size(); i++) {
		if (visited1[connected[n][i]])
			return true;
		else if (dfs1(connected[n][i]))
			return true;
	}

	return false;
}

bool trigger() {
	for (int i = 1; i <= N; i++)
		if (dfs(i))
			return true;

	return false;
}

void getInput();
void getResult();
int main() {
	//freopen("A-small-attempt2.in", "r", stdin); freopen("a-small2.out", "w", stdout);
	freopen("A-large.in", "r", stdin); freopen("a-large.out", "w", stdout);

	int cases;
	cin >> cases;
	cin.ignore();
	for (int cnt = 1; cnt <= cases; cnt++) {
		getInput();
		cout << "Case #" << cnt << ":";
		getResult();
		cout << endl;
	}

	return 0;
}

void getInput() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		connected[i].clear();
		int n;
		cin >> n;

		while (n--) {
			int temp;
			cin >> temp;
			connected[i].push_back(temp);
		}
	}
}

void getResult() {
	if (trigger())
		cout << " Yes";
	else
		cout << " No";
}
