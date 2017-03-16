#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool visited[2600];

void solve(int test) {
	int n;
	memset(visited, 0, sizeof(visited));
	cin >> n;
	for (int i = 0; i < 2 * n - 1; ++i)
		for (int j = 0; j < n; ++j) {
		int data;
		cin >> data;
		visited[data] = !visited[data];
	}
	cout << "Case #" << test << ":";
	for (int i = 1; i <= 2500; ++i) {
		if (visited[i]) cout << " " << i;
	}
	cout << endl;
//	cout << "Case #" << test << ": " << res << endl;
}

int main() {
//	freopen("test.in", "r", stdin);
//	freopen("test.our", "w", stdout);
	int testNumber;
	cin >> testNumber;
	for (int test = 1; test <= testNumber; ++test) {
		solve(test);
	}
}