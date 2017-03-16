//============================================================================
// Name        : GCJ16R1B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

#define sz(X) ((int)(X).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define FOR(I,S,N) for(int I=(S);I<(N);++I)
#define REP(I,N) FOR(I,0,N)

typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;




// end of pre-inserted code

void printv(VI &a) {
	REP(i, sz(a)) cerr << a[i] << " ";
	cerr << endl;
}

int get_id(const string& s, map<string, int>& a) {
	if(a.count(s) == 0) {
		int k = sz(a);
		a[s] = k;
		return k;
	}
	return a[s];
}

int sum(const VI& a) {
	int ans = 0;
	REP(i, sz(a)) ans += a[i];
	return ans;
}

int f(vector<pair<string, string> > a) {
	int n = sz(a);
	VI used(n);
	vector<PII> b(n);
	map<string, int> lx, ly;
	REP(i, n) {
		b[i].X = get_id(a[i].X, lx);
		b[i].Y = get_id(a[i].Y, ly);
//		cerr << b[i].X << " " << b[i].Y << endl;
	}
//	cerr << "---" << endl;

	VI hx(sz(lx)), hy(sz(ly));

	VI cx(sz(lx)), cy(sz(ly));
	REP(i, n) {
		++cx[b[i].X];
		++cy[b[i].Y];
	}

	REP(i, n) {
		if(cx[b[i].X] == 1 || cy[b[i].Y] == 1) {
			used[i] = 1;
			hx[b[i].X] = 1;
			hy[b[i].Y] = 1;
//			cerr << "!!!!!" << endl;
		}
	}
//	printv(hx);
//	printv(hy);

	while(sum(hx) < sz(lx) && sum(hy) < sz(ly)) {
		REP(i, n) if(!used[i]) {
			if(!hx[b[i].X] && !hy[b[i].Y]) {
				hx[b[i].X] = 1;
				hy[b[i].Y] = 1;
				used[i] = 1;
				goto next;
			}
		}

		REP(i, n) if(!used[i]) {
			if(!hx[b[i].X] || !hy[b[i].Y]) {
				hx[b[i].X] = 1;
				hy[b[i].Y] = 1;
				used[i] = 1;
				goto next;
			}
		}

		next: ;
	}
	return n - sum(used);
}

vector<VI> edges;
int q[1024], t[1024];

bool dfs(int u) {
	if(t[u]) return false;
	t[u] = 1;
	REP(i, sz(edges[u])) {
		if(q[edges[u][i]] == -1) {
			q[edges[u][i]] = u;
			return true;
		}
	}
	REP(i, sz(edges[u])) {
		int v = edges[u][i];
		if(dfs(q[v])) {
			q[v] = u;
			return true;
		}
	}
	return false;
}
int max_matching(int n, int m, const vector<PII>& e) {
	int ans = 0;
	edges = vector<VI>(n);
	REP(i, sz(e)) {
		edges[e[i].X].pb(e[i].Y);
	}
	memset(q, -1, sizeof(q));
//	REP(i, sz(e)) {
//		if(q[e[i].Y == -1) {
//			q[e[i].Y] = e[i].X;
//			++ans;
//		}
//	}
	REP(i, n) {
		memset(t, 0, sizeof(t));
		if(dfs(i)) {
			++ans;
		}
	}
	return ans;
}

int f2(vector<pair<string, string> > a) {
	int n = sz(a);
	VI used(n);
	vector<PII> b(n);
	map<string, int> lx, ly;
	REP(i, n) {
		b[i].X = get_id(a[i].X, lx);
		b[i].Y = get_id(a[i].Y, ly);
//		cerr << b[i].X << " " << b[i].Y << endl;
	}
//	cerr << "---" << endl;

	VI hx(sz(lx)), hy(sz(ly));

	VI cx(sz(lx)), cy(sz(ly));
	REP(i, n) {
		++cx[b[i].X];
		++cy[b[i].Y];
	}

	int mm = max_matching(sz(lx), sz(ly), b);

	int to_use = mm + (sz(lx) - mm) + (sz(ly) - mm);
	return n - to_use;
}



int main() {

//	freopen("1.txt", "r", stdin);

	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int tc;
	cin >> tc;
	FOR(t, 1, tc+1)
	{
		cerr << t << " ... " << endl;
		printf("Case #%d:", t);
		int n;
		cin >> n;
		vector<pair<string, string> > a(n);
		REP(i, n) cin >> a[i].X >> a[i].Y;
		printf(" %d\n", f2(a));
	}
	fclose(stdout);
	return 0;
}
