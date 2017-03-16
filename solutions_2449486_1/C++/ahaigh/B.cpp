/*
 ID: aaandrew
 PROG: gcj 13 qual round 
 LANG: C++
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <utility>
#include <cassert>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <fstream>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef pair<int,int> pii;
typedef long long ll;
#define MP make_pair
#define PB push_back

const int N = 105;
int T, n, m, a[N][N], v[N][N];
vector<pair<int,pii> > V;
int done_row[N], done_col[N];

int main() {
	cin >> T;
	REP(t,T) {
		V.clear();
		
		cin >> n >> m;
		REP(i,n) REP(j,m) {
			cin >> a[i][j];
			V.PB(MP(-a[i][j],MP(i,j)));
			v[i][j] = 100;
			done_row[i] = done_col[j] = 0;
		}
		sort(V.begin(), V.end());
		
		REP(i,V.size()) {
			int h = -V[i].first, x = V[i].second.first, y = V[i].second.second;
			
			//try to cut row
			if (done_row[x] <= h) {
				REP(j,m) v[x][j] = min(v[x][j], h);
			}
			//try to cut col
			else if (done_col[y] <= h) {
				REP(j,n) v[j][y] = min(v[j][y], h);
			}
			
			/*cout << x << " " << y << endl;
			REP(i,n) {
				REP(j,m) cout << v[i][j] << " ";
				cout << endl;
			}
			cout << endl;*/
			
			done_row[x] = max(done_row[x], h);
			done_col[y] = max(done_col[y], h);
		}
		
		bool flag = true;
		REP(i,n) REP(j,m) if (a[i][j] != v[i][j]) flag = false;
		cout << "Case #" << (t+1) << ": " << (flag ? "YES" : "NO") << endl;
	}
}
