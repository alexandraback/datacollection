//Written by technolt~h

#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
 #include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
 #include <complex>

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
 #define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
 #define MP make_pair
#define F first
#define S second
#define Aint(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define LL long long
#define PI acos(-1.0)
#define oo 1000111


using namespace std;

bool Free[400][400];

int N, X, Y, res, cnt;

void next(int u, int v, vector <pair <int, int> > * pos) {
	while (v > 5 && Free[u][v - 2] && Free[u - 1][v - 1] && Free[u + 1][v - 1]) v--;
	
	if (v == 5) {
		(*pos).PB(MP(u, v));
		return;
	}

	if (Free[u - 1][v - 1]) {
		next(u - 1, v - 1, pos);
		if (Free[u + 1][v - 1]) next(u + 1, v - 1, pos);
	}
	else
	if (Free[u + 1][v - 1]) next(u + 1, v - 1, pos);
	else {
		(*pos).PB(MP(u, v));
		return;
	}
}

double call(int i) {
	if (i == N + 1) {
		int res = 0;
		if (1 <= X + 100  && X + 100 <= 200 && 1 <= Y + 5 && Y + 5 <= 200)
			res += (Free[X + 100][Y + 5] == false);
		return res;
	}
	
	
	vector <pair <int, int> > pos;
	pos.clear();
	next(100, 50, &pos);
	
	double ratio = 1.0/(double)(pos.size());
	double res = 0;
	REP (j, pos.size()) {
		int u = pos[j].first;
		int v = pos[j].second;
		
		Free[u][v] = false;
		res += ratio * call(i + 1);
		Free[u][v] = true;
	}
	
	return res;
}
int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("b2.out", "w", stdout);
	int ntest;
	
	cin >> ntest;
	FOR (test, 1, ntest) {
		cout << "Case #" << test << ": ";
		
		cin >> N >> X >> Y;
		RESET (Free, true);
		/*
		vector <pair <int, int> > pos;
		pos.clear();
		next(100, 50, &pos);
		cerr << pos.size() << endl;
		cerr << pos[0].first << " " << pos[0].second << endl;;
		cerr << pos[1].first << " " << pos[1].second << endl;
		break;
		*/
		
		double RES = call(1);
		
		printf("%.9lf\n", RES);
	}
    return 0;
}



