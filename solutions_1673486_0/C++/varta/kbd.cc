#include <fstream>
#include <iostream>
#include <iomanip>


double kbd(std::ifstream& infile)
{
	size_t ntyped, ntotal;
	infile >> ntyped >> ntotal;

	double Ekeystrokes = 0., minE = 1 + ntotal + 1;
	double pkcorrect = 1., pkthcorrect;

	double pkcorrectInto2np1 = 1. * (ntotal + 1.);
	if (ntyped > 0)
	{
		for (size_t k = 1; k < ntyped+1; ++ k)
		{
			infile >> pkthcorrect;
			pkcorrectInto2np1 *= pkthcorrect;
			pkcorrect *= pkthcorrect;
			Ekeystrokes = 
				// backspaced + remaining + enter
				(pkcorrect) * (ntyped - k + ntotal - k + 1) +
				// backspaced + remaining + enter + ntotal + enter
				(1. - pkcorrect) * (ntyped - k + ntotal - k + 1 + ntotal + 1);
			//std::cout << pkcorrect  << " at " << k << "[" << (ntyped - k + ntotal - k + 1) << "] [" << (ntyped - k + ntotal - k + 1 + ntotal + 1) << "] " << Ekeystrokes << std::endl;

			// simplifying:
			//ntyped - k + ntotal - k + 1 + (1-pkcorrect) * (ntotal + 1)
			//ntyped -k + ntotal - k + 1 + ntotal + 1 - pkcorrect * (ntotal + 1)
			//ntyped - k + ntotal - k + 1 + 2 *ntotal + 1 - pkcorrectInto2np1;
			//ntyped - 2.*k + 2. + 3*ntotal - pkcorrectInto2np1;

			if (minE > Ekeystrokes)
				minE = Ekeystrokes;
		}
	}
	return minE;
}

int main(int argc, char** argv)
{
	std::ifstream infile(argv[1]);
	std::ofstream outfile(argv[2]);

	size_t ncases;
	infile >> ncases;
	outfile.setf(std::ios::fixed, std::ios::floatfield);
	for (size_t idx = 0; idx < ncases; ++ idx)
	{
		outfile << "Case #" << idx + 1 << ": " << std::setprecision(6) << kbd(infile) << std::endl;
	}
	outfile.close();
	infile.close();
}
