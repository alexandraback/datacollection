#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;
int x, y;
char r[510];

int main()
{
	//ifstream infile("test.in");
	ifstream infile("B-small-attempt0.in");
	//ifstream infile("B-small-attempt1.in");
	//ifstream infile("B-large.in");
	ofstream outfile("B.out", ios::out);
	int T;
	infile >> T;
	int testcase;
	for (testcase = 1;testcase <= T;testcase++)
	{
		infile >> x >> y;
		int i, j;
		outfile << "Case #" << testcase << ": ";
		if (x >= 0)
		{
			for(i = 0;i < x;i++)
			{
				outfile << "WE";
			}
		}
		else
		{
			for(i = 0;i < -1*x;i++)
			{
				outfile << "EW";
			}
		}
		if (y >= 0)
		{
			for(i = 0;i < y;i++)
			{
				outfile << "SN";
			}
		}
		else
		{
			for(i = 0;i < -1*y;i++)
			{
				outfile << "NS";
			}
		}
		
		
		outfile << endl;
	}
	return 0;
}