#include <algorithm>  
#include <bitset>  
#include <cctype>  
#include <cmath>  
#include <complex>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <ctime>  
#include <deque>  
#include <functional>  
#include <iomanip>  
#include <iostream>  
#include <fstream>
#include <list>  
#include <map>  
#include <numeric>  
#include <queue>  
#include <set>  
#include <sstream>  
#include <stack>  
#include <string>  
#include <utility>  
#include <vector>   
using namespace std;

ifstream ifile;
ofstream ofile;

int T;
char gra[51][51];
int R,C,M;

int cases;

void show()
{
	ofile<<"Case #"<<cases<<":"<<endl;
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			ofile<<gra[i][j];
		}
		ofile<<endl;
	}
}

void impossible()
{
	ofile<<"Case #"<<cases<<":"<<endl<<"Impossible"<<endl;
}

void solve(int r, int c, int m)
{

	if(r<=1||c<=1)
	{
			impossible();
			return;
		
	}

	if(m==0)
	{
		show();
		return;
	}

	if(r>=c)
	{
		if(m>=c)
		{
			for(int i = 0; i < c; i++)
			{
				gra[r-1][i]='*';
			}
			solve(r-1,c,m-c);
		}
		else
		{
			if(m<=c-2)
			{
				for(int i = 0; i < m; i++)
				{
					gra[r-1][c-1-i]='*';
				}
				solve(r-1,c,0);
			}
			else
			{
				for(int i = 0; i < c-2; i++)
				{
					gra[r-1][c-1-i]='*';
				}
				solve(r-1,c,1);
			}
		}
	}
	else
	{
		if(m>=r)
		{
			for(int i = 0; i < r; i++)
			{
				gra[i][c-1]='*';
			}
			solve(r,c-1,m-r);
		}
		else
		{
			if(m<=r-2)
			{
				for(int i = 0; i < m; i++)
				{
					gra[r-1-i][c-1]='*';
				}
				solve(r,c-1,0);
			}
			else
			{
				for(int i = 0; i < r-2; i++)
				{
					gra[r-1-i][c-1]='*';
				}
				solve(r,c-1,1);
			}
		}
	}
}

int main(void)
{
	ifile.open("input.txt");
	ofile.open("output.txt");

	ifile>>T;

	for(int k = 0; k < T; k++)
	{
		cases=k+1;
		ifile>>R>>C>>M;
		for(int i = 0; i < 51; i++)
			for(int j = 0; j < 51; j++)
				gra[i][j]='.';

		gra[0][0]='c';

		if(R*C==M+1)
		{
			for(int i = 0; i < R; i++)
			{
				for(int j = 0; j < C; j++)
				{
					gra[i][j]='*';
				}
			}
			gra[0][0]='c';
			show();
			continue;
		}

		if(R==1)
		{
			if(C<=2)
			{
				if(M>0)
					impossible();
				else
				{
					show();
				}
			}
			else
			{
				if(M<=C-2)
				{
					for(int i = 0; i < M; i++)
					{
						gra[0][C-1-i]='*';
					}
					show();
				}
				else
					impossible();
			}
		}
		else if(C==1)
		{
			if(R<=2)
			{
				if(M>0)
					impossible();
				else
				{
					show();
				}
			}
			else
			{
				if(M<=R-2)
				{
					for(int i = 0; i < M; i++)
					{
						gra[R-1-i][0]='*';
					}
					show();
				}
				else
					impossible();
			}
		}
		else
			solve(R,C,M);
	}

	ifile.close();
	ofile.close();
	return 0;
}