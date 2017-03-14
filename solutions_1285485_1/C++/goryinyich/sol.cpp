#pragma comment(linker, "/STACK:33554432")

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <memory.h>

using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define ABS(n) ((n)<0 ? -(n) : (n))
#define SQR(a) (a)*(a)
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define MP make_pair
#define PB push_back
#define FILL(a) memset(a,0,sizeof(a));
#define COPY(a,b) memcpy(a,b,sizeof (b));
#define SI(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define y1 yyyyy1
#define prev prevvvvv
#define LL long long
const double PI = 2*acos(0.0);
const double EPS = 1e-8;
const int INF = (1<<30)-1;
const int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

struct Point{
	double x, y;
	Point (double x = 0, double y = 0){
		this->x = x; this->y = y;
	}
};

double dist (const Point& a, const Point& b){
	return sqrt(SQR(a.x-b.x) + SQR(a.y-b.y));
}

int tc, m, n, dd;
int cx, cy;
char s[100][100];

int gcd (int a, int b){
	while (a && b)
		if (a > b) a %= b;
		else b %= a;
	return a+b;
}

bool intNum (double x){
	return MIN(abs(x-floor(x)),abs(ceil(x)-x)) < EPS;
}

int round (double x){
	return int (floor (x + 0.5));
}

int intCase (Point cp, Point dir){
	int ix = round (cp.x);
	int iy = round (cp.y);
	if (dir.x < 0) --ix;
	if (dir.y < 0) --iy;
	if (s[iy][ix]=='.') return 0;
	char a1, a2;
	if (dir.x > 0) a1 = s[iy][ix-1];
	else a1 = s[iy][ix+1];
	if (dir.y > 0) a2 = s[iy-1][ix];
	else a2 = s[iy+1][ix];
	if (a1=='#' && a2=='#') return 3;
	if (a1 == '#') return 2;
	if (a2 == '#') return 1;
	return -1;
}

bool reached (Point cp, Point dir, double d){
	double dx, dy;
	if (dir.x > 0){
		dx = ceil(cp.x) - cp.x;
		if (dx <= 0) dx += 1;
	}else{
		dx = cp.x - floor(cp.x);
		if (dx <= EPS) dx += 1;
	}
	if (dir.y > 0){
		dy = ceil(cp.y) - cp.y;
		if (dy <= 0) dy += 1;
	}else{
		dy = cp.y - floor(cp.y);
		if (dy <= EPS) dy += 1;
	}
	double t = MIN(abs(dx/dir.x), abs(dy/dir.y));
	Point np = Point (cp.x + dir.x*t, cp.y + dir.y*t);
	double dv = sqrt(SQR(dir.x) + SQR(dir.y));
	d -= dv*t;
	if (d < -EPS) return false;

	if (intNum (np.x) && intNum (np.y)){
		np = Point((double)round(np.x), (double)round(np.y));
		if (dist (np, Point(cx, cy)) < EPS) return true;
		int res = intCase (np, dir);
		if (res < 0) return false;
		if (res == 0) return reached (np, dir, d);
		if (res == 1) return reached (np, Point (-dir.x, dir.y), d);
		if (res == 2) return reached (np, Point (dir.x, -dir.y), d);
		if (res == 3) return 2*d + EPS > double(dd);
	}else if (intNum (np.x)){
		np.x = round (np.x);
		int iy = (int)floor (np.y);
		int ix = round (np.x);
		if (dir.x < 0) --ix;
		if (s[iy][ix]=='.') return reached (np, dir, d);
		else return reached (np, Point(-dir.x, dir.y), d);
	}else if (intNum (np.y)){
		np.y = double(round (np.y));
		int ix = (int)floor (np.x);
		int iy = round (np.y);
		if (dir.y < 0) --iy;
		if (s[iy][ix]=='.') return reached (np, dir, d);
		else return reached (np, Point (dir.x, -dir.y), d);
	}else while (true){cout << "FUCK!!!";}
	
}

bool move (Point currPos, Point dir){
	return (reached (currPos, dir, dd));
}

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	scanf ("%d", &tc);
	REP(ic,tc){
		scanf ("%d%d%d\n", &m, &n, &dd);
		REP(i,m) gets (s[i]);

		REP(i,m) REP(j,n) if (s[i][j]=='X'){
			cx = j; cy = i;}

		int ans = 0;
		REP(k,4){
			int tx = cx, ty = cy;
			int len = 0;
			do{
				++len;
				tx += dc[k]; ty += dr[k];
			}while (s[ty][tx]!='#');
			if (2*len-1 <= dd) ++ans;
		}

		for (int i = m-1; i >= 0; --i){
			for (int j = n-1; j >= 0; --j){
				s[2*i+1][2*j+1] = s[2*i+1][2*j] = s[2*i][2*j+1] = s[2*i][2*j] = s[i][j];
			}
		}

		m *= 2; n *= 2;

		REP(i,m) REP(j,n) if (s[i][j]=='X'){
			s[i][j] = s[i+1][j] = s[i][j+1] = s[i+1][j+1] = '.'; cx = j+1; cy = i+1;
		}
		dd *= 2;

		for (int dx = -dd; dx <= dd; dx += 2) if (dx != 0){
			for (int dy = -dd; dy <= dd; dy += 2) if (dy != 0) if (dx*dx + dy*dy <= dd*dd) if (gcd (abs(dx), abs(dy)) == 2){
				if (move (Point(cx, cy), Point(dx,dy))) ++ans;
			}
		}
		cout << "Case #" << ic+1 << ": " << ans << endl;
	}
	return 0;
};