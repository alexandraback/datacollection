#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cassert>

using namespace std;

class OvationTestCase
{
protected:
	int mMax;
	int mCnt;
public:
	vector<int> mLevel;
public:
	OvationTestCase(int s) : 
	mMax(s),
	mCnt(0),
	mLevel(s) // ignore the highest
	{
	} 
	void compute();
	int getCount() {return mCnt;}
};

void OvationTestCase::compute()
{
	int sum = 0; // the sum of number of people below a shiness level
	// the loop ends at sMax - 1
	for (int i = 0; i < mMax; ++i)
	{
		sum += mLevel[i];
		if (sum < i + 1)
		{
			mCnt += i + 1 - sum;
			sum = i + 1;
		}
	}
}

void RunTests(string fname)
{
	ifstream tf(fname);
	string line;
	getline(tf, line);
	int nTests = stoi(line);
	// cout << nTests << std::endl;
	for (int i = 0; i < nTests; ++i)
	{
		// create a testcase class
		// now inteprete each line;
		getline(tf, line);
		size_t idx;
		int sMax = stoi(line, &idx);
		OvationTestCase t(sMax);
		// idx + 1 is the starting position of the substring
		// that contains the vector;
		for (int j = 0; j < sMax; ++j)
		{
			t.mLevel[j] = line[j + idx + 1] - '0';
		}
		t.compute();
		cout << "Case #" << i + 1 << ": " << t.getCount() << endl;
	}
}

int main()
{
	RunTests("A-small-attempt0.in");
	return 0;
}