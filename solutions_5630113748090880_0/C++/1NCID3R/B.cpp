#include <bits/stdc++.h>
using namespace std;

deque<int> arr[100];

int grid[50][50];
int rowflag = 0;
int ans = 0;

bool check_row(int row, int pos, int n)
{
	for(int i=0; i<n; i++)
	{
		if(grid[row][i]==-1)
			continue;
		if(grid[row][i]!=arr[pos][i])
			return false;
	}
	return true;
}

bool check_col(int col, int pos, int n)
{
	for(int i=0; i<n; i++)
	{
		if(grid[i][col]==-1)
			continue;
		if(grid[i][col]!=arr[pos][i])
			return false;
	}
	return true;
}

bool rec(int pos, int rowpos, int colpos, int skip, int n)
{
	/*
	cout << pos << " " << rowpos << " " << colpos << " " << skip << endl;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}
	*/
	if(rowpos==n && colpos==n)
		return true;
	if(pos==2*n-1)
	{
		if(rowpos!=n)
			rowflag = 1;
		ans = n-1;
		return true;
	}

	int temp[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			temp[i][j] = grid[i][j];

	if(rowpos!=n && check_row(rowpos,pos,n))
	{
		for(int i=0; i<n; i++)
			grid[rowpos][i] = arr[pos][i];
		if(rec(pos+1,rowpos+1,colpos,skip,n))
			return true;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				grid[i][j] = temp[i][j];
	}
	if(colpos!=n && check_col(colpos,pos,n))
	{
		for(int i=0; i<n; i++)
			grid[i][colpos] = arr[pos][i];
		if(rec(pos+1,rowpos,colpos+1,skip,n))
			return true;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				grid[i][j] = temp[i][j];
	}
	if(skip)
	{
		if(rowpos!=n)
		{
			rowflag = 1;
			ans = rowpos;
			if(rec(pos,rowpos+1,colpos,0,n))
				return true;
		}
		if(colpos!=n)
		{
			rowflag = 0;
			ans = colpos;
			if(rec(pos,rowpos,colpos+1,0,n))
				return true;
		}
	}

	return false;
}

int main()
{
	int t;
	scanf("%d",&t);

	for(int cn=1; cn<=t; cn++)
	{
		int n;
		scanf("%d",&n);

		for(int i=0; i<2*n-1; i++)
		{
			arr[i].resize(n);
			for(int j=0; j<n; j++)
				scanf("%d",&arr[i][j]);
		}

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				grid[i][j] = -1;

		sort(arr,arr+2*n-1);
		rec(0,0,0,1,n);
		printf("Case #%d:",cn);
		if(rowflag)
		{
			for(int i=0; i<n; i++)
				printf(" %d",grid[ans][i]);
			puts("");
		}
		else
		{
			for(int i=0; i<n; i++)
				printf(" %d",grid[i][ans]);
			puts("");
		}
	}
}