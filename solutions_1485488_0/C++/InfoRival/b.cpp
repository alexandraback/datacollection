#include <cstdio>
#include <cstring>
#include <set>
//#include <iostream>
using namespace std;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const double inf=1e20;
const double eps=1e-3;
const int c=128;
struct pii {
	int x,y;
	pii (int xx=0, int yy=0) {
		x=xx;
		y=yy;
	}
};
double d[c][c];
struct cmp {
	bool operator () (const pii &a, const pii &b) const {
		if (d[a.x][a.y]!=d[b.x][b.y]) return d[a.x][a.y]<d[b.x][b.y];
		if (a.x!=b.x) return a.x<b.x;
		return a.y<b.y;				
	}
};
int t,ii;
int n,m;
int h,fh[c][c],ch[c][c];
bool b[c][c];
set<pii,cmp> st;
pii k;
bool ok(int x, int y) {
	return x>=1 && x<=n && y>=1 && y<=m;
}
inline bool ls(double a, double b) {
	return b-a>eps;
}
double get(double t, int x, int y, int xx, int yy) {
	double hh=h-t*10;
	double dt;
	if (ch[xx][yy]>fh[xx][yy]-50 || ch[x][y]>fh[xx][yy]-50) return inf;
	if (ch[xx][yy]>fh[x][y]-50) return inf;
	if (hh>fh[xx][yy]-50) dt=(hh-(fh[xx][yy]-50))/10; else dt=0;
	hh=h-(t+dt)*10;
	if (t+dt>0) {
		if (ls(hh-ch[x][y],20)) dt+=10; else dt+=1;
	}
	return t+dt;
}
int main() {
	scanf("%d",&t);
	int i,j;
	for (ii=1; ii<=t; ++ii) {
		scanf("%d%d%d",&h,&n,&m);
		for (i=1; i<=n; ++i)
			for (j=1; j<=m; ++j)
				scanf("%d",&fh[i][j]);
		for (i=1; i<=n; ++i)
			for (j=1; j<=m; ++j)
				scanf("%d",&ch[i][j]);
		for (i=1; i<=n; ++i)
			for (j=1; j<=m; ++j)
				d[i][j]=inf;
		d[1][1]=0;
		for (i=1; i<=n; ++i)
			for (j=1; j<=m; ++j)
				st.insert(pii(i,j));
		memset(b,0,sizeof(b));
		double nd;
		while (st.size()) {
			k=*(st.begin());
			st.erase(st.begin());
			b[k.x][k.y]=1;
			for (i=0; i<4; ++i)
				if (ok(k.x+dx[i],k.y+dy[i]) && !b[k.x+dx[i]][k.y+dy[i]]) {
					nd=get(d[k.x][k.y],k.x,k.y,k.x+dx[i],k.y+dy[i]);
					if (nd<d[k.x+dx[i]][k.y+dy[i]]) {
						st.erase(st.find(pii(k.x+dx[i],k.y+dy[i])));
						d[k.x+dx[i]][k.y+dy[i]]=nd;
						st.insert(pii(k.x+dx[i],k.y+dy[i]));
					}
				}						
		}
/*
		for (i=1; i<=n; ++i) {
			for (j=1; j<=m; ++j) cerr << d[i][j] << ' ';
			cerr << '\n';
		}
*/
		printf("Case #%d: %.7lf\n",ii,d[n][m]);
	}
	return 0;
}
