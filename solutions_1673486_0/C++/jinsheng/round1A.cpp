
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double one(const int n, const int total, const double *poss)
{
	double rp = poss[0];
	for (int i = 1; i < n; ++i)
		rp *= poss[i];
	double count = (total - n + 1) * rp + (total - n +1 + total +1) * (1 - rp);
	return count;
}

double two(const int n, const  int total, const double * poss)
{
	double min = 200000;
	for (int i = 1; i <= n; ++i)
	{
		double allright = 1;
		for (int j = 0; j <= n-i-1; ++j)
			allright *= poss[j];
		int allrightsteps = i + total - (n - i) + 1;
		int wrongsteps = i + total - (n - i) + 1 + total + 1;
		double minCount = allrightsteps * allright + wrongsteps * (1 - allright);
		if (min > minCount)
			min = minCount;
	}
	return min;
}

double three(const int n, const int total, const double * poss)
{
	return 1 + total + 1;
}

double Min(double A, double B, double C)
{
	if (A-B > 0.000001)
		return (B-C > 0.000001) ? C : B;
	else
		return (A-C > 0.000001) ? C : A;
}

int main()
{
	fstream infile("input.txt", ios::in);
	fstream outfile("output.txt", ios::out);
	int T, A, B;
	infile>>T;
	for (int i = 1; i <= T; ++i)
	{
		infile>>A>>B;
		double * poss = new double [A];
		for (int j = 0; j < A; ++j)
			infile>>poss[j];
		double temp1 = one(A, B, poss);
		double temp2 = two(A, B, poss);
		double temp3 = three(A, B, poss);
		double temp = Min(temp1, temp2, temp3);
		outfile<<"Case #"<<i<<": "<<fixed << setprecision(6)<<temp;
		if (i != T)
			outfile<<endl;
	}
}