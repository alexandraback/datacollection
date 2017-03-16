#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
#include <iomanip> 
using namespace std;
int R,C,M;
#define RR 50
#define CC 50
void Solve(int row,int col,int mine)
{	
	int flag = 0;
	char str[RR][CC];
	int temp;
	int transposition=0;
	if(row>col)
	{
		temp=row;
		row=col;
		col=temp;
		transposition=1;
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			str[i][j]='.';
		}
	}
	if(row==1)
	{	
		if(row==1)
		{
			for(int i=0;i<mine;i++)
				str[0][i]='*';
			str[0][col-1]='c';
		}
		flag=1;
	}
	else if((row*col-mine)==1)
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				str[i][j]='*';
			}
		}
		str[0][0]='c';
		flag=1;
	}
	else if(mine==0)
	{
		str[0][0]='c';
		flag=1;
	}
	else if(row==2)
	{
		if((row*col-mine==2)||mine%2==1)
			flag=0;
		else
		{
			int line=mine/2;
			for(int i=0;i<line;i++)
			{
				str[0][i]='*';
				str[1][i]='*';
			}
			str[0][col-1]='c';
			flag=1;
		}
	}
	else if(row*col-mine==1||row*col-mine==2||row*col-mine==3||row*col-mine==5||row*col-mine==7)
	{
		flag=0;
	}
	else
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				str[i][j]='*';
			}
		}
		int blank=row*col-mine;//468910
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				str[i][j]='.';
			}
		}
		int currow=2;
		int curcol=2;
		
		if(blank%2==0)
		{
			blank=blank-4;
			while(blank>0)
			{
				str[0][curcol]='.';
				str[1][curcol]='.';
				blank=blank-2;
				curcol++;
				if(curcol>=col)
					break;
			}
			while(blank>0)
			{
				str[currow][0]='.';
				str[currow][1]='.';
				blank=blank-2;
				currow++;
				if(currow>=row)
					break;
			}
			currow=2;
			curcol=2;
			while(blank>0)
			{
				str[currow][curcol]='.';
				blank--;
				curcol++;
				if(curcol>=col)
				{
					curcol=2;
					currow++;

				}
			}
		}
		else
		{
			blank=blank-9;
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					str[i][j]='.';
				}
			}
			currow=3;
			curcol=3;
			while(blank>0)
			{
				str[0][curcol]='.';
				str[1][curcol]='.';
				blank=blank-2;
				curcol++;
				if(curcol>=col)
					break;
			}
			while(blank>0)
			{
				str[currow][0]='.';
				str[currow][1]='.';
				blank=blank-2;
				currow++;
				if(currow>=row)
					break;
			}
			currow=2;
			curcol=3;
			while(blank>0)
			{
				str[currow][curcol]='.';
				blank--;
				curcol++;
				if(curcol>=col)
				{
					curcol=2;
					currow++;
				}
			}
		}
		str[0][0]='c';
		flag=1;
	}
	if(flag==1&&transposition==0)
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				cout<<str[i][j];
			}
			cout<<endl;
		}

	}
	else if(flag==1&&transposition==1)
	{
		for(int i=0;i<col;i++)
		{
			for(int j=0;j<row;j++)
			{
				cout<<str[j][i];
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"Impossible"<<endl;
	}
}
void main()
{
	//freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-large.in", "r", stdin);
	//freopen("1.txt", "r", stdin);
	freopen("C-large.out", "w", stdout);
	//freopen("2.txt", "w", stdout);
	//freopen("C-small-attempt1.out", "w", stdout);
	int Numcase;
	cin>>Numcase;

	double temp;
	for(int test=1;test<=Numcase;test++)
	{
		cin>>R;
		cin>>C;
		cin>>M;
		cout<<"Case #"<<test<<":"<<endl;
		Solve(R,C,M);
	}
	fclose(stdout);
}