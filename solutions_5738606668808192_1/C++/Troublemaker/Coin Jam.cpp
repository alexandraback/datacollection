
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

#define PRINT

#define TASKNUM "C"
#define DATASET "large"

class TTestCase
{
private:
    unsigned N, J;

    void Load();
    void Run();
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
    cin >> N >> J;
}

#include <limits.h>

__int128 F(int radix, int N) {
    __int128 res = 1;
    for (int n = 0; n < N / 2; ++n) {
        res *= radix;
    }
    return res + 1;
}

void TTestCase::Run()
{
}


TTestCase::~TTestCase()
{
    cout << endl;
    for(int i = 0; i < J; ++i) {
        cout << '1';
        for(int j = 0; j < N/2 - 2; ++j) {
            cout << ((i & (1 << j))? 1: 0 );
        }
        cout << "1";
        cout << '1';
        for(int j = 0; j < N/2 - 2; ++j) {
            cout << ((i & (1 << j))? 1: 0 );
        }
        cout << "1 ";
        for(int j = 2; j <= 10; ++j) {
            long del = F(j, N);
            cout << del << " ";
        }
        cout << endl;
    }
}








int main()
{
    int numberOfCases;
    cin >> numberOfCases;

	for( int caseNum = 1; caseNum <= numberOfCases; ++caseNum )
	{
        TTestCase testCase;

        
        cout << "Case #" << caseNum << ": ";
	}
	
	cout << "Finished";
    for(;;);
	return 0;
}
