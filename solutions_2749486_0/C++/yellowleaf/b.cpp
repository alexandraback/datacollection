#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;
//#define DEBUG

const int BUFSIZE = 2 * 1024 * 1024;

string  processOneCase(ifstream &ifs)
{
	string ret;
#if 1
	char buf[BUFSIZE];
	ifs.getline(buf, BUFSIZE);
	istringstream iss(buf);
	int x, y;
	iss >> x >> y;
	if (x != 0)
	{
		int ab = abs(x);
		string substr;
		if (x > 0)
		{
			substr = "WE";
		}
		else
		{
			substr = "EW";
		}
		for (int i = 0; i < ab; i++)
			ret += substr;
	}
	if (y != 0)
	{
		int ab = abs(y);
		string substr;
		if (y > 0)
		{
			substr = "SN";
		}
		else
		{
			substr = "NS";
		}
		for (int i = 0; i < ab; i++)
			ret += substr;
	}
#endif

	return ret;
}

int main(int argc, char *argv[])
{
	ifstream ifs(argv[1]);
	char buf[BUFSIZE];
	ifs.getline(buf, BUFSIZE);
	int lines = atoi(buf);

	for (int i = 0; i < lines; i++)
	{   
		string result = processOneCase(ifs); 
		cout << "Case #" << (i+1) << ": " << result  << endl;
	}   
	return 0;
}
