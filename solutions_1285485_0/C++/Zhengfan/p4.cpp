#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

void change_direction(int& dx, int& dy) {
	if (dy == 1 && dx == 0) {
		dx = 1; dy = 0;
	} else if (dx == 1 && dy == 0) {
		dx = 0; dy = -1;
	} else if (dx == 0 && dy == -1) {
		dx = -1; dy = 0;
	} else if (dx == -1 && dy == 0) {
		dx = 0; dy = 1;
	}
}

int gcd(int a, int b) {
	if (b>a) swap(a, b);
	while (b != 0) {
		a = a%b;
		swap(a, b);
	}
	return a;
}

struct slope {
	int x;
	int y;
	int quad;
	friend bool operator<(const slope& a, const slope& b);
	friend bool operator==(const slope& a, const slope& b);
};

bool operator<(const slope& a, const slope& b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y) || (a.x == b.x && a.y == b.y && a.quad < b.quad) ;
}

bool operator==(const slope& a, const slope& b) {
	return a.x == b.x && a.y == b.y && a.quad == b.quad;
}

int main(int argc, char* argv[]) {
/*	set<slope> sl;
	slope temp;
	temp.x = 1; temp.y = 2; temp.quad = 1;
	sl.insert(temp);
	temp.x = 3; temp.y = 3; temp.quad = 1;
	sl.insert(temp);
	temp.x = 1; temp.y = 3; temp.quad = 1;
	sl.insert(temp);
							for (set<slope>::iterator si = sl.begin(); si != sl.end(); ++si) {
								cout << si->x << " " << si->y << si->quad << "LLLL" << endl;
							}
	
*/
	ifstream f;
	f.open(argv[1]);
	int T;
	f >> T;
	for (int t=0; t<T; t++) {
		cout << "Case #" << t+1 << ": ";
		int H, W, D;
		f >> H >> W >> D;
		H -= 2;
		W -= 2;
		int count = 0;
		int* m = new int [H*W];
		string s;
		f >> s;
		int x0, y0;
		for (int i=0; i<H; i++) {
			f >> s;
			for (int j=0; j<W; j++) {
				if (s[j+1] == 'X') { m[i*W+j] = 1; x0 = i; y0 = j; }
				else m[i*W+j] = 0;
			}
		}
		f >> s;
		bool found = false;
		int l = 0;
		set<slope> sl;
		do {
			found = false;
			l++;
			//cout << l << endl;
			int x = -l;
			int y = -l;
			int dx = 0;
			int dy = 1;
			int xx, yy;
			do {
				//cout << x << " " << y << " ";
				int ax = abs(x);
				int ay = abs(y);
				//int u, v;
				//if (ax%2 == 0) u = ax/2; else u = (ax+1)/2;
				//if (ay%2 == 0) v = ay/2; else v = (ay+1)/2;
				if (!(ax == 0 && ay > 1 || ay == 0 && ax > 1)) { // || gcd(u, v) > 1)) {
					if (x >= 0) xx = ax/2*2*W+ax%2*(2*y0+1);
					else xx = ax/2*2*W+ax%2*(2*W-2*y0-1);
					if (y >= 0) yy = ay/2*2*H+ay%2*(2*x0+1);
					else yy = ay/2*2*H+ay%2*(2*H-2*x0-1);
					//cout << xx << " " << yy << endl;
					if (xx*xx+yy*yy <= D*D) {
						if (xx == 0 || yy == 0) {
							count++; //cout << "L" << endl;
							found = true;
						} else {
							int k = gcd(xx, yy);
							int u = xx/k;
							int v = yy/k;
							int quad;
							if (x > 0 && y > 0) quad = 1;
							else if (x > 0 && y < 0) quad = 4;
							else if (x < 0 && y > 0) quad = 2;
							else quad = 3;
							slope temp;
							temp.x = u; temp.y = v; temp.quad = quad;
							//cout << u << " " << v << " " << quad << endl;
							//for (set<slope>::iterator si = sl.begin(); si != sl.end(); ++si) {
							//	cout << si->x << " " << si->y << si->quad << "LLLL" << endl;
							//}
							if (sl.find(temp) == sl.end()) {
								count++;
								found = true;
								//cout << "D" << endl;
								sl.insert(temp);
							}
						}
					}
				} //else cout << endl;
				x += dx;
				y += dy;
				if (x+dx > l || x+dx < -l || y+dy > l || y+dy < -l) change_direction(dx, dy);
			} while (x!=-l || y!=-l);
		} while (found);
		cout << count << endl;
		delete[] m;

	}
	f.close();
}
