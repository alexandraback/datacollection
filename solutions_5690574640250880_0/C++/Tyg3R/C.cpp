#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)

#define DRI(a) int a; scanf("%d ", &a);
#define DRII(a, b) int a, b; scanf("%d %d ", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d ", &a, &b, &c);
#define DRIIII(a, b, c, d) int a, b, c, d; scanf("%d %d %d %d ", &a, &b, &c, &d);
#define RI(a) scanf("%d ", &a);
#define RII(a, b) scanf("%d %d ", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d ", &a, &b, &c);
#define RIIII(a, b, c, d) scanf("%d %d %d %d ", &a, &b, &c, &d);

#define PB push_back
#define MP make_pair

#define ll long long
#define ull unsigned long long

#define MM(co, cim) memset((co), (cim), sizeof((co)))

#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

bool res[7][7][30];
int resState[7][7][30];
pair<int,int> resStart[7][7][30];
bool mp[7][7];
bool ex[7][7];
bool visited[7][7];
int dr[8] = {-1,-1,-1,0,0,1,1,1};
int dc[8] = {-1,0,1,-1,1,-1,0,1};
pair<int,int> st;

int fillMe(int R, int C, int state, int r, int c) {
	MM(visited,false);
	queue<pair<int,int> > q;
	q.push(MP(r,c));
	int filled = 0;
	while(!q.empty()) {
		pair<int,int> pos = q.front();
		q.pop();
		r = pos.first;
		c = pos.second;
		if(visited[r][c] || mp[r][c]) continue; // mp shouldnt happen
		visited[r][c] = true;
		filled++;
		if(!ex[r][c]) continue;
		FOR(i,0,8) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nc >= 0 && nc < C && nr >= 0 && nr < R) q.push(MP(nr,nc));
		}
	}
	return filled;
}

bool fill(int R, int C, int state) {
	// find start
	int msk = 1;
	int needFill = 0;
	FOR(r,0,R) {
		FOR(c,0,C) {
			if(state & msk) mp[r][c] = true;
			else {
				mp[r][c] = false;
				needFill++;
			}
			msk <<= 1;
		}
	}
	bool found = false;
	pair<int,int> start;
	FOR(r,0,R) {
		FOR(c,0,C) {
			ex[r][c] = false;
			if(mp[r][c]) continue;
			if(r > 0 && c > 0 && mp[r-1][c-1]) continue;
			if(r < R-1 && c < C-1 && mp[r+1][c+1]) continue;
			if(r > 0 && c < C-1 && mp[r-1][c+1]) continue;
			if(r < R-1 && c > 0 && mp[r+1][c-1]) continue;
			if(c > 0 && mp[r][c-1]) continue;
			if(r > 0 && mp[r-1][c]) continue;
			if(c < C-1 && mp[r][c+1]) continue;
			if(r < R-1 && mp[r+1][c]) continue;
			ex[r][c] = true;
			found = true;
			start = MP(r,c);
		}
	}
	st = start;
	if(!found) return false;
	int filled = fillMe(R,C,state,start.first,start.second);
	if(filled != needFill) return false;
	return true;
}

void print(int R, int C, int M) {
	int state = resState[R][C][M];
	pair<int,int> start = resStart[R][C][M];
	int msk = 1;
	FOR(r,0,R) {
		FOR(c,0,C) {
			if(r == start.first && c == start.second) cout << 'c';
			else if(msk & state) cout << '*';
			else cout << '.';
			msk <<= 1;
		}
		cout << endl;
	}
}

int main ()
{
	MM(res,false);
  FOR(R,1,6) {
//  	cout << "some" << endl;
  	FOR(C,1,6) {
//  	cout << "some2" << endl;
  		int Cells = R*C;
  		//int limit = 1 << Cells
  		FORDE(state,(1<<Cells)-2,0) {
//  	cout << "some3" << endl;
  			int msk = 1;
  			int bombs = 0;
  			FOR(i,0,Cells) {
//  	cout << "some4" << endl;
	 				if(state & msk) bombs++;
  				msk <<= 1;
  			}
  			
  			if(bombs == Cells-1) {
  				res[R][C][bombs] = true;
					resState[R][C][bombs] = state;
					msk = 1;
					FOR(i,0,Cells) {
		 				if(!(state & msk)) resStart[R][C][bombs] = MP(i/C,i%C);
						msk <<= 1;
					}
  				continue;
  			}
  			
  			if(res[R][C][bombs] == false) {
  				bool r = fill(R,C,state);
  				if(r) {
  					res[R][C][bombs] = true;
  					resState[R][C][bombs] = state;
  					resStart[R][C][bombs] = st;
  				}
				}
  		}
  	}
  }
//  cout << "done" << endl;
/*	
  FOR(R,1,6) {
  	FOR(C,1,6) {
  		FOR(M,0,R*C) {
				cout << R << "," << C << "," << M << endl;
				if(res[R][C][M]) {
					print(R,C,M);
				} else {
					printf("Impossible\n");
				}
			}
  	}
	}
	*/
	DRI(T);
	FOR(t,1,T+1) {
		DRIII(R,C,M);
		printf("Case #%d:\n", t);
		if(res[R][C][M]) {
			print(R,C,M);
		} else {
			printf("Impossible\n");
		}
	}
  return 0;
}












