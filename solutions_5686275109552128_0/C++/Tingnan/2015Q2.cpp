#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <queue>
#include <algorithm>

using namespace std;

class Pancakes
{	
	vector<int> mCnt;
public:
	priority_queue<int> mCakes;
	Pancakes() : mCnt(0) {}
	void compute();
	int getCount() {return *min_element(mCnt.begin(), mCnt.end()); }
};

void Pancakes::compute()
{
	// suppose we have already initialized the priority queue
	// each time we stop and split the dish, we choose the highest pile to split
	mCnt.push_back(mCakes.top());
	// the current ountd
	int rd = 0;
	while(true)
	{
		// remove a top element
		int tmp = mCakes.top();
		int newMax = tmp + rd;
		mCnt.push_back(newMax);
		// stop if the time excceds the last computed
		if (tmp == 1)
			break;
		mCakes.pop();
		// then split by half
		int t1 = tmp / 2;
		int t2 = tmp - t1;
		// push those two into pq
		mCakes.push(t1);
		mCakes.push(t2);
		rd++;
	}

}


void RunTests(string fname)
{
	ifstream tf(fname);
	ofstream of("test.out");
	string line;
	getline(tf, line);
	int nTests = stoi(line);
	// cout << nTests << endl;
	for (int i = 0; i < nTests; ++i)
	{
		// create a testcase class
		Pancakes tc;
		// now inteprete each line;
		getline(tf, line);
		// number of people
		int np = stoi(line);
		// get a new line that contains the plate distribution
		getline(tf, line);
		// now split the string
		stringstream ss(line);
		// of << "Case #" << i + 1 << ": " << t.getCount() << endl;
		istream_iterator<string> begin(ss);
		istream_iterator<string> end;
		vector<string> vstrings(begin, end);

		int nP = vstrings.size();
		assert(np == nP);
		for (int j = 0; j < np; ++j)
		{
			tc.mCakes.push(stoi(vstrings[j]));
		}
		tc.compute();
		of << "Case #" << i + 1 << ": " << tc.getCount() << "\n";
	}
}


int main()
{
	RunTests("B-small-attempt0.in");
	return 0;
}