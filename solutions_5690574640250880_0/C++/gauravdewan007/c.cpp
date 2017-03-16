#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>
#include <iterator>

#include <cmath>
#include <cstring>
using namespace std;
int m[5][5];
#if 0
#include "generic.h"
#define cin fin
#define cout fout
#endif
int dfscount = 0;
int dfs(int row, int col, int r, int c)
{
	int a[] = {1,0,-1};
	int newrow, newcol;
	m[row][col] = 2000; dfscount++;
	
	for(int i = 0;i<3;i++)
		for(int j =0;j<3;j++)
		{
			newrow = row+a[i]; newcol = col+a[j];
			if(newrow >= 0 && newrow < r && newcol >=0 && newcol < c)
				if(m[newrow][newcol] == 0) //note self is neighbour of self; we dont care as long as we unplace correctly
				{
					dfs(newrow, newcol,r,c);
				}
		}
		return 0;
}
//test next place
bool test(int r,int c)
{//return true if every natural no has 
	int i,j;
	int cnt = 0;
	int zi,zj;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			int row = i; int col = j;
			if(m[i][j] >0)
			{ //validate atleast one neighbour is 0
				int a[] = {1,0,-1};
				int newrow, newcol;
				bool valid = false;
				for(int i =0;i<3&&!valid;i++)
					for(int j =0;j<3;j++)
					{
						newrow = row+a[i]; newcol = col+a[j];
						if(newrow >= 0 && newrow < r && newcol >=0 && newcol < c)
							if(m[newrow][newcol] == 0) //note self is neighbour of self; we dont care as long as we unplace correctly
							{
								valid = true; break;
							}
					}
					if(!valid)
						return false;
			}

			else if(m[i][j] == 0)
			{
				zi = i; zj = j;
				cnt++;
			}
		}
		bool zvalid = false;

		dfscount = 0;
		dfs(zi,zj,r,c);
		if(cnt == dfscount)
			zvalid = true;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
			{
				if(m[i][j] == 2000)
					m[i][j] = 0;
			}
	return zvalid;
}

bool place(int i,int r, int c)
{
	int row = i/c;
	int col = i%c;
	m[row][col] -= 100;
	int a[] = {1,0,-1};
	int newrow, newcol;
	for(int i =0;i<3;i++)
	for(int j =0;j<3;j++)
	{
		newrow = row+a[i]; newcol = col+a[j];
		if(newrow >= 0 && newrow < r && newcol >=0 && newcol < c)
			m[newrow][newcol] ++; //note self is neighbour of self; we dont care as long as we unplace correctly
	}
	return true; //if (!test()) {unplace(i,r,c); return false;}
}

void unplace(int i,int r, int c)
{ //no checking ; assume we were placed correctly
	int row = i/c;
	int col = i%c;
	m[row][col] += 100;
	int a[] = {1,0,-1};
	int newrow,newcol;
	for(int i =0;i<3;i++)
	for(int j =0;j<3;j++)
	{
		newrow = row+a[i]; newcol = col+a[j];
		if(newrow >= 0 && newrow < r && newcol >=0 && newcol < c)
			m[newrow][newcol] --; //note self is neighbour of self; we dont care as long as we unplace correctly
	}
}

bool mine(int r,int c,int mc, int l, int idx)
{ //l mines have been placed; idx of this mine
	if(l == mc)
	{
		return test(r,c);
	}
	if(idx+mc-l > r*c)
	{
		return false;
	}
	for(int i=idx;i<r*c;i++)
	{
		if(place(i,r,c))
		{
			if(mine(r,c,mc,l+1,i+1)) //dp candidate
				return true;
			unplace(i,r,c);
		}
		
	}
	return false;
}


int main()
{
	int t,kase;
	cin>>t;
	int r,c,mc;
	for(kase=1;kase<=t;kase++)
	{
		cin>>r>>c>>mc;
		memset(m,0,sizeof(m));
		cout<<"Case #"<<kase<<":\n";
		if(mc == r*c-1)
		{
			for(int i =0;i<r;i++){
				for(int j =0;j<c;j++)
				{
					if(i==0 && j==0)
						cout<<"c";
					else
						cout<<"*";
				}
					//if(i!=r-1) 
						cout<<endl;
			}
		}
		else if(mine(r,c,mc,0,0))
		{
			bool once = true;
			for(int i =0;i<r;i++){
			for(int j =0;j<c;j++)
			{
				if(m[i][j] == 0 && once)
				{cout<<"c"; once = false;}
				else if(m[i][j] < 0)
					cout<<"*";
				else 
					cout<<".";
			}
			//if(i!=r-1) 
				cout<<endl;
			}
			
		}
		else
			cout<<"Impossible"<<endl;
	
	}
	return 0;
}