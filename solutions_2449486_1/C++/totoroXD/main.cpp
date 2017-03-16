#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
using namespace std;

int n,m, h[111][111], s[2][111],cnt;
struct grid{
	int x, y, h;
	bool operator <(const grid & that)const{
		return h<that.h;
	}
};
void input()
{
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d",&h[i][j]);
}
void solve()
{
	printf("Case #%d: ",cnt+1);
	memset(s,-1,sizeof(s));
	priority_queue<grid> q;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			q.push((grid){i,j,h[i][j]});
	while(!q.empty()){
		grid g = q.top();
		q.pop();
		//printf("\t%d %d %d\n",g.x,g.y,g.h);
		if(s[0][g.x]==-1)s[0][g.x]=g.h;
		if(s[1][g.y]==-1)s[1][g.y]=g.h;
		if((g.h<s[0][g.x]) && (g.h<s[1][g.y])){
			printf("NO\n");
			return;
		}

	}
	printf("YES\n");
}
int main ()
{
	freopen("B-large.in","r",stdin);
	freopen("xddd.out","w",stdout);
	int zz;
	scanf("%d",&zz);
	for(cnt=0; cnt<zz; cnt++){
		input();
		solve();
	}
}
/*
3 3
2 1 2
1 1 1
2 1 2
5 5
2 2 2 2 2
2 1 1 1 2
2 1 2 1 2
2 1 1 1 2
2 2 2 2 2
3 9
2 1 2 2 2 2 2 1 2
2 2 2 2 2 2 2 1 2
2 2 1 1 2 2 2 2 1
6 8
2 2 2 2 2 2 1 1
2 2 2 2 2 2 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
2 2 2 2 2 2 1 1
1 1 1 1 1 1 1 1
6 8
1 2 1 1 2 2 2 2
2 2 2 2 1 2 1 2
1 2 2 2 2 2 2 2
2 2 1 2 2 2 2 2
2 2 2 2 2 1 2 2
2 2 2 2 1 2 2 2
3 9
2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 1 2 2
*/
