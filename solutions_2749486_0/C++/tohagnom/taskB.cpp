#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <memory.h>

using namespace std;

#define x first
#define y second
#define ll long long
#define ld long double
#define pii pair<int, int>

const int qS=2000000;

string d[400][400];
bool inQ[400][400];
pii q[qS];
const int SX=200,SY=200;

int main()
{
	int T;
	cin >> T;
	for(int step=1; step<=T; ++step)
	{
		memset(inQ,0,sizeof(inQ)*sizeof(bool));
		int l=0, r=0;
		q[r++]=pii(SX,SY);
		int x,y;
		cin >> x >> y;
		x+=SX, y+=SY;
		d[SX][SY]="";
		inQ[SX][SY]=true;
		int dx[4]={1,0,-1,0};
		int dy[4]={0,1,0,-1};
		char dir[4]={'E','N','W','S'};
		while(l!=r)
		{
			pii u=q[l++];
			int len=d[u.x][u.y].length()+1;
			for(int i=0; i<4; ++i)
			{
				int ni=u.x+dx[i]*len;
				int nj=u.y+dy[i]*len;
				if(ni<0 || nj<0 || ni>=400 || nj>=400 || inQ[ni][nj])
					continue;
				inQ[ni][nj]=true;
				d[ni][nj]=d[u.x][u.y]+dir[i];
				q[r++]=pii(ni,nj);
			}
		}
		cout << "Case #" << step << ": " << d[x][y] << endl;
	}
}
