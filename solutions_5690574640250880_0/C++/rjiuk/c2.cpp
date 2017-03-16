#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#define FOR(i,p,k) for(int i = (p);i<(k);i++)
typedef long long int LL;
using namespace std;

int t,r,c,m;
int A[55];

int Dostep[55][55];
int Bomb[55][55];
int kx[9]={-1,0,1,-1,1,-1,0,1,0};
int ky[9]={1,1,1,0,0,-1,-1,-1,0};

void zaznacz(int kt)
{
	int row = (A[kt]+c-1)/c;
	int col = A[kt]-(row-1)*c;
	FOR(i,0,9)
		Dostep[kx[i]+row][ky[i]+col]++;
	Bomb[row][col]=1;
}

bool Odw[55][55];

bool in(int x, int y)
{
	if(x>=1 && x<=r &&y>=1&&y<=c)
		return 1;
	return 0;
}

vector<pair<int,int> > Kolejka;

void bfs(int px,int py)
{
	Kolejka.push_back(make_pair(px,py));
	Odw[px][py]=1;
	
	FOR(i,0,Kolejka.size())
	{

		int x = Kolejka[i].first;
		int y = Kolejka[i].second;
		if(Dostep[x][y]==0)		
		FOR(i,0,8)
		{
			if(Odw[x+kx[i]][y+ky[i]]==0 && in(kx[i]+x,ky[i]+y) )
			{
				Odw[x+kx[i]][y+ky[i]]=1;
				Kolejka.push_back(make_pair(x+kx[i],y+ky[i]));
			}
		}
	}
}

bool czy_da_sie()
{
	int px=-1,py=-1;
	FOR(i,1,r+1)
		FOR(j,1,c+1)
			if(Dostep[i][j]==0)
				px=i,py=j;
	if(r*c-m==1)
	{
		FOR(i,1,r+1)
			FOR(j,1,c+1)
				Bomb[i][j]=1;
		Bomb[1][1]=-1;
		return 1;	
	}	
	if(m==0)
	{
		Bomb[1][1]=-1;
		return 1;
	}
	if(px==-1)
		return 0;
	bfs(px,py);
	
	bool Wsio = 1;
	FOR(i,1,r+1)
		FOR(j,1,c+1)
			if(Odw[i][j]==0 && Dostep[i][j]!=0 && Bomb[i][j]!=1)
				Wsio=0;
	if(Wsio==1)
		Bomb[px][py]=-1;
	return Wsio;
		
}

bool licz()
{
	FOR(i,1,m+1)
		zaznacz(i);
	
	FOR(row,1,r+1)
		FOR(col,1,c+1)
		{
			if(czy_da_sie()){
				FOR(i,1,r+1)
				{
					FOR(j,1,c+1)
						if(Bomb[i][j]==1)
							cout<<"*";
						else if(Bomb[i][j]==-1)
							cout<<"c";
						else
							cout<<".";
					cout<<"\n";				
				}
				return 1;			
			}
		}
	return 0;
}

void czysc()
{
	Kolejka.clear();
	FOR(row,1,r+1)
		FOR(col,1,c+1)
			Bomb[row][col]=0,Dostep[row][col]=0,Odw[row][col]=0;
}

void generuj(int ss)
{
	cin>>r>>c>>m;
	int w = r*c+1;
	FOR(i,1,m+1)
		A[i]=i;
	
	int p = m;
	printf("Case #%d:\n",ss);
	if(m==0)
	{
		Bomb[1][1]=-1;
		FOR(i,1,r+1)
				{
					FOR(j,1,c+1)
						if(Bomb[i][j]==1)
							cout<<"*";
						else if(Bomb[i][j]==-1)
							cout<<"c";
						else
							cout<<".";
					cout<<"\n";				
				}
		czysc();
		return;
	}
	while(p>=1)
	{
		if(licz()){
			czysc();return;}
		if(A[m]==w-1)
			--p;
		else
			p=m;
		if(p>=1)
		{
			for (int i = m ;i>=p;i--)
				A[i] = A[p]+i-p+1;
		}
		czysc();
	}
	printf("Impossible\n");
	
}


void dane()
{
	cin>>t;
	FOR(przy,0,t)
	{
		generuj(przy+1);
	}
}

int main()
{
	dane();
	return 0;
}
