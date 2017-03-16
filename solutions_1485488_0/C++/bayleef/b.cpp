#include <stdio.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include <string>

using namespace std;

unsigned int d[11][11][2000];
bool u[11][11][2000];
int c[11][11],f[11][11];

struct T
{
	int i,j,h,d;
}t,tt;

bool operator <(T t1,T t2)
{
	return t1.d>t2.d;
}

priority_queue<T>q;

int TT,ts,i,j,n,m,h,z,k;

int di[]={1,0,-1,0};
int dj[]={0,1,0,-1};

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&TT);
	while(TT--)
	{
		memset(d,-1,sizeof(d));
		memset(u,0,sizeof(u));
		while(!q.empty())
			q.pop();
		scanf("%d%d%d",&h,&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&c[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&f[i][j]);
		d[0][0][h]=0;
		t.i=t.j=0;
		t.h=h;
		t.d=0;
		q.push(t);
		while(!q.empty())
		{
			t=q.top();
			q.pop();
			if(t.i==n-1 && t.j==m-1)
				break;
			u[t.i][t.j][t.h]=1;
			tt=t;
			if(tt.h)
			{
				tt.h--;
				tt.d++;
			}
			if(!u[tt.i][tt.j][tt.h] && d[tt.i][tt.j][tt.h]>tt.d)
			{
				d[tt.i][tt.j][tt.h]=tt.d;
				q.push(tt);
			}
			for(k=0;k<4;k++)
			{
				tt.i=t.i+di[k];
				tt.j=t.j+dj[k];
				if(tt.i<0 || tt.j<0 || tt.i>=n || tt.j>=m)
					continue;
				z=c[tt.i][tt.j]-50;
				if(t.h>z || f[t.i][t.j]>z || f[tt.i][tt.j]>z || f[tt.i][tt.j]+50>c[t.i][t.j])
					continue;
				if(t.h==h)
				{
					tt.d=0;
					tt.h=h;
				}
				else if(t.h>=f[t.i][t.j]+20)
				{
					tt.d=t.d+10;
					tt.h=t.h-10;
					if(tt.h<0)tt.h=0;
				}
				else
				{
					tt.d=t.d+100;
					tt.h=t.h-100;
					if(tt.h<0)tt.h=0;
				}
				if(!u[tt.i][tt.j][tt.h] && d[tt.i][tt.j][tt.h]>tt.d)
				{
					d[tt.i][tt.j][tt.h]=tt.d;
					q.push(tt);
				}
			}
		}
		printf("Case #%d: %d.%d\n",++ts,t.d/10,t.d%10);
	}
	return 0;
}