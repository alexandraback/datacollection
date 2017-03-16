#include <stdio.h>
#include <algorithm>
using namespace std;

char map[70][70];
int H, W, D;
int wx, wy;

void input() {
	scanf("%d %d %d\n", &H, &W, &D);
	for(int y=0; y<H; y++) {
		for(int x=0; x<W; x++) {
			scanf("%c", &map[2*x][2*y]);
			map[2*x+1][2*y] = map[2*x+1][2*y + 1] = map[2*x][2*y +1] = map[2*x][2*y];
			if(map[2*x+1][2*y+1]=='X') wx = 2*x+1, wy = 2*y+1;
		}
		scanf("\n");
	}
	D*=2;
}

int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b, a%b);
}
int err(int x, int y, int dx, int dy) {//y *dx = x *dy +err
	return y*dx - x*dy;
}

bool ism(int x, int y, int sx, int sy) {
	return (map[x + ((sx==1) ? 0 : -1)][y + ((sy==1) ? 0 : -1)]=='#');
}
bool investigate(int x0, int y0, int cx, int cy, int dx, int dy, int sx, int sy) {
	//printf("%d %d|%d %d|%d %d|%d %d\n", x0, y0, cx, cy, dx, dy, sx, sy);
	int e1 = err(cx, cy, dx, dy);
	int e2 = err(cx+sx, cy, dx, dy);
	if(e1==0 and !(cx==0 and cy==0)) {
		if(x0 + cx == wx and y0 + cy == wy) return true;
	}
	if(cx == dx and cy == dy) return false;
	if(ism(x0 + cx, y0 + cy, sx, sy)) {
		//mirror
		bool mx = false, my = false;
		if(e1==0) {
			if(ism(x0 + cx - sx,y0 + cy, sx, sy)) my = true;
			if(ism(x0 + cx,y0 + cy - sy, sx, sy)) mx = true;
			if(!mx and !my) return false;
		} else {
			if(e1 * e2 < 0)
				my = true;
			else
				mx = true;
		}
		if(mx) {
			x0 += 2*cx;
			cx = -cx;
			dx = -dx;
			sx = -sx;
		}
		if(my) {
			y0 += 2*cy;
			cy = -cy;
			dy = -dy;
			sy = -sy;
		}
	}
	
	e2 = err(cx+sx, cy, dx, dy);
	int e3 = err(cx + sx, cy + sy, dx, dy);
	if(e3==0) {
		return investigate(x0, y0, cx + sx, cy + sy, dx, dy, sx, sy);
	} else if(e2 * e3 < 0) {
		return investigate(x0, y0, cx + sx, cy, dx, dy, sx, sy);
	} else { //nach r
		return investigate(x0, y0, cx, cy + sy, dx, dy, sx, sy);
	}
}

int solve() {
	int cnt = 0;
	input();
	
	int sx, sy;
	for(int i=0; i<4; i++) {
		if(i==0) sx = 0, sy = 1;
		else if(i==1) sx = 0, sy = -1;
		else if(i==2) sx = 1, sy = 0;
		else if(i==3) sx = -1, sy = 0;
		int x = wx, y = wy;
		
		for(int l=0; l<D; l++) {
			if(ism(x, y, sx, sy)) {
				sx = -sx; sy = -sy;
			}
			x += sx;
			y += sy;
			if(x==wx and y==wy) {
				cnt++;
				break;
			}
		}
	}
	
	for(int x=-D; x<=D; x+=2) for(int y=-D; y<=D; y+=2) if(x!=0 and y!=0 and gcd(abs(x/2), abs(y/2))==1){
		if(x*x + y*y <= D*D) {
			int n = 2;
			while(n*n*(x*x + y*y) <= D*D) n++;
			n--;
			
			if(investigate(wx, wy, 0, 0, n*x, n*y, (x>0)? 1 : -1, (y>0) ? 1 : -1))
				cnt++;
		}
	}
	
	return cnt;
}

int main() {
	
	int T;
	scanf("%d", &T);
	//T=2;
	for(int nc=1; nc<=T; nc++) {
		printf("Case #%d: %d\n", nc, solve());
	}
}
