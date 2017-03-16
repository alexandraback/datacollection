#include <cstdlib>

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <boost/current_function.hpp>

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
// Problem util
//////////////////////////////////////////////////////////////////////////

typedef int Dim;
static Dim const DIM_R = 1;
static Dim const DIM_I = 2;
static Dim const DIM_J = 3;
static Dim const DIM_K = 4;
static size_t const DIMS = 4;

class MulTool
{
public:
	/**
	* 1 -> Real; -1 -> -Real;
	* 2 -> i   ; -2 -> -i   ;
	* 3 -> j   ; -3 -> -j   ;
	* 4 -> k   ; -4 -> -k   ;
	*/
	typedef unsigned int Index;
	static size_t const ROW_LEN = 5; // convenience for addressing
	static size_t const COL_COUNT = 5; // convenience for addressing
	static size_t const CELL_COUNT = ROW_LEN * COL_COUNT;
	typedef std::vector<Dim> RawType;

	static Dim mul(Dim dim1, Dim dim2)
	{
		ASSERT(dim1);
		ASSERT(dim2);
		Dim const abs1 = abs(dim1);
		Dim const sign1 = dim1 / abs1;
		Dim const abs2 = abs(dim2);
		Dim const sign2 = dim2 / abs2;
		Index const offset = toOffset((Index)abs1, (Index)abs2);
		Dim ret = sign1 * sign2 * table()[ offset ];
		return ret;
	}
public:
	//////////////////////////////////////////////////////////////////////////
	// Lower level approach
	//////////////////////////////////////////////////////////////////////////
	static RawType const & table()
	{
		static RawType data = _createTable();
		return data;
	}
	static Index toOffset(Index first, Index second)
	{
		return first * ROW_LEN + second;
	}
	static Index toFirst(Index offset)
	{
		return offset / ROW_LEN;
	}
	static Index toSecond(Index offset)
	{
		return offset % ROW_LEN;
	}
private:
	static RawType _createTable()
	{
		RawType ret;
		ret.reserve(CELL_COUNT);
		Dim data[] = {
			   0,  0,  0,  0,  0
			,  0,  1,  2,  3,  4
			,  0,  2, -1,  4, -3
			,  0,  3, -4, -1,  2
			,  0,  4,  3, -2, -1
		};
		for(size_t i = 0; i < CELL_COUNT; ++i)
			ret.push_back(data[i]);
		return ret;
	}
};

//////////////////////////////////////////////////////////////////////////
// Problam control
//////////////////////////////////////////////////////////////////////////

typedef std::vector<Dim> Sample;
typedef size_t Pos;

inline
Dim dimOfInput(Sample const &sample, Pos pos)
{
	return sample[pos % sample.size()];
}

inline
Dim prod(Sample const &sample, Pos const beg, Pos const end)
{
	Dim ret = DIM_R;
	for(Pos pos = beg; pos!=end; ++pos)
		ret = MulTool::mul(ret, dimOfInput(sample, pos));
	return ret;
}

inline
Pos searchLeftI(Sample const &sample, Pos const beg, Pos const end)
{
	Dim p = DIM_R;
	for(Pos pos=beg; pos!=end; ++pos)
	{
		p = MulTool::mul(p, dimOfInput(sample, pos));
		if(p==DIM_I)
			return pos+1;
	}
	return end;
}

inline
Pos searchRightK(Sample const &sample, Pos const beg, Pos const end)
{
	ASSERT(beg>=2);
	Dim p = DIM_R;
	for(Pos pos=end-1; pos>=beg; --pos)
	{
		p = MulTool::mul(dimOfInput(sample, pos), p);
		if(p==DIM_K)
			return pos;
	}
	return 0;
}

inline
bool solve(Sample const &sample, Pos const beg, Pos const end)
{
	if(prod(sample, beg, end)!=-DIM_R)
		return false;
	Pos pos1 = searchLeftI(sample, beg, end);
	ASSERT(pos1>=1);
	if(pos1+2>end)
		return false;
	Pos pos2 = searchRightK(sample, pos1+1, end);
	if(pos2!=0)
		return true;
	return false;
}

//////////////////////////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////////////////////////

inline
Dim charToDim(char c)
{
	return c - 'i' + DIM_I;
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
		size_t sampleLen;
		fIn >> sampleLen;
		size_t repeat;
		fIn >> repeat;
		std::string sampleStr;
		fIn >> sampleStr;
		ASSERT(sampleLen==sampleStr.size());
		Sample sample(sampleLen, DIM_R);
		for(size_t j = 0; j < sampleLen; ++j)
			sample[j] = charToDim(sampleStr[j]);

		// std::cout << sampleStr << " * " << repeat << std::endl;

		bool ok = solve(sample, 0, sampleLen * repeat);

		fOut << "Case #" << (i+1) << ": " << ( ok ? "YES" : "NO" ) << "\n";
		// std::cout << "Case #" << (i+1) << ": " << (ok ? "YES" : "NO") << "\n";
		// std::cout << std::endl;
	}

	return 0;
}
