#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
int H,W,D;
int Sx,Sy;
char area[64][64];

int gcd(int a, int b) { return b ? gcd(b,a%b): a; }
int sgn(int a) {
	if (a<0) return -1;
	if (a==0) return 0;
	return 1;
}

struct C {
	int i;
};

int dirdist(int sx, int sy) {
	int x=Sx, y=Sy;
	int r=0;
	while(area[y][x]=='.') ++r, x+=sx, y+=sy;
	return r;
}

bool test(int sx, int sy) {
	if (!sx || !sy) {
//		cout<<"dirdist "<<sx<<' '<<sy<<" : "<<dirdist(sx/2,sy/2)<<'\n';
		return 2*dirdist(sx/2,sy/2)-1 <= D;
	}
//	cout<<"*** TEST "<<sx<<' '<<sy<<" ***\n";
	int x=Sx,y=Sy;
	int ax=abs(sx), ay=abs(sy);
	int fx=ay/2,fy=ax/2;
	long double dist = 0;
//	int rounds = sqrt(4*D*D / (sx*sx + sy*sy));
//	cout<<"rounds "<<rounds<<'\n';
//	int cround = 1;
//	while(cround <= rounds) {
	const double eps = 1e-9;
	while(dist<D) {
//		cout<<x<<' '<<y<<' '<<fx<<' '<<fy<<" ; "<<sx<<' '<<sy<<" ; "<<dist<<'\n';
		if (x==Sx && y==Sy && dist && fx<ay/2 && fy<ax/2 && (ay-2*fx) == (ax-2*fy)) {
			dist += hypot(double(ay/2-fx)/ay, double(ax/2-fy)/ax);
			if (dist>D+eps) return 0;
//			cout<<"yes\n";
			return 1;
		}
		assert(area[y][x]=='.');

		int nx = ax*(fx + ax - fy);
		int ny = ay*(fy + ay - fx);

		int xx=x,yy=y;
		int px=fx,py=fy;
//		cout<<"nxny "<<nx<<' '<<ny<<'\n';
		if (nx<ny) {
			yy = y + sgn(sy);
			fx += ax - fy;
			fy = 0;
		} else if (ny<nx) {
			xx = x + sgn(sx);
			fy += ay - fx;
			fx = 0;
		} else {
			xx = x + sgn(sx);
			yy = y + sgn(sy);
			fx=fy=0;
		}
		int dx = (fx ? fx : ay) - px;
		int dy = (fy ? fy : ax) - py;
//		cout<<"dxdy "<<dx<<' '<<dy<<'\n';
		dist += hypot(ay ? dx/(double)ay : 0, ax ? dy/(double)ax : 0);
//		if (dist > cround*D) ++cround;

		if (area[yy][xx]=='.') {
			x = xx;
			y = yy;
//			cout<<"MOVING "<<sx<<' '<<sy<<'\n';
		} else {
			if (area[yy][x]=='.') {
				if (area[y][xx]=='.') {
					return 0;
				} else {
					y = yy;
					sx *= -1;
				}
			} else {
				if (area[y][xx]=='.') {
					x = xx;
					sy *= -1;
				} else {
					sx *= -1;
					sy *= -1;
				}
			}
		}
	}
	return 0;
}

int main() {
	int t;cin>>t;
	for(int a=1; a<=t; ++a) {
		cin>>H>>W>>D;
		memset(area,'#',sizeof(area));
		for(int i=0; i<H; ++i) cin>>&area[i+1][1];
		for(int i=1; i<=H; ++i) for(int j=1; j<=W; ++j) if (area[i][j]=='X') Sx=j,Sy=i;
		area[Sy][Sx]='.';

		int r=0;
		for(int sa=-D; sa<=D; ++sa) {
			for(int sb=-D; sb<=D; ++sb) {
				if (gcd(abs(sa),abs(sb))!=1) continue;
				if (sa*sa+sb*sb > D*D) continue;
				r += test(2*sa,2*sb);
			}
		}
		cout<<"Case #"<<a<<": "<<r<<'\n';
	}
}
