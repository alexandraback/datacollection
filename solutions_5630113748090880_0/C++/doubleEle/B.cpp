#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

const int N=55;

int ansx,ansy,n,x,y,map[N][N],vis[N][N][N],T;

struct node
{
	int a[N];
	bool operator < (const node &o) const
	{
		return a[x]<o.a[x];
	}
}a[2*N];


bool pd1(int k)
{
	for (int i=1; i<x; i++)
	  if ((map[x][i]!=a[k].a[i])&&(map[x][i]!=-1))
	    return 0;
	return 1;
}

bool pd2(int k)
{
	for (int i=1; i<x; i++)
	  if ((map[i][x]!=a[k].a[i])&&(map[i][x]!=-1))
	    return 0;
	return 1;
}

void dfs()
{
//	cout << x << ' ' << ansx << endl;
	if (x>n) return;
	sort(a+1+y,a+1+2*n-1);
	for (int i=1; i<=n; i++) 
	  for (int j=1; j<=n; j++)
	    vis[x][i][j]=map[i][j];
	if (a[y+1].a[x]==a[y+2].a[x])
	{
		if ((pd1(y+1))&&(pd2(y+2)))
		{
			for (int i=1; i<=n; i++) map[x][i]=a[y+1].a[i];
			for (int i=1; i<=n; i++) map[i][x]=a[y+2].a[i];
			x++; y+=2;
			dfs();
			if (x>n) return;
			x--; y-=2;
			for (int i=1; i<=n; i++)
			  for (int j=1; j<=n; j++) map[i][j]=vis[x][i][j];
		}
		if ((pd2(y+1))&&(pd1(y+2)))
		{
			for (int i=1; i<=n; i++) map[x][i]=a[y+2].a[i];
			for (int i=1; i<=n; i++) map[i][x]=a[y+1].a[i];
			x++; y+=2;
			dfs();
			if (x>n) return;
			x--; y-=2;
			for (int i=1; i<=n; i++)
			  for (int j=1; j<=n; j++) map[i][j]=vis[x][i][j];
		}
	}
	else
	{
//		cout << 'e' << endl;
		ansx=x;
		if (pd1(y+1))
		{
			for (int i=1; i<=n; i++) map[x][i]=a[y+1].a[i];
			x++; y++; ansy=1;
			dfs();
			if (x>n) return;
			x--; y--;
			for (int i=1; i<=n; i++)
			  for (int j=1; j<=n; j++) map[i][j]=vis[x][i][j];
		}
		if (pd2(y+1))
		{
			for (int i=1; i<=n; i++) map[i][x]=a[y+1].a[i];
			x++; y++; ansy=2;
			dfs();
			if (x>n) return;
			x--; y--;
			for (int i=1; i<=n; i++)
			  for (int j=1; j<=n; j++) map[i][j]=vis[x][i][j];
		}
	}
}

int main()
{
//	freopen("B-small-attempt1.in","r",stdin);
//	freopen("B-small-attempt1.out","w",stdout);
	scanf("%d",&T);
	for (int id=1; id<=T; id++)
	{
		scanf("%d",&n);
		for (int i=1; i<2*n; i++) 
		  for (int j=1; j<=n; j++)
		    scanf("%d",&a[i].a[j]);
		a[2*n].a[n]=-1;
		memset(map,-1,sizeof(map));
		x=1; y=0;
		dfs();
		printf("Case #%d: ",id);
		if (ansy==1) for (int i=1; i<=n; i++) printf("%d ",map[i][ansx]); else
					 for (int i=1; i<=n; i++) printf("%d ",map[ansx][i]); 
		printf("\n");
//		for (int i=1; i<=n; i++)  {for (int j=1; j<=n; j++) cout << map[i][j] << ' '; cout << endl;}
	}
	return 0;
}
