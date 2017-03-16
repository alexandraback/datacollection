#include <iostream>
#include <iomanip>		// setprecision
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>			// map, unordered_map
#include <set>			// set, unordered_set
#include <algorithm>	// sort, stable_sort
#include <cstdlib>		// atoi, atof, etc.
using namespace std;

typedef unsigned long long ull_int;

struct T
{
	int x;
	int y;
	T(int i, int j):x(i),y(j) {}
	bool operator<(const T &b) const  { return y<b.y; }
};

string solve(int x, int y)
{
	string result;
	for (int i=0; i<abs(x); i++)
	{
		if (x>0)
		{
			result += 'W';
			result += 'E';
		} else
		{
			result += 'E';
			result += 'W';			
		}
	}
	for (int i=0; i<abs(y); i++)
	{
		if (y>0)
		{
			result += 'S';
			result += 'N';
		} else
		{
			result += 'N';
			result += 'S';			
		}
	}
	return result;
}

int main()
{
	ifstream infile;
	infile.open("B-small-attempt0.in");
	ofstream outfile;
	outfile.open("small.out");
	int nCases;
	infile >> nCases;
	infile.ignore(10,'\n');
	for (int t=1; t<=nCases; t++)
	{
		int x, y;
		infile >> x >> y;
		infile.ignore(10,'\n');
		string result = solve(x,y);

		outfile << "Case #" << t << ": " << result << endl;;


		cout << "Case #" << t << " solved!\n";
	}
	infile.close();
	outfile.close();
	char c;
	cin >> c;
	return 0;
}