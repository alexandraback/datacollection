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
	long index = (a - 'h') * 4 + (b - 'h');
	return kSymbTable[index];
}

const bool kSignTable[16] = {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1};
bool SignTable(char a, char b)
{
	long index = (a - 'h') * 4 + (b - 'h');
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
	Quaternion conj() const
	{
		// conjugate of this 
		Quaternion q = *this;

		if (q.symb == 'h')
		{

		}
		else
		{
			q.sign = q.sign != true;
		}

		return q;
	}
	bool operator == (const Quaternion& other) const
	{
		return (symb == other.symb) && (sign == other.sign);
	}
	Quaternion(bool sign, char symb) :
	sign(sign), symb (symb)
	{}
	Quaternion() {}
};

const Quaternion kQi(false, 'i');
const Quaternion kQj(false, 'j');
const Quaternion kQk(false, 'k');


class Dijkstra
{
protected:
	long mX;
	long mL;
	// the prefix symbol table
	vector<Quaternion> mPattern;
	Quaternion mLn[4];
public:
	// the basic string
	vector<Quaternion> mBase;
public:
	Dijkstra() {}
	Dijkstra(long X, long L) : mX(X), mL(L), mBase(mL), mPattern(mL) {}
	void computePattern()
	{
		// suppose we have already initilized the base quaternion
		mPattern[0] = mBase[0];
		long i = 1;
		while (i < mL)
		{
			// the pattern table contains produc of mBase[0] *...* mBase[i]
			mPattern[i] = mPattern[i - 1] * mBase[i];
			++i;
		}
		// let us compute a L repeat table
		Quaternion id(false, 'h');
		mLn[0] = id;
		mLn[1] = mPattern[mL - 1] * mLn[0];
		mLn[2] = mPattern[mL - 1] * mLn[1];
		mLn[3] = mPattern[mL - 1] * mLn[2];

	}

	bool compute()
	{
		// suppose X >= 12
		long X = mX % 4;
		// cut branch using precomputed table

		if (mLn[X].symb != 'h' || mLn[X].sign != true)
		{
			return false;
		}

		// first consider the case when we have to cut two strings
		long rem = (mX - 2) % 4;

		// the rem is a constralong condition which we have  to satisfy 
		for (long l1 = 0; l1 < 4; ++l1)
		{
			for (long l2 = 0; l2 < 4; ++l2)
			{
				for (long l3 = 0; l3 < 4; ++l3)
				{
					// satisfy the constralong
					if ((l1 + l2 + l3) % 4 != rem)
						continue;
					if (twocut(l1, l2, l3))
						return true;
				}
			}
		}

		// now consider when the two cuts are in the same place
		if (mL >= 3)
		{
			rem = (mX - 1) % 4;
			for (long l1 = 0; l1 < 4; ++l1)
			{
				for (long l2 = 0; l2 < 4; ++l2)
				{
					if ((l1 + l2) % 4 != rem)
						continue;
					if (onecut(l1, l2))
						return true;
				}
			}
		}

		return false;
	}

	bool onecut(long l1, long l2)
	{
		for (long i = 0; i < mL - 1; ++i)
		{
			Quaternion first = mPattern[i];
			if (!(mLn[l1] * first == kQi))
				continue;
			for (long j = i + 1; j < mL; ++j)
			{
				// compute the middle
				
				Quaternion middle = first.conj() * mPattern[j];
				if (!(middle == kQj))
					continue;

				// compute the last 
				Quaternion last  = mPattern[j].conj() * mPattern[mL - 1];

				if (!(last * mLn[l2] == kQk))
					continue;
				return true;
			}
		}
		return false;
	}

	bool twocut(long l1, long l2, long l3)
	{
		for (long i = 0; i < mL; ++i)
		{
			Quaternion q1 = mPattern[i];
			Quaternion q2 = q1.conj() * mPattern[mL - 1];
			for (long j = 0; j < mL; ++j)
			{
				Quaternion q3 = mPattern[j];
				Quaternion q4 = q3.conj() * mPattern[mL - 1];
				// now compute 
				Quaternion first = mLn[l1] * q1;
				Quaternion second = q2 * mLn[l2] * q3;
				Quaternion third = q4 * mLn[l3];
				if ((first == kQi) && (second == kQj) && (third == kQk))
				{
					return true;
				}
			}
		}
		return false;
	}


	bool computeBrute()
	{
		assert(mX == 1);
		if (mL < 3)
		{
			return false;
		}

		if (mPattern[mL - 1 ].symb == 'h' && mPattern[mL - 1].sign == false)
			return false;

		// cut in the same string
		return onecut(0, 0);
	}
};


void RunTests(string fname)
{
	ifstream tf(fname);
	ofstream of("test.out");
	string line;
	getline(tf, line);
	long nTests = stoi(line);
	// cout << nTests << endl;
	for (long i = 0; i < nTests; ++i)
	{
		// now longeprete each line;
		getline(tf, line);
		// now split the string
		stringstream ss(line);
		istream_iterator<string> begin(ss);
		istream_iterator<string> end;
		vector<string> vstrings(begin, end);
		cout << vstrings[1] << endl;
		long L = stol(vstrings[0]);
		long X = stol(vstrings[1]);

		// create the test case

		if (X < 12)
		{
			Dijkstra solver(1, X * L);
			// ge the symbol line
			getline(tf, line);

			for (long j = 0; j < X; ++j)
			{
				for (long i = 0; i < L; ++i)
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
		else
		{
			Dijkstra solver(X, L);
			// ge the symbol line
			getline(tf, line);
			for (long i = 0; i < L; ++i)
			{
				solver.mBase[i].symb = line[i];
				solver.mBase[i].sign = false;
			}

			solver.computePattern();

			if (solver.compute())
				of << "Case #" << i + 1 << ": YES\n";
			else
				of << "Case #" << i + 1 << ": NO\n";

		}
	}
}


int main()
{
	RunTests("C-large.in");
	/*
	const char *array = "hijk";
	for (long i = 0; i < 4; ++i)
	{
		Quaternion a;
		a.sign = false;
		a.symb = array[i];

		for (long j = 0; j < 4; ++j)
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