/*************************
* Stanislaw Szczesniak   *
*2013.luty, out_constest *
*************************/

#include <utility>
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string.h>
#include <tr1/functional>
#include <stack>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <list>
#include <cassert>
#include <numeric>

#define DEBUG(x) printf ("debug%d\n", x);
#define ST first
#define ND second
#define PB push_back
#define PPB pop_back
#define MP make_pair
#define PF push_front
#define PPF pop_front
#define FOR(x,b,e) for (int x=b; x<=(e);x++)
#define FORD(x,b,e) for (int x=b;x>=(e);x--)
#define REP(x,n) for (int x=0;x<(n);x++)
#define DET(a,b,c) (((LL)(b.x-a.x))*(c.y-a.y) - ((LL)(b.y-a.y))*(c.x-a.x))
#define INARR(arr, i, n) REP(i,n) scanf ("%d",&arr[i]);
#define VAR(v,n) __typeof(n) v = n
#define FOREACH(i,c) for (VAR(i,c.begin()); i != c.end(); i++) 
#define SIZE(x) ((int)(x).size())
#define NL printf ("\n")
#define MAXN 1000001
#define IY -1

using namespace std;
using std::tr1::hash;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef long long LL;
typedef priority_queue<PII> PQII;

struct matrix
{
	int arr[4][4];
};

int res (matrix a)
{
	int x,y,t;
	REP(i,4)
	{
		x=y=t=0;
		REP(j,4)
		{
			if (a.arr[i][j] == 0)
				t++;
			else if (a.arr[i][j] == 1)
				x++;
			else if (a.arr[i][j] == 2)
				y++;
		}
		if (t == 1)
		{
			if (x == 3)
				return 1;
			else if (y == 3)
				return 2;
		}
		else
		{
			if (x == 4)
				return 1;
			else if (y == 4)
				return 2;
		}
			
		
	}
	REP(i,4)
	{
		x=y=t=0;
		REP(j,4)
		{
			if (a.arr[j][i] == 0)
				t++;
			else if (a.arr[j][i] == 1)
				x++;
			else if (a.arr[j][i] == 2)
				y++;
		}
		if (t == 1)
		{
			if (x == 3)
				return 1;
			else if (y == 3)
				return 2;
		}
		else
		{
			if (x == 4)
				return 1;
			else if (y == 4)
				return 2;
		}
			
		
	}
	x=y=t=0;
	REP(i,4)
	{
		if (a.arr[i][i] == 0)
			t++;
		else if (a.arr[i][i] == 1)
			x++;
		else if (a.arr[i][i] == 2)
			y++;

	}
	if (t == 1)
	{
		if (x == 3)
			return 1;
		else if (y == 3)
			return 2;
	}
	else
	{
		if (x == 4)
			return 1;
		else if (y == 4)
			return 2;
	}
	x=y=t=0;
	REP(i,4)
	{
		if (a.arr[i][3-i] == 0)
			t++;
		else if (a.arr[i][3-i] == 1)
			x++;
		else if (a.arr[i][3-i] == 2)
			y++;

	}
	if (t == 1)
	{
		if (x == 3)
			return 1;
		else if (y == 3)
			return 2;
	}
	else
	{
		if (x == 4)
			return 1;
		else if (y == 4)
			return 2;
	}

	int l = 0;
	REP(i,4)
	{
		REP(j,4)
		{
			if (a.arr[i][j]  <= 2)
				l++;
		}
	}
	if (l < 16)
		return 3;
	else
		return 0;

}

int main () 
{
	int n;
	char tmp;
	scanf("%d", &n);
	REP(i,n)
	{
		matrix a;
		REP(j,4)
		{
			REP(k,4)
			{
				cin>>tmp;
				if (tmp == 'X')
					a.arr[j][k] = 1;
				else if (tmp == 'O') 
					a.arr[j][k] = 2;
				else if (tmp == 'T')
					a.arr[j][k] = 0;
				else
					a.arr[j][k] = 3;
			}
		}
		int cus = res(a);
		printf("Case #%d: ", i+1);
		if (cus == 1)
			printf("X won\n");
		else if (cus == 2)
			printf("O won\n");
		else if (cus == 3)
			printf("Game has not completed\n");
		else
			printf("Draw\n");
			
				
	}
}
