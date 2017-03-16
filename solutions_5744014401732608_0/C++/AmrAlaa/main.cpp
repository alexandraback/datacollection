#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <fstream>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <map>
#include <set>

using namespace std;
const unsigned long long O = 2e9;
const double E = 1e-9;
const double pi = 3.1415926536;
int DX[] = { 1, -1, 0, 0 };
int DY[] = { 0, 0, 1, -1 };

/*bool valid(int x, int y)
 {
 return ((x >= 0 && x<n) && (y >= 0 && y<n));
 }*/
set<vector<int> > v1;
vector<int> way;
vector<vector<int> > v;

int n, m, vis[7];
void path(int num, int all, int ind) {
	if (num == all) {
		if (!vis[n])
			way.push_back(n);
		v1.insert(way);
		if(!vis[n])
		way.pop_back();
		return;
	}

	for (int i = ind; i <= n; i++)
		if (v1.size() < m && !vis[i]) {
			way.push_back(i);
			vis[i] = 1;
			path(num + 1, all, i);
			way.pop_back();
			vis[i] = 0;
		}
}
int main() {
	freopen("B-small-attempt3.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, X = 1;
	cin >> t;
	while (t--) {

		cin >> n >> m;
		int arr[55][55];
		memset(arr, 0, sizeof arr);
		way.push_back(1);
		for (int i = 1; i <= n; i++) {
			if (v1.size() < m)
				path(0, i, 2);

		}
		for(set<vector<int> >::iterator it=v1.begin();it!=v1.end();it++)
			v.push_back(*it);
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size() - 1; j++)
				arr[v[i][j]][v[i][j + 1]] = 1;
		}
		if (v.size() != m)
			cout << "Case #" << X++ << ": IMPOSSIBLE\n";
		else {
			cout << "Case #" << X++ << ": POSSIBLE\n";
			for (int i = 1; i <= n; i++) {
				cout << arr[i][1];
				for (int j = 2; j <= n; j++)
					cout << " " << arr[i][j];
				cout << endl;
			}
		}
		v.clear();
		way.clear();
		v1.clear();
	}

}
