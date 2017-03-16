#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int r,c,m,b;
bool can(int w)
{
	if (w*r<b)
	{
		return false;
	}
	static char a[62][62];
	int t=0;
	int y,x;
	for (y=0;y<r;y++)
	{
		for (x=0;x<c;x++)
		{
			if (x<w&&t<b)
			{
				a[y][x]=t==0?'c':'.';
				t++;
			}
			else
			{
				a[y][x]='*';
			}
		}
		a[y][c]='\0';
	}
	if (w>2&&b%w==1)
	{
		int ym=b/w;
		if (ym>0)
		{
			a[ym][1]='.';
			a[ym-1][w-1]='*';
		}
	}
	static int d[62][62];
	memset(d,0,sizeof(d));
	static int dx[8]={1,1,0,-1,-1,-1,0,1},dy[8]={0,-1,-1,-1,0,1,1,1};
	for (y=0;y<r;y++)
	{
		for (x=0;x<c;x++)
		{
			if (a[y][x]=='*')
			{
				int k;
				for (k=0;k<8;k++)
				{
					int y2=y+dy[k];
					int x2=x+dx[k];
					if (x2>=0&&x2<c&&y2>=0&&y2<r)
					{
						d[y2][x2]++;
					}
				}
			}
		}
	}
	//printf("w=%d\n",w);
	for (y=0;y<r;y++)
	{
		for (x=0;x<c;x++)
		{
			//printf("%c",a[y][x]=='*'?'*':'0'+d[y][x]);
		}
		//printf("\n");
	}
	static bool v[62][62];
	memset(v,false,sizeof(v));
	v[0][0]=true;
	for (y=0;y<r;y++)
	{
		for (x=0;x<c;x++)
		{
			if (v[y][x]&&d[y][x]==0)
			{
				int k;
				for (k=0;k<8;k++)
				{
					int y2=y+dy[k];
					int x2=x+dx[k];
					if (x2>=0&&x2<c&&y2>=0&&y2<r)
					{
						v[y2][x2]=true;
					}
				}
			}
		}
	}
	for (y=0;y<r;y++)
	{
		for (x=0;x<c;x++)
		{
			if (!v[y][x]&&a[y][x]!='*'&&d[y][x])
			{
				//printf("Unrevealed at y=%d,x=%d.\n",y,x);
				return false;
			}
		}
	}
	for (y=0;y<r;y++)
	{
		printf("%s\n",a[y]);
	}
	return true;
}
int main()
{
	int t,ti;
	scanf("%d",&t);
	for (ti=1;ti<=t;ti++)
	{
		scanf("%d%d%d",&r,&c,&m);
		b=r*c-m;
		printf("Case #%d:\n",ti);
		int w;
		for (w=1;w<=c;w++)
		{
			if (can(w))
			{
				break;
			}
		}
		if (w>c)
		{
			printf("Impossible\n");
		}
	}
	return 0;
}
