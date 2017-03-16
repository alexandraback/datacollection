#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

#define uchar unsigned char
#define ushort unsigned short
#define ull unsigned ll
#define ll long long
#define ull unsigned ll

#define E 2.718281828
#define PI 3.14159265358979323846264338328

int n;
int out[1001];
set<int> in[1001];

int flag[1001];

int opt = 0;

//0 - initial
//1 - to long circle
//2 - in long circle
//3 - to 2-length circle
//4 - in 2-length circle
//5 - done
void mark(int node) {
	set<int> v;
	while (flag[node] == 0 && v.find(node) == v.end()) {
		v.insert(node);
		node = out[node];
	}
	if (flag[node] != 0) {
		int f = flag[node];
		if (f == 2)
			f = 1;
		else if (f = 4)
			f = 3;
		for (set<int>::iterator sit = v.begin(); sit != v.end(); sit++)
			flag[*sit] = f;
		return;
	}
	if (out[out[node]] == node) {
		for (set<int>::iterator sit = v.begin(); sit != v.end(); sit++)
			flag[*sit] = 3;
		flag[node] = flag[out[node]] = 4;
	} else {
		for (set<int>::iterator sit = v.begin(); sit != v.end(); sit++)
			flag[*sit] = 1;
		flag[node] = 2;
		node = out[node];
		while (flag[node] != 2) {
			flag[node] = 2;
			node = out[node];
		}
	}
}

int dfs(int node) {
	int res = 0;
	for (set<int>::iterator sit = in[node].begin(); sit != in[node].end(); sit++)
		res = max(res, dfs(*sit));
	res++;
	flag[node] = 5;
	return res;
}

void solve() {
	opt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		out[i] = 0;
		in[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		cin >> out[i];
		in[out[i]].insert(i);
		flag[i] = 0;
	}
	for (int i = 1; i <= n; i++)
		if (flag[i] == 0)
			mark(i);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (flag[i] == 1)
			flag[i] = 5;
		else if (flag[i] == 2) {
			int len = 1, first = i, node = out[i];
			flag[i] = 5;
			while (node != first) {
				flag[node] = 5;
				len++;
				node = out[node];
			}
			opt = max(opt, len);
		} else if (flag[i] == 4) {
			in[i].erase(out[i]);
			in[out[i]].erase(i);
			sum += dfs(i) + dfs(out[i]);
		}
	}
	opt = max(opt, sum);
	cout << opt << endl;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}