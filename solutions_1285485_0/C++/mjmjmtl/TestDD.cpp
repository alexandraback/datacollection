// TestDD.cpp : Defines the entry polong long for the console application.
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;


long long gcd(long long a,long long b) {//如果a和b有一个是0，返回另一个
	static long long t;
	for(; t=b; b=a%b,a=t);
	return a;
}
long long sig(long long m) {
	return m > 0 ? 1 : m < 0 ? -1 : 0;
}
struct Frac {
	long long a, b;
	Frac (long long a, long long b=1) {
		this->a = a;
		this->b = b;
		for(long long t; t=b; b=a%b,a=t);
		this->a /= a;		this->b /= a;

		if(this->b<0) {
			this->a = -this->a;
			this->b = -this->b;
		}
	}
	long long sig() const {
		return ::sig(this->a);
	}
	Frac operator + (const Frac & f) const {
		return Frac(a*f.b+b*f.a, b*f.b);
	}
	Frac operator - (const Frac & f) const {
		return Frac(a*f.b-b*f.a, b*f.b);
	}
	Frac operator * (const Frac & f) const {
		return Frac(a*f.a, b*f.b);
	}
	Frac operator / (const Frac & f) const {
		return Frac(a*f.b, b*f.a);
	}
	bool operator < (const Frac & f) const {
		Frac tmp = *this-f;
		return ::sig(tmp.a) * ::sig(tmp.b) < 0;
	}
	bool operator ==(const Frac & f) const {
		if(*this < f)	return false;
		if(f < *this)	return false;
		return true;
	}
	void output() {
		printf("%d/%d\n", a, b);
	}
	long long getUpper() {
		return (a+b-1)/b;
	}
};

typedef pair<long long,long long> T;

/////////////

long long H, W, D, ans;
char G[50][50];

long long startRow, startCol;

//////////////

long long DX, DY;


Frac getStep(Frac x, Frac y, long long col, long long row, long long dx, long long dy) {
	Frac res(1000000);
	if(dx>0) {
		res = min(res, (Frac(col+1)-x) / Frac(dx));
	} else if(dx<0) {
		res = min(res, (Frac(col)-x) / Frac(dx));
	}
	if(dy>0) {
		res = min(res, (Frac(row+1)-y) / Frac(dy));
	} else if(dy<0) {
		res = min(res, (Frac(row)-y) / Frac(dy));
	}
	return res;
}

bool test() {
	//prlong longf("test, DX = %d, DY = %d\n", DX, DY);
	Frac sumC(0);
	Frac x(startCol*2+1, 2);
	Frac y(startRow*2+1, 2);

	long long col = startCol;
	long long row = startRow;
	long long dx = DX;
	long long dy = DY;

	while(true) {
		Frac c = getStep(x,y,col,row,dx,dy);

		c = min(c, Frac(1)-sumC);
		sumC = sumC + c;

		x = x + c * dx;
		y = y + c * dy;

		//c.output();
		if(sumC == Frac(1)) {
			//x.output();
			//y.output();
			
			if(x==Frac(startCol*2+1, 2) && y==Frac(startRow*2+1, 2)) {
				return true;
			} else {
				return false;
			}
		}

		long long col2 = col + sig(dx);
		long long row2 = row + sig(dy);

		if(x.b==1 && y.b==1) {
			if(G[row2][col2] == '#') {
				if(G[row][col2]=='#' && G[row2][col]=='#') {
					col = col;
					row = row;
					dx = -dx;
					dy = -dy;
				} else if(G[row][col2] == '#') {
					row = row2;
					col = col;
					dx = -dx;
					dy = dy;
				} else if(G[row2][col] == '#') {
					row = row;
					col = col2;
					dx = dx;
					dy = -dy;
				} else {
					return false;	//absorb...........
				}
			} else {
				col = col2;
				row = row2;
				dx = dx;
				dy = dy;
			}
		} else if(x.b==1) {
			if(G[row][col2] == '#') {
				dx = -dx;
				dy = dy;
				col = col;
				row = row;
			} else {
				dx = dx;
				dy = dy;
				col = col2;
				row = row;
			}
		} else if(y.b==1) {
			if(G[row2][col] == '#') {
				dx = dx;
				dy = -dy;
				col = col;
				row = row;
			} else {
				dx = dx;
				dy = dy;
				col = col;
				row = row2;
			}
		} else {
			printf("err....\n");
		}
	}
}

void compute() {
	set<T> sets;
	for(DX = -D; DX <= D; DX ++) {
		for(DY = -D; DY <= D; DY ++) {
			if(DX*DX+DY*DY <= D*D && (DX||DY)) {
				if(test()) {
					long long g = gcd(abs(DX),abs(DY));
					sets.insert(T(DX/g, DY/g));
				}
			}
		}
	}
	ans = sets.size();
}

int _tmain(long long argc, _TCHAR* argv[])
{
	freopen("D-small-attempt2.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	long long t;
	cin >> t;
	for(long long idx=1; idx<=t; idx++) {
		cin >> H >> W >> D;
		memset(G, 0, sizeof(G));
		for(long long i = 0; i < H; i ++) {
			cin >> G[i];
			for(long long j = 0; j < W; j ++) {
				if(G[i][j] == 'X') {
					startRow = i;
					startCol = j;
				}
			}
		}
		compute();
		cout << "Case #" << idx << ": " << ans << endl;
		fflush(stdout);
	}
	return 0;
}

