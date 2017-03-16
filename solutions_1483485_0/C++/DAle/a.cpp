#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>

using namespace std;

string inp[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string out[3] = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};


int main()
{
	map<char, char> m;
	m['y'] = 'a';
	m['e'] = 'o';
	m['q'] = 'z';
	m['z'] = 'q';
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < inp[i].size(); ++j)
		{
			m[inp[i][j]] = out[i][j];
		}
	ifstream ifs("a.in");
	ofstream ofs("a.out");
	string s;
	getline(ifs, s);
	int t;
	sscanf(s.c_str(), "%d", &t);
	for (int test = 0; test < t; ++test)
	{
		string s2;
		getline(ifs, s);
		s2 = s;
		for (int i = 0; i < s.size(); ++i)
			s2[i] = m[s[i]];
		ofs << "Case #" << test+1 << ": " << s2 << endl; 
	}
	return 0;
}
