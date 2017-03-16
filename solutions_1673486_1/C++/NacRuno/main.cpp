#include <iostream>
#include <fstream>
#include <string>
#include <climits>
using namespace std;

int main()
{
	ifstream input;
	ofstream output;

	string inputname = "input.txt";
	string outputname = "output.txt";

	input.open(inputname.c_str());
	output.open(outputname.c_str());

	unsigned T;
	input >> T;

	for (unsigned t = 0; t < T; t++)
	{
		unsigned A, B;

		input >> A >> B;

		double p_acc = 1;
		double p;
		double * E;
		E = new double [A+2];

		int temp = B-A+1;
		int temp2 = temp+B+1;

		unsigned n;
		unsigned i;
		for (n = 0; n < A-1; n++)
		{
			input >> p;

			i = A-n-1;

			p_acc = p_acc * p;

			E[n] = p_acc*(temp+i+i) + (1-p_acc)*(temp2+i+i);
		}

		input >> p;
		p_acc = p_acc * p;

		E[n] = A + B + 1;
		E[n+1] = p_acc*(temp) + (1-p_acc)*(temp2);
		E[n+2] = B+2;

		double smallest = E[n+2];
		
		for (n = 0; n < A+1; n++)
		{
			if (E[n] < smallest)
				smallest = E[n];
		}

		output << "Case #" << t+1 << ": ";
		output.fixed;
		output.precision(7);
		output << smallest;
		output << endl;
	}


	return 0;
}