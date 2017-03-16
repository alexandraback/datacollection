// D.cpp : Defines the entry point for the console application.
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

ifstream in("D-large.in");
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
#define amfor(Iterator, Container) 	for ( auto Iterator = begin(Container); (Iterator) != end(Container); ++(Iterator) )

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//asigna en a el minimo
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//asigna en a el maximo

///LLONG_MAX,INT_MAX
#define INF INT_MAX
int N;
int WinA(vector<char> data)
{
	int b = 0;
	int wins = 0;
	REP(i,data.size())
	{
		int val = data[i];
		if(val == 0)
		{
			if(b == 0)
				wins++;
			else
				--b;
		}
		else
			++b;
	}
	return wins;
}
void Solve()
{
	in >> N;
	set<pair<double,char> > input;
	REP(i,N)
	{
		double block;
		in >> block;
		input.insert(make_pair(1-block,0));
	}
	REP(i,N)
	{
		double block;
		in >> block;
		input.insert(make_pair(1-block,1));
	}
	vector<char> data;
	amfor(it,input)
	{
		data.push_back(it->second);
	}
	int wa = WinA(data);
	reverse(all(data));
	int wb = WinA(data);
	out << (N-wb) << " " << wa;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int ccc;
	in >> ccc;
	REP(c,ccc)
	{
		out << "Case #" << c+1 << ": ";
		Solve();
		out << endl;
	}	return 0;
}

