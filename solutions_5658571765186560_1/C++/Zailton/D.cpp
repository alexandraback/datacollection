#include<bits/stdc++.h>
 
using namespace std;
 
// Typedefs
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
 
// Macros
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, a) FOR(i, 0, a)
#define sz(e) (int)e.size()
#define all(e) e.begin(), e.end()
#define pb(e) push_back(e)

const int MAXN = 1000006;

#define omino vector<ii>

omino now;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int G[8][8];

void dfs (int x, int y, int R, int C) {
	G[x][y] = 1;
	FORR (i, 4) {
		int a = x+dx[i], b = y+dy[i];
		if (a<0 || a>=R || b<0 || b>=C) continue;
		if (G[a][b]) continue;
		dfs (a, b, R, C);
	}
} 

int R, C;

bool backtracking (int X) {
	//cout << X << endl;
	if (X==0) {
		omino novo = now;
		int x0 = now[0].first, x1 = now[0].first, y0 = now[0].second, y1 = now[0].second;
		FOR (i, 1, sz(now)) {
			x0 = min (x0, now[i].first), x1 = max (x1, now[i].first);
			y0 = min (y0, now[i].second), y1 = max (y1, now[i].second);
		}
		x1 -= x0, y1 -= y0;
		FORR (i,  sz(novo)) novo[i].first -= x0, novo[i].second -= y0;
		//cout << sz(novo) << endl;
		//cout << x1 << " " << y1 << endl;
		//FORR (i, sz(novo)) cout << novo[i].first << " " << novo[i].second << " | " ; cout << endl;
		FORR (i, R-x1) {
			FORR (j, C-y1) {
				if (x1>=R || y1 >= C) continue;
				memset (G, 0, sizeof G);
				FORR (w, sz(novo)) G[novo[w].first+i][novo[w].second+j] = 1;
				int cnt = 0;
				FORR (fi, R) FORR (fj, C) if (G[fi][fj]==0) dfs(fi, fj, R, C), cnt++;
				//cout << cnt << endl;
				if (cnt<=1) return true;
			}
		}
		FORR (i, C-x1) {
			FORR (j, R-y1) {
				if (x1>=C || y1 >= R) continue;
				memset (G, 0, sizeof G);
				FORR (w, sz(novo)) G[novo[w].first+i][novo[w].second+j] = 1;
				int cnt = 0;
				FORR (fi, C) FORR (fj, R) if (G[fi][fj]==0) dfs(fi, fj, C, R), cnt++;
				if (cnt<=1) return true;
			}
		}
		return false;
	} else {
		FORR (i, sz(now)) {
			FORR (j, 4) {
				int a = now[i].first+dx[j], b = now[i].second+dy[j];
				bool found = false;
				FORR (k, sz(now)) if (now[k].first==a && now[k].second==b) found = true;
				if (found) continue;
				now.push_back (ii(a, b));
				//cout << X << " " << sz(now) * 4 << endl;
				if (!backtracking (X-1)) return false;
				now.erase (now.begin()+sz(now)-1);
			}
		}
		return true;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int testes;
	cin>>testes;
	FORR (caso, testes) {
		int X;
		cin>>X>>R>>C;
		bool res = false;
		if (X<=6) {
			if ((R*C) % X == 0) {
				now.clear();
				now.pb (ii(0,0));
				R = min (8, R);
				C = min (8, C);
				res = backtracking (X-1);
			}
		}
		cout << "Case #" << caso + 1 << ": " << (res?"GABRIEL":"RICHARD") << endl;
	}
	
}
