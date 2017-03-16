#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;


char vis[4][4];

set<string> viss;
char d[] = "urdl";
int dr[] = {-1,0,1,0,0};
int dc[] = {0,1,0,-1,0};

vector<string> allShape[5];
void i_dont_fking(string cur)
{
	if (viss.find(cur) != viss.end())
		return;
	viss.insert(cur);

	allShape[cur.size()].push_back(cur);
	if (cur.size() == 4)
	{
		return;
	}

	for (int i = 0 ; i < 4; ++i)
	{		
		i_dont_fking(cur+d[i]);
	}
}

int X , R,C;

char ok(int i, int j, string& path)
{
	for(int a = 0 ; a < path.size(); ++a)
	{
		int v;
		for (v = 0 ; v < 4; ++v)
			if (path[a] == d[v]) break;
		i += dr[v];
		j += dc[v];
		if ( i < 0 || i >= R ||
			 j < 0 || j >= C ||
			 vis[i][j] )
			 return 0;
	}

	return 1;
}

void draw(int i, int j, string& path, char c)
{
	for(int a = 0 ; a < path.size(); ++a)
	{
		int v;
		for (v = 0 ; v < 4; ++v)
			if (path[a] == d[v]) break;
		i += dr[v];
		j += dc[v];

		vis[i][j] = c;
	}
}

char play()
{
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			for (int a = 0; a < allShape[X].size(); ++a)
			{
				if (ok(i,j, allShape[X][a]))
				{
					draw(i,j, allShape[X][a],'a');
					if (!play())
					{
						draw(i,j, allShape[X][a],0);
						return 1;
					}
					draw(i,j, allShape[X][a],0);
				}
			}
		}
	}

	return 0;
}

int main()
{	
	i_dont_fking("*");

	int Case, cases = 0;
	scanf("%d" , &Case);

	while (Case--)
	{
		
		cin >> X >> R >> C;

		char;
		memset(vis,0,sizeof(vis));
		
		char ans = 0;
		//printf("Case #%d: %d\n" , ++cases, ans);
		
		//hmm
		if ( X == 1 )
			ans = 1;
		else if ( X == 2 )
		{
			ans = R%2 == 0 || C%2 == 0;
		}
		else if (X == 3)
		{
			ans = (R%2==0  && C%3 == 0) ||
				  (R%3==0  && C%2 == 0) ||
				  (R%3==0  && C%3 == 0);
		}
		else if (X == 4)
		{
			ans = (R%4==0  && C%3 == 0) ||
				  (R%3==0  && C%4 == 0) ||
				  (R%4==0  && C%4 == 0);
		}

		printf("Case #%d: %s\n" , ++cases, ans? "GABRIEL":"RICHARD");
		
	}

	return 0;
}
