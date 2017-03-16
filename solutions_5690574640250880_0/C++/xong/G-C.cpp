#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MM 51
struct point
{
	short rw,cl;
};
struct queue
{
	point pts[8];
	short quecnt;
}gque[MM][MM];
int tt,rr,cc,mm,totalcell,safecell,safecnt;
bool grid[MM][MM],flag;

void ini(int row,int col)
{
	memset(grid,1,sizeof(grid));
	memset(gque,0,sizeof(gque));
	totalcell=rr*cc;
	safecell=totalcell-mm;
	safecnt=1;
	grid[row][col]=false;
}
bool mark(int row,int col)
{
	for (int i=-1;i^2;i++)
		for (int j=-1;j^2;j++)
			if (i||j)
				if (row+i>=0&&row+i<rr&&col+j>=0&&col+j<cc)
					if (grid[row+i][col+j])
					{
						grid[row+i][col+j]=false;
						safecnt++;
						gque[row][col].pts[gque[row][col].quecnt].rw=row+i;
						gque[row][col].pts[gque[row][col].quecnt++].cl=col+j;
					}
	if (safecnt>safecell)
		return false;
	return true;
}
void unmark(int row,int col)
{
	for (int i=0;i^gque[row][col].quecnt;i++)
		grid[gque[row][col].pts[i].rw][gque[row][col].pts[i].cl]=true;
	gque[row][col].quecnt=0;
}
void wipe(int row,int col)
{
	if (safecnt==safecell)
		flag=true;
	if (flag||grid[row][col])
		return;
	if (mark(row,col))
		for (int i=0;i^gque[row][col].quecnt;i++)
			wipe(gque[row][col].pts[i].rw,gque[row][col].pts[i].cl);
	else
		unmark(row,col);
}
int main()
{
//	freopen("g-c.txt","r",stdin);
	freopen("C-small-attempt1.in","r",stdin);
	freopen("c-ans.txt","w",stdout);
	cin>>tt;
	for (int ci=1;ci<=tt;ci++)
	{
		cin>>rr>>cc>>mm;
		flag=false;
		for (int i=0;i^rr;i++)
			for (int j=0;j^cc;j++)
			{
				if (flag)
					continue;
				ini(i,j);
				wipe(i,j);
			}
		cout<<"Case #"<<ci<<":"<<endl;
		if (!flag)
			cout<<"Impossible"<<endl;
		else
			for (int i=0;i^rr;i++)
			{
				for (int j=0;j^cc;j++)
					if (i==0&&j==0)
						cout<<'c';
					else if (grid[i][j])
						cout<<'*';
					else
						cout<<'.';
				cout<<endl;
			}
	}
	return 0;
}
