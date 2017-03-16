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

class Ominous
{
protected:
	int mX, mR, mC;
public:
	Ominous(int X, int R, int C) :
	mX(X)
	{
		// make sure R >= C
		mR = R >= C? R : C;
		mC = R <= C? R : C;
	}
	bool computeSmall();
};


bool Ominous::computeSmall()
{
	// return true if RICHARD Wins
	// return false if GABRIEL Wins
	// first check for modulus
	if ((mR * mC) % mX != 0)
		return true;
	// now cut branches
	// 1 and 2 onimous are very simple
	if (mX == 1 || mX == 2)
		return false;
	if (mX == 3)
	{
		// now check for mR and mC
		if (mC < 2)
		{
			// RIC wins
			return true;
		}
		// GAB wins
		return false;
	}
	if (mX == 4)
	{
		if (mC < 3)
		{
			return true;
		}
		return false;
	}
	assert(0);
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
		// now inteprete each line;
		getline(tf, line);
		// now split the string
		stringstream ss(line);
		istream_iterator<string> begin(ss);
		istream_iterator<string> end;
		vector<string> vstrings(begin, end);
		// initialize the test class
		Ominous tc(stoi(vstrings[0]), stoi(vstrings[1]), stoi(vstrings[2]));
		if (tc.computeSmall())
		{
			of << "Case #" << i + 1 << ": " << "RICHARD" << "\n";
		}
		else
		{
			of << "Case #" << i + 1 << ": " << "GABRIEL" << "\n";
		}
	}
}


int main()
{
	RunTests("D-small-attempt0.in");
	return 0;
}

