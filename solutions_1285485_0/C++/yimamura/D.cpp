#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

template<class Ty>
Ty gcd(Ty a, Ty b) {
	if(b<a) swap(a, b);
	while(a) {
		b %= a;
		swap(a, b);
	}
	return b;
}

int g_cx, g_cy;
char g_map[32][32];

bool isNear(double a, double b) {
	return fabs(a-b) < 1e-9;
}

bool funcA(double dx, double dy, double t) {
	int x = g_cx;
	int y = g_cy;
	double xx = 0;
	double yy = 0;
	while(0<t) {
		double tt = t;
		if(0<dx) tt = min(tt, (0.5-xx) / dx);
		if(dx<0) tt = min(tt, (-0.5-xx) / dx);
		if(0<dy) tt = min(tt, (0.5-yy) / dy);
		if(dy<0) tt = min(tt, (-0.5-yy) / dy);
		if(g_cx==x && g_cy==y) {
			if(dx!=0) {
				double dtx = -xx / dx;
				if(0<dtx) tt = min(tt, dtx);
			}
			if(dy!=0) {
				double dty = -yy / dy;
				if(0<dty) tt = min(tt, dty);
			}
		}
		xx += dx * tt;
		yy += dy * tt;
		t -= tt;
		if(g_cx==x && g_cy==y && isNear(xx, 0) && isNear(yy, 0)) {
			return true;
		}
		int flgCnt = 0;
		int mx = 0;
		int my = 0;
		if(0<dx && isNear(0.5, xx)) {
			mx = 1;
			++flgCnt;
		}
		if(dx<0 && isNear(-0.5, xx)) {
			mx = -1;
			++flgCnt;
		}
		if(0<dy && isNear(0.5, yy)) {
			my = 1;
			++flgCnt;
		}
		if(dy<0 && isNear(-0.5, yy)) {
			my = -1;
			++flgCnt;
		}
		if(flgCnt==1) {
			if(g_map[y+my][x+mx]=='#') {
				if(mx) dx = -dx;
				else dy = -dy;
			}
			else {
				if(mx) { x += mx; xx = -xx; }
				else { y += my; yy = -yy; }
			}
		}
		else if(flgCnt==2) {
			if(g_map[y+my][x+mx]=='#') {
				if(g_map[y][x+mx]=='#') {
					if(g_map[y+my][x]=='#') {
						dx = -dx;
						dy = -dy;
					}
					else {
						dx = -dx;
						y += my; yy = -yy;
					}
				}
				else if(g_map[y+my][x]=='#') {
					dy = -dy;
					x += mx; xx = -xx;
				}
				else {
					return false;
				}
			}
			else {
				xx = -xx;
				yy = -yy;
				x += mx;
				y += my;
			}
		}
	}
	return false;
}

int main() {
	ifstream cin("D-small-attempt0.in");
	freopen("D-small-attempt0.out.txt", "wb", stdout);
	string line;
	getline(cin, line);
	int T = atoi(line.c_str());
	for(int t=0; t<T; ++t) {
		getline(cin, line);
		int H, W, D;
		sscanf(line.c_str(), "%d%d%d", &H, &W, &D);
		for(int y=0; y<H; ++y) {
			getline(cin, line);
			strcpy(g_map[y], line.c_str());
		}
		for(int y=0; y<H; ++y) {
			for(int x=0; x<W; ++x) {
				if(g_map[y][x]=='X') {
					g_cx = x;
					g_cy = y;
				}
			}
		}
		int result = 0;
		for(int dy=-D; dy<=D; ++dy) {
			for(int dx=-D; dx<=D; ++dx) {
				if(dx==0 && abs(dy)!=1) continue;
				if(dy==0 && abs(dx)!=1) continue;
				if(gcd(abs(dx), abs(dy))!=1) continue;
				double dd = sqrt(dx*dx + dy*dy);
				if(funcA(dx / dd, dy / dd, D)) {
					++result;
				}
			}
		}
		printf("Case #%d: %d\n", t+1, result);
	}
	return 0;
}
