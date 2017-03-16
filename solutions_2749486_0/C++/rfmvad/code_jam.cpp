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
	int X, Y;
	in >> X >> Y;
	string res = "";

	for (; X > 0; X--)
		res = res.append("WE");
	for (; X < 0; X++)
		res = res.append("EW");
	for (; Y > 0; Y--)
		res = res.append("SN");
	for (; Y < 0; Y++)
		res = res.append("NS");

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