//	main: load input, run tasks, write output

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <assert.h>

#include "QD.h"

using namespace std;

///////////////////////////////////////////////////////////

class CInParser {
public:
	explicit CInParser( const std::string& fileName );

	int ReadLineAsInt();
	std::string ReadLineAsString();
	void ReadLineAsIntsVector( std::vector<int>& ints );
	void ReadLineAsIntsVector( std::vector<__int64>& ints );
	void ReadLineAsIntAndString(int& n, std::string& str);

private:
	std::ifstream inFile;
};

///////////////////////////////////////////////////////////

//const string inFileName = "./../in/test.txt";
//const string outFileName = "./../out/test.txt";

//const string inFileName = "./../in/D-small-attempt2.in";
//const string outFileName = "./../out/D-small-attempt2.out";
const string inFileName = "./../in/D-large.in";
const string outFileName = "./../out/D-large.out";


void writeOutput( std::ofstream& outFile, int setN, bool result )
{
	outFile << "Case #" << setN << ": " << (result ? "RICHARD" : "GABRIEL") << "\n";
}

///////////////////////////////////////////////////////////

CInParser::CInParser( const string& fileName )
{
	inFile.open( fileName.c_str() );
}

int CInParser::ReadLineAsInt()
{
	std::string line;
	std::getline(inFile, line);
	std::istringstream iss(line);
	int result = 0;
	iss >> result;
	return result;
}

//	N "str"
void CInParser::ReadLineAsIntAndString(int& n, std::string& str)
{
	std::string line;
	std::getline(inFile, line);
	std::istringstream iss(line);
	iss >> n;
	iss >> str;
}

std::string CInParser::ReadLineAsString()
{
	std::string line;
	std::getline(inFile, line);
	return line;
}

void CInParser::ReadLineAsIntsVector( std::vector<int>& ints )
{
	std::string line;
	std::getline(inFile, line);
	std::istringstream iss(line);
	ints.clear();
	int n = 0;
	while(iss >> n) {
		ints.push_back(n);
	}
}

void CInParser::ReadLineAsIntsVector( std::vector<__int64>& ints )
{
	std::string line;
	std::getline(inFile, line);
	std::istringstream iss(line);
	ints.clear();
	__int64 n = 0;
	while(iss >> n) {
		ints.push_back(n);
	}
}

///////////////////////////////////////////////////////////

void parseInFile( CInParser& parser, int& X, int& R, int& C )
{
	std::vector<int> ints;
	parser.ReadLineAsIntsVector( ints );
	assert( ints.size() == 3 );
	X = ints[0];
	R = ints[1];
	C = ints[2];
}

int main(int argc, char* argv[])
{
	//	parse input
	CInParser parser( inFileName );
	const int numberOfSets = parser.ReadLineAsInt();
	assert( numberOfSets > 0 );

	std::ofstream outFile( outFileName.c_str() );

	CQDTaskProcessor taskProcessor;

	for( int setN = 1; setN <= numberOfSets; setN++ ) {
		cout << "Processing set #" << setN <<"...\n";

		//	parse in file
		int X = 0;
		int R = 0;
		int C = 0;
		parseInFile( parser, X, R, C );

		//	process		
		const bool result = taskProcessor.doesNastyOminoExist( X, R, C );

		//	output
		writeOutput( outFile, setN, result );
	}

	return 0;
}

