#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
long long calc(long long left, long long right, long long r, long long  t)
{
	if (left >= right) return left;
	if ((left +1) == right) 
	{
		if (right*(2*r+2*right-1)<=t) return right;
		else return left;
	}
	long long  mid = (left + right) /2;
	double result = (double)mid*(2*r+2*(double)mid-1);
	if (result <= (double)t)
	{
		return calc(mid, right, r, t);
	}
	else return (calc(left, mid-1, r, t));
}


int main()
{
	long long  n;
	ifstream fin("input.txt");
	fin >> n;
	ofstream fout("output.txt");
	long long r, t;
	for (long long i=0; i<n; i++)
	{
		fin >> r >> t;
		fout << "Case #" << i+1 << ": " << calc(1, t,r, t) << endl;
	}
	fin.close();
	fout.close();
	return 0;
}

