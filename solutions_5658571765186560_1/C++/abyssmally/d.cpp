#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mp make_pair

int t, x, r, c;
vector<vector<pair<int,int> > > oms;
vector<pair<int,int> > cur;
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
char s[25][25];
void gen() {
	if (cur.size() == x) {
		oms.push_back(vector<pair<int,int> >(cur));
		return;
	}
	for (int i = 0; i < cur.size(); i++) for (int dir = 0; dir < 4; dir++) {
		int ny = cur[i].first + dy[dir], nx = cur[i].second + dx[dir];
		if (ny < 0 || nx < 0) continue;
		char g = 1;
		fo(j,0,cur.size()) if (ny == cur[j].first && nx == cur[j].second) {
			g = 0; break;
		}
		if (!g) continue;
		cur.pb(mp(ny, nx));
		gen();
		cur.pop_back();
	}
}
vector<pair<int,int> > rot(vector<pair<int,int> > a) {
	vector<pair<int,int> > res;
	fo(i,0,a.size()) res.pb(mp(a[i].second, a[i].first));
	return res;
}
int dfs(int y, int x) {
	int res = 1;
	s[y][x] = 1;
	fo(dir,0,4) {
		int ny = y + dy[dir], nx = x + dx[dir];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (!s[ny][nx]) res += dfs(ny, nx);
	}
	return res;
}
bool tr(vector<pair<int,int> > a, int py, int px) {
	fo(i,0,r) fo(j,0,c) s[i][j] = 0;
	fo(i,0,a.size()) s[a[i].first + py][a[i].second + px] = 1;
	fo(i,0,r) fo(j,0,c) if (!s[i][j]) {
		int sz = dfs(i,j);
		//printf("SZ %d\n", sz);
		if (sz%x != 0) return false;
	}
	return true;
}
int main() {
	freopen("d.in", "r", stdin); freopen("d.out", "w", stdout);
	scanf("%d", &t);
	fo(tc,1,t+1) {
		scanf("%d %d %d", &x, &r, &c);
		printf("Case #%d: ", tc);
		if (x >= 7) {
			puts("RICHARD"); continue;
		}
		if (r >= 7 && c >= 7) {
			puts("GABRIEL"); continue;
		}
		oms.clear(); cur.clear();
		cur.pb(mp(0,0));
		gen();
		char done = 0;
		fo(i,0,oms.size()) {
			cur = oms[i];
			char g = 0;

			int h = 0, w = 0;			
			fo(j,0,x) h = max(h, cur[j].first), w = max(w, cur[j].second);
			fo(j,0,r-h) {
				fo(k,0,c-w) {
					if (tr(cur, j, k)) {
						g = 1; break;
					}
				}
				if (g==1) break;
			}
			if (g==1) continue;

			cur = rot(cur);

			h = 0, w = 0;			
			fo(j,0,x) h = max(h, cur[j].first), w = max(w, cur[j].second);
			fo(j,0,r-h) {
				fo(k,0,c-w) {
					if (tr(cur, j, k)) {
						g = 1; break;
					}
				}
				if (g==1) break;
			}
			if (g==1) continue;
			//printf("DIM %d %d %d\n", x, r, c);
			//for (int i = 0; i < cur.size(); i++) printf("%d %d\n", cur[i].first, cur[i].second);

			puts("RICHARD");
			done = 1; break;
		}
		//printf("DIM %d %d %d\n", x, r, c);
		if (!done) puts("GABRIEL");
	}

	return 0;
}