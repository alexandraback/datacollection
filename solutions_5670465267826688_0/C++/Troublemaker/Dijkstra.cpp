#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cstdint>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define FROM_0_TO(i,n) FOR(i,0,n) 

#define PRINT

#define TASKNUM "C"
#define DATASET "small"

ifstream fsIn(TASKNUM "-" DATASET "-practice.in.txt");
ofstream fsOut(TASKNUM "-" DATASET "-practice.out.txt");

class TTestCase
{
public:
private:
	bool Result;
	uint64_t L, X;
	string S;
	
	char Mult(string &s);
	char Mult(char a, char b);
	bool Try(string &s, int T);

	void Load();
	void Run();
	void Print();
public:
	TTestCase();
	~TTestCase();
};

char TTestCase::Mult(char a, char b)
{
	switch (a)
	{
	case '1':
		switch (b)
		{
		case 'i':
			return 'i';
		case 'j':
			return 'j';
		case 'k':
			return 'k';
		}
	case 'i':
		switch (b)
		{
		case 'i':
			return '-';
		case 'j':
			return 'k';
		case 'k':
			return 'J';
		}
	case 'j':
		switch (b)
		{
		case 'i':
			return 'K';
		case 'j':
			return '-';
		case 'k':
			return 'i';
		}
	case 'k':
		switch (b)
		{
		case 'i':
			return 'j';
		case 'j':
			return 'I';
		case 'k':
			return '-';
		}
	case '-':
		switch (b)
		{
		case 'i':
			return 'I';
		case 'j':
			return 'J';
		case 'k':
			return 'K';
		}
	case 'I':
		switch (b)
		{
		case 'i':
			return '1';
		case 'j':
			return 'K';
		case 'k':
			return 'j';
		}
	case 'J':
		switch (b)
		{
		case 'i':
			return 'k';
		case 'j':
			return '1';
		case 'k':
			return 'I';
		}
	case 'K':
		switch (b)
		{
		case 'i':
			return 'J';
		case 'j':
			return 'i';
		case 'k':
			return '1';
		}
	}
}

char TTestCase::Mult(string &s)
{
	char res = s[0];

	for (auto i = 1; i < s.size(); ++i)
	{
		res = Mult(res, s[i]);
	}

	return res;
}

bool TTestCase::Try(string &s, int T)
{
	char acc = '1';
	char state = '1';
	for (auto t = 0; t < T; ++t)
	{
		for (auto i = 0; i < s.size(); ++i)
		{
			acc = Mult(acc, s[i]);
			if (acc == 'i' && state == '1')
			{
				state = 'i';
				acc = '1';
			}
			else if (acc == 'j' && state == 'i')
			{
				state = 'j';
				acc = '1';
			}
			else if (acc == 'k' && state == 'j')
			{
				return true;
			}
		}
	}
	return false;
}

void TTestCase::Run()
{
	Result = false;
	char r = Mult(S);
	if (r == '1')
	{
		return;
	}
	else if (r == '-')
	{
		if (X % 2 == 0)
			return;
	}
	else if (r == 'i' || r == 'j' || r == 'k')
	{
		if (X % 4 != 2)
			return;
	}
	else //if (r == 'I' || r == 'J' || r == 'K')
	{
		if (X % 4 != 2)
			return;
	}

	Result = Try(S, min(20ULL, X));
}






void TTestCase::Print()
{
#ifndef PRINT
	return;
#endif
}

TTestCase::TTestCase()
	: Result(0)
{
	Load();
	Run();
}

void TTestCase::Load()
{
	cin >> L >> X;
	cin >> S;
}

TTestCase::~TTestCase()
{
	cout << (Result? "YES": "NO") << endl;
	fsOut << (Result ? "YES" : "NO") << endl;
}

int main()
{
	if (!fsIn.is_open())
	{
		cout << "No input file found";
	}
	cin.rdbuf(fsIn.rdbuf());

	int numberOfCases;
	cin >> numberOfCases;

	for (int caseNum = 1; caseNum <= numberOfCases; ++caseNum)
	{
		TTestCase testCase;


		cout << "Case #" << caseNum << ": ";
		fsOut << "Case #" << caseNum << ": ";
	}

	cout << "Finished";
	for (;;);
	return 0;
}
