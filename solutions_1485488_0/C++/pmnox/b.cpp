#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>

#define ld long double
using namespace std;

int debug=0;
#define db(x) {if(debug){cerr<<__LINE__<<#x<<" "<<x<<endl; }}

int h, n, m;
int hi[111][111];
int lo[111][111];
int result[111][111];

struct pos {
	int hei, r, c;
	pos(int hei_, int r_, int c_){hei=hei_,r=r_,c=c_;}
	bool operator < (const pos &rhs) const {
		if (hei!=rhs.hei)
			return hei>rhs.hei;
		if (r!=rhs.r)
			return r<rhs.r;
		if (c!=rhs.c)
			return c<rhs.c;
	}
};

void doit() {
	memset(hi,0x2f,sizeof(hi));
	memset(lo,0x2f,sizeof(hi));
	memset(result,0x90,sizeof(hi));
	scanf("%d%d%d",&h,&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d", &hi[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d", &lo[i][j]);
	set<pos> kol;
	kol.insert(pos(h,1,1));result[1][1] = h;
	int dr[4] = {-1,0,1,0};
	int dc[4] = {0,-1,0,1};
	int xx = 0;
	while (!kol.empty()) {
//		if (debug && ++xx >= 20) break;
		pos cur = *kol.begin();
		kol.erase(kol.begin());
	//	if (result[cur.r][cur.c]>cur.hei) continue;
		
		int r = cur.r;
		int c = cur.c;
		for (int dd=0;dd<4;dd++) {
			int nr = r + dr[dd];
			int nc = c + dc[dd];
			if (!(hi[nr][nc] - lo[nr][nc] >= 50)) continue;
			if (!(hi[r][c] - lo[r][c] >= 50)) continue;

			if (!(hi[nr][nc] >= lo[r][c] + 50)) continue;
			if (!(hi[r][c] >= lo[nr][nc] + 50)) continue;
			int minwat = min(cur.hei, min(hi[r][c] - 50, hi[nr][nc] - 50));

			int nwat = (h == cur.hei && minwat >= h ? h :
				(minwat - (minwat >= lo[r][c] + 20? 10 : 100)));
			if (result[nr][nc] < nwat) {
				result[nr][nc] = nwat;
				kol.insert(pos(nwat,nr,nc));
			}
		}
	}
	int wynik = h - result[n][m];
	printf(" %Lf", wynik / (ld)10);
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Case #%d:", i+1);
		doit();
		printf("\n");
//		if (debug) break;
	}
	return 0;
}
