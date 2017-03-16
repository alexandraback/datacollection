#include <iostream>
#include <iomanip>		// setprecision
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>			// map, unordered_map
#include <set>			// set, unordered_set
#include <algorithm>	// sort, stable_sort
#include <cstdlib>		// atoi, atof, etc.
using namespace std;


int GCD(int a, int b)
{
	return b==0 ? a : GCD(b, a%b);
}



typedef unsigned long long ull_int;

int solve__(int A, const vector<int> &S, int k)
{	// A: current size;  k: remaining: S[k:n-1]
	int n=S.size();
	if (k==n)		return 0;
	if (n-k==1)	return A>S[n-1]? 0 : 1;
	while (k<n && A>S[k])
	{
		A += S[k];
		k++;
	}
	int temp = 1+solve__(2*A-1, S, k);
	return min(temp,n-k);
}

int solve(int A, vector<int> &S)
{
	int n=S.size();
	sort(S.begin(), S.end());		// ascending sort
	if (A==1)		return n;
	return solve__(A,S,0);
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
		int A, n;
		infile >> A >> n;
		infile.ignore(10,'\n');
		vector<int> sizes(n);
		for (int i=0; i<n; i++)
		{
			infile >> sizes[i];			
		}
		infile.ignore(10,'\n');
		int result = solve(A, sizes);
		outfile << "Case #" << t << ": " << result << endl;
		cout << "Case #" << t << " solved!\n";
	}
	infile.close();
	outfile.close();
	char c;
	cin >> c;
	return 0;
}