#include<stdio.h>
#include<queue>

using namespace std;

const int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int h,n,m;
int ceil[200][200],flor[200][200];
double times[200][200];
int starts[20000],nstarts;

inline double passage(int tx, int ty, double time)
{
	if ((double)h-time*10.0>=(double)flor[tx][ty]+20.0) { return 1.0; } else { return 10.0; }
}
double gothere(int tx, int ty, int nx, int ny, double time)
{
	double target,delta=0.0;
	if (nx<0 || nx>=m || ny<0 || ny>=n) { return -1.0; }
	if (ceil[nx][ny]-flor[nx][ny]<50 || ceil[nx][ny]-flor[tx][ty]<50 || ceil[tx][ty]-flor[nx][ny]<50) { return -1.0; }

	target=(double)ceil[nx][ny]-50.0;
	if (target<(double)h-time*10.0) { delta=((double)h-time*10.0-target)/10.0; }
	return delta+passage(tx,ty,time+delta);
}

struct comp
{
	bool operator()(const int i1, const int i2) const
	{
		int tx=i1%m,ty=i1/m;
		int nx=i2%m,ny=i2/m;
		return times[tx][ty]>times[nx][ny];
	}
};

double bfs(int startpos)
{
	priority_queue<int,vector<int>,comp> q;
	int cur,tx,ty,nx,ny;
	int i;
	double delta;

	q.push(startpos);
	times[startpos%m][startpos/m]=0.0;
	while (!q.empty())
	{
		cur=q.top(); q.pop();
		ty=cur/m;
		tx=cur%m;

		if (tx==m-1 && ty==n-1) { return times[tx][ty]; }

		for (i=0;i<4;i++)
		{
			nx=tx+dirs[i][0];
			ny=ty+dirs[i][1];
			delta=gothere(tx,ty,nx,ny,times[tx][ty]);
			//printf("(%d,%d) -> (%d,%d) = %.7f\n",tx,ty,nx,ny,delta);
			if (delta<0.0 || (times[nx][ny]>=0.0 && times[tx][ty]+delta>=times[nx][ny])) { continue; }
			q.push(ny*m+nx);
			times[nx][ny]=times[tx][ty]+delta;
		}
	}
	return 1e20;
}

bool ini_gothere(int tx, int ty, int nx, int ny)
{
	if (nx<0 || nx>=m || ny<0 || ny>=n) { return false; }
	if (ceil[nx][ny]-flor[nx][ny]<50 || ceil[nx][ny]-flor[tx][ty]<50 || ceil[tx][ty]-flor[nx][ny]<50) { return false; }
	if (ceil[nx][ny]-h<50) { return false; }
	return true;
}

void ini_bfs()
{
	queue<int> q;
	int tx,ty,nx,ny;
	int i,cur;

	q.push(0);
	while (!q.empty())
	{
		cur=q.front(); q.pop();
		ty=cur/m;
		tx=cur%m;
		times[tx][ty]=0.0;
		starts[nstarts++]=cur;

		for (i=0;i<4;i++)
		{
			nx=tx+dirs[i][0];
			ny=ty+dirs[i][1];
			if (ini_gothere(tx,ty,nx,ny) && times[nx][ny]<0.0)
			{
				times[nx][ny]=0.0;
				q.push(ny*m+nx);
			}
		}
	}
}

int main()
{
	int t,tt;
	int i,j;
	double curtime,besttime;

	scanf("%d",&t);
	for (tt=1;tt<=t;tt++)
	{
		scanf("%d %d %d",&h,&n,&m);
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++) { scanf("%d",&ceil[j][i]); }
		}
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++) { scanf("%d",&flor[j][i]); }
		}

		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++) { times[j][i]=-1.0; }
		}
		besttime=1e20;

		nstarts=0;
		ini_bfs();

		for (i=0;i<nstarts;i++)
		{
			curtime=bfs(starts[i]);
			//printf("start (%d,%d) has time %.7f\n",starts[i]%m,starts[i]/m,curtime);
			if (curtime<besttime) { besttime=curtime; }
		}
		printf("Case #%d: %.7f\n",tt,besttime);
	}

	return 0;
}

