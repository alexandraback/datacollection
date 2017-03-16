#include <iostream>
#include <iomanip>

int main(int argc, char* argv[])
{
	int numCases;
	std::cin >> numCases;
	for (int i=0; i<numCases; i++)
	{
		int A, B;
		std::cin >> A >> B;
		double correct = 1;
		//Enter and continue
		double result = 1 + B + 1;
		//Delete all
		double all = A + B + 1;
		if (all < result) result = all;
		for (int j=0; j<A; j++)
		{
			double p;
			std::cin >> p;
			correct *= p;
			double n = correct*(A-j-1+B-A+A-j-1+1) + (1-correct)*(A-j-1+B-A+A-j-1+1+B+1);
			if (n < result) result = n;
		}
		std::cout << "Case #" << (i+1) << ": " << std::setiosflags(std::ios::fixed) << std::setprecision(6) << result << std::endl;
	}
	return 0;
}

