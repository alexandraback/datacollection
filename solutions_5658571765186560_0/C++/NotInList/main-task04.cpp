#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>

#include <boost/current_function.hpp>

// #include <utils/macros.h>

//////////////////////////////////////////////////////////////////////////
// Utility
//////////////////////////////////////////////////////////////////////////

inline
std::string constructDebugInfo(std::string const &msg, char const *file, int line, char const *func, char const * cond = 0)
{
	using namespace std;
	stringstream ss;
	ss << "=== Debug information ===" << endl;
	ss << "- Message: " << msg << endl;
	ss << "- File: " << file << endl;
	ss << "- Line: " << line << endl;
	ss << "- Function: " << func << endl;
	if(cond)
		ss << "- Condition: " << cond << " (failed)" << endl;
	return ss.str();
}

#define DEBUG_INFO_C(msg,cond) \
	constructDebugInfo(msg, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, #cond)

#define ASSERT_M(cond, msg) if(!(cond)){ throw std::logic_error(DEBUG_INFO_C(msg,cond)); }
#define ASSERT(cond) ASSERT_M(cond, "PROGRAMMER ERROR")


//////////////////////////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////////////////////////

void report(std::ofstream &fOut, bool possible, size_t i)
{
	fOut << "Case #" << (i+1) << ": " << (possible ? "GABRIEL" : "RICHARD") << "\n";
	std::cout << "Case #" << (i+1) << ": " << (possible ? "GABRIEL" : "RICHARD") << "\n";
}

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

	for(size_t i = 0; i<caseCount; ++i)
	{
		size_t tileSize;
		fIn >> tileSize;
		size_t rows;
		fIn >> rows;
		size_t cols;
		fIn >> cols;

		size_t size = rows * cols;
		if(size % tileSize != 0)
		{
			report(fOut, false, i);
			continue;
		}
		switch(tileSize)
		{
			case 1:
			case 2:
			{
				report(fOut, true, i);
				continue;
			}
			case 3:
			{
				report(fOut, (rows>=2 && cols>=2), i);
				continue;
			}
			case 4:
			{
				report(fOut, (rows>=3 && cols>=3), i);
				continue;
			}
			case 5:
			{
				report(fOut, (rows>=4 && cols>=4), i);
				continue;
			}
			case 6:
			{
				report(fOut, (rows>=4 && cols>=4), i);
				continue;
			}
			default:
			{
				report(fOut, false, i);
				continue;
			}
		} // switch tileSize
	} // for i in cases

	return 0;
}
