#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
 
using namespace std;
 
 
#define REP(a,b) for (int a=0; a<(int)(b); ++a)
#define FOR(a,b,c) for (int a=(b); a<(int)(c); ++a)
 
int n;
int zip[64];
vector <int> al[64];
int best[64], cur[64];
char vis[64];
int path[64], plen;
/*
void go(int pos, int left) {
	if (left == 0) {
		int pos = 0;
		while (best[pos] == cur[pos]) ++pos;
		if (cur[pos] < best[pos]) {
			REP(i,n) best[i] = cur[i];
		}
	} else {
		REP(i,al[pos].size()) {
			int next = al[pos][i];
			if (vis[next]==0) {
				vis[next] = 1;
				cur[n-left] = zip[next];
				go(next, left-1);
				vis[next] = 0;
			}
		}
	}
}*/

char cm[64][64];
char conn[64][64];
char v[64];

bool onpath(int a, int b) {
	for (int i = plen-1; i > 0; --i) if (path[i] == a && path[i-1] == b) return true;
	return false;
}

int dfs(int pos) {
	int res = vis[pos]?0:1;
	v[pos] = 1;
	REP(i,al[pos].size()) if (!v[al[pos][i]] && conn[pos][al[pos][i]] && (!vis[al[pos][i]] || onpath(pos, al[pos][i]))) res += dfs(al[pos][i]);
	return res;
}

void go(int pos, int left) {
	if (left == 0) return;
	
	int bestnext = -1, bestback = 0;
	REP(i,al[pos].size()) {
		int next = al[pos][i];
		if (vis[next] == 0 && (bestnext < 0 || zip[next] < zip[bestnext])) bestnext = next;
	}
	
	REP(i,n) REP(j,n) conn[i][j] = cm[i][j];
	int s = 0;
	while (vis[s]) ++s;

	REP (back,plen-1) {
		pos = path[plen-1-back-1];
		conn[path[plen-1-back-1]][path[plen-1-back]] = 0;
		conn[path[plen-1-back]][path[plen-1-back-1]] = 0;
		memset(v, 0, sizeof(v));
		if (dfs(pos) != left) break;
		REP(i,al[pos].size()) {
			int next = al[pos][i];
			if (vis[next] == 0 && (bestnext < 0 || zip[next] < zip[bestnext])) { bestnext = next; bestback = back+1; }
		}				
	}

	best[n-left] = zip[bestnext];
	plen -= bestback;
	path[plen] = bestnext;
	plen++;
	vis[bestnext] = 1;
	go(bestnext, left-1);
}

int main() {
	int t;
	int m, a, b, start;

	cin >> t;

	REP(tc,t) {
		cin >> n >> m;

		REP(i,n) REP(j,n) cm[i][j] = 0;
		start = 0;
		REP(i,n) { best[i] = 99999; cin >> zip[i]; al[i].clear(); if (zip[i] < zip[start]) start = i; }
		REP(i,m) {
			cin >> a >> b;
			al[a-1].push_back(b-1);
			al[b-1].push_back(a-1);
			cm[a-1][b-1] = cm[b-1][a-1] = 1;
		}

		memset(vis, 0, sizeof(vis));
		vis[start] = 1; best[0] = zip[start]; cur[0] = zip[start]; path[0] = start; plen = 1;
		go(start, n-1);
		/*priority_queue<pair<int,int> > pq;
		pq.push(make_pair(-zip[start], start));
		int ix = 0;
		while (!pq.empty()) {
			int city = pq.top().second; pq.pop();
			best[ix++] = zip[city];
			REP(i,al[city].size()) {
				int next = al[city][i];
				if (!vis[next]) { pq.push(make_pair(-zip[next], next)); vis[next] = 1; }
			}
		}*/
		

		cout << "Case #" << tc+1 << ": ";
		REP(i,n) cout << best[i];
		cout << endl;
	}

	return 0;
} 