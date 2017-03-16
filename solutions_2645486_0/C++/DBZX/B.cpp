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

using namespace std;

ifstream in("B-small-attempt0.in");
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

int E,R,N;
vector<int>  values;
vector<int> gasto; 
int winner = 0;
int Gain()
{
	int res=0;
	int En = E;
	REP(i,N)
	{
		if(gasto[i] > En)
			return 0;///no tengo
		res += gasto[i]*values[i];
		En -= gasto[i];
		En += R;
		if(En > E)
			En = E;
	}
	return res;
}
void Test()
{
	checkmax(winner,Gain());
}

void Solve(int pos)
{
	if(pos == N)
	{
		Test();
		return;
	}
	REP(j,E+1)
	{
		gasto[pos] = j;
		Solve(pos+1);
	}
	
}
void Solve()
{
	winner = 0;
	gasto = vector<int>(N,0) ;
	Solve(0);


	out << winner;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int ccc;
	in >> ccc;
	cout << ccc << endl;
	REP(c,ccc)
	{
		in >> E >> R >> N;
		values.resize(N);
		REP(i,N)
			in >> values[i];
		cout << c << endl;
		out << "Case #" << c+1 << ": ";
		Solve();
		out << endl;
	}	return 0;
}

