#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <utility>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vi vector<int>
#define rep(i,n) for( int i = 0; i < (n); i++ )
#define forn(i,a,b) for( int i = (a); i < (b); i++ )
#define fi first
#define se second

const int MXN = 4000100;
const int MXV = 310;
const int MXM = 500;

char ans [MXN];

bool was [MXV][MXV][MXM];
char pre [MXV][MXV][MXM];

pii qq [MXN];
int qqi [MXN];
int qh = 0, qt = 0;

int dx [] = {1,-1,0,0};
int dy [] = {0,0,1,-1};
char dir [] = {'E','W','N','S'};

void out( int x, int y, int mv ){
	int anc = 0;
	while(pre[x][y][mv]!='X'){
		ans[anc++] = pre[x][y][mv];

		int q = 0;
		if(pre[x][y][mv]=='N') q = 3;
		else if(pre[x][y][mv]=='S') q = 2;
		else if(pre[x][y][mv]=='E') q = 1;
		else if(pre[x][y][mv]=='W') q = 0;

		x+=dx[q]*(mv-1);
		y+=dy[q]*(mv-1);
		mv--;
	}

	ans[anc] = 0;

	reverse(ans, ans+anc);
}

void solve(){
	int x,y;
	scanf("%d%d", &x, &y);

	x+=MXV/2, y+=MXV/2;

	qq[qt] = mp(MXV/2, MXV/2);
	qqi[qt++] = 1;
	pre[MXV/2][MXV/2][1] = 'X';
	was[MXV/2][MXV/2][1] = 1;

	while( qh!=qt ){
		pii cur = qq[qh];
		int st = qqi[qh++];

		if( cur.first == x && cur.second == y ){
			out(x,y,st);
			break;
		}

		rep(i,4){
			int nx = cur.first + dx[i]*st;
			int ny = cur.second + dy[i]*st;
			if( nx>=0 && ny >=0 && nx<MXV && ny < MXV && !was[nx][ny][st+1] ){
				qqi[qt] = st+1;
				qq[qt++] = mp(nx,ny);
				was[nx][ny][st+1] = 1;
				pre[nx][ny][st+1] = dir[i];
			}
		}
	}
}

int main(){
	freopen("B.in", "r", stdin);	freopen("B.out", "w", stdout);

	int T;
	scanf("%d", &T);

	rep(i,T){
		solve();
		printf("Case #%d: %s\n", i+1, ans);
	}
}	