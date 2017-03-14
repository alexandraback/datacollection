//Solution for D small only.
#include <iostream>
#include <string>
#include <map>
#include <utility>
using namespace std;

int H, W, D;
int a, b;

#define SIZE 50

int x[2*SIZE + 5];
int y[2*SIZE + 5];

int up, down, lft, rght;

int delta_swap(int *delta, int d1, int d2) {
	int orig = *delta;
	if (orig == d1) *delta = d2;
	else *delta = d1;
	return orig;
}

int abs(int n) {
	if (n >= 0) return n;
	return -n;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> H >> W >> D;
		for (int i = 0; i < H; i++) {
			string line;
			cin >> line;
			for (int j = 0; j < W; j++) if (line[j] == 'X') { a = i; b = j; }
		}
		
		map< pair<int,int>, bool > hit;
		
		x[SIZE + 2] = y[SIZE + 2] = 0; // real image is at center coordinates 
		
		up = 2*a - 1;
		down = 2*(H-1-a) - 1;
		lft = 2*b - 1;
		rght = 2*(W-1-b) - 1;
		
		int delta;
		// initialize middle rows and columns
		delta = rght;
		for (int xx = SIZE + 3; xx < 2*SIZE + 5; xx++)
			x[xx] = x[xx-1] + delta_swap(&delta, lft, rght);
		
		delta = lft;
		for (int xx = SIZE + 1; xx >= 0; xx--)
			x[xx] = x[xx+1] - delta_swap(&delta, lft, rght);
			
		delta = up;
		for (int yy = SIZE + 3; yy < 2*SIZE + 5; yy++)
			y[yy] = y[yy-1] + delta_swap(&delta, up, down);
		
		delta = down;
		for (int yy = SIZE + 1; yy >= 0; yy--)
			y[yy] = y[yy+1] - delta_swap(&delta, up, down);
			
		int res = 0;
		for (int xx = 0; xx < 2*SIZE + 5; xx++)
			for (int yy = 0; yy < 2*SIZE + 5; yy++) {
				if (x[xx] == 0 && y[yy] == 0)
					continue; // exclude origin itself
				int dst = x[xx]*x[xx] + y[yy]*y[yy];
				if (dst <= D*D) {
					int gd = gcd(abs(x[xx]), abs(y[yy]));
					int X = x[xx] / gd, Y = y[yy] / gd;
					pair<int,int> direction = make_pair(X,Y);
					if (!hit[direction]) {
						res++;
						hit[direction] = true;
					}
				}
			}
		
		cout << "Case #" << icase << ": " << res << endl;
	}
	return 0;
}
