#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int pos[2000010],last[2000010];

typedef pair<int,int> II;
typedef pair<double,II> DII;

#define INF 1e29
double best[101][101];

int n,m,h,f[101][100],c[100][100];
#define state(t,r,c) make_pair((t),make_pair((r),(c)))
#define valid(r,c) (r>=0&&r<n&&c>=0&&c<m)
#define testpush(t,r,c) { if (best[r][c]>t){q.push(state(t,r,c)); best[r][c]=t;}}
#define hh(time) (max(0.0,(h-(time)*10.0)))

int main(){
	int tt,u,i,j,k,i1,j1;
	int ir[]={-1,0,1,0},ic[]={0,1,0,-1};
	double time;
	cin>>tt;
	for (u=0; u<tt; u++){
		cin>>h>>n>>m;
		for (i=0; i<n; i++) for (j=0; j<m; j++) cin>>c[i][j];
		for (i=0; i<n; i++) for (j=0; j<m; j++) cin>>f[i][j];
		for (i=0; i<n; i++) for (j=0; j<m; j++) best[i][j]=INF;
		priority_queue<DII> q;
		testpush(0.0,0,0);
		//best[0][0]=0;
		//q.push(state(0.0,0,0));
		while(!q.empty()){
			DII s=q.top(); q.pop();
			i=s.second.first;
			j=s.second.second;
			time=s.first;
			if (i==n-1 && j==m-1) break;
			for (k=0; k<4; k++){
				i1=i+ir[k];
				j1=j+ic[k];
				if (valid(i1,j1) && f[i1][j1]<=c[i][j]-50 &&  f[i1][j1]<=c[i1][j1]-50 && f[i][j]<=c[i1][j1]-50){ //valid move
					double time1;
					if (hh(time)<=c[i1][j1]-50) time1=time;
					else time1=time+(hh(time)-(c[i1][j1]-50))/10.0;
					if (time1==0){
						testpush(0.0,i1,j1);
					}
					else{
						double time2;
						time2=time1+(hh(time1)-f[i][j]>=20.0?1.0:10.0);
						testpush(time2,i1,j1);
					}
				}
			}
		}
		printf("Case #%d: %.08lf\n",u+1,time);
	}
	return 0;
}
