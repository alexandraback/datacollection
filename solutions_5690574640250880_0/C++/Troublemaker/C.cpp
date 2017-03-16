
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
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
private:
    bool Result;
    vector<vector<char> > Result1;
	bool Transp;

	int C, R, M;

    void Load();
    void Run();
    void Print();
public:
    TTestCase();
    ~TTestCase();
};


TTestCase::TTestCase()
{
	Load();

    Run();
}

void TTestCase::Load()
{
    cin >> R >> C >> M;
}

void TTestCase::Run()
{
	Result = false;
	Transp = false;
	if(M == C*R)
		return; //case A

	int RR = min(R, C);
	int CC = max(R, C);
	if(R > C)
	{
		Transp = true;
	}

	Result1.resize(RR);
	FOR(i, 0, RR)
		Result1[i].resize(CC);

	if(M == CC*RR-1)
	{
		Result = true;
		FOR(i, 0, RR)
			FOR(j, 0, CC)
				Result1[i][j] = '*';
		Result1[0][0] = 'c';
		return; //case B
	}

	if(RR == 1)
	{
		Result = true;
		FOR(j, 0, CC)
		{
			if(M > 0)
				--M, Result1[0][j] = '*';
			else
				Result1[0][j] = '.';
		}
		Result1[0][CC-1] = 'c';
		return; //case C
	}

	if(RR == 2)
	{
		if(M%2 == 1 || (CC*RR-M) == 2)
		{
			return; //case D1
		}
		else
		{
			Result = true;
			FOR(j, 0, CC)
				FOR(i, 0, RR)
				{
					if(M > 0)
						--M, Result1[i][j] = '*';
					else
						Result1[i][j] = '.';
				}
			Result1[RR-1][CC-1] = 'c';
			return; //case D2
		}
	}

	if((CC*RR - M) == 2 ||
	   (CC*RR - M) == 3 ||
	   (CC*RR - M) == 5 ||
	   (CC*RR - M) == 7)
	{
		return;
	}

	Result = true;
	if((CC*RR - M) % 2 == 0)
	{
		FOR(j,0,CC-2)
			FOR(i,0,RR-2)
				if(M == 0)
					Result1[i][j] = '.';
				else
					--M, Result1[i][j] = '*';
		FOR(j,0,CC-2)
			FOR(i,RR-2,RR)
				if(M == 0)
					Result1[i][j] = '.';
				else
					--M, Result1[i][j] = '*';
		FOR(i,0,RR)
			FOR(j,CC-2,CC)
				if(M == 0)
					Result1[i][j] = '.';
				else
					--M, Result1[i][j] = '*';
		Result1[RR-1][CC-1] = 'c';
	}
	else
	{
		FOR(i,RR-3,RR)
			FOR(j,CC-3,CC)
				Result1[i][j] = '.';

		FOR(j,0,CC-2)
			FOR(i,0,RR-3)
				if(M == 0)
					Result1[i][j] = '.';
				else
					--M, Result1[i][j] = '*';
		FOR(j,0,CC-3)
			if(M == 0)
				Result1[RR-3][j] = '.';
			else
				--M, Result1[RR-3][j] = '*';
		FOR(j,0,CC-3)
			FOR(i,RR-2,RR)
				if(M == 0)
					Result1[i][j] = '.';
				else
					--M, Result1[i][j] = '*';
		FOR(i,0,RR)
			FOR(j,CC-2,CC)
				if(M == 0)
					Result1[i][j] = '.';
				else
					--M, Result1[i][j] = '*';

		Result1[RR-1][CC-1] = 'c';
	}

	/*if(M % RR == 0)
	{
		if(M <= (CC-2)*RR)
		{
			Result = true;
			FOR(j,0,CC)
				FOR(i,0,RR)
				{
					if(M == 0)
						Result1[i][j] = '.';
					else
					{
						Result1[i][j] = '*';
						--M;
					}
				}
			Result1[RR-1][CC-1] = 'c';
		}
		return;
	}

	if(M > (RR*(CC-2)))
	{
		if(M == RR*CC-2)
			return;
		if((M - (RR*CC-2)) % 2 != 0)
			return;

		Result = true;
		int j=0;
		for(; j<CC-2; ++j)
			FOR(i, 0, RR)
				Result1[i][j] = '*';
		for(; j<CC; ++j)
			FOR(i, 0, RR)
				Result1[i][j] = '.';

		M -= RR*(CC-2);

		FOR(i,0,RR)
			FOR(j,0,2)
			{
				if(M>0)
					--M, Result1[i][CC-2 + j] = '*';
				else
					Result1[i][CC-2 + j] = '.';
			}

		Result1[R-1][C-1] = 'c';
		return;
	}

	if(RR == 2 && (M%2 != 0))
	{
		return;
	}

	// RR > 2
	if(RR == 3 && M == RR*CC-7)
	{
		return;
	}

	Result = true;
	int j=0;
	for(; j<M/RR; ++j)
		FOR(i, 0, RR)
			Result1[i][j] = '*';
	for(; j<CC; ++j)
		FOR(i, 0, RR)
			Result1[i][j] = '.';

	for(int i=0; i<M%RR && i<(RR-2); ++i)
		Result1[i][M/RR + 0] = '*';

	if(M%RR == RR-1)
		Result1[0][M/RR + 1] = '*';

	Result1[RR-1][CC-1] = 'c';*/
}


TTestCase::~TTestCase()
{
	cout << endl;
	fsOut << endl;
	if(Result)
	{
		FOR(i,0,R)
		{
			FOR(j,0,C)
			{
				if(Transp)
				{
					cout << Result1[j][i];
					fsOut << Result1[j][i];
				}
				else
				{
					cout << Result1[i][j];
					fsOut << Result1[i][j];
				}
			}
			cout << endl;
			fsOut << endl;
		}
	}
	else
	{
		cout << "Impossible" << endl;
		fsOut << "Impossible" << endl;
	}
}

void TTestCase::Print()
{
#ifndef PRINT
    return;
#endif
}








int main()
{
    if(!fsIn.is_open())
    {
        cout << "No input file found";
    }
    cin.rdbuf( fsIn.rdbuf() );

    int numberOfCases;
    cin >> numberOfCases;

	for( int caseNum = 1; caseNum <= numberOfCases; ++caseNum )
	{
        TTestCase testCase;

        
        cout << "Case #" << caseNum << ": ";
        fsOut << "Case #" << caseNum << ": ";
	}
	
	cout << "Finished";
    for(;;);
	return 0;
}
