#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <ctime>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
#define FOR(x, b, e) for(int x=(b); x<=(e); ++x)
#define FORD(x, b, e) for(int x=((int)(b))-1; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) ((int)((x).size()))
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define mp(x,y) make_pair(x,y)
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FOREACH(it, (x)) cerr <<*it <<", "; cout <<endl; }}
#include <stdio.h>
#include <stdlib.h>
typedef short int sint;

const int K = 4;
char x[K], y[K];
int roz;
char ib[K], jb[K];

bool ok(int ii, int jj) {
	int isz; 
	int jsz;
	if (roz == 1) {
		isz = sprintf(ib, "%01d", ii);
		jsz = sprintf(jb, "%01d", jj);
	} else if (roz == 2) {
		isz = sprintf(ib, "%02d", ii);
		jsz = sprintf(jb, "%02d", jj);
	} else if (roz == 3) {
		isz = sprintf(ib, "%03d", ii);
		jsz = sprintf(jb, "%03d", jj);
	}
	if (isz != jsz || isz != roz) {
		return false;
	}
	REP(i, roz) {
		if (x[i] != '?' && x[i] != ib[i]) return false;
		if (y[i] != '?' && y[i] != jb[i]) return false;
	}
	return true;
}

void solve() {
	scanf("%s %s\n", x, y);
	roz = strlen(x);
	int resx = -1, resy = -1, resDiff = 1000000;
	REP(i, 1000) REP(j, 1000) {
		if (ok(i, j)) {
			// printf("ok: %d, %d\n", i, j);
			int diff = abs(i - j);
			if (resx == -1) {
				resx = i, resy = j, resDiff = diff;
			} else if (diff < resDiff) {
				resx = i, resy = j, resDiff = diff;
			} else if (diff == resDiff && i < resx) {
				resx = i, resy = j, resDiff = diff;
			} else if (diff == resDiff && i == resx && j < resy) {
				resx = i, resy = j, resDiff = diff;
			}
		}
	}
	if (roz == 1) {
		sprintf(ib, "%01d", resx);
		sprintf(jb, "%01d", resy);
	} else if (roz == 2) {
		sprintf(ib, "%02d", resx);
		sprintf(jb, "%02d", resy);
	} else if (roz == 3) {
		sprintf(ib, "%03d", resx);
		sprintf(jb, "%03d", resy);
	}

	printf("%s %s\n", ib, jb);
}

int main(){
	int t;
	scanf("%d\n", &t);
	FOR(i, 1, t) {
		cout << "Case #" << i << ": ";
		solve();
	}
}