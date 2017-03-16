#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <sstream>
#include <queue>
using namespace std ;
int n,x,y ;
struct node
{
	bool s[10][10] ;
	double p ;
	int num ;
	node ()
	{
		memset(s,0,sizeof(s)) ;
		p = 0 ;
		num = 0 ;
	}
} ;
bool operator==(node n1,node n2)
{
	for (int i=0;i<10;i++)
		for (int j=0;j<10;j++)
			if (n1.s[i][j]!=n2.s[i][j]) return false ;
	return true ;
}
deque<node> q ;
node curr ;
node simu(int d)
{
	node ret ;
	ret = curr ;
	int x,y ;
	x = 4 ; y = 5 ;
	ret.s[x][y] = 1 ;
	while (x>=1)
	{
		if (((x>=2&&ret.s[x-2][y]==0)||x==1)&&(ret.s[x-1][y-1]==0&&ret.s[x-1][y+1]==0))
		{
			swap(ret.s[x-1][y],ret.s[x][y]) ;	
			x = x - 1 ;
			y = y ;
		}
		else
		if (ret.s[x-1][y-1]==0&&ret.s[x-1][y+1]!=0)
		{
			swap(ret.s[x-1][y-1],ret.s[x][y]) ;
			x = x - 1 ;
			y = y - 1 ;
		}
		else
		if (ret.s[x-1][y-1]!=0&&ret.s[x-1][y+1]==0)
		{
			swap(ret.s[x-1][y+1],ret.s[x][y]) ;
			x = x - 1 ;
			y = y + 1 ;
		}
		else
		if (ret.s[x-1][y-1]==0&&ret.s[x-1][y+1]==0)
		{
			if (d==0)
			{
				swap(ret.s[x-1][y-1],ret.s[x][y]) ;
				x = x - 1 ;
				y = y - 1 ;
			}
			else
			{
				swap(ret.s[x-1][y+1],ret.s[x][y]) ;
				x = x - 1 ;
				y = y + 1 ;		
			}
		}
		else break ;
	}

	return ret ;
}
int main()
{
	int cs ;
	cin>>cs ;
	for (int t=1;t<=cs;t++)
	{
		cin>>n>>x>>y ;
		node start ;
		start.p = 1 ;
		q.push_back(start) ;
		while (!q.empty())
		{
			curr = q.front() ;

			if (curr.num==n)
			{
				break ;
			}
			q.pop_front() ;
			node next_l,next_r ;
			next_l = simu(0) ;
			next_l.p = curr.p * 0.5 ;
			next_l.num = curr.num + 1 ;
			
			next_r = simu(1) ;
			next_r.p = curr.p * 0.5 ;
			next_r.num = curr.num + 1 ;
			if (next_r==next_l)
			{
				next_l.p *= 2 ;
				q.push_back(next_l) ;
				continue ;
			}

			q.push_back(next_l) ;
			q.push_back(next_r) ;
		}
			int nx = y ;
			int ny = x ;
			ny = ny + 5 ;
			double ret = 0 ;
			if (nx<0||nx>=10||ny<0||ny>10)
			{
				printf("Case #%d: 0\n",t) ;
				continue ;
			}
			while (!q.empty())
			{
				node curr = q.front() ;
				q.pop_front() ;
				if (curr.s[nx][ny]==1)
				{
					ret += curr.p ;
				}
			}
			printf("Case #%d: %.7f\n",t,ret) ;		
	}

}
