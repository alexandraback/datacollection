// B.cpp : Defines the entry point for the console application.
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
#include <iomanip>

using namespace std;

ifstream in("B-large.in");
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

void Solve()
{
	double C,F,X;
	in >> C >> F >> X;
	double currentFarmBuyTime = 0;
	double currentSpeed = 2;
	double lastTry = X/2;

	while(true)
	{
		currentFarmBuyTime += C/currentSpeed;
		currentSpeed += F;
		double newTry = currentFarmBuyTime+X/currentSpeed;
		if(newTry > lastTry)
		{
			out << lastTry;
			return;
		}
		lastTry = newTry;
	}




	//T
	
	//	out << n;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int ccc;
	in >> ccc;
	out << std::fixed;
	out << std::setprecision(8);
	REP(c,ccc)
	{
		out << "Case #" << c+1 << ": ";
		Solve();
		out << endl;
	}	return 0;
}

