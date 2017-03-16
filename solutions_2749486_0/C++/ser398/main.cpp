#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#define  mp make_pair
using namespace std;
typedef pair<pair<int,int>,int > piii;
const int m=210;
piii q[m*m*510];
int f[m][m][510];
int d[m][m][510];
int qb=0,qe=0;
bool corect(int x)
{
	if(x<0)
		return 0;
	if(x>=m)
		return 0;
	return 1;
}
#define forn(i,n) for(int i=0;i<(int)n;i++)
void bfs()
{
	qb=qe=0;
	memset(d,-1,sizeof d);
	q[qe++]=mp(mp(m/2,m/2),1);
	memset(f,-1,sizeof f);
	while(qb!=qe)
	{
		piii v=q[qb++];
		if(v.second==500)
			break;
		
		int x=v.first.first;
		int y=v.first.second;
		
		
		int nx,ny;
		nx=x+v.second;
		ny=y;
		if(corect(nx)&&corect(ny))
		{
			if(d[nx][ny][v.second+1]==-1)
			{
				d[nx][ny][v.second+1]=1;
				f[nx][ny][v.second+1]=0;
				q[qe++]=mp(mp(nx,ny),v.second+1);
			}
		}
		nx=x;
		ny=y-v.second;
		if(corect(nx)&&corect(ny))
		{
			if(d[nx][ny][v.second+1]==-1)
			{
				d[nx][ny][v.second+1]=1;
				f[nx][ny][v.second+1]=1;	
				q[qe++]=mp(mp(nx,ny),v.second+1);
			}
		}
		nx=x-v.second;
		ny=y;
		if(corect(nx)&&corect(ny))
		{
			if(d[nx][ny][v.second+1]==-1)
			{
				d[nx][ny][v.second+1]=1;
				f[nx][ny][v.second+1]=2;
				q[qe++]=mp(mp(nx,ny),v.second+1);
			}
		}
		nx=x;
		ny=y+v.second;
		if(corect(nx)&&corect(ny))
		{
			if(d[nx][ny][v.second+1]==-1)
			{
				d[nx][ny][v.second+1]=1;
				f[nx][ny][v.second+1]=3;
				q[qe++]=mp(mp(nx,ny),v.second+1);
			}
		}

	}
	return;//
}
void solve()
{
	int X,Y;
	cin>>X>>Y;

	if(X<0)
	{
		forn(it,abs(X))
			cout<<"EW";
	}
	else
	{
			forn(it,X)
			cout<<"WE";
	
	}
	if(Y<0)
	{
		forn(it,abs(Y))
			cout<<"NS";
	}
	else
	{
			forn(it,Y)
			cout<<"SN";
	
	}

}
void solve2()
{
	int X,Y;
	cin>>X>>Y;
	X+=m/2;
	Y+=m/2;
	int  Min=1e9;
	forn(it,500)
	{
		if(d[X][Y][it]==1)
			Min=min(Min,it);
	}
	string ans="";
	int x=X,y=Y;
	x=X;
	while(x!=m/2||y!=m/2)
	{
		
		if(f[x][y][Min]==0)
			ans+='E',x-=Min-1;
		if(f[x][y][Min]==1)
			ans+='S',y+=Min-1;
		if(f[x][y][Min]==2)
			ans+='W',x+=Min-1;
		if(f[x][y][Min]==3)
			ans+='N',y-=Min-1;
		Min--;
		
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	//bfs();
	cin>>t;
	forn(i,t)
	{
		printf("Case #%d: ",i+1);
		solve();//
		puts("");
	}
	return 0;

	return 0;
}