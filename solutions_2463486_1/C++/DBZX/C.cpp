// C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
using namespace std;
ifstream in("C-large-1.in");
ofstream out("out.txt");


#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define REP(i,n) FOR(i,0,(n)-1)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define sz size()
template<class T> inline int size(const T& c) { return c.sz; }
#define FORA(i,c) REP(i,size(c))



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

	vector<__int64> resReal(res.size());
	for(unsigned int i = 0;i < res.size();++i)
		resReal[i] = res[res.size()-1-i];
	return resReal;
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


__int64 FromBase(vector<__int64> &num,int size,__int64 base)
{
	__int64 nn = 0;
	REP(n,size-1)
	{
		nn += num[n];
		nn *= base;
	}
	nn += num[size-1];
	return nn;
}


__int64 A,B;
vector<__int64> currentNum(200);
set<__int64> valid;

bool IsPoli(vector<__int64> &num,int digits)
{
	for(unsigned int i = 0;i < digits/2;++i)
	{
		if(num[i] != num[digits-1-i])
			return false;
	}
	return true;
}

void TestPoli(int digits)
{
	assert(IsPoli(currentNum,digits));
	__int64 num = FromBase(currentNum,digits,10);
	assert(num < INT_MAX);
	__int64 numSq = num*num ;
	vector<__int64> testNum = InBase(numSq,10);
	if(IsPoli(testNum,testNum.size()))
		valid.insert(numSq);
}

void AddDig(int digits, int pos,int maxPos)
{
	if(pos == maxPos)
	{
		TestPoli(digits);
		return;
	}
	for(int i = ((pos == 0)?1:0); i < 10;++i)///pruebo todos los digitos
	{
		currentNum[pos] = i;
		currentNum[digits-1-pos] = i;
		AddDig(digits,pos+1,maxPos);
	}

}

void AddDig(int digits)
{
	AddDig(digits,0,(digits+1)/2);
}

void PreComp()
{
	for(int i = 1;i < 9;++i)
	{
		AddDig(i);
		std::cout << i << " " << valid.size() << endl;
	}
	
}

int Solve()
{
	int count = 0;
	set<__int64>::iterator it; ;
	for(it = valid.begin();it != valid.end();++it)
	{
		if(*it >= A && *it <= B)
			++count;
	}
	return count;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	in >> T;

	PreComp();

	for(int i = 0;i<T;++i)
	{
		in >> A >> B;
		out << "Case #" << (i+1) << ": " << Solve() << endl;
	}
	return 0;
}