#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct cell {
	int i,j;
	int h;
	bool vertically;
	bool horizontally;
	cell():i(0),j(0),h(0),vertically(false),horizontally(false) {}
	cell(int i, int j, int h) : i(i),j(j),h(h),vertically(false),horizontally(false) {}	
	bool operator<(const cell& o) const{
		if (h == o.h) 
			if (i == o.i) return j < o.j;
			else return i < o.i;		
		else return h < o.h;
	}
	bool operator==(const cell& o) const {
		return i == o.i and j == o.j and h == o.h;
	}
	bool operator>(const cell& o) const {
		return o < *this;
	}
};

bool solve() {
	int n,m;
	cin >> n >> m;
	cell *cells = new cell[n*m];	
	int max_i_h[100] = {0};
	int max_j_h[100] = {0};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int h;
			cin >> h;
			if (h > max_i_h[i]) max_i_h[i] = h;
			if (h > max_j_h[j]) max_j_h[j] = h;
			cells[i*m + j] = cell(i,j,h);
		}
	}	
	for (int i = 0; i < n; ++i) {
		for (int j =0 ; j < m; ++j) {
			if (cells[i*m+j].h == max_i_h[i])
				cells[i*m+j].horizontally = true;
			if (cells[i*m+j].h == max_j_h[j]) 
				cells[i*m+j].vertically = true;			
		}
	}
//	cerr << endl << "HORIZONTALLY" << endl;
	for (int i =0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cell *c = cells + i*m+j;
		//	cerr << c->horizontally << ' ';
			if (!(c->horizontally || c->vertically)) return false;
		}
		//cerr << endl;
	}
//	cerr << "VERTICALLY" << endl;
//	for (int i =0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			cell *c = cells + i*m+j;
//			cerr << c->vertically << ' ';
		//	if (!(c->horizontally || c->vertically)) return false;
//		}
//		cerr << endl;
//	}
	return true;	
	delete[] cells;
}

int main() {
	int T;
	cin >> T;
	for (int kase = 1; kase <= T; ++kase) {
		cout << "Case #" << kase << ": ";
		if (solve()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
