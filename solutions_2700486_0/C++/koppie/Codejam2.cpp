//============================================================================
// Name        : Codejam2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
double calc_prob(int N, int start, int end);
int main() {
	int T;
	int N, X, Y;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		double prob = 0.0;
		cin >> N >> X >> Y;
		if (X < 0) X = -X; // they are the same!
		int lbound = (X+Y)/2 * (X+Y-1);
		int ubound = (X+Y+2)/2 * (X+Y+1);
		int Np = N - lbound;
		if (N <= lbound)
			prob = 0.0;
		else if (N >= ubound)
			prob = 1.0;
		else if (Np <= Y )
			prob = 0.0;
		else if (Np >= X + 2*Y + 1)
			prob = 1.0;
		else if (X == 0)//if (Np <= X + Y)
			prob = 0.0;
		else
			prob = calc_prob(Np, Y+1, Np);
		//else
			//prob = calc_prob(Np, Y+1, X+Y);
		cout << "Case #" << t << ": " << prob << endl;
	}
	return 0;
}

double calc_prob(int N, int start, int end)
{
	double result = 0;
	double tmp = 1.0;
	for (int i = 1; i <= end; ++i){
		tmp = tmp * (N-i+1)/i; // N choose i
		if (i >= start)
			result += tmp;
	}
	for (int i = 0; i < N; ++i)
		result /= 2;
	return result;
}

