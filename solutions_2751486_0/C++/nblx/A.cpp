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

ull_int solve(string &s, int n)
{
	int L = s.size();
	set<char> vow;
	vow.insert('a');
	vow.insert('e');
	vow.insert('i');
	vow.insert('o');
	vow.insert('u');
	vector<int> start, end;
	start.push_back(-1);
	end.push_back(-1);
	int i=0, j, count=0;
	while (i<L)
	{	
		if (vow.count(s[i])==0)	// s[j] is consonant
		{
			count++;
			if (count>=n)
			{
				start.push_back(i-n+1);
				end.push_back(i);
			}
		} else		// s[i] is vowel
		{
			count=0;
		}
		i++;
	}
	ull_int result=0ULL;
	for (i=1; i<start.size(); i++)
	{
		result += (ull_int)(start[i]-start[i-1])*(L-end[i]);
	}
	return result;
}

int main()
{
	ifstream infile;
	infile.open("A-small-attempt0.in");
	ofstream outfile;
	outfile.open("small.out");
	int nCases;
	infile >> nCases;
	infile.ignore(10,'\n');
	for (int t=1; t<=nCases; t++)
	{
		int n;
		string s;
		infile >> s >> n;
		infile.ignore(10,'\n');

		ull_int result = solve(s,n);

		outfile << "Case #" << t << ": " << result << endl;
		cout << "Case #" << t << " solved!\n";
	}
	infile.close();
	outfile.close();
	char c;
	cin >> c;
	return 0;
}