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



//double solve(int n, int x, int y)
//{
//	int K=(int)sqrt(2.0*n);
//	while (K*(2*K-1)>n)		K--;
//	if (abs(x)+y<=2*K-2)		return 1.0;
//	if (abs(x)+y>2*K)		return 0.0;
//	n = n-K*(2*K-1);		// remaining diamonds
//	if (n<=2*K)
//	{
//
//	} else
//	{
//	}
//
//}

double solve(int n, int x, int y)
{
	int K;
	if (n<6)		K=1;
	else if (n<15)		K=2;
	else		K=3;
	if (abs(x)+y<=2*K-2)		return 1.0;
	if (abs(x)+y>2*K)		return 0.0;
	n = n-K*(2*K-1);		// remaining diamonds
	if (y+1>n)		return 0.0;	
	if (K==1)
	{	// n<=4K
		if (y==0)
		{
			if (n==1)	return 0.5;
			else if (n==2)	return 0.75;
			else if (n>=3)	return 1.0;
		} else if (y==1)
		{
			if (n==2)	return 0.25;
			else if (n==3)	return 0.5;
			else		return 1.0;
		} else	return 0.0;
	} else if (K==2)
	{
		if (y==0)
		{
			if (n==1)	return 0.5;
			else if (n==2)	return 0.75;
			else if (n==3)	return 0.875;
			else		return 1.0;
		} else if (y==1)
		{
			if (n==2)		return 0.25;
			else if (n==3)	return 0.5;
			else if (n==4)	return 11.0/16;
			else		return 1.0;
		} else if (y==2)
		{
			if (n==3)		return 0.125;
			else if (n==4)	return 5.0/16;
			else if (n==5)	return 0.5;
			else		return 1.0;
		} else		return 0.0;
	} else	// K==3
	{	// n<=5
		if (y==0)
		{
			if (n==1)	return 0.5;
			else if (n==2)	return 0.75;
			else if (n==3)	return 0.875;
			else if (n==4)	return 1-1.0/16;
			else	return 1-1.0/32;
		} else if (y==1)
		{
			if (n==2)		return 1.0/4;
			else if (n==3)	return 0.5;
			else if (n==4)	return 11.0/16;
			else		return 26.0/32;
		} else if (y==2)
		{
			if (n==3)		return 1.0/8;
			else if (n==4)	return 5.0/16;
			else				return 0.5;
		} else if (y==3)
		{
			if (n==4)		return 1.0/16;
			else		return 6.0/32;
		} else if (y==4)
		{
			return 1.0/32;
		} else		return 0.0;
	}
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
		int n, x, y;
		infile >> n >> x >> y;
		infile.ignore(10,'\n');
		double result = solve(n, x, y);

		outfile << "Case #" << t << ": ";
		outfile << setprecision(10) << result << endl;
		cout << "Case #" << t << " solved!\n";
	}
	infile.close();
	outfile.close();
	char c;
	cin >> c;
	return 0;
}