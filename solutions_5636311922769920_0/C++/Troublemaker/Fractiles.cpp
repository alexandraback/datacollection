
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

#define PRINT

#define TASKNUM "D"
#define DATASET "small"

ifstream fsIn(TASKNUM "-" DATASET "-practice.in.txt");
ofstream fsOut(TASKNUM "-" DATASET "-practice.out.txt");

class TTestCase
{
private:
    vector<long long> Result;
    unsigned K, C, S;

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
    cin >> K >> C >> S;
}

long long F(int k, int K, int C, long long &size) {
    if(C == 1) {
        size = K;
        return k;
    }
    long long tmp_size;
    long long f;
    if(k == K) {
        f = F(k, K, C - 1, tmp_size);
    }
    else {
        f = F(k + 1, K, C - 1, tmp_size);
    }
    size = tmp_size * K;
    return (k - 1LL) * tmp_size + f;
}

void TTestCase::Run()
{
    if (S < (K/C + (K%C? 1: 0))) {
        return;
    }
    for (int k = 1; k <= K; k += C) {
        long long size = 1;
        Result.push_back(F(k, K, C, size));
    }
}


TTestCase::~TTestCase()
{
	if(Result.size() == 0)
	{
		cout << "IMPOSSIBLE" << endl;
		fsOut << "IMPOSSIBLE" << endl;
	}
	else
	{
        for(int i = 0; i < Result.size(); ++i) {
		    cout << Result[i] << ' ';
		    fsOut << Result[i] << ' ';
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
