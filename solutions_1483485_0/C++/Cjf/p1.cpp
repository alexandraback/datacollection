#include "p1.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

p1::p1(void)
{
}


p1::~p1(void)
{
}

void p1::solve()
{
	vector<string> s1, s2;
	s1.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
	s1.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
	s1.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");

	s2.push_back("our language is impossible to understand");
	s2.push_back("there are twenty six factorial possibilities");
	s2.push_back("so it is okay if you want to just give up");

	map<char, char> m;
	for ( int i=0; i<3; ++i )
		for ( int j=0; j<s2[i].size(); ++j )
			m[s1[i][j]] = s2[i][j];
	m['q']='z';
	m['z']='q';

	ifstream fin("A-small-attempt3.in");
	ofstream fout("A-small-attempt3.out");
	int n;
	fin >> n;
	char buff[1000];
	for ( int i=0; i<=n; ++i )
	{	
		fin.getline(buff, 1000);
		if ( !i ) continue;
		for ( int j=0; j<strlen(buff); ++j )
			buff[j] = m[buff[j]];
		fout << "Case #" << i << ": " << buff << endl;
	}
	cerr << 1;
}