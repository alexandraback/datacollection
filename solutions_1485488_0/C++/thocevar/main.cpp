#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
#include <string.h>
#include <queue>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#define all(c) (c).begin(),(c).end()
#define present(c,x) (find(c.begin(),c.end(),x) != (c).end())
#define pb push_back
#define traverse(v,it) for (typeof(v.begin()) it=v.begin();it!=v.end();it++)
using namespace std;
template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }
typedef long long int64;
typedef pair<int,int> PII;

typedef struct {
	int y; int x; int t;
} state;

bool operator<(state s1, state s2) { return s1.t>s2.t; }

int tests;
int h,n,m;
int c[100][100],f[100][100];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int dist0[100][100], dist1[100][100];

int move(int y, int x, int d, int t) {
	int y2=y+dir[d][0], x2=x+dir[d][1];
	if (y2<0 || x2<0 || y2>=n || x2>=m) return -1;
	int top=min(c[y][x],c[y2][x2]);
	int bottom=max(f[y][x],f[y2][x2]);
	if (top-bottom<50) return -1;
	int w=h-t;
	return max(w-(top-50),0);
}

int main() {
	//freopen("B.in","r",stdin);
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
    scanf("%d",&tests);
    for (int test=1;test<=tests;test++) {
    	scanf("%d %d %d",&h,&n,&m);
    	for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&c[i][j]);
    	for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&f[i][j]);
		priority_queue<state> pq;

		memset(dist0,-1,sizeof(dist0));
		pq.push((state){0,0,0});
		dist0[0][0]=0;
		while (!pq.empty()) {
			state s=pq.top(); pq.pop();
			if (dist0[s.y][s.x]!=s.t) continue;
			for (int d=0;d<4;d++) {
				int w=move(s.y,s.x,d,s.t);
				if (w==-1) continue;
				if (w!=0) continue;
				state s2=(state){s.y+dir[d][0],s.x+dir[d][1],s.t};
				if (dist0[s2.y][s2.x]==-1 || s2.t<dist0[s2.y][s2.x]) {
					dist0[s2.y][s2.x]=s2.t;
					pq.push(s2);
				}
			}
		}

		memset(dist1,-1,sizeof(dist1));
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (dist0[i][j]!=-1) {
			pq.push((state){i,j,0});
			dist1[i][j]=0;
		}
		int prev=0;
		while (!pq.empty()) {
			state s=pq.top(); pq.pop();
			prev=s.t;
			if (dist1[s.y][s.x]!=s.t) continue;
			for (int d=0;d<4;d++) {
				int w=move(s.y,s.x,d,s.t);
				if (w==-1) continue;
				state s2=(state){s.y+dir[d][0],s.x+dir[d][1],s.t+w};
				if (h-s2.t>=f[s.y][s.x]+20) s2.t+=10; else s2.t+=100;
				if (dist1[s2.y][s2.x]==-1 || s2.t<dist1[s2.y][s2.x]) {
					dist1[s2.y][s2.x]=s2.t;
					pq.push(s2);
				}
			}
		}

    	printf("Case #%d: %.1lf\n",test,dist1[n-1][m-1]/10.0);
	}
    return 0;
}
