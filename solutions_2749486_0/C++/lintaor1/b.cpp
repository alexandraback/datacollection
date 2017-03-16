#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

#define fi first
#define sc second
#define MP make_pair
#define pb push_back
#define PI acos(-1.0) //alternative #define PI (2.0 * acos(0.0))
#define vi vector<int>
#define vii vector<ii>
#define ALL(c) (c).begin(), (c).end()
#define RESET( c,a ) memset( (c), a, sizeof(c) )
#define REP( a,b,c ) for ( int a=b, _c=c; a<_c; ++a )
#define RED( a,b,c ) for ( int a=b, _c=c; a>=_c; --a )
#define REPI( it, c ) for ( __typeof( (c).begin() ) it=(c).begin(); it!=(c).end(); ++it )

const int big = 2000000000;
const double INF = 1e9;
const double EPS = 1e-9;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

//#define _DEBUG 1
#ifdef _DEBUG
	#define DEBUG printf
#else
	#define DEBUG if (0) printf
#endif

// NTU The Lyons' Template
//----------------------------------------------------------------------

int ud[2004][2004];

int dx[] = { 1, 0, -1, 0 },
	dy[] = { 0, 1, 0, -1 };

struct wew
{
	pii loc;
	int path;
};
void findpath( int, int, int );

void solve( int T )
{
	RESET( ud, 0 );
	int X, Y, step=0;
	
	scanf("%d%d", &X, &Y);
	X += 1000;
	Y += 1000;
	//ud[X][Y] = 
	
	queue <wew> q;
	q.push( (wew){MP( 1000,1000 ), -2} );
	
	DEBUG(" %d %d\n", X, Y);
	//return;
	
	while (!q.empty())
	{
		int sz = q.size();
		++step;
		
		DEBUG("> %d:\n", step);
		
		while (sz--)
		{
			wew cur = q.front();
			q.pop();
			
			DEBUG(">> %d %d %d\n", cur.loc.fi, cur.loc.sc, cur.path);
			
			if ((cur.loc.fi<=2000) && (cur.loc.fi>=0) && (cur.loc.sc>=0) && (cur.loc.sc<=2000) && (!ud[cur.loc.fi][cur.loc.sc]))
			{
				ud[cur.loc.fi][cur.loc.sc] = cur.path+1;
				
				if ( (cur.loc.fi == X)  &&  (cur.loc.sc == Y) )
				{
					printf("Case #%d: ", T);
					findpath( X, Y, step-1 );
					printf("\n");
					return;
				}
				
				REP( z,0,4 )
					q.push( (wew){ MP( cur.loc.fi + step*dx[z], cur.loc.sc + step*dy[z] ), z } );
			}
		}
	}
	
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(TT,0,T) solve( TT+1 );
	return 0;
}



void findpath( int x, int y, int step )
{
	DEBUG(">>> %d %d %d => %d\n", x, y, step, ud[x][y]);
	if (step < 0) return;
	if (ud[x][y] != -1)
	{
		findpath( x - step*dx[ud[x][y]-1], y - step*dy[ud[x][y]-1], step-1 );
		switch (ud[x][y])
		{
			case 1 : printf("E"); break;
			case 2 : cout << 'N'; break;
			case 3 : cout << 'W'; break;
			case 4 : cout << 'S'; break;
			default:  break;
		}
	}
}
