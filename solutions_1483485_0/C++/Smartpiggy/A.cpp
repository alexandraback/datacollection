#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef __int64 LONG; 

string SRC ="our language is impossible to understand" "there are twenty six factorial possibilities" "so it is okay if you want to just give up";
string TGT ="ejp mysljylc kd kxveddknmc re jsicpdrysi" "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" "de kr kd eoya kw aej tysr re ujdr lkgc jv";
char CMAP[128];

string Translate(const string& s)
{
	string ss =s;

	for (int i=0; i<s.size(); i++)
	{
		ss[i] = CMAP[s[i]];
	}

	return ss;
}


void RunCase (ifstream& fin, ofstream& fout)
{
	string s;

	while (s.empty())
	{
		std::getline( fin, s);
	}

	s= Translate(s);
	fout<<s;
}

void RunAll(const char* fnameIn, const char* fnameOut)
{
	ifstream fin(fnameIn);
	ofstream fout(fnameOut);

	int caseCount;
	fin >> caseCount;

	for (int i=0; i<caseCount; i++)
	{
		fout<<"Case #"<<i+1<<": ";
		RunCase (fin, fout);
		fout<<"\n";
	}
}

void main()
{
	for (int i=0; i<SRC.size(); i++)
	{
		CMAP[TGT[i]] = SRC[i];
	}
	CMAP['q'] = 'z';
	CMAP['z'] = 'q';

	RunAll("A-small-attempt1.in", "A-small-attempt1.out");

	return;
}