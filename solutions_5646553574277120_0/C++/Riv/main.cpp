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

	int c,d,v; //keys, word, string
	vector<int> den;

	double answer;
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
			iss >> t.c;
			iss >> t.d;
			iss >> t.v;
			
			t.den.resize(t.d);
			getline(in_file, line);
			iss.clear();
			iss.str( line );
			for ( int j = 0; j < t.d; j++ )
				iss >> t.den[j];
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

void perfect()
{
}

// assume we can make anything less than that number as will have already tried
bool can_make(int c, vector<int> den, int v )
{
	int count = 0;
	int* left = new int[den.size()];
	for (int i = 0; i < den.size(); i++)
		left[i] = c;

	for (int i = den.size()-1; i >= 0; )
	{
		if (den[i]+count > v)
		{
			i--;
			continue;
		}
		if (left[i] == 0)
		{
			i--;
			continue;
		}
		left[i]--;
		count += den[i];
	}

	return count==v;
}

void TestCase::solve()
{
	for (int i = 1; i <= v; i++)
	{
		if (!can_make(c,den,i))
		{
			auto it = den.begin();
			while ( it != den.end() && (*it) < i )
				it++;
			den.emplace(it, i);
		}
	}
	answer = den.size() - d;
}











