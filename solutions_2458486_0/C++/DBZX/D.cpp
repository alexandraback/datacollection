// D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
using namespace std;
ifstream in("D-small-attempt0.in");
ofstream out("out.txt");

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define REP(i,n) FOR(i,0,(n)-1)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define sz size()
template<class T> inline int size(const T& c) { return c.sz; }
#define FORA(i,c) REP(i,size(c))


int K,N;
typedef map<int,int> KeySet;
KeySet keys;
struct Chest
{
	int m_type;
	vector <int > m_keys;
};
vector< Chest > chests;
typedef vector<bool> State;///opened chests

set<State> failedStates;

vector<int> result;
bool Check(State s,KeySet keys,int openedChests)
{
	if(openedChests == N)
		return true;
	if(failedStates.find(s)!= failedStates.end())
		return false;
	REP(n,N)
	{
		if(!s[n] && keys[chests[n].m_type] > 0)
		{
			KeySet oldKeys = keys;
			keys[chests[n].m_type]--;
			REP(k,chests[n].m_keys.size())
				keys[chests[n].m_keys[k]]++;
			s[n] = true;
			if(Check(s,keys,openedChests+1))
			{
				result.push_back(n);
				return true;
			}
			s[n] = false;
			keys = oldKeys;
		}
	}
	failedStates.insert(s);
	return false;
	
}
void Solve()
{

	KeySet curKeys = keys;
	State st = vector<bool>(N,false);
	if(!Check(st,curKeys,0))
		out << " IMPOSSIBLE";
	else
	{
		REP(n,N)
		{
			out << " " << result[N-1-n]+1;
		}
		
	}
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	in >> T;
	for(int i = 0;i<T;++i)
	{
		cout << i << endl;
		keys.clear();
		chests.clear();
		failedStates.clear();
		result.clear();
		in >> K >> N;
		for(int k = 0;k<K;++k)
		{
			int tp;
			in >> tp;
			keys[tp]++;
		}
		
		REP(n,N)
		{
			Chest c;
			in >> c.m_type;
			int keyCount;
			in >> keyCount;
			REP(kc,keyCount)
			{
				int kk;
				in >> kk;
				c.m_keys.push_back(kk);
			}
			chests.push_back(c);
			
		}
		out << "Case #" << (i+1) << ":";
		Solve();
		out << endl;
	}
	return 0;
}

