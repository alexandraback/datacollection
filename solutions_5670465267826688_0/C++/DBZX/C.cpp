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
//http://www.ttmath.org/
#include "ttmath\ttmath.h"

using namespace std;

ifstream in("C-small-attempt0.in");
ofstream out("out.txt");
///LLONG_MAX,INT_MA
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
#define amfor(Iterator, Container) 	for ( auto Iterator = begin(Container); (Iterator) != end(Container); ++(Iterator) )
#define ramfor(Iterator, Container) for ( auto Iterator = Container.rbegin(); (Iterator) != Container.rend(); ++(Iterator) )
template<class C, class E> inline bool contains(const C& container, const E& element){	return container.find(element) != container.end() ;}

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//asigna en a el minimo
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//asigna en a el maximo

///typedef ttmath::Int<10> ii;

#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))

///typedef ttmath::Int<10> II;///640 bits
typedef __int64 II;
//typedef ttmath::Big<1,10> DD;/// 64 exp ,640bits mant
typedef double DD;
#define INF LLONG_MAX


///1= 1,i= 2,j = 3 , k = 4
char multMat[5][5]= {{0,0,0,0,0},/*1*/{0,1,2,3,4},/*i*/{0,2,-1,4,-3},/*j*/{0,3,-4,-1,2},/*k*/{0,4,3,-2,-1}};

char Mult(char a,char b)
{
	assert(a != 0 && b != 0);
	if(a < 0 == b < 0)
		return multMat[abs(a)][abs(b)];
	else
		return -multMat[abs(a)][abs(b)];
}




bool Solve()
{
	//	out << n;
	__int64 L,X;
	in >> L >> X;
	vector<char> data(L);
	char totalData = 1;
	REP(i,L)
	{
		char c;
		in >> c;
		data[i] = c - 'i' + 2;
		totalData = Mult(totalData,data[i]);
	}
	int totalToMult = X % 4;
	int total = 1;
	REP(i,totalToMult)
		total = Mult(total,totalData);
	if(total != -1)
		return false;
	__int64 firstI = INF;
	char firstMult[4];
	firstMult[0] = 1;
	FOR(i,1,3)
		firstMult[i] = Mult(firstMult[i-1],totalData);

	char current = 1;
	REP(i,L+1)
	{
		REP(j,4)
		{
			char r = Mult(firstMult[j],current);
			if(r == 2)
				checkmin(firstI,i+L*j);
		}
		if(i != L)
			current = Mult(current,data[i]);
	}
	if(firstI == INF)
		return false;





	__int64 firstK = INF;
	firstMult[0] = 1;
	FOR(i,1,3)
		firstMult[i] = Mult(totalData,firstMult[i-1]);
	current = 1;
	REP(i,L+1)
	{
		REP(j,4)
		{
			char r = Mult(current,firstMult[j]);
			if(r == 4)
				checkmin(firstK,i+L*j);
		}
		if(i != L)
			current = Mult(data[(L-1)-i],current);
	}
	if(firstK == INF)
		return false;

	return firstI + firstK  <= L*X;


}

int _tmain(int argc, _TCHAR* argv[])
{
	int ccc;
	in >> ccc;
	cout << ccc << endl;
	out << std::setprecision(15);
	out << std::fixed;

	REP(c,ccc)
	{
		cout << c << endl;
		out << "Case #" << c+1 << ": ";
		out << (Solve()?"YES":"NO");
		out << endl;
	}	return 0;
}

