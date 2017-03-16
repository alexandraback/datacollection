#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>


#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;

inline long double get_time(){   
	return (long double)clock()/CLOCKS_PER_SEC;
};

int board[100][100];
int wantboard[100][100];
int n, m;

void resetboard()
{
	fill(&board[0][0], &board[99][100], 100);
	fill(&wantboard[0][0], &wantboard[100][100], 100);
}

bool cancol(int j, int h)
{
	for (int i = 0; i < n; ++i)
	{
		if (wantboard[i][j] > h) return false;
	}
	return true;
}
bool canrow(int i, int h)
{
	for (int j = 0; j < m; ++j)
	{
		if (wantboard[i][j] > h) return false;
	}
	return true;
}
void makerow(int i, int h)
{
	for (int j = 0; j < m; ++j) board[i][j] = h;
}
void makecol(int j, int h)
{
	for(int i = 0; i < n; ++i) board[i][j] = h;
}

int main()
{
	freopen("Lawnmower.in","r",stdin);
	freopen("Lawnmower.out","w",stdout);
	//program
	int tests;
	scanf("%d\n", &tests);
	for (int Case = 1; Case <= tests; Case++)
	{
		set <int> hset;
		priority_queue <int> hq;
		resetboard();
		bool res = true;
		scanf("%d %d\n", &n, &m);
		for (int i = 0; i < n; ++i)	{
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &wantboard[i][j]);
				if (hset.count(wantboard[i][j]) == 0)
				{
					hset.insert(wantboard[i][j]);
					hq.push(wantboard[i][j]);
				}
			}
		}
		while (!hq.empty())
		{
			int h = hq.top();
			hq.pop();
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					if (wantboard[i][j] == h)
					{
						if (cancol(j, h)) makecol(j, h);
						if (canrow(i, h)) makerow(i, h);
					}
				}
			}
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (wantboard[i][j] != board[i][j]) res = false;
		printf("Case #%d: %s\n", Case, res ? "YES":"NO");
	}


	//end program
	return 0;
}






