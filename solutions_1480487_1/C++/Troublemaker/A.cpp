
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

#define TASKNUM "A"
#define DATASET "large"

ifstream fsIn(TASKNUM "-" DATASET "-practice.in.txt");
ofstream fsOut(TASKNUM "-" DATASET "-practice.out.txt");

class TTestCase
{
private:
	struct STR
	{
		unsigned index;
		unsigned S;
		double Result;
	};

    vector<STR> Data;
    unsigned N;

	static bool CmpInd( STR& s1, STR& s2)
	{
		return s1.index < s2.index;
	}
	static bool CmpS( STR& s1, STR& s2)
	{
		return s1.S < s2.S;
	}

    void Load();
    void Run();
    void Print();
public:
    TTestCase();
    ~TTestCase();
};


TTestCase::TTestCase()
    //: Result(0)
{
	cout.precision(10);
	fsOut.precision(10);

	Load();

    Run();
}

void TTestCase::Load()
{
    cin >> N;
	Data.resize(N);
	FOR(i,0,N)
	{
		Data[i].index = i;
		Data[i].Result = 0;
		cin >> Data[i].S;
	}
}

void TTestCase::Run()
{
	unsigned sum=0;
	FOR(i,0,N)
	{
		sum+=Data[i].S;
	}

	sort(Data.begin(), Data.end(), CmpS);


	FOR(i,0,N)
	{
		double tmp = sum;
		double needed = Data[i].S;
		int j=0;
		for(; j<i; ++j)
		{
			if(tmp==0)
				break;
			if(i==j)
				continue;

			tmp-=Data[i].S-Data[j].S;
		}
		if(tmp<=0)
		{
			Data[i].Result = 0;
			break;
		}
		for(; j<N; ++j)
		{
			double diff = Data[j].S - needed;//Data[i].S;
			if(diff * (j) < tmp)
			{
				tmp -= diff * (j);
				needed += diff;
			}
			else
			{
				needed += tmp/(j);
				tmp = 0;
			}
		}
		if(tmp!=0)
		{
			needed += tmp/N;
		}
		Data[i].Result = (needed-Data[i].S)/sum;
	}

	FOR(i,0,N)Data[i].Result *=100;

	sort(Data.begin(), Data.end(), CmpInd);
}


TTestCase::~TTestCase()
{
	cout << Data[0].Result;
    fsOut << Data[0].Result;
	for(int i=1; i<N; ++i)
	{
    cout << " " << Data[i].Result;
    fsOut << " " << Data[i].Result;
	}
    cout << endl;
    fsOut << endl;
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
