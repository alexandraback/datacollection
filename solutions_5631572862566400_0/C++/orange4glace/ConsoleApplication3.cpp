#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;

#define INF 300000000
#define LLINF 10000000000000LL
#define MOD 1000000000LL
#define cout cout
#define cin cin
typedef long long ll;

int Q, N, M, K, L;
int g[1005];
vector<int> gr[1005];
bool visit[1005];
int d[1005];
int dret = 0;
int ret;
int r1 = 0;
int r2 = 0;
bool canconnec;
int cs, ce;

void dfs(int n, int dep) {
	visit[n] = true;
	int next = g[n];
	if (visit[next]) {
		if (abs(d[next] - dep) == 1)
			canconnec = true;
		if (canconnec) dret = 2;
		else dret = abs(d[next] - dep) + 1;
		cs = next;
		ce = n;
		return;
	}
	d[next] = dep + 1;
	dfs(next, dep + 1);
}

void rdfs(int n, int d, int& r) {
	r = max(r, d);
	visit[n] = true;
	for (int i = 0; i < gr[n].size(); i++) {
		int next = gr[n][i];
		if (visit[next]) continue;
		rdfs(next, d + 1, r);
	}
}

int main() {
	ifstream in("C-small-attempt4.in");
	ofstream out("out.txt");
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());
	
	cin >> Q;
	for (int qq = 0; qq < Q; qq++) {
		cin >> N;
		ret = 0;
		for (int i = 1; i <= N; i++) gr[i].clear();
		for (int i = 1; i <= N; i++) {
			cin >> g[i];
			gr[g[i]].push_back(i);
		}
		for (int i = 1; i <= N; i++) {
			for (int i = 1; i <= N; i++) visit[i] = false, d[i] = 0;
			d[i] = 1;
			cs = i;
			r1 = 0;
			r2 = 0;
			dret = 0;
			canconnec = false;
			dfs(i, 1);
			if (canconnec) {
				rdfs(ce, 0, r1);
				rdfs(cs, 0, r2);
				dret += r1 + r2;
			}
			ret = max(ret, dret);
		}
		cout << "Case #" << qq +1 << ": " << ret << endl;
	}

	return 0;
}