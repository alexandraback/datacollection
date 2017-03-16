#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stdlib.h>
#include <sstream>
#include <assert.h>

#include <time.h>
#pragma comment(linker, "/STACK:20000000")

#define fr(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define fd(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define mp make_pair
#define pb push_back
#define ll long long

using namespace std;

int ri(){int x;scanf("%d",&x);return x;}
ll rll(){ll x;scanf("%lld",&x);return x;}

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
string D = "SNEW";
int mas[205][205][205];
int parent[205][205][205];

void solve()
{
	int ntest = ri();
	fr(test,1,ntest)
	{
		int x = ri(), y = ri();
		swap(x,y);
		x+=100,y+=100;
		queue<pair<int,int> > st;
		st.push(mp(100,100));
		memset(mas,-1,sizeof(mas));
		memset(parent,-1,sizeof(parent));
		mas[0][100][100] = 0;
		int step = 0;
		while(!st.empty())
		{
			step++;
			for(int a = 0,maxa = st.size();a < maxa;a++)
			{
				pair<int,int> v = st.front();
				st.pop();
				fr(i,0,3)
				{
					int xx = v.first + step*dx[i],yy = v.second + step*dy[i];
					if (xx>=0 && xx<=200 && yy>=0 && yy<=200 && mas[step][xx][yy]==-1)
					{
						mas[step][xx][yy] = mas[step][v.first][v.second] + 1;
						parent[step][xx][yy] = i;
						st.push(mp(xx,yy));
					}
				}
			}
			if (mas[step][x][y] != -1)
				break;
		}
		string path;
		pair<int,int> v(x,y);
		while(step)
		{
			int a = parent[step][v.first][v.second];
			v.first-=step*dx[a];
			v.second-=step*dy[a];
			step--;
			path.pb(D[a]);
		}
		reverse(path.begin(),path.end());
		int xx = 100,yy = 100;
		step = 1;
		fr(i,0,(int)path.size()-1)
		{
			if (path[i] == 'N')
				xx+=step;
			else
			if (path[i] == 'S')
				xx-=step;
			else
			if (path[i] == 'W')
				yy-=step;
			else
			if (path[i] == 'E')
				yy+=step;
			step++;
		}
		printf("Case #%d: %s\n",test,path.c_str());
	}


}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("C:/Users/CleRIC/Desktop/Универ/acm.timus.ru/input.txt","rt",stdin);
		freopen("C:/Users/CleRIC/Desktop/Универ/acm.timus.ru/output.txt","wt",stdout);
	#else
		//freopen("input.in","rt",stdin);
		//freopen("output.out","wt",stdout);
	#endif

	solve();

	#ifndef ONLINE_JUDGE
		printf("\n\ntime-%.3lf",clock()*1e-3);
	#endif

	return 0;
}