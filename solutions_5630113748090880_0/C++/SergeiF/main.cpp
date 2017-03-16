//	main: load input, run tasks, write output

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <assert.h>

#include "TaskProcessor.h"

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
const string inFileName = "./../in/B-small-attempt0.in";
const string outFileName = "./../out/B-small-attempt0.out";
//const string inFileName = "./../in/A-large.in";
//const string outFileName = "./../out/A-large.out";

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

void writeOutput( std::ofstream& outFile, int setN, const vector<int>& result )
{
	outFile << "Case #" << setN << ": ";
	for( int i = 0; i < (int)result.size(); i++ ) {
		outFile << result[i];
		if( i < (int)result.size() - 1 ) {
			outFile << " ";
		}
	}
	outFile << "\n";
}

int parseInFile( CInParser& parser, vector< vector<int> >& lines )
{
	const int N = parser.ReadLineAsInt();
	assert( N > 0 );
	lines.resize( 2 * N - 1 );
	for( int i = 0; i < 2 * N - 1; i++ ) {
		parser.ReadLineAsIntsVector( lines[i] );
		assert( lines[i].size() == N );
	}
	return N;
}

int main(int argc, char* argv[])
{
	//	parse input
	CInParser parser( inFileName );
	const int numberOfSets = parser.ReadLineAsInt();
	assert( numberOfSets > 0 );

	std::ofstream outFile( outFileName.c_str() );

	CTaskProcessor taskProcessor;

	for( int setN = 1; setN <= numberOfSets; setN++ ) {
		cout << "Processing set #" << setN <<"...\n";

		//	parse in file
		vector< vector<int> > lines;
		const int N = parseInFile( parser, lines );

		//	process		
		vector<int> missingLine;
		taskProcessor.findMissingLine( lines, missingLine );

		//	output
		writeOutput( outFile, setN, missingLine );
	}

	return 0;
}

