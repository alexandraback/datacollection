#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <bitset>
#include <list>

#define EPS 1e-11
#define PI M_PI
#define LL long long
#define INF 2123123123
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define swap(a,b) a=a^b, b=a^b, a=a^b;
#define OPENR(a) freopen(a,"r",stdin)
#define OPENW(a) freopen(a,"w",stdout)

int x4[4] = { 0, 0,-1, 1};
int y4[4] = {-1, 1, 0, 0};
int x8[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int y8[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
int xhorse[8] = {1,2,1,2,-1,-2,-1,-2};
int yhorse[8] = {2,1,-2,-1,2,1,-2,-1};
int ax[3] = {-1,-1,0};
int ay[3] = {0,-1,-1};


using namespace std;

#define MAXN 55

int t,r,c,m;
int ar[MAXN][MAXN]; //-1,0,1
bool ada;

void print(int tc)
{
	printf("Case #%d:\n",tc);
	if (!ada)
	{
		printf("Impossible\n");
		return;
;	}
	
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			if (i==0 && j==0) printf("c");
			else if (ar[i][j]==-1) printf("*");
			else printf(".");
		}
		printf("\n");
	}
}

void dfs(int mine)
{
	/*
	printf("dfs(%d)\n",mine);
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			printf("%2d",ar[i][j]);
		}
		printf("\n");
	}*/
	
	if (mine==m)
	{
		ada = true;
		return;
	}
	
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			if (ar[i][j]==1)
			{
				//proc
				vector<pair<int,int> > v; v.clear();
				int change = 0;
				for (int k=0;k<8;k++)
				{
					int nextx = i+x8[k];
					int nexty = j+y8[k];
					if (nextx<0 || nextx>=r || nexty<0 || nexty>=c) continue;
					if (ar[nextx][nexty]==-1)
					{
						v.PB(MP(nextx,nexty));
						ar[nextx][nexty] = 1;
						change++;
					}
				}
				ar[i][j] = 0;
				if (mine-change>=m) dfs(mine-change);
				
				if (ada) break;
				//rollback
				ar[i][j] = 1;
				for (int k=0;k<v.size();k++) ar[v[k].first][v[k].second] = -1;
			}
		}
		if (ada) break;
	}
}

int main()
{
	OPENR("C-small-attempt1.in");
	OPENW("C-small-attempt1.out");
	
	scanf("%d",&t);
	
	for (int tc=1;tc<=t;tc++)
	{
		scanf("%d %d %d",&r,&c,&m);
		
		ada = false;
		memset(ar,-1,sizeof(ar));
		ar[0][0] = 1;
		
		dfs(r*c-1);
		
		print(tc);
	}
	
 	return 0;
}



