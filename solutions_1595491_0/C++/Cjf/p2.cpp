#include "p2.h"
#include <iostream>
#include <fstream>
using namespace std;

p2::p2(void)
{
}


p2::~p2(void)
{
}

void p2::solve()
{
	ifstream fin("B-small-attempt0 (1).in");
	ofstream fout("B-small-attempt0 (1).out");

	int t;
	fin >> t;
	for ( int tests=1; tests<=t; ++tests )
	{
		int n, s, p;
		fin >> n >> s >> p;

		int res = 0, a;
		for ( int i=0; i<n; ++i )
		{
			fin >> a;
			if ( a>=max(3*p-2,p) ) ++res;
			else if ( a>=max(3*p-4,p) && s ) --s, ++res;
		}
		fout << "Case #" << tests << ": " << res << endl;
	}
}