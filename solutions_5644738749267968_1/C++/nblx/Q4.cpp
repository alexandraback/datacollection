#include <iostream>
#include <iomanip>		// setprecision
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>		// sort, stable_sort
#include <cstdlib>			// atoi, atof, etc.
#include <cmath>			// floor
using namespace std;
typedef unsigned long long ull_int;

pair<int, int> solve(vector<double> &W, vector<double> &M)
{	// W: Naomi's woods;  M: Ken
	sort(W.begin(), W.end());
	sort(M.begin(), M.end());
	int n=W.size(), cW=0, cM=0, i=0, j=0;
	while (i<n)
	{
		if (W[i]>M[j])
		{	cW++;			
			j++;
		}
		i++;
	}
	i=j=0;
	while (j<n)
	{
		if (M[j]>W[i])
		{	cM++;
			i++;
		}
		j++;
	}
	return make_pair(cW, n-cM);
}


int main()
{
	ifstream infile;
	infile.open("D-large.in");
	ofstream outfile;
	outfile.open("large.out");
	int nCases;
	infile >> nCases;
	infile.ignore(10,'\n');
	for (int t=1; t<=nCases; t++)
	{
		int n;
		infile >> n;
		infile.ignore(10,'\n');

		vector<double> W(n), M(n);
		for (int i=0; i<n; i++)		infile >> W[i];
		infile.ignore(10,'\n');
		for (int i=0; i<n; i++)		infile >> M[i];
		infile.ignore(10,'\n');

		auto p = solve(W, M);
		outfile << "Case #" << t << ": " << p.first << " " << p.second << endl;
		cout << "Case #" << t << ": " << p.first << " " << p.second << endl;
	}
	infile.close();
	outfile.close();
	char c;
	cin >> c;
	return 0;
}