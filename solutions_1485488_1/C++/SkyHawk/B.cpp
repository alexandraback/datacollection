//SkyHawk, CMC MSU

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

#define FOR(i,n) for(int i = 0;i < n;++i)
#define PII pair<int,int>
#define EPS 1e-9
#define INF 1000000000

int ar[1000];
int ruk[1000010];

int cel[110][110];
int flor[110][110];
int t[110][110];
int h,n,m;

inline int canmove(int i1,int j1,int i2,int j2,int wat)
{
	if(i2>=n || i2<0 || j2>=m ||j2<0)
		return -1;
	if(!((cel[i2][j2]-flor[i2][j2]>=50)
		&& cel[i2][j2]-flor[i1][j1]>=50 && cel[i1][j1]-flor[i2][j2]>=50))
		return -1;
	if(cel[i2][j2]-wat >=50)
		return 0;
	return (wat-(cel[i2][j2]-50));
}

int used[110][110];
int last[110][110];

inline pair<int,int> findmin()
{
	int minv = INF;
	int mini = 0,minj = 0;
	FOR(i,n)
		FOR(j,m)
			if(!used[i][j] && t[i][j]<minv)
			{
				minv = t[i][j];
				mini = i;
				minj = j;
			}
	return make_pair(mini,minj);
}

void deikstra()
{
	FOR(i,n*m)
	{
		pair<int,int> v = findmin();
		int x = v.first;
		int y = v.second;
		used[x][y] = 1;
		int t0 = canmove(x,y,x+1,y,h-t[x][y]);
		if(t0>=0 && t[x+1][y]>t0+t[x][y]+((h-t[x][y]-t0-flor[x][y])>=20?10:100))
		{
			t[x+1][y]=t0+t[x][y]+((h-t[x][y]-t0-flor[x][y])>=20?10:100);
			//last[x+1][y] = (h-t[x][y])>=20?10:100;
		}
		t0 = canmove(x,y,x-1,y,h-t[x][y]);
		if(t0>=0 && t[x-1][y]>t0+t[x][y]+((h-t[x][y]-t0-flor[x][y])>=20?10:100))
		{
			t[x-1][y]=t0+t[x][y]+((h-t[x][y]-t0-flor[x][y])>=20?10:100);
			//last[x-1][y] = (h-t[x][y])>=20?10:100;
		}
		t0 = canmove(x,y,x,y+1,h-t[x][y]);
		if(t0>=0 && t[x][y+1]>t0+t[x][y]+((h-t[x][y]-t0-flor[x][y])>=20?10:100))
		{
			t[x][y+1]=t0+t[x][y]+((h-t[x][y]-t0-flor[x][y])>=20?10:100);
			//last[x][y+1] = (h-t[x][y]-t0-flor[x][y])>=20?10:100;
		}
		t0 = canmove(x,y,x,y-1,h-t[x][y]);
		if(t0>=0 && t[x][y-1]>t0+t[x][y]+((h-t[x][y]-t0-flor[x][y])>=20?10:100))
		{
			t[x][y-1]=t0+t[x][y]+((h-t[x][y]-t0-flor[x][y])>=20?10:100);
			//last[x][y-1] = (h-t[x][y])>=20?10:100;
		}
	}
}

void dfs(int i,int j)
{
	t[i][j] = 0;
	if(canmove(i,j,i+1,j,h)==0 && t[i+1][j])
		dfs(i+1,j);
	if(canmove(i,j,i-1,j,h)==0 && t[i-1][j])
		dfs(i-1,j);
	if(canmove(i,j,i,j+1,h)==0 && t[i][j+1])
		dfs(i,j+1);
	if(canmove(i,j,i,j-1,h)==0 && t[i][j-1])
		dfs(i,j-1);
}

int main(int argc, char** argv)
{
	freopen("INPUT.TXT","r",stdin);
	freopen("OUTPUT.TXT","w",stdout);
	int tests;
	cin >> tests;
	FOR(count,tests)
	{
		cout << "Case #" << count+1 << ": ";
		FOR(i,110)
			FOR(j,110)
				used[i][j] = 0;
		cin >> h >> n >> m;
		FOR(i,n)
			FOR(j,m)
				cin >> cel[i][j];
		FOR(i,n)
			FOR(j,m)
				cin >> flor[i][j];
		FOR(i,n)
			FOR(j,m)
				t[i][j] = INF;
		dfs(0,0);
		deikstra();
		cout << t[n-1][m-1]/10 << "." << t[n-1][m-1]%10 << endl;
	}
	return 0;
}
