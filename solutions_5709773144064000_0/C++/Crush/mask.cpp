#pragma warning(disable:4786)

#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <sstream>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

#define VT vector
typedef VT<int> VI;
typedef VT<VI> VVI;
typedef VT<string> VS;
typedef VT<double> VD;
typedef pair<int,int> PII;
#define REP(i,n) for (int i = 0; i < (n); i++)
#define ALL(c) c.begin(),c.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz size()

ifstream ifs;
ofstream ofs;

typedef long long ll;

typedef long double ld;

void testcase(int tst)
{
	ld c, f, x;
	ifs >> c >> f >> x;

	ld res = 1E+20;

	ld time = 0.0;
	ld ratio = 2;

	while (time < res) {
		res = min(res, time + x / ratio);
		time += c / ratio;
		ratio += f;
	}

	char buf[100];
	sprintf(buf, "%.9llf", res);
	ofs << "Case #" << tst+1 << ": " << buf << endl;
}

int main()
{
	ifs.open("input.txt");
	ofs.open("output.txt");
	
	int t;
	ifs >> t;
	REP(tn, t)
	{
		testcase(tn);
	}

	return 0;
} 
