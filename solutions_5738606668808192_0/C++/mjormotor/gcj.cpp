#include <fstream>
#include <string>
#include <vector>
#include <iostream>

//#include "test.h"
//#include "cardshutfle.h"
//#include "coffee.h"
//#include "bitnum.h"
#include "coinjam.h"

namespace {
std::string const TARGET = "C-small-attempt1";
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

	CoinJamProblem* problem = new CoinJamProblem();
	problem->Init( in );
	//problem->DumpState();
	problem->Solve();
	//problem->DumpAnswer();
	std::vector< std::string > const& answer = problem->GetAnswer();
	
	std::cout << OUTPUT_PATH << " saving.." << std::endl;

	std::ofstream ofs( OUTPUT_PATH );

#if 0
	problem->OutputStateAndAnswer( ofs );
#else
	if( ofs )
	{
		ofs << "Case #1:" << std::endl;
		for( unsigned int i = 0; i < answer.size(); ++i )
		{
			ofs << answer[i].c_str() << std::endl;
		}
	}
#endif

	delete problem;
	
	return 0;
}