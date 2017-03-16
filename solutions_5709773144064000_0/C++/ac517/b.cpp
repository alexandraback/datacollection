#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <queue>
#include <iomanip>

using namespace std;

#define FOR(i,a,b)  for(int i = (a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define S           size()
#define PB          push_back
#define ALL(a)      a.begin(),a.end()
#define MP          make_pair
#define V           vector
#define VI          V < int > 
#define VVI         V < VI >
#define VVVI		V < VVI >
#define VL			V < long long > 
#define VVL			V < VL >
#define VD          V < double >
#define VVD			V < VD >
#define VF          V < float >
#define VS			V < string >

struct State
{
	double sec;
	double cook;
	double cps;
};

double check(double C, double F, double X)
{
	double upperBound = X/2;
	State ini;
	ini.sec = 0;
	ini.cook= 0;
	ini.cps = 2;
	queue<State> q;
	q.push(ini);
	//queue is not needed, realized it after I started
	while(!q.empty())
	{
		State s = q.front();
		q.pop();
		//not buy the farm
		double sec = s.sec + (X - s.cook) / s.cps;
		upperBound = min(sec,upperBound);
		//buy the farm
		s.sec = s.sec + (C - s.cook) / s.cps;
		s.cps += F;
		
		if(s.sec < upperBound)
			q.push(s);
	}
	return upperBound;
	
}

int main(int argc, char** argv)
{
	int n;
	++argv;
	ifstream in(*argv);
	
	in >> n;
	VD res;
	VVD cook;
	double C,F,X;
	REP(i,n)
	{
		in >> C >> F >> X;
		res.PB(check(C,F,X));
	}
				
	
	stringstream ss;
	REP(i,res.S)
	{
		stringstream tmp;
		tmp << std::setprecision(7) << std::fixed << res[i];
		ss << "Case #" << i+1 << ": " << tmp.str() << endl;
	}
	
	cout << ss.str();




}


