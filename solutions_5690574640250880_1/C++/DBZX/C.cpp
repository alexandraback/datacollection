// C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <map>
#include <set>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cassert>
#include <math.h>

using namespace std;

ifstream in("C-large.in");
ofstream out("out.txt");

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define REP(i,n) FOR(i,0,(n)-1)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define sz size()
template<class T> inline int size(const T& c) { return c.sz; }
#define FORA(i,c) REP(i,size(c))

#define itype(c) __typeof((c).begin())
#define FORE(e,c) for(itype(c) e=(c).begin();e!=(c).end();e++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))
#define CLEAR(x,c) memset(x,c,sizeof(x)) 
#define metafor(c,i) for(i = c.begin();i != c.end();++i)
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//asigna en a el minimo
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//asigna en a el maximo

///LLONG_MAX,INT_MAX
#define INF INT_MAX
char mapa[50][50];
int Y,X,M;
bool bPosible;
void Solve1()
{
	if(X == 1)
	{
		REP(i,M)
			mapa[0][Y-1-i] = '*';

	}
	else
	{
		REP(i,M)
			mapa[X-1-i][0] = '*';
	}
}

void Solve2()
{
	if(M%2 == 1 || M == (X*Y)-2)
	{
		bPosible = false;
		return;
	}

	if(X == 2)
	{
		REP(i,M/2)
		{
			mapa[0][Y-1-i] = '*';
			mapa[1][Y-1-i] = '*';
		}

	}
	else
	{
		REP(i,M/2)
		{
			mapa[X-1-i][0] = '*';
			mapa[X-1-i][1] = '*';
		}
	}
}

void SS(int sX,int sY,int mm)
{
	if(mm == 0)
		return;
	if(sX < sY)///altoo
	{
		if(mm >= sX)
		{
			REP(i,sX)
				mapa[sX-1-i][sY-1]= '*';
			SS(sX,sY-1,mm-sX);
		}
		else
		{
			if(mm == sX-1)
			{
				REP(i,sX-2)
					mapa[sX-1-i][sY-1]= '*';
				mapa[sX-1][sY-2]= '*';
			}
			else
			{
				REP(i,mm)
					mapa[sX-1-i][sY-1]= '*';
			}
		}
	}
	else
	{
		if(mm >= sY)
		{
			REP(i,sY)
				mapa[sX-1][sY-1-i]= '*';
			SS(sX-1,sY,mm-sY);
		}
		else
		{
			if(mm == sY-1)
			{
				REP(i,sY-2)
					mapa[sX-1][sY-1-i]= '*';
				mapa[sX-2][sY-1]= '*';
			}
			else
			{
				REP(i,mm)
					mapa[sX-1][sY-1-i]= '*';
			}
		}
	}

}

void Solve3()
{
	if(M > (X*Y-9))
	{
		int extra = M-(X*Y-9);
		if(extra == 2 || extra == 4 || extra == 6 || extra == 7)
		{
			bPosible = false;
			return;
		}
	}
	SS(X,Y,M);
}

void Solve()
{
	REP(i,50)
	{
		REP(j,50)
		{
			mapa[i][j] = '.';
		}
	}
	mapa[0][0] = 'c';
	bPosible = true;
	bool bTranspose = false;
	if(M == (X*Y)-1)
	{
		//memset(mapa,sizeof(mapa),'*');
		REP(i,50)
		{
			REP(j,50)
			{
				mapa[i][j] = '*';
			}
		}
		mapa[0][0] = 'c';
	}
	else if(X == 1 || Y == 1)
		Solve1();
	else if(X == 2 || Y == 2)
		Solve2();
	else
		Solve3();
	if(bPosible)
	{
		REP(y,Y)
		{
			REP(x,X)
			{
				out << mapa[x][y];
			}
			out << endl;
		}
	}
	else
		out << "Impossible" << endl;
	//	out << n;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int ccc;
	in >> ccc;
	REP(c,ccc)
	{
		in >> Y >> X >> M;
		out << "Case #" << c+1 << ": " << endl;
//		if(c+1 == 154)
			Solve();
/*		else
			out << endl;*/
		
	}	return 0;
}

