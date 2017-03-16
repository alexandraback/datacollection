#include <algorithm>
#include "BigIntegerLibrary.hh"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void func(ifstream& in, ofstream& out)
{
	int n, spc;
	string name, line;

	getline(in, line);
	if (line.size() < 1)
		getline(in, line);
	spc = line.find(' ');
	name = line.substr(0, spc);
	stringstream ss(line.substr(spc + 1));
	ss >> n;

	int pos = -1;
	long long res = 0;
	int count = 0;
	string vow = "aeiou";
	for (int i = 0; i < name.size(); i++)
	{
		if (vow.find(name[i]) == string::npos)
			count++;
		else
			count = 0;

		if (count >= n)
			pos = i - n + 1;

		if (pos >= 0)
			res += pos + 1;
	}

	out << res << endl;
}

int main()
{
	ifstream in;
	in.open("D:\\code_jam_in.txt");

	ofstream out;
	out.open ("D:\\code_jam_out.txt");
	out << fixed << showpoint << setprecision(7);

	int T;
	in >> T;

	for (int t = 1; t <= T; t++)
	{
		//cout << "Case #" << t << endl;
		out << "Case #" << t << ": ";
		func(in, out);
	}

	in.close();
	out.close();
	
	return 0;
}