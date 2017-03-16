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

ifstream in("A-small-attempt1.in");
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

II N;

vector<__int64> InBase(__int64 num,__int64 base)
{
	vector<__int64> res;
	while(num >= base)
	{
		__int64 rem = num%base;
		num /= base;
		res.push_back(rem);
	}	
	res.push_back(num);
	REVERSE(res);
	return res;
}
__int64 FromBase(vector<__int64> &num,__int64 base)
{
	__int64 nn = 0;
	REP(n,num.size()-1)
	{
		nn += num[n];
		nn *= base;
	}
	nn += num[num.size()-1];
	return nn;
}

II Revert(II a)
{
	vector<__int64> digitsTmp = InBase(a,10);
	reverse(all(digitsTmp));
	return FromBase(digitsTmp,10);
}
II RevertFast(II num)
{
	II res=0;
	while(num >= 10)
	{
		__int64 rem = num%10;
		num /= 10;
		res+= rem;
		res*=10;
		
	}	
	res+= num;
	return res;
}
/*
void Solve()
{
	in >> N;
	if(!bDoIt)
		return;
	if(N <= 20)
	{
		out << N;
		return;
	}
	II currNum = 1;
	II count = 1;///dije 1
	vector<__int64> digits = InBase(N,10);
	///Llego a 1 0000 donde  0000 es digits.size()-1
	currNum = 10;
	count = 10;
	II curr0 = 1;
	II meta = 100;
	///currNum siempre arranca en 1000..
	while(curr0 < digits.size()-1)
	{
		///sumo 9
		currNum += 9;
		assert(currNum<N);
		count+=9;
		///inv
		++count;
		vector<__int64> digitsTmp = InBase(currNum,10);
		reverse(all(digitsTmp));
		currNum = FromBase(digitsTmp,10);
		assert(currNum<N);

		count += meta-currNum;
		currNum = meta;
		assert(currNum<=N);
		curr0++;
		meta *= 10;
	}
	II posible =count+(N-currNum);

	vector<__int64> digitsRev;
	REP(i,digits.size()/2)
		digitsRev.push_back(digits[i]);
	reverse(all(digitsRev));//primeros digitos
	II newNum = FromBase(digitsRev,10);
	if(newNum != 1)
	{
		if(digits[digits.size()-1] != 0)
		{
			count += newNum;
			currNum += newNum;

			++count;
			currNum = Revert(currNum);
			assert(currNum<=N);
			count += N-currNum;
		}
		else
		{
			vector<__int64> digitsRev2;
			REP(i,digits.size()/2)
				digitsRev2.push_back(digits[i]);
			II newNum = FromBase(digitsRev2,10);
			--newNum;
			digitsRev2 = InBase(newNum,10);
			reverse(all(digitsRev2));//primeros digitos
			II delta = FromBase(digitsRev2,10);
			count += delta;
			currNum += delta;
			assert(currNum<N);
			++count;
			currNum = Revert(currNum);
			assert(currNum<=N);
			count += N-currNum;
		}
	}
	else
	{
		count += N-currNum;
	}
	II res = min(posible,count);
	assert(res != 0 );
	out << res;
}

*/
#define MAX 1000009
II data[MAX+1];
void Solve()
{
	in >> N;
	if(!bDoIt)
		return;
	II aa = RevertFast(1234);
	
	REP(i,MAX)
		data[i] = INF;
	data[1] = 1;
	bool changed = true;
	int t= 0;
	while(changed)
	{
		changed = false;
		FOR(i,2,MAX-1)
		{
			if(i % 10!= 0)
			{
				II revI = RevertFast(i);
				if(revI < i)
				{
					if(data[revI]+1 < data[i])
					{
						data[i] = data[revI]+1;
						changed = true;
					}
				}
			}
			if(data[i-1]+1 < data[i])
			{
				data[i] = data[i-1]+1;
				changed = true;
			}

		}
		++t;
	}


	if(N <= 20)
	{
		out << N;
		return;
	}
	out << data[N];
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
