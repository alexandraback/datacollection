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

const char *kSymbTable = "hijkihkjjkhikjih";
char SymbTable(char a, char b)
{
	int index = (a - 'h') * 4 + (b - 'h');
	return kSymbTable[index];
}

const bool kSignTable[16] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1};
bool SignTable(char a, char b)
{
	int index = (a - 'h') * 4 + (b - 'h');
	return kSignTable[index];
}

struct Quaternion
{
	// sign, 0 for plus and 1 for minus, so we can use xor(!=) to compute new sign
	bool sign;
	// symbol, h, i, j, k, we always convert 1 to h;
	char symb;
	Quaternion operator * (const Quaternion& other) const
	{
		Quaternion q;
		q.symb = SymbTable(symb, other.symb);
		q.sign = (sign != other.sign) != SignTable(symb, other.symb);
		return q;
	}
	Quaternion(bool sign, char symb) :
	sign(sign), symb (symb)
	{}
	Quaternion() {}
};

class Dijkstra
{
protected:
	int mX;
	int mL;
	// the prefix symbol table
	vector<Quaternion> mPattern;
public:
	// the basic string
	vector<Quaternion> mBase;
public:
	Dijkstra() {}
	Dijkstra(int X, int L) : mX(X), mL(L), mBase(mL), mPattern(mL) {}
	void computePattern()
	{
		// suppose we have already initilized the base quaternion
		mPattern[0] = mBase[0];
		int i = 1;
		while (i < mL)
		{
			// the pattern table contains produc of mBase[0] *...* mBase[i]
			mPattern[i] = mPattern[i - 1] * mBase[i];
			++i;
		}
	}
	bool computeBrute()
	{
		assert(mX == 1);
		if (mL < 3)
		{
			return false;
		}
		// cut in the same string
		for (int i = 0; i < mL - 1; ++i)
		{
			Quaternion first = mPattern[i];
			if (first.symb != 'i')
				continue;
			for (int j = i + 1; j < mL; ++j)
			{
				// compute the middle
				Quaternion first_copy = first;
				// flip the sign, because we now only have i j k in the symbol
				first_copy.sign = first_copy.sign != true;
				Quaternion middle = first_copy * mPattern[j];
				if (middle.symb != 'j')
					continue;


				// compute the last 
				Quaternion prefix = mPattern[j];
				if (prefix.symb != 'h')
				{
					// flip the sign
					prefix.sign = prefix.sign != true;
				}
				Quaternion last  = prefix * mPattern[mL - 1];

				if (last.symb != 'k')
					continue;

				if ((first.sign != middle.sign) != last.sign == 0)
					return true;

			}
				
		}
		return false;
	}
};


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
		int L = stoi(vstrings[0]);
		int X = stoi(vstrings[1]);

		// create the test case
		Dijkstra solver(1, X * L);
		// ge the symbol line
		getline(tf, line);

		for (int j = 0; j < X; ++j)
		{
			for (int i = 0; i < L; ++i)
			{
				solver.mBase[i + j * L].symb = line[i];
				solver.mBase[i + j * L].sign = false;
			}
		}
		solver.computePattern();
		if (solver.computeBrute())
			of << "Case #" << i + 1 << ": YES\n";
		else
			of << "Case #" << i + 1 << ": NO\n";
	}
}


int main()
{
	RunTests("C-small-attempt0.in");
	/*
	const char *array = "hijk";
	for (int i = 0; i < 4; ++i)
	{
		Quaternion a;
		a.sign = false;
		a.symb = array[i];

		for (int j = 0; j < 4; ++j)
		{
			Quaternion b;
			b.sign = true;
			b.symb = array[j];

			Quaternion c = a * b;
			cout << c.sign << " " << c.symb << endl;

		}
	}
	*/
	return 0;
}