#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define all(v) v.begin(), v.end()

int n,m;
int a[103][103];

#define REP(i, n) for(int i=0; i<(int)(n); ++ i) 
#define uniquify(v) {sort(all(v));(v).erase(unique(all(v)), (v).end());}

bool go() {
	int hmax = 0;
	REP(i, n) REP(j, n) hmax = max(hmax, (int)a[i][j]);

	for(int h = hmax; h >= 1; -- h)
	{
		// able(i,j) = a[i][j] <= h
		vector<int> rows, cols;

		REP(i, n) {
			vector<int> should;
			REP(j, m) if(a[i][j] <= h) should.push_back(j);

			if(should.size() == 0);
			else if(should.size() == m)
				rows.push_back(i);
			else cols.insert(cols.end(), all(should));
		}
		REP(j, m) {
			vector<int> should;
			REP(i, n) if(a[i][j] <= h) should.push_back(i);

			if(should.size() == 0);
			else if(should.size() == n)
				cols.push_back(j);
			else rows.insert(rows.end(), all(should));
		}
		uniquify(rows);
		uniquify(cols);
		for(int i : rows) {
			REP(j, m) if(a[i][j] > h) return false;
		}
		for(int j : cols) {
			REP(i, n) if(a[i][j] > h) return false;
		}
	}
	
	return true;
}

int main() {
	int T;
	freopen("B-small.in","r",stdin);
	freopen("B-small.out","w",stdout);

	scanf("%d", &T);
	for(int t=1; t<=T; ++t) {
		scanf("%d %d", &n, &m);
		REP(i, n) REP(j, m)
			scanf("%d", &a[i][j]);
		printf("Case #%d: %s\n", t, go() ? "YES":"NO");
	}
	return 0;
}