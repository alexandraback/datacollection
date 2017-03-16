#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;
const int inf = int(1e9)+7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

const int MAXN = 100+5;
const int dir[4][2] = {-1,0, 1,0, 0,1, 0,-1};
int up[MAXN][MAXN], down[MAXN][MAXN];
double f[MAXN][MAXN];
int h, n, m;

void init() {
	cin>>h>>n>>m;
	FOR(i,n) FOR(j,m) {
		cin>>up[i][j];
	}
	FOR(i,n) FOR(j,m) {
		cin>>down[i][j];
	}
}
bool hefa(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	if (up[x][y] - down[x][y] < 50) return false;
	return true;
}
bool keda(int x, int y, int x1, int y1) {
	if (up[x][y] - down[x1][y1] < 50) return false;
	if (up[x1][y1] - down[x][y] < 50) return false;
	return true;
}
queue<int> qx, qy;
void work() {
	FOR(i,n) FOR(j,m) f[i][j] = inf;
	f[0][0] = 0;
	while (!qx.empty()) {
		qx.pop();
		qy.pop();
	}
	qx.push(0);
	qy.push(0);
	while (!qx.empty()) {
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();
		FOR(k,4) {
			int x1 = x + dir[k][0];
			int y1 = y + dir[k][1];
			if (!hefa(x1,y1)) continue;
			if (!keda(x,y,x1,y1)) continue;
		
			double ch = max(h-10*f[x][y], (double)down[x][y]);
			double len = h-10*f[x][y]-down[x][y];
			if (up[x1][y1] - ch >= 50-eps) {
			//	cout<<x1<<" "<<y1<<endl;
				double nf = f[x][y] + 1;
				if (len < 20-eps) nf += 9;
				if (f[x][y] == 0) nf = 0;
				if (nf < f[x1][y1]) {
					f[x1][y1] = nf;
					qx.push(x1);
					qy.push(y1);
				}
			} else {
			//		cout<<"r"<<x1<<" "<<y1<<endl;
			
				double tt = (50 - (up[x1][y1] - ch))/10;
				double nf = f[x][y] + 1 + tt;
				len -= tt*10;
				if (len < 20-eps) nf += 9;
				if (nf < f[x1][y1]) {
					f[x1][y1] = nf;
					qx.push(x1);
					qy.push(y1);
				}
			}
		}
	}
}
int main() {
	freopen("b.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int caseNum;
	scanf("%d", &caseNum);
		
	REP(c, 1, caseNum+1) {
		init();
		work();
		printf("Case #%d: %.8lf\n", c, f[n-1][m-1]);
	};
//	while (1>0) {}
	return 0;
} 
