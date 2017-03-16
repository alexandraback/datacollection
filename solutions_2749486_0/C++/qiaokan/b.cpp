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
struct state
{
	int x , y , f ;
	int sum ;
} ;
int f[4][2] ;
char d[4] ;
int mark[2001][2001] ;
int X,Y ;
state a[50000000] ;
bool check(int x,int y)
{
	return (x>=0&&y>=0&&x<=2000&&y<=2000) ;
}
int main()
{
	int cs ;
	cin>>cs ;
	d[0] = 'N' ;d[1] = 'S' ; d[2] = 'E' ; d[3] = 'W' ;
	f[0][0] = 0 ; f[0][1] = 1 ; 
	f[1][0] = 0 ; f[1][1] = -1 ;
	f[2][0] = 1 ; f[2][1] = 0 ;
	f[3][0] = -1 ;f[3][1] = 0 ;
	vector<state> res ;
	for (int tt=1;tt<=cs;tt++)
	{
	//	cout<<tt<<endl ;
		cin>>X>>Y ;
		X += 1000 ;
		Y += 1000 ;
		memset(mark,0,sizeof(mark)) ;
		state start ;
		start.x = 1000 ; start.y = 1000 ; start.sum = 0 ; start.f = -1 ;
		mark[1000][1000] = 1 ;
		int s,t ;
		s = t = 1 ;
		a[s] = start ;
		while (s<=t)
		{
			state curr = a[s] ;
			int l = curr.sum + 1 ;
			for (int i=0;i<4;i++)
			{
				int nx = curr.x + l * f[i][0] ;
				int ny = curr.y + l * f[i][1] ;
				if (check(nx,ny)&&!mark[nx][ny])
				{
					state next ;
					next.x = nx ; next.y = ny ; next.sum = l ;next.f = s ;
					a[++t] = next ;
					mark[nx][ny] = 1 ;
					if (next.x==X&&next.y==Y)
					{
					//	cout<<l<<endl ;
						res.clear() ;
						while (t!=-1)
						{
							res.push_back(a[t]) ;
							t = a[t].f ;
						}
						reverse(res.begin(),res.end()) ;
						string out = "" ;
						for (int i=0;i<res.size()-1;i++)
						{
							
							for (int j=0;j<4;j++)
							{
								if (res[i+1].x-res[i].x==(i+1)*f[j][0]&&res[i+1].y-res[i].y==(i+1)*f[j][1])
								{
						//			cout<<res[i].x<<" "<<res[i].y<<endl ;
									out = out + char(d[j]) ;
								}
							}
						}
						cout<<"Case #"<<tt<<": "<<out<<endl ;
					}
				}
			}
			s++ ;
		}
	}
}