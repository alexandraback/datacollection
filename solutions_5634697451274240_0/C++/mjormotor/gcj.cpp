#include <fstream>
#include <string>
#include <vector>
#include <iostream>

//#include "test.h"
//#include "cardshutfle.h"
//#include "coffee.h"
//#include "bitnum.h"
#include "revengeofthepancakes.h"

namespace {
std::string const TARGET = "B-small-attempt0";
std::string const INPUT_PATH = TARGET + ".in";
std::string const OUTPUT_PATH = TARGET + ".out";
}

int main()
{
	std::cout << INPUT_PATH << " loading.." << std::endl;

	std::ifstream ifs( INPUT_PATH );
	std::string buf;
	std::vector< std::string > in;

	while( ifs && getline( ifs, buf ) )
	{
		in.push_back( buf );
	}

	RevengeOfThePancakesProblem* problem = new RevengeOfThePancakesProblem();
	problem->Init( in );
	problem->DumpState();
	problem->Solve();
	problem->DumpAnswer();
	std::vector< std::string > answer = problem->GetAnswer();
	
	std::cout << OUTPUT_PATH << " saving.." << std::endl;

	std::ofstream ofs( OUTPUT_PATH );
	
//	problem->OutputStateAndAnswer( ofs );
	if( ofs )
	{
		for( unsigned int i = 0; i < answer.size(); ++i )
		{
			ofs << "Case #" << i + 1 << ": " << answer[i] << std::endl;
		}
	}

	delete problem;

	return 0;
}