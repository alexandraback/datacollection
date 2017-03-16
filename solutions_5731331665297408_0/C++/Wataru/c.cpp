#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;


int n, m;

vector<int> zip;
vector< vector<int> > a;

void Load()
{
	cin >> n >> m;
	zip.clear();
	a.clear();
	int i, j;
	a.resize(n);
	zip.resize(n);
	for (i = 0; i < n; i++)
		cin >> zip[i];
	for (j = 0; j < m; j++) {
		int q, w;
		cin >> q >> w;
		cerr << q << " -> " << w << "\n";
		q--;
		w--;
		a[q].push_back(w);
		a[w].push_back(q);
	}
	cerr << "loaded\n";
}

vector<int> stack;
vector<int> was;
int nfree;


int Dfs2(int u)
{
//	cerr << "dfs2 " << u << "\n";
	int ans = 1;
	was[u] = 2;
	for (int i = 0; i < (int) a[u].size(); i++) {
		if (was[a[u][i]] == 0)
		ans += Dfs2(a[u][i]);
	}
	return ans;
}

int calc(int i) {
	int j;
	int ans = 0;
	for (j = 0; j <= i; j++) {
		int t, l;
		l = stack[j];
		for (t = 0; t < (int) a[l].size(); t++) {
			int k = a[l][t];
			if (was[k] == 0) ans += Dfs2(k);
		}
	}
	for (int t = 0; t < n; t++)
		if (was[t] == 2) was[t] = 0;
	return ans;
}

void Dfs1(int z) {
	cerr << "Dfs1 " << z << "\n";
	stack.push_back(z);
	cout << zip[z];
	was[z] = 1;
	nfree--;
	if (nfree == 0) return;
	int mi = -1;
	int mj = -1;
	int i, j;
	for (i = (int)stack.size()-1; i >= 0; i--) {
		int t = calc(i);
		cerr << "for " << i << " calc = " << t << " nfree = " << nfree << "\n";
		for (j = 0; j < (int)a[stack[i]].size(); j++) {
			int l = a[stack[i]][j];
			if (was[l] != 0) continue;
			if (t == nfree) {
				cerr << "trying " << l << "\n";
				if (mj == -1 || zip[l] < zip[mj]) {
					mi = i;
					mj = l;
				}
			}
		}
	}
	cerr << "mi = " << mi << " mj = " << mj << "\n"; 
	stack.resize(mi+1);
	Dfs1(mj);
}

void Solve()
{
	int mi = 0;
	int i;
	for (i = 1; i < n; i++) {
		if (zip[i] < zip[mi])
			mi = i;
	}
	stack.clear();
	was.clear();
	was.resize(n);
	nfree = n;
	Dfs1(mi);
	cout << "\n";
}

int main()
{
	cout.setf(ios::fixed|ios::showpoint);
	cout.precision(10);
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Load();
		Solve(); 
	}
	return 0;
}
