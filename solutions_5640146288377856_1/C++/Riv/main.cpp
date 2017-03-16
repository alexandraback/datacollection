///////////////////////////// TestCase::solve is the problem specific code

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;

bool debug = false;

class TestCase
{
public:
	int ass_id;
	int r,c,w;

	int answer;
	TestCase() {}
	TestCase( int assigned_id ) : ass_id(assigned_id) {}
	void solve();
	void print( ostream& out )
	{
		out<<"Case #"<<(ass_id)<<": "<<(answer);
	}
	void solve_print( ostream& out )
	{
		solve();
		print( out );
	}
};
class DataSet
{
	vector<TestCase> test_cases;
public:
	void init()
	{
		ifstream in_file( "in.txt" );

		string line;
		istringstream iss;

		getline(in_file, line);
		iss.str(line);
		int count_cases;
		iss >> count_cases;
		string s_str;
		test_cases.resize(count_cases);
		for ( int i = 0; i < count_cases; i++ )
		{
			getline(in_file, line);
			iss.clear();
			iss.str( line );
			TestCase& t = test_cases[i];
			t = TestCase( i+1 );
			iss >> t.r;
			iss >> t.c;
			iss >> t.w;
		}
	}
	void calc()
	{
		ofstream out_file( "out.txt" );
		ostream& out = debug ? cout : out_file;
		for ( uint32_t i = 0; i<test_cases.size() && ( !i || &(out<<endl) ); i++ )
		{
			test_cases[i].solve_print( out );
		}
	}
};

DataSet data_set;

int main()
{
	data_set.init();
	data_set.calc();
	
	if ( debug )
		cin.get();
}

////////////////// Problem related code starts here


void TestCase::solve()
{
	int cbyw = (c/w);

	answer = (r-1)*cbyw;

	answer += cbyw-1;

	if (c%w==0)
	{
		answer += w;
	}
	else
	{
		if (c>w)
			answer += 1+w;
	}

//	answer += c-((cbyw-1)*w);
}











