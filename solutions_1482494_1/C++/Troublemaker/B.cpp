
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define FROM_0_TO(i,n) FOR(i,0,n) 

#define PRINT

#define TASKNUM "B"
#define DATASET "large"

ifstream fsIn(TASKNUM "-" DATASET "-practice.in.txt");
ofstream fsOut(TASKNUM "-" DATASET "-practice.out.txt");

class TTestCase
{
private:
	struct S {int a,b; };
	struct P {int level; int stars; int index; int b;};

    int Result;
    unsigned N;
	vector<S> Data;
	list<P>	Pos;
	set<int> Ind;

    void Load();
    void Run();
    void Print();

	static bool C( P& p1, P& p2)
	{
		if( p1.level > p2.level ) return true;
		if( p1.level < p2.level ) return false;

		if( p1.level == 2)
			return p1.stars<p2.stars;
		return p1.b>p2.b;
	}
public:
    TTestCase();
    ~TTestCase();
};


TTestCase::TTestCase()
    : Result(0)
{
	Load();

    Run();
}

void TTestCase::Load()
{
    cin >> N;
	Data.resize(N);
	FOR(i,0,N)
	{
		cin >> Data[i].a >> Data[i].b;
	}
}

void TTestCase::Run()
{
	FOR(i,0,N)
	{
		P p;
		p.index = i;
		p.level = 1;
		p.stars = Data[i].a;
		p.b = Data[i].b;
		Pos.push_back(p);
		p.level = 2;
		p.stars = Data[i].b;
		p.b = 111111;
		Pos.push_back(p);
	}
	Pos.sort(C);

	int curr = 0;

	list<P>::iterator it = Pos.begin();
	while(!Pos.empty())
	{
		if(it == Pos.end())
		{
			Result = -1;
			return;
		}
		if(it->stars <= curr)
		{
			if(Ind.find(it->index)==Ind.end())
			{
				curr += it->level;
				Ind.insert(it->index);
				++Result;
			}
			else
			{
				if(it->level == 2)
				{
					++curr;
					++Result;
				}
			}

			if(it->level == 2)
			{
				it=Pos.erase(it);
				it = Pos.begin();
			}
			else
			{
				Pos.erase(it);
				it = Pos.begin();
			}
		}
		else
		{
			++it;
		}
	}


}


TTestCase::~TTestCase()
{
	if(Result != -1)
	{
    cout << Result << endl;
    fsOut << Result << endl;
	}
	else
	{
    cout << "Too Bad" << endl;
    fsOut << "Too Bad" << endl;
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
