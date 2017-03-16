#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 110
#define EPS 1e-7

typedef pair<int,int> pii;


double v[MAX][MAX];
int c[MAX][MAX];
int f[MAX][MAX];

int di[] = {0,1,0,-1};
int dj[] = {1,0,-1,0};

int n,m;

queue<pii> q;

void vadj(int i, int j, double h, int mod)
{
	for(int k=0; k<4; ++k)
	{
		int ni=i+di[k];
		int nj=j+dj[k];
		if(ni>=n || ni<0 || nj>=m || nj<0)
			continue;
		if(c[ni][nj]<f[i][j]+50 || c[i][j]<f[ni][nj]+50 || c[ni][nj] < f[ni][nj]+50)
			continue;
		double twait = (h-c[ni][nj]+50)/10;
		if(twait<0)
			twait = 0;
		if(mod && twait > 0)
			continue;
		double w;
		if(h-twait*10 +EPS >= f[i][j]+20)
			w = 1;
		else
			w = 10;
		w+=twait;
		if(v[ni][nj] == -1 || v[i][j]+w < v[ni][nj])
			v[ni][nj] = v[i][j]+w;
	}
}

void dijkstra(int mod, double h)
{
	int mark[MAX][MAX];
	int i,j;

	for(i=0; i<n; ++i)
		for(j=0; j<m; ++j)
			mark[i][j] = 0;

	while(!mark[n-1][m-1])
	{
		double mval=31000000;
		int mi,mj;
		for(i=0; i<n; ++i)
			for(j=0; j<m; ++j)
				if(!mark[i][j] && v[i][j] > -EPS && v[i][j] < mval)
				{
					mval = v[i][j];
					mi = i;
					mj = j;
				}
		if(mval > 30000000)
			break;
		i=mi; j = mj;
		mark[i][j] = 1;
		double nh = h;
		if(!mod)
			nh -= 10*v[i][j];

		vadj(i,j,nh,mod);
	}
}


int main()
{
	int t;
	scanf("%d",&t);
	for(int tcnt=1; tcnt<=t; ++tcnt)
	{
		double h;
		scanf("%lf %d %d",&h,&n,&m);

		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				scanf("%d",&c[i][j]);
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				scanf("%d",&f[i][j]);

		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				v[i][j]= -1;
		v[0][0] = 0;

		dijkstra(1,h);
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				if(v[i][j] > -EPS)
					v[i][j] = 0;
		dijkstra(0,h);

		printf("Case #%d: %.7f\n",tcnt,v[n-1][m-1]);
	}
	return 0;
}

