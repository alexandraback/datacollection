
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

#define TASKNUM "B"
#define DATASET "small"

ifstream fsIn(TASKNUM "-" DATASET "-practice.in.txt");
ofstream fsOut(TASKNUM "-" DATASET "-practice.out.txt");

class TTestCase
{
private:
    vector<int> Result;

    int N;
    //vector<vector<int>> R;
    vector<int> Num;
    //int maxH;

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
    cin >> N;
    Num.resize(N * (2*N - 1));
    for (int i = 0; i < Num.size(); ++i) {
        cin >> Num[i];
    }
    /*R.resize(N*2 - 1);
    maxH = 0;
    for (int i = 0; i < N*2 - 1; ++i) {
        R[i].resize(N);
        for (int j = 0; j < N; ++j) {
            cin >> R[i][j];
            maxH = max(maxH, R[i][j]);
        }
    } */
}

void TTestCase::Run()
{
    sort(Num.begin(), Num.end());

    int n = 0;
    int count = 0;

    for (int i = 0; i < Num.size(); ++i) {
        if (n != Num[i]) {
            if (count % 2) {
                Result.push_back(n);
            }
            n = Num[i];
            count = 1;
        }
        else {
            ++count;
        }
    }
    if (count % 2) {
        Result.push_back(n);
    }

    /*sort(R.begin(), R.end());

    vector<int> rows;
    vector<int> cols;
    fill(rows.begin(), rows.end(), -1);
    fill(cols.begin(), cols.end(), -1);

    rows[0] = 0;

    cols[0] = 1;*/

}


TTestCase::~TTestCase()
{
    for (auto n : Result) {
        cout << n << ' ';
        fsOut << n << ' ';
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
