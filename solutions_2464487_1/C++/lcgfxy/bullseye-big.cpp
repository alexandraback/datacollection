// test1.cpp : Defines the entry polong long for the console application.
//

#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std; 

class testcase {
public:
	void parse_testcase(){
		string line;
		getline(cin, line);
		stringstream sline(line);
		sline >> _r >> _t;
	}

	long long solve(){
		double x = (2.0 * _r + 3) * (2.0 * _r + 3) - 8 * (2.0 * _r + 1 - _t);

		double sol = ((-2.0 * _r - 3) + sqrt(x))/4;

		long long int_sol = long long(floor(sol));
		return int_sol;
	}

private:
	long long _t;
	long long _r;
};

class Bullseye{
public:
	void parse_testcases(){
		string line;
		getline(cin, line);
		stringstream sline(line);
		sline >> _count;
		for(long long i = 0; i < _count; ++i){
			testcase tc;
			tc.parse_testcase();
			_tcs.push_back(tc);
		}	
	}
	void solve(){
		long long i = 0;
		for(i = 0; i < _count; ++i){
			cout <<"Case #" << i + 1 <<": " << _tcs[i].solve() << endl;
		}
	}

private:
	vector<testcase> _tcs;
	long long _count;
};

int main(int argc, char* argv[])
{
	Bullseye be;

	be.parse_testcases();
	be.solve();
	return 0;
}


