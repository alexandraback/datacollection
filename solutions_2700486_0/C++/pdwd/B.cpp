#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

#define MR 110
#define ZERO 55

double t[MR][MR];
int N, X, Y;
bool done[MR][MR];

pair <int, int> go(int x, int y, int dir)
{	
	while(!done[x+dir][y-1] && y)
	{
		x += dir;
		y--;
	}
	return MP(x,y);
}

void simulate(int mask, double p)	//0-left, 1 - rigt
{	
	vector < pair < int, int > > v;
	done[ZERO][0] = 1;
	v.PB(MP(ZERO,0));
	t[ZERO][0] = 1;
	REP(i,N-1)
	{
		int x = ZERO, y = 20;		
		pair < int, int > end(x,y);
		while(true)
		{
			y--;				//firstly we go down vertically
			if(done[x][y-2])	//collision
			{
				if(!done[x+1][y-1] && !done[x-1][y-1])
				{					
					if(mask&(1<<i))	 //try right
						end = go(x,y,1);
					else			 //try left
						end = go(x,y,-1);
				}
				else	//only one or no ways are free
				{
					pair < int, int > old = MP(x,y);
					end = go(x,y,1);	//right
					if(end == old)		//only left is probable
						end = go(x,y,-1);
				}
				break;
			}
		}
		t[end.ST][end.ND] += p;
		done[end.ST][end.ND] = 1;
		v.PB(end);
	}
	REP(i,N)	//clean
		done[v[i].ST][v[i].ND] = 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(c,T)
	{		
		scanf("%d%d%d", &N, &X, &Y);
		int ile = 1<<(N-1);
		double p = 1/(double)ile;
		REP(mask, ile) simulate(mask, p);
		printf("Case #%d: %lf\n", c+1, (X+ZERO >= 0 && X+ZERO < MR && Y < MR? t[X+ZERO][Y] : 0));
		memset(t,0,sizeof(t));
	}
	return 0;
}