#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
// #include <utils/macros.h>

//////////////////////////////////////////////////////////////////////////
// Problem space
//////////////////////////////////////////////////////////////////////////

template<typename Element>
struct More
{
	bool operator()(Element const &e1, Element const &e2)
	{
		return e2 < e1;
	}
};

typedef int Height;
typedef std::multiset< Height, More<Height> > Stacks;

inline
size_t solve(Stacks const &stacks)
{
	Height problemHeight = *stacks.begin();
	size_t best = problemHeight;
	for(Height finalHeight = problemHeight-1; finalHeight>=1; --finalHeight)
	{
		size_t cutCost = 0;
		for(Stacks::const_iterator i = stacks.begin(); i!=stacks.end(); ++i)
		{
			Height h = *i;
			if(h<=finalHeight)
				break;
			cutCost += (h-1) / finalHeight;
			if(cutCost >= best)
				return best;
			if(cutCost + finalHeight >= best)
				break;
		}
		if(cutCost + finalHeight < best)
			best = cutCost + finalHeight;
	}
	return best;
}

/////////////////////////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////////////////////////

int main(int argc, char const * const * argv)
{
	if(argc!=3)
	{
		std::cerr << "Invalid invocation. Schema: " << argv[0] << " <inFile> <outFile>" << std::endl;
		return 1;
	}
	std::string const fInName(argv[1]);
	std::ifstream fIn(fInName.c_str());
	int caseCount;
	fIn >> caseCount;

	std::string const fOutName(argv[2]);
	std::ofstream fOut(fOutName.c_str());

	for(int i = 0; i<caseCount; ++i)
	{
		Stacks current;
		size_t plateCount;
		fIn >> plateCount;
		for(size_t j = 0; j<plateCount; ++j)
		{
			Height h;
			fIn >> h;
			current.insert(h);
// 			if(j>0)
// 				std::cout << " ";
// 			std::cout << h;
		}
// 		std::cout << std::endl;

		if(plateCount==0)
		{
			fOut << "Case #" << (i+1) << ": 0\n";
// 			std::cout << "Case #" << (i+1) << ": 0\n";
			continue;
		}

		size_t moveCount = solve(current);
		fOut << "Case #" << (i+1) << ": " << (moveCount) << "\n";
// 		std::cout << "Case #" << (i+1) << ": " << (moveCount) << "\n";
// 		std::cout << std::endl;
	}

	return 0;
}
