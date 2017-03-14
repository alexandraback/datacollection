#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<string> board;
int t, w, h, d;

long long gcd(long long a, long long b) {
	if(a == 0 && b == 0)
		return 1;
	if(a < 0)
		return gcd(-a, b);
	if(b < 0)
		return gcd(a, -b);
	return b > 0 ? gcd(b, a % b) : a;
}
	

struct ray {
	long long x;
	long long y;
};

struct cmp {
	bool operator ()(const ray &l, const ray &r) const {
		return l.x == r.x ? l.y < r.y : l.x < r.x;
	}
};


set<ray, cmp> rays;



int correct(int a) {
	if(a == 0)
		return 0;
	if(a < 0 && a % 2 != 0)
		return -((-a)/2 + 1);
	return a/2;
}

int main() {
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cin >> h >> w >> d;
		board.resize(h);
		getline(cin, board[0]);
		for(int i = 0; i < h; i++)
			getline(cin, board[i]);

		int h2 = (h - 2) * 2;
		int w2 = (w - 2) * 2;
		int x, y;

		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
				if(board[i][j] == 'X') {
					y = 2 * i - 1;
					x = 2 * j - 1;
				}
		int dd = d * 2;
		int l = y;
		int r = w2 - y;
		int t = x;
		int d = h2 - x;
//		cout << l << " " << r << endl << t << " " << d << endl;

		for(int sx = -200; sx <= 200; sx++)
			for(int sy = -200; sy <= 200; sy++) {
				x = (correct(sx)) * (2 * r + 2 * l) + (sx % 2 != 0 ? 2 * r : 0);
				y = (correct(sy)) * (2 * t + 2 * d) + (sy % 2 != 0 ? 2 * t : 0);
				if((x * x) > (dd * dd))
					continue;
				if((y * y) > (dd * dd))
					continue;
//				cout << x << " " << y << " ( " << sx << " " << sy << " )" << endl;
//				cout << (x * x + y * y) << "  " << dd * dd << endl;
				if((x * x + y * y) <= (dd * dd) && (x != 0 || y != 0)) {
					long long xll = x;
					long long yll = y;


					long long gll = gcd(x, y);
					xll /= gcd(x, y);
					yll /= gcd(x, y);
					ray r;
					r.x = xll;
					r.y = yll;
					rays.insert(r);
				}
			}
		cout << "Case #" << tt << ": " << rays.size() << endl;
		rays.clear();
		
	}	
	return 0;	
}