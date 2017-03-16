// In The Name of God
#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>
#define cin fin
#define cout fout
using namespace std;

ifstream fin("B-large.in");
ofstream fout("B-large.out");

struct tri{
	int h, I, J;
};
bool operator<(tri a, tri b) {
	if(a.h != b.h) return a.h < b.h;
	if(a.I != b.I) return a.I < b.I;
	return a.J < b.J;
}

const int MAXN = 105;
int t, n, m, arr[MAXN][MAXN];
bool mark_row[MAXN], mark_colomn[MAXN], ans;
set<tri>s;

void print(int c, bool f) {
	cout << "Case #" << c << ": ";
	if(ans) cout << "YES" << endl;
	if(!ans) cout << "NO" << endl;	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		s.clear();
		fill(mark_row, mark_row + MAXN, false);
		fill(mark_colomn, mark_colomn + MAXN, false);
		cin >> n >> m;
		for(int j = 0; j < n; ++j)
			for(int k = 0; k < m; ++k) {
				cin >> arr[j][k];
				tri tmp;
				tmp.h = arr[j][k];
				tmp.I = j;
				tmp.J = k;
				s.insert(tmp);
			}
		int mn = (*s.begin()).h;
		int mx = (*(--s.end())).h;
		ans = true;
		while(mn < mx) {
			int x = (*s.begin()).I;
			int y = (*s.begin()).J;
			bool satr = true;
			for(int j = 0; j < m; ++j)
				if(!mark_colomn[j] && arr[x][j] > arr[x][y]) satr = false;
			bool sotun = true;
			for(int j = 0; j < n; ++j)
				if(!mark_row[j] && arr[j][y] > arr[x][y]) sotun = false;
			if(!satr && !sotun) {
				ans = false;
				break;
			}
			if(satr) {
				mark_row[x] = true;
				for(int j = 0; j < m; ++j)
					if(!mark_colomn[j]) {
						tri tmp;
						tmp.h = arr[x][j];
						tmp.I = x;
						tmp.J = j;
						s.erase(tmp);
					}
				mn = (*s.begin()).h;
				mx = (*(--s.end())).h;
				continue;
			}
			mark_colomn[y] = true;
			for(int j = 0; j < n; ++j)
				if(!mark_row[j]) {
					tri tmp;
					tmp.h = arr[j][y];
					tmp.I = j;
					tmp.J = y;
					s.erase(tmp);
				}
			mn = (*s.begin()).h;
			mx = (*(--s.end())).h;
		}
		print(i, ans);
	}
	return 0;
}
