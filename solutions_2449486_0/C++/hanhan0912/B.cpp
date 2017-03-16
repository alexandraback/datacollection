/* hanhanw v1.1 */
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
// for Online Judge or Contests
#define MSET(x,y) memset(x,y,sizeof(x))
#define REP(x,y,z) for(int x=y; x<=z; x++)
#define FORD(x,y,z) for(int x=y; x>=z; x--)
#define FLST(x,y,z) for(int x=y; x; x=z[x])
#define SZ size
#define PB push_back

using namespace std;
//
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LD;
// start here OAO~

struct QQ{
	int x,y,v;
	QQ (){}
	QQ (int _x, int _y, int _v){ x=_x; y=_y; v=_v; }
}p[10010];
int n,m,np,x[300][300];

bool comp(QQ a, QQ b){ return a.v > b.v; }

bool check(int stx, int sty, int px, int py, int v){
	while (1 <= stx && stx <= n && 1 <= sty && sty <=m){
		if (x[stx][sty] > v)
			return false;
		stx += px;
		sty += py;
	}
	return true;
}
void done(int stx, int sty, int px, int py, int v){
	while (1 <= stx && stx <= n && 1 <= sty && sty <=m){
		if (x[stx][sty] > v)
			x[stx][sty] = v;
		stx += px;
		sty += py;
	}
}
void solve(int nT){
	int sign=1;
	np=0;
	scanf("%d %d", &n, &m);
	REP(i,1,n)
		REP(j,1,m){
			scanf("%d", &x[i][j]);
			p[np++] = QQ(i,j,x[i][j]);
		}
	sort(p,p+np,comp);
	REP(i,0,np-1){
		if (check(p[i].x,1,0,1,p[i].v))
			done(p[i].x,1,0,1,p[i].v);
		else if (check(1,p[i].y,1,0,p[i].v))
			done(1,p[i].y,1,0,p[i].v);
		else {
			sign = 0;
			break;
		}
	}
	
	if (sign)
		printf("Case #%d: YES\n", nT);
	else
		printf("Case #%d: NO\n", nT);
}


int main(){
	int nT; scanf("%d", &nT);
	REP(i,1,nT)
		solve(i);

	return 0;
}
