#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 10005
#define MP(a,b) make_pair((a),(b))
#define HS pair<PII, int>
class piece{
public:
	int n, r, c;
	bool g[10][10];
	piece(){}
	piece(int _n, int _r, int _c, bool _g[10][10]){
		n = _n; r = _r; c = _c;
		memcpy(g, _g, sizeof(g));
	}
	piece(bool _g[10][10]){
		memcpy(g, _g, sizeof(g));
		n = r = c = 0;
		REP(i, 0, 10) REP(j, 0, 10) if (g[i][j]) {
			r = max(i, r);
			c = max(j, c);
			n++;
		}
		r++; c++;
	}
	void flip(){
		bool ng[10][10] = {};
		REP(i, 0, r) REP(j, 0, c) if (g[i][j]) ng[r - 1 - i][j] = 1;
		memcpy(g, ng, sizeof(g));
	}
	void rot(){
		bool ng[10][10] = {};
		REP(i, 0, r) REP(j, 0, c) if (g[i][j]) ng[j][r - 1 - i] = 1;
		swap(r, c);
		memcpy(g, ng, sizeof(g));
	}
	void print(){
		REP(i, 0, r){
			REP(j, 0, c){
				cerr << (g[i][j] ? "#" : ".");
			}
			cerr << endl;
		}
	}
	HS hash(){
		HS h;
		h.first = PII(r, c);
		h.second = 0;
		REP(i, 0, r) REP(j, 0, c) if (g[i][j]) h.second += 1 << (i*c + j);
		return h;
	}
};
vector<piece> pcs[7];
set<HS> hss[7];

int dir[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };
bool ee[10][10], tt[10][10], gg[10][10];
void normalize(bool g[10][10]){
	int r1 = 100, c1 = 100;
	REP(i, 0, 10) REP(j, 0, 10){
		if (g[i][j]) {
			r1 = min(i, r1);
			c1 = min(j, c1);
		}
	}
	bool ng[10][10] = {};
	REP(i, 0, 10) REP(j, 0, 10){
		if (g[i][j]) ng[i - r1][j - c1] = 1;
	}
	memcpy(g, ng, sizeof(ng));
}

bool v[25][25], pg[25][25];
int dfs(int x, int y, int R, int C){
	int ret = 1;
	v[x][y] = 1;
	REP(t, 0, 4){
		int nx = x + dir[t][0], ny = y + dir[t][1];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C || pg[nx][ny] || v[nx][ny]) continue;
		ret += dfs(nx, ny, R, C);
	}
	return ret;
}
bool solve(int n, int R, int C){
	if (n >= 7) return 1;
	REP(k, 0, (int)pcs[n].size()){
		piece &p = pcs[n][k];

		bool free = 0;
		REP(t, 0, 2){
			swap(R, C);
			if (p.r > R || p.c > C) continue;
			
			REP(ii, 0, R - p.r + 1) {
				REP(jj, 0, C - p.c + 1){ // find place
					FILL(pg, 0);
					REP(i, 0, p.r) REP(j, 0, p.c) pg[ii + i][jj + j] = p.g[i][j];	// place

					FILL(v, 0);	// check components
					bool bad = 0;
					REP(i, 0, R) {
						REP(j, 0, C){
							if (!pg[i][j] && !v[i][j]){
								int cnt = dfs(i, j, R, C);
								if (cnt % n) {
									bad = 1;
									break;
								}
							}
						}
						if (bad) break;
					}
					if (!bad) {
						free = 1;
						break;
					}
				}
				if (free) break;
			}
			if (free) break;
		}
		if (!free) return 1;
	}
	return 0;
}

void process() {
	// precompute
	FILL(gg, 0);
	gg[0][0] = 1;
	pcs[1].push_back(piece(gg));
	hss[1].insert(pcs[1][0].hash());

	REP(n, 2, 7){
		int sz = pcs[n - 1].size();
		REP(k, 0, sz){
			piece &p = pcs[n - 1][k];
			FILL(tt, 0);
			REP(i, 0, p.r) REP(j, 0, p.c)
				if (p.g[i][j])
					tt[i + 1][j + 1] = 1;
			REP(i, 0, 10) REP(j, 0, 10){
				if (tt[i][j]) continue;
				bool ok = 0;
				REP(t, 0, 4){
					int ni = i + dir[t][0], nj = j + dir[t][1];
					if (ni < 0 || nj < 0 || ni >= 10 || nj >= 10) continue;
					if (tt[ni][nj]) {
						ok = 1;
						break;
					}
				}
				if (ok) {
					memcpy(ee, tt, sizeof(ee));
					ee[i][j] = 1;
					normalize(ee);
					piece p(ee);
					//p.print();

					bool exist = 0;
					REP(f, 0, 2){
						p.flip();
						REP(r, 0, 4){
							p.rot();
							HS h = p.hash();
							if (hss[p.n].find(h) != hss[p.n].end()) {
								exist = 1;
								break;
							}
						}
						if (exist) break;
					}
					if (!exist){
						hss[p.n].insert(p.hash());
						pcs[p.n].push_back(p);
					}
				}
			}
		}
	}
	REP(n, 1, 21){
		REP(r, 1, 21){
			REP(c, 1, 21){
				int ok = solve(n, r, c);
				printf("%d %d %d %d\n", n, r, c, ok);
			}
		}
	}
}


int anstable[21][21][21];
int main(){
	//process();
	//return 0;

	int cs;
	cin >> cs;

	ifstream ans("Dans", ios::in);
	int x, r, c, a;
	while (ans >> x >> r >> c >> a)
		anstable[x][r][c] = a;

	REP(csn, 1, cs + 1){
		printf("Case #%d: ", csn);
		cin >> x >> r >> c;
		puts(!anstable[x][r][c] ? "GABRIEL" : "RICHARD");
	}
	return 0;
}