#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include <utils/macros.h>
#include <utils/Error.h>

//////////////////////////////////////////////////////////////////////////
// Problem space
//////////////////////////////////////////////////////////////////////////

/**
* A shyness -> amount mapping.
*/
typedef std::vector<unsigned int> ShyAudience;

inline
size_t solve(ShyAudience const &audience)
{
	size_t missing = 0;
	size_t standing = 0;
	for(size_t minStanding = 0; minStanding<audience.size(); ++minStanding)
	{
		if(audience[minStanding] && standing<minStanding)
		{
			size_t needed = minStanding - standing;
			missing += needed;
			standing += needed;
		}
		standing += audience[minStanding];
	}
	return missing;
}

//////////////////////////////////////////////////////////////////////////
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
	size_t caseCount;
	fIn >> caseCount;

	std::string const fOutName(argv[2]);
	std::ofstream fOut(fOutName.c_str());

	ShyAudience current;
	for(size_t i = 0; i<caseCount; ++i)
	{
		size_t mapTop;
		fIn >> mapTop;
		std::string shymap;
		fIn >> shymap;
		ED_USERASSERT(mapTop+1==shymap.length(), "Invalid input. Map top value does not match actual input size.");
		current.clear();
		for(char const *it = shymap.c_str(); *it; ++it)
			current.push_back(*it - '0');
		fOut << "Case #" << (i+1) << ": " << solve(current) << "\n";
	}
	
	return 0;
}
