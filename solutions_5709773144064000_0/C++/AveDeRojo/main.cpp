#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <set>
#include <iomanip>
#include <cstdio>

using std::vector;
using std::ostream;
using std::istream;
using std::set;

double calcMinTime(double C, double F, double X)
{
	double S = 0.0f;
	double V = 2.0f;
	double T = C / V;
	while (true)
	{
		if ((X - C) / V > X / (V + F))
		{
			V = V + F;
			T += C / V;	
		}
		else
		{
			T += (X - C) / V;
			break;
		}
	}
	return T;
}

int main()
{
	std::ifstream in("B-small-attempt0.in");
	std::ofstream out("textOut.txt");

	int numberOfCases = 0;
	in >> numberOfCases;

	for (int i = 1; i < numberOfCases + 1; ++i)
	{
		double C = 0.0f;
		double F = 0.0f;
		double X = 0.0f;
		in >> C >> F >> X;
		double optTime = calcMinTime(C, F, X);
		out.setf(std::ios_base::fixed, std::ios_base::floatfield);
		out.precision(7);
		out << "Case #" << i <<  ": " << optTime << std::endl;
	}
	return 0;
}