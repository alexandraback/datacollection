#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define FROM_0_TO(i,n) FOR(i,0,n) 

#define PRINT

#define TASKNUM "A"
#define DATASET "large"

ifstream fsIn(TASKNUM "-" DATASET "-practice.in.txt");
ofstream fsOut(TASKNUM "-" DATASET "-practice.out.txt");

class TTestCase
{
public:
private:
	int Result;
	int X, R, C;

	void Load();
	void Run();


	void Print();
public:
	TTestCase();
	~TTestCase();
};


void TTestCase::Run()
{
	if (R > C)
		swap(R, C);

	if (X == 1)
		Result = 2;
	else if (R*C % X == 0)
	{
		if (X == 2)
			Result = 2;
		else
		{
			// X > 2
			if (R == 1)
				Result = 1;
			else
			{
				if (X == 3)
					Result = 2;
				else
				{
					// X > 3
					if (R == 2)
						Result = 1;
					else
					{
						// R > 2
						if (X == 4)
							Result = 2;
						else
						{
							// X > 4
							if (X == 5)
							{
								if (R == 3 && C == 5)
									Result = 1;
								else
									Result = 2;
							}
							else
							{
								// X > 5
								if (X == 6)
								{
									if (R == 3)
										Result = 1;
									else
										Result = 2;
								}
								else
									Result = 1;
							}
						}
					}
				}
			}
		}
	}
	else
		Result = 1;

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
	cin >> X >> R >> C;
}

TTestCase::~TTestCase()
{
	cout << (Result == 1? "RICHARD": "GABRIEL") << endl;
	fsOut << (Result == 1 ? "RICHARD" : "GABRIEL") << endl;
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
