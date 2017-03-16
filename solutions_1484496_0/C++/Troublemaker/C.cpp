
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
    unsigned N;
	struct DATA
	{
		__int64 Value;
		int state;
	};
	vector<DATA> D;

	//static bool Cmp( DATA& d1, DATA& d2)
	//{
	//	return d1.Value < d2.Data;
	//}

	bool F(vector<DATA>& d, int pos);

    void Load();
    void Run();
    void Print();
public:
    TTestCase();
    ~TTestCase();
};


TTestCase::TTestCase()
    : Result(-1)
{
	Load();

    Run();
}

void TTestCase::Load()
{
    cin >> N;
	D.resize(N);
	FOR(i,0,N)
	{
		cin >> D[i].Value;
	}
	Result = false;
}

bool TTestCase::F(vector<DATA>& d, int pos)
{
	if(pos == N)
	{
		__int64 v1=0;
		__int64 v2=0;
		FOR(i,0,N)
		{
			if(d[i].state == 1)
				v1 += d[i].Value;
			else if(d[i].state == 2)
				v2 += d[i].Value;
		}
		if(v1==v2 && v1 != 0)
		{
			throw 1;
		}
		return false;
	}
	d[pos].state=0;
	F(d,pos+1);
	d[pos].state=1;
	F(d,pos+1);
	d[pos].state=2;
	F(d,pos+1);
}

void TTestCase::Run()
{
//	sort(D.begin(), D.end());
	try
	{
	    F(D, 0);
	}
	catch(...)
	{
		Result = true;
	}


}


TTestCase::~TTestCase()
{
	if(Result == false)
	{
		cout << "Impossible" << endl;
		fsOut << "Impossible" << endl;
	}
	else
	{
		cout << endl;
		fsOut << endl;
		FOR(i,0,N)
		{
			if(D[i].state == 1)
			{
				cout << D[i].Value << " ";
				fsOut << D[i].Value << " ";
			}
		}
		cout << endl;
		fsOut << endl;

		FOR(i,0,N)
		{
			if(D[i].state == 2)
			{
				cout << D[i].Value << " ";
				fsOut << D[i].Value << " ";
			}
		}
		cout << endl;
		fsOut << endl;
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
