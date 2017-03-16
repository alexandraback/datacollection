// test1.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std; 

class testcase {
public:
	void parse_testcase(){
		string line;
		getline(cin, line);
		stringstream sline(line);
		sline >> _r >> _t;
	}

	int solve(){
		int c = 0;
		while(_t >= 0){
			int paint = 2 * _r + 4 * c + 1;
			//cout << "has " << _t << " need " <<paint << endl;
			if (_t >= paint){
				++c;
				_t -= paint;
			}
			else
				break;
		}
		return c;
	}

private:
	int _t;
	int _r;
};

class Bullseye{
public:
	void parse_testcases(){
		string line;
		getline(cin, line);
		stringstream sline(line);
		sline >> _count;
		for(int i = 0; i < _count; ++i){
			testcase tc;
			tc.parse_testcase();
			_tcs.push_back(tc);
		}	
	}
	void solve(){
		int i = 0;
		for(i = 0; i < _count; ++i){
			cout <<"Case #" << i + 1 <<": " << _tcs[i].solve() << endl;
		}
	}

private:
	vector<testcase> _tcs;
	int _count;
};

int main(int argc, char* argv[])
{
	Bullseye be;

	be.parse_testcases();
	be.solve();
	return 0;
}


