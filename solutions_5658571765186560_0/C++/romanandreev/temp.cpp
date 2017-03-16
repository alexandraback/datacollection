#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(a) ((int)a.size())
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

set<set<pair<int, int> > > ls[7];
int x, n, m;
set<pair<int, int> > norm(set<pair<int, int> > a) {
	int mnx = 0;
	int mny = 0;
	for (auto p : a) {
		mnx = min(mnx, p.x);
		mny = min(mny, p.y);
	}
	set<pair<int, int> > b;
	for (auto p : a) {
		b.insert(mp(p.x - mnx, p.y - mny));
	}
	return b;
}
bool can2(vector<vector<int> > A) {
	int mni = -1;
	int mnj = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (A[i][j] == 0) {
			mni = i;
			mnj = j;			
		}
	}
	if (mni == -1) return true;
	for (auto f : ls[x]) {
		for (auto p : f) {
			bool good = true;
			auto B = A;
			for (auto p1 : f) {
				int px = p1.x - p.x + mni;
				int py = p1.y - p.y + mnj;
				if (px < 0 || py < 0 || px >= n || py >= m || A[px][py] == 1) {
					good = false;
					break;
				}	
				B[px][py] = 1;
			}
			if (good) {
				if (can2(B)) return true;
			}
		}
	}
	return false;
}
bool can(int si, int sj, set<pair<int, int> > a) {
	vector<vector<int> > A(n, vector<int>(m, 0));
	for (auto x : a) {
		A[x.x + si][x.y + sj] = 1;
	}
	return can2(A);
}
bool cant(set<pair<int, int> > a) {
	int mxx = 0;
	int mxy = 0;
	for (auto p : a) {
		mxx = max(mxx, p.x + 1);
		mxy = max(mxy, p.y + 1);
	}
	for (int i = 0; i < n - mxx + 1; i++) {
		for (int j = 0; j < m - mxy + 1; j++) {
			if (can(i, j, a)) {
				return false;
			}
		}
	}
	return true;
}
set<pair<int, int> > rot(set<pair<int, int> > a) {
	set<pair<int, int> > res;
	for (auto x : a) {
		res.insert(mp(x.y, x.x));
	}
	return res;
}
void solve() {
	scanf("%d %d %d", &x, &n, &m);
	//cerr<<x<<" "<<n<<" "<<m<<endl;	
	if (n > m) {
		swap(n, m);
	}
	if (n * m % x != 0) {
		printf("RICHARD\n");
		return;
	}		
	if (x >= 7) {
		printf("RICHARD\n");
		return;
	}
	for (auto a : ls[x]) {
		if (cant(a) && cant(rot(a))) {
		  printf("RICHARD\n");
			return;
		}
	}
	printf("GABRIEL\n");
}
int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	ls[1].insert({mp(0, 0)});
	for (int x = 1; x < 6; x++) {
		for (auto a : ls[x]) {
			for (auto p : a) {
				for (int i = 0; i < 4; i++) {
					auto na = a;
					na.insert(mp(p.x + dx[i], p.y + dy[i]));
					if (sz(na) == x + 1) {
						ls[sz(na)].insert(norm(na)); 
					}
				}                                     
			}
		}
	}
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		printf("Case #%d: ", ti);
		solve();
	}
	return 0;
}