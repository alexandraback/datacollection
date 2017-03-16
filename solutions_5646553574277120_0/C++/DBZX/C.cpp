// A.cpp : Defines the entry point for the console application.
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
#include <windows.h>
//#define PROC_NUM 8
bool bDoIt = true;////MULTIPROC
bool RunMultiProc(int argc, _TCHAR* argv[]);
char outName[100] = "out.txt";
int fromProblem = -1, fromProblemNext = INT_MAX;
int theCase;
int totalCases;

//ifstream in("in.txt");
ifstream in("C-small-attempt4.in");

ofstream out;
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

II C,D,V;
typedef II DType;
vector<II> currentCoins;
set<II> currentCoinsSet;

vector<bool> baseReach;
II baseReachCount;
II minVal = V;
int AddReach(vector<bool> &currentReach,const vector<II> &newCoins)
{
	int cc=0;
	FORA(iCoin,newCoins)
	{
		II coin = newCoins[iCoin];
		vector<bool> tmpNewReach = currentReach;
		FORA(i,currentReach)
		{
			if(currentReach[i] && i+coin < currentReach.size() && !currentReach[i+coin])
			{
				tmpNewReach[i+coin] = true;
				++cc;
			}
		}
		currentReach = tmpNewReach;
	}
	return cc;
}
void TestSub(vector<bool> &included,vector<DType> &data)
{
	vector<DType> usedCoins;
	FORA(i,data)
	{
		if(included[i])
			usedCoins.push_back(data[i]);
	}
	if(usedCoins.size() >= minVal)
		return;
	vector<bool> newReach = baseReach;
	II addedCount = AddReach(newReach,usedCoins);
	if(baseReachCount+addedCount==V)
	{
		checkmin(minVal,(II)usedCoins.size());
	}
}

void Test(vector<int> &indexes,vector<DType> &data)
{
	vector<DType> usedCoins;
	FORA(i,indexes)
		usedCoins.push_back(data[indexes[i]]);
	
	vector<bool> newReach = baseReach;
	II addedCount = AddReach(newReach,usedCoins);
	if(baseReachCount+addedCount==V)
	{
		checkmin(minVal,(II)usedCoins.size());
	}


}



void SomeFromVector(int indexPos,vector<int> &indexes,vector<DType> &data)
{
	if(indexPos == indexes.size())
	{
		Test(indexes,data);
		return;
	}
	int faltan = indexes.size()-1-indexPos;
	int base = (indexPos == 0)?0:indexes[indexPos-1]+1;
	///solo elijo indices que me dejen suficientes para elegir del resto
	FOR(i,base,data.size()-faltan-1)
	{
		indexes[indexPos] = i;
		SomeFromVector(indexPos+1,indexes,data);
	}
}

void SomeFromVector(int s,vector<DType> &data)
{
	vector<int> indexes(s);
	SomeFromVector(0,indexes,data);

};


void AllSub(int pos,vector<bool> &included,vector<DType> &data)
{
	if(pos == included.size())
	{
		TestSub(included,data);
		return;
	}
	included[pos] = false;
	AllSub(pos+1,included,data);
	included[pos] = true;
	AllSub(pos+1,included,data);
}

void AllSub(vector<DType> &data)
{
	vector<bool> included(data.size());
	AllSub(0,included,data);
}

void Solve()
{
	in >> C>> D>> V;
	currentCoins.resize(D);
	currentCoinsSet.clear();
	REP(i,D)
	{
		in >> currentCoins[i];
		currentCoinsSet.insert(currentCoins[i]);
	}
	if(!bDoIt /*|| theCase != 1*/)
		return;
	vector<II> data;
	baseReach = vector<bool>(V+1,0);
	baseReach[0] = true;
	baseReachCount = AddReach(baseReach,currentCoins);
	if(baseReachCount == V)
	{
		out << 0;
		return;
	}
	minVal = 5;
	assert(baseReachCount < V);

	/*vector<II> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(4);
	test.push_back(8);
	test.push_back(16);
	vector<bool> newReach = baseReach;
	II addedCount = AddReach(newReach,test);*/
	FOR(i,1,V)
	{
		if(!contains(currentCoinsSet,i))
			data.push_back(i);
	}
//	AllSub(data);
	FOR(i,1,min(5,data.size()))
	{
		SomeFromVector(i,data);
		if(minVal == i)
		{
			out << i;
			return;
		}
	}


	out << minVal;
}

int _tmain(int argc, _TCHAR* argv[])
{
	in >> totalCases;
	if(RunMultiProc(argc, argv))
		return 0;
	out.open(outName);
	//out.open("out.txt");
	out << std::setprecision(15);
	out << std::fixed;
	for(theCase = 0;theCase < totalCases;theCase++)
	{
		bDoIt = (theCase >= fromProblem && theCase < fromProblemNext);
		if(bDoIt){cout << theCase << endl; out << "Case #" << theCase+1 << ": ";	}
		Solve();
		if(bDoIt)out << endl;
	}	
	return 0;
}


bool RunMultiProc(int argc, _TCHAR* argv[])
{
#ifdef PROC_NUM
	if(argc == 1)
	{
		cout << "TOTAL " << totalCases << endl;
		CreateDirectory(L"Tmp",NULL);
		PROCESS_INFORMATION procInfo[PROC_NUM];
		HANDLE waits[PROC_NUM];
		STARTUPINFO s;
		memset(&s,0,sizeof(s));
		REP(i,PROC_NUM )
		{
			s.cb = sizeof(s);
			_TCHAR appExe[1000];
			wsprintf(appExe,L"%s %d",argv[0],i);
			CreateProcess(NULL,appExe,NULL,NULL,FALSE,0,NULL,NULL,&s,&procInfo[i]);
			waits[i] = procInfo[i].hProcess;
		}
		WaitForMultipleObjects(PROC_NUM,waits,TRUE,INFINITE);
		out.open("out.txt");
		REP(i,PROC_NUM)
		{
			char inName[100];
			sprintf(inName,"Tmp\\out%d.txt",i);
			ifstream tmpIn(inName);
			char line[10000];
			while(!tmpIn.getline(line,10000).fail())
				out << line << endl;
		}
		return true;
	}
	int thisProc;
	swscanf(argv[1],L"%d",&thisProc);
	int probPerProc = totalCases/PROC_NUM;
	if(totalCases%PROC_NUM != 0)
		++probPerProc;
	fromProblem = thisProc*probPerProc;fromProblemNext = (thisProc+1)*probPerProc;
	sprintf(outName,"Tmp\\out%d.txt",thisProc);
#endif
	return false;
}
