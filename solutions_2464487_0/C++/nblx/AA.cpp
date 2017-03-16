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

typedef unsigned long long ull_int;


ull_int solve(ull_int r, ull_int T)
{
	ull_int result=0ULL;
	ull_int start = 2*r+1;
	ull_int num = 1ULL;
	ull_int temp = 2*num*num+(start-2)*num;
	while (temp<T)
	{
		num *= 2;
		temp = 2*num*num+(start-2)*num;
	}
	if (temp==T)		return num;
	ull_int left = num/2, right = num;
	ull_int i=left, j=right, pivot;
	while (i<j)
	{
		pivot=(i+j)/2;
		temp = 2*pivot*pivot+(start-2)*pivot;
		if (temp==T)		return pivot;
		else if (temp<T)		i=pivot+1;
		else						j=pivot-1;
	}
	temp = 2*i*i+(start-2)*i;
	if (temp<T)	return i;
	else		return i-1;
}

ull_int solve_(ull_int r, ull_int T)
{
	ull_int start = 2*r+1;
	ull_int count = 0ULL, sum=start;
	while (sum<=T)
	{
		count++;
		start += 4;
		sum += start;
	}
	return count;
}

int main()
{
	ifstream infile;
	//infile.open("A-small-attempt1.in");
	infile.open("A-small-attempt2.in");
	ofstream outfile;
	outfile.open("small_.out");
	int nCases;
	infile >> nCases;
	infile.ignore(10,'\n');
	for (int t=1; t<=nCases; t++)
	{
		ull_int r, T;
		infile >> r >> T;
		infile.ignore(10,'\n');
		
		ull_int result = solve_(r, T);
		
		outfile << "Case #" << t << ": " << result << endl;
		cout << "Case #" << t << " solved!\n";
	}
	infile.close();
	outfile.close();
	char c;
	cin >> c;
	return 0;
}