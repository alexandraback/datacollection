#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <deque>
#include <string>

using namespace std;

int t,T;
ifstream ein;
ofstream aus;

void runtestcase()
{
	string S;
	ein >> S;
	int c = 0;
	for (unsigned int i = 0; i < S.length()-1; i++)
	{
		if (S[i] != S[i+1])
			c++;
	}
	if (S[S.length()-1]=='-')
		c++;
	aus << c;
}

void main()
{
	ein.open("B-large.in");
	aus.open("ausgabe.txt");

	ein >> T;
	for (t = 1; t <= T; t++)
	{
		printf("%d\n", t);
		aus << "Case #" << t << ": ";
		runtestcase();
		aus << endl;
	}

	aus.close();
	ein.close();
}