#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct state
{
	int t;
	int x,y;
};
bool operator <(const state &a,const state &b)
{
	if (a.t!=b.t)
		return a.t>b.t;
	else if (a.x!=b.x)
		return a.x<b.x;
	else
		return a.y<b.y;
}
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int l[100][100],r[100][100],m,n,h;
state hh[100000],rr,rrr;
int nh;
int d[100][100];
int f[100][100];
int move_time(int x1,int y1,int x2,int y2)
{
	if (x2<0||x2>=m||y2<0||y2>=n)
		return -1;
	if (r[x1][y1]-l[x2][y2]<50)
		return -1;
	if (r[x2][y2]-l[x1][y1]<50)
		return -1;
	if (r[x2][y2]-l[x2][y2]<50)
		return -1;
	if (r[x2][y2]-h>=50)
		return 0;
	return h-(r[x2][y2]-50);
}
bool can_move(int x1,int y1,int x2,int y2)
{
	return move_time(x1,y1,x2,y2)==0;
}
void bfs()
{
	int p,q,i;
	memset(d,0,sizeof(d));
	hh[0].t=0;
	hh[0].x=hh[0].y=0;
	p=0;
	q=1;
	d[0][0]=1;
	f[0][0]=0;
	while (p<q)
	{
		for (i=0;i<4;i++)
		{
			hh[q].x=hh[p].x+dx[i];
			hh[q].y=hh[p].y+dy[i];
			hh[q].t=0;
			if (can_move(hh[p].x,hh[p].y,hh[q].x,hh[q].y)&&d[hh[q].x][hh[q].y]==0)
			{
				d[hh[q].x][hh[q].y]=1;
				f[hh[q].x][hh[q].y]=0;
				q++;
			}
		}
		p++;
	}
	nh=q;
	return;
}
int cal()
{
	int i;
	int temp;
	make_heap(hh,hh+nh);
	while (nh>0)
	{
		rr=hh[0];
		pop_heap(hh,hh+nh);
		nh--;
		if (rr.x==m-1&&rr.y==n-1)
			return rr.t;
		if (d[rr.x][rr.y]==2)
			continue;
		d[rr.x][rr.y]=2;
		for (i=0;i<4;i++)
		{
			rrr.x=rr.x+dx[i];
			rrr.y=rr.y+dy[i];
			temp=move_time(rr.x,rr.y,rrr.x,rrr.y);
			if (temp==-1)
				continue;
			if (temp<rr.t)
				temp=rr.t;
			if (h-temp-l[rr.x][rr.y]>=20)
				rrr.t=temp+10;
			else
				rrr.t=temp+100;
			if (d[rrr.x][rrr.y]==2)
				continue;
			if (d[rrr.x][rrr.y]==0||(d[rrr.x][rrr.y]==1&&f[rrr.x][rrr.y]>rrr.t))
			{
				d[rrr.x][rrr.y]=1;
				f[rrr.x][rrr.y]=rrr.t;
			}
			hh[nh]=rrr;
			nh++;
			push_heap(hh,hh+nh);
		}
	}
	return 0;
}
int main()
{
	int t,tt,i,j;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++)
	{
		scanf("%d %d %d",&h,&m,&n);
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				scanf("%d",&r[i][j]);
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				scanf("%d",&l[i][j]);
		bfs();
		printf("Case #%d: %.1lf\n",tt,cal()/10.0);
	}
	return 0;
}