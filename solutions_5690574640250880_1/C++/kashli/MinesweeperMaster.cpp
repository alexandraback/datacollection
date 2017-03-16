/*
 * MineSweeperMaster.cpp
 *
 *  Created on: Apr 12, 2014
 *      Author: Ganesh
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#define iter(i, N) for(long long i=0 ; i<N ; i++)

using namespace std;

bool dfs(vector<vector<char> > &grid, int i, int j, int r, int c, int &rem, bool cond)
{
	if(i<0 || j<0 || i>=r || j>=c)
		return false;
	if(grid[i][j]=='*')
	{
		return true;
	}
	if(rem==0)
		return true;
	if(cond)
	{
		rem--;
		grid[i][j] = '*';
		if(dfs(grid,i+1,j-1,r,c,rem,false))
			return true;
		rem++;
		grid[i][j]='.';
		return false;
	}
	if(i>=1)
		if(grid[i-1][j] == '.')
			return false;
	if(j>=1)
		if(grid[i][j-1] == '.')
			return false;

	if((rem==1)&&(i==r-2|| j==c-2))
		return false;
	if(j==c-2)
	{
		rem--;
		grid[i][j] = '*';
		if(dfs(grid,i,j+1,r,c,rem,true))
			return true;
		else
		{
			rem++;
			grid[i][j] = '.';
			return false;
		}
	}
	rem--;
	grid[i][j] = '*';

	if(i==r-1)
	{
		if(dfs(grid,0,j+1,r,c,rem,cond))
		{
			return true;
		}
		else
		{
			rem++;
			grid[i][j] = '.';
			return false;
		}
	}
	else
	{
		if(!dfs(grid,i+1,j,r,c,rem,cond) )
		{
			if(i==r-2)
			{
				rem++;
				grid[i][j]='.';
				return false;
			}
			if(dfs(grid,0,j+1,r,c,rem,cond))
				return true;
			else
			{
				rem++;
				grid[i][j]='.';
				return false;
			}
		}
		else
		{
			return true;
		}
	}
}
int main()
{
	long long cases;
	cin>>cases;
	iter(q, cases)
	{
		int r,c,M;
		cin>>r>>c>>M;
		vector<vector<char> > grid;
		grid.resize(r);
		iter(i,r)
			grid[i].resize(c);
		iter(i,r)
		iter(j,c)
		grid[i][j] = '.';
		cout<<"Case #"<<q+1<<":\n";
		if((r==1) || (c==1))
		{
			if(r==1)
			{
				iter(i,M)
					grid[0][i] = '*';
				grid[0][c-1] = 'c';
			}
			else
			{
				iter(i,M)
					grid[i][0] = '*';
				grid[r-1][0] = 'c';
			}
		}
		if(r*c-M==1)
		{
			iter(i,r)
			iter(j,c)
				grid[i][j]='*';
			grid[r-1][c-1]='c';
		}

		if((r==1) || (c==1) || r*c-M==1)
		{
			iter(i,r)
			{
				iter(j,c)
					cout<<grid[i][j];
				cout<<"\n";
			}
			continue;
		}
		if(r*c-M == 3 || r*c-M == 5 || r*c-M == 7 || r*c-M==2)
		{
			cout<<"Impossible\n";
			continue;
		}
		else
		if(r==2 || c==2)
			if(M%2!=0 && r*c-1 != M)
			{
				cout<<"Impossible\n";
				continue;
			}

		bool result = dfs(grid, 0,0,r,c,M,false);
		grid[r-1][c-1] = 'c';
		if(!result)
			cout<<"Impossible\n";
		else
		iter(i,r)
		{
			iter(j,c)
				cout<<grid[i][j];
			cout<<"\n";
		}
	}
	return 0;
}

