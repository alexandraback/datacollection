#include <fstream>
#include <iostream>
#include <vector>

void kr(std::ifstream& infile, std::ofstream& outfile, int caseid)
{
	bool err = false;
	int nlevels;

	infile >> nlevels;
	std::vector<std::pair<int, int> > n1;

	std::vector<int> cstars;
	int nstars = 0;
	int n2stars = 0;
	int nparticipated = 0;
	int a, b;
	for (int idx = 0; idx < nlevels; ++ idx)
	{
		infile >> a >> b;
		n1.push_back(std::make_pair<int, int>(a, b)); 
		cstars.push_back(0);
	}

	// for each instance, select one that gives two stars with current field
	// otherwise pick one that gives 1 star
	int cand2, cand1;
	while (n2stars < nlevels && !err)
	{
		cand2 = -1;
		cand1 = -1;
		// hunt for the minimum level to grant 2 stars
		for (int idx = 0; (idx < nlevels) && (cand2 < 0); ++ idx)
		{
			if ((n1[idx].second <= nstars) && (cstars[idx] < 2))
			{
				cand2 = idx;
			}
			else if ((n1[idx].first <= nstars) && (cstars[idx] < 1))
			{
				cand1 = idx;
			}
		}
		if (cand2 >= 0)
		{
			nstars += (2-cstars[cand2]);
			n2stars += 1;
			cstars[cand2] = (2-cstars[cand2]);
			++ nparticipated;
			std::cout << "playing " << cand2 << std::endl;
		}
		else if (cand1 >= 0)
		{
			nstars += 1;
			cstars[cand1] = 1;
			++ nparticipated;
			std::cout << "playing " << cand1 << std::endl;
		}
		else
		{
			std::cout << "erred " << cand1 << " " << cand2<< std::endl;
			err = true;
		}
	}

	std::cout << "case " << nparticipated << " " << err << std::endl;
	if (!err)
	{
		outfile << "Case #" << caseid <<  ": " << nparticipated << std::endl;
	}
	else
	{
		outfile << "Case #" << caseid <<  ": Too Bad" << std::endl;
	}
}

int main(int argc, char** argv)
{
	std::ifstream infile(argv[1]);
	std::ofstream outfile(argv[2]);

	int ncases;
	infile >> ncases;
	for (int idx = 0; idx < ncases; ++ idx)
	{
		kr(infile, outfile, idx+1);
	}
	outfile.close();
	infile.close();
}
