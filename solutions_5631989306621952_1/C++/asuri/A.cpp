#include <vector>
using namespace std;
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <unordered_set>

string last_word(string s)
{
	string res;
	for(int i=0; i<s.size(); i++)
	{
		char c = s[i];
		if(res.empty() || c >= res[0])
			res = c+res;
		else
			res = res+c;
	}
	return res;
}

void main()
{
	ifstream ifile("A-large.in");
	ofstream ofile("A-large.out");
	int n_tests;
	ifile >> n_tests;
	for (int id=0; id<n_tests; id++)
	{
		string s;
		ifile >> s;
		ofile << "Case #" << id+1 << ": " << last_word(s) << endl;
	}
	ofile.close();
}

