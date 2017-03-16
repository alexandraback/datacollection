// test1.cpp : Defines the entry point for the console application.
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
		sline >> E >> R >> items;
		getline(cin, line);
		sline = stringstream(line);
		copy(istream_iterator<int>(sline), istream_iterator<int>(),back_insert_iterator<vector<int> >(W));
	}

	int rec_solve(int index, int cur_E, string space){
		if(index >= items || cur_E > E) {
			return 0;
		}

		int this_W = W[index];
		int cur_best = 0;
		for(int i = 0; i <= cur_E; ++i){
			int this_sol = i * this_W + rec_solve(index + 1, cur_E - i + R, "  " + space);
			if(this_sol > cur_best) cur_best = this_sol;
			//cout << space << "Use " << i << " on item " << index << " Got " << this_sol << endl;
		}

		return cur_best;
	}

	int solve(){
		return rec_solve(0, E, "");
	}

private:
	int E;
	int R;
	int items;
	vector<int> W;
};

class MYE{
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
	MYE mye;

	mye.parse_testcases();
	mye.solve();
	return 0;
}


