#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <cassert>
using namespace std;

char maze[111][111];

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

long long dist2(long long x, long long y) { return x * x + y * y; }

int cond = 0;
#define db(x) { if (cond) cerr << __LINE__ << #x << " " << x << endl ; }
#define abs(x) ((x)>0?(x):-(x))

void doit(){
	int h, w, d;
	scanf("%d%d%d", &h, &w, &d);

	int sx = -1, sy = -1;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++) {
			scanf(" %c", &maze[i][j]);
			if (maze[i][j] == 'X') {
				sx = i; sy = j;
				maze[i][j] = '.';
			}
		}
	if (cond)
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++) {
			cerr<<maze[i][j];
		}
	cerr<<endl;
}
int ret = 0;
	db(sx<<" "<<sy);
	for (int dx = -d; dx <= d; dx++)
		for (int dy = -d; dy <= d; dy++) if (dx!=0||dy!=0) {
			//db(dx<<" "<<dy<<" "<<gcd(abs(dx), abs(dy)));
			if (gcd(abs(dx), abs(dy)) == 1) {
				int fact = max(1,abs(dx))*max(1,abs(dy));
				int cx = (sx*2+1)*fact;
				int cy = (sy*2+1)*fact;
				int px = (sx*2+1)*fact;
				int py = (sy*2+1)*fact;
				int mx = dx;
				int my = dy;

				int trav = 0;
				bool ok = 0;
				//db(dx<<" "<<dy);
				while (dist2(trav * dx, trav * dy) <= dist2(d * 2 * fact, 0)) {
					//db(trav<<" "<<px<<" "<<py<<" "<<mx<<" "<<my<<" "<<fact);
					int travel = (int)1e9;
					if (trav > 0 && px == cx && py == cy) { ok = 1; break; }
					//db("");
					{
						if (mx > 0) { travel = min(travel, 
							((px + fact)/fact*fact - px) / mx); }
						if (mx < 0) { travel = min(travel, 
							((px - 1)/fact*fact - px) / mx); }
					}
					//db("");
					{
						if (my > 0) { travel = min(travel, 
							((py + fact)/fact*fact - py) / my); }
						if (my < 0) { travel = min(travel, 
							((py - 1)/fact*fact - py) / my); }
					}
					//db("");
					px += mx * travel;
					py += my * travel;
					//db(px<<" "<<px<<" "<<mx<<" "<<my);
					if (px % (2*fact) == 0) {
						if (py % (2*fact) == 0) {
							int ni = px / (2*fact);
							int nj = py / (2*fact);
							if (maze[ni+(mx>=0?0:-1)][nj+(my>=0?0:-1)] == '#') {
								bool c1= (maze[ni+(mx>=0?0:-1)][nj+(my>=0?-1:0)] == '#');
								bool c2= (maze[ni+(mx>=0?-1:0)][nj+(my>=0?0:-1)] == '#');
								bool c3= (maze[ni+(mx>=0?-1:0)][nj+(my>=0?-1:0)] == '#');
								assert(c3 == 0);
								if (c1 == 0 && c2 == 0) break;
								if (c1) mx = -mx;
								if (c2) my = -my;
							}
							else { 
								//do nothing
						       	}
						}
						else {
							int ni = px / (2*fact);
							int nj = py / (2*fact);
							assert(maze[ni+(mx>=0?-1:0)][nj] == '.');

							if (maze[ni+(mx>=0?0:-1)][nj] == '#') {
								mx = -mx;
							}
							else { 
								//do nothing
							}


						}
					}
					else {
						if (py % (2*fact) == 0) {
							int ni = px / (2*fact);
							int nj = py / (2*fact);
							assert(maze[ni][nj+(my>=0?-1:0)] == '.');
							if (maze[ni][nj+(my>=0?0:-1)] == '#') {
								my = -my;
							}
							else { 
								//do nothing
							}

						}
						else {
							///...
						}
					}

					trav += travel;
				}
				if (ok) ret++;
			}
		}
	printf("%d", ret);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i=1;i<=t;i++){
		printf("Case #%d: ", i);
		doit();
		printf("\n");
	}

	return 0;
}
