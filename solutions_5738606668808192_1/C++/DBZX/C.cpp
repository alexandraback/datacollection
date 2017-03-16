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

ifstream in("in.txt");
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
typedef ttmath::Int<6> ii;

#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))

///typedef ttmath::Int<10> II;///640 bits
typedef __int64 II;
//typedef ttmath::Big<1,10> DD;/// 64 exp ,640bits mant
typedef double DD;
#define INF LLONG_MAX
int N = 32;
int J = 500;
/*int N = 6;
int J = 3;*/
/*int N = 16;
int J = 50;*/

////Primmos

#define MAX_PRIMES 5000010
//#define MAX_PRIMES 100
bool isPrime[MAX_PRIMES];
set<__int64> primos;

bool IsPrime(ii n)
{
	/*if(contains(primos,n))
		return true;*/
//__int64  ns = sqrt((double)n)+1;
	amfor(it,primos)
	{
		if(n == *it)
			return true;
		if((n % *it) == 0)
			return false;
	}
	return true;
}
void InitPrim()
{
	///Genero primos
	REP(i,MAX_PRIMES)
		isPrime[i] = true;
	for(int i=2;i < MAX_PRIMES;++i)
	{
		if(isPrime[i])
		{///Piso no primos
			for(int j = 2*i;j < MAX_PRIMES;j+=i)
				isPrime[j] = false;
		}
	}
	for(int i=2;i < MAX_PRIMES;++i)
	{
		if(isPrime[i])
			primos.insert(i);
	}

}


vector<__int64> InBase(ii num,__int64 base)
{
	vector<__int64> res;
	while(num >= base)
	{
		ii rem = num%base;
		num /= base;
		res.push_back(rem.ToInt());
	}	
	res.push_back(num.ToInt());
	REVERSE(res);
	return res;
}

ii FromBase(vector<__int64> &num,__int64 base)
{
	ii nn = 0;
	REP(n,num.size()-1)
	{
		nn += num[n];
		nn *= base;
	}
	nn += num[num.size()-1];
	return nn;
}


__int64 FindDivisor(ii n)
{
	amfor(it,primos)
	{
		if((n % *it) == 0)
			return *it;
	}
}

vector<__int64> divisors(20);
bool Check(ii num)
{
	vector<__int64> numDig = InBase(num,2);
	for(int i = 2;i <= 10;++i)
	{
		ii test = FromBase(numDig,i);
		if(IsPrime(test))
			return false;
		else
			divisors[i] = FindDivisor(test);
	}
}

void Solve()
{
	out << "Case #1:" << endl;
	InitPrim();
	int count = 0;
	ii num = 2;
	for(int i = 0;i< N-2;++i)
		num*=2;
	num++;
	
	while(count < J)
	{
		if(Check(num))
		{
			vector<__int64> numDig = InBase(num,2);
			amfor(it,numDig)
				out << *it;
			out << " ";
			for(int i = 2;i <= 10;++i)
				out << " " << divisors[i];
			out << endl;
			++count;
		}
		num+=2;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	out.open(outName);
/*	in >> totalCases;
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
	}	*/
	Solve();
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
