#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

struct cmp{
	bool operator()(pair<double,pair<int,int> >a,pair<double,pair<int,int> >b){
		return a.first>=b.first;
	}
};

int lower[110][110],upper[110][110],T,h,n,m;
priority_queue<pair<double,pair<int,int> >,vector<pair<double,pair<int,int> > >,cmp> q;
double ans[110][110];
int de[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
	scanf("%d",&T);
	for (int cases=0;cases<T;++cases){
		scanf("%d%d%d",&h,&n,&m);
		for (int i=0;i<n;++i)
			for (int j=0;j<m;++j)
				scanf("%d",&upper[i][j]);
		for (int i=0;i<n;++i)
			for (int j=0;j<m;++j)
				scanf("%d",&lower[i][j]);
		for (int i=0;i<n;++i)
			for (int j=0;j<m;++j)
				ans[i][j]=-1;
		q.push(make_pair(0,make_pair(0,0)));
		while (!q.empty()){
			pair<double,pair<int,int> > cur=q.top();
			double ct=cur.first;
			int cx=cur.second.first;
			int cy=cur.second.second;
			q.pop();
			if (ans[cx][cy]<0){
				ans[cx][cy]=ct;
				for (int i=0;i<4;++i){
					int nx=cx+de[i][0];
					int ny=cy+de[i][1];
					double nt=ct;
					if ((nx<0)||(nx>=n)) continue;
					if ((ny<0)||(ny>=m)) continue;
					double waterlevel=h-ct*10;
					if (lower[nx][ny]+50>upper[nx][ny]) continue;
					if (lower[cx][cy]+50>upper[nx][ny]) continue;
					if (lower[nx][ny]+50>upper[cx][cy]) continue;
					if (waterlevel+50>upper[nx][ny]){
						nt+=(waterlevel+50-upper[nx][ny])/10;
						waterlevel=upper[nx][ny]-50;
					}
					if (fabs(nt)>1e-8){
						if (waterlevel-lower[cx][cy]>=20) nt+=1;
						else nt+=10;
					}
					if ((ans[nx][ny]<0)||(nt<ans[nx][ny])) q.push(make_pair(nt,make_pair(nx,ny)));
				}
			}
		}
		printf("Case #%d: %.7lf\n",cases+1,ans[n-1][m-1]);
	}
	return 0;
}
