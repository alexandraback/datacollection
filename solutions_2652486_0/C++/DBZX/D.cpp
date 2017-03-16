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

ifstream in("C-small-1-attempt0.in");
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
#define bitN(X) (1<<(X))//bit enesimo
#define bitN64(X) (((int64)(1))<<(X))////bit enesimo int 64
#define contain(S,X) (((S)&bitN(X))!=0)//tiene el bit
///LLONG_MAX,INT_MAX
#define INF INT_MAX
int N,M,R,K;


typedef vector<int> Cards;
//#define Cards vector<int> 

Cards cards;

map<Cards,map<int,int> > data;

void Test()
{
	map<int,int> &m = data[cards];
	int setCount = 1 << N;
	REP(s,setCount)
	{
		int val = 1;
		REP(j,N)
		{
			if(contain(s,j))
				val *= cards[j];
		}
		++m[val];
	}

}
void Calc(int pos)
{
	if(pos == N)
	{
		Test();
		return;
	}
	FOR(i,2,M)
	{
		cards[pos] = i;
		Calc(pos+1);
	}

}

void Solve()
{
	cards = vector<int> (N);
	Calc(0);
	//	out << n;
}
vector<int> prod;

int Err(map<int,int> &mdata,map<int,int> &m)
{
	map<int,int>::iterator it;
	int res = 0;
	metafor(m,it)
	{
		if(it->second != 0)
		{
			if(mdata[it->first] == 0)
				return INF;
			res += abs(mdata[it->first]-it->second);
		}

	}
	return res;

}

void Choose(map<int,int> &mm)
{
	int winnerVal = INF;
	Cards winner;
	//map<Cards,map<int,int> > 
	map<Cards,map<int,int> >::iterator it;// = data.begin();
	metafor(data,it)
	{
		int val = Err(it->second,mm);
		if(val < winnerVal)
		{
			val = winnerVal; 
			winner = it->first;
		}
	}
	out << endl;
	REP(i,N)
	{
		out << winner[i];
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	int ccc;
	in >> ccc;
	cout << ccc << endl;
	REP(c,ccc)
	{
		in >> R >> N >> M >> K;
		out << "Case #" << c+1 << ": ";

		Solve();
		prod.resize(K);
		REP(i,R)
		{
			map<int,int> mm;
			REP(j,K)
			{
				in >> prod[j];
				++mm[prod[j]];
			}
			Choose(mm);

			
		}
		cout << c << endl;
		out << endl;
	}	return 0;
}

