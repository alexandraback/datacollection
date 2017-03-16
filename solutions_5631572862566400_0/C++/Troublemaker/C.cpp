
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
    int Result;

    int N;
    vector<int> F;

    vector<pair<int, int>> cycles;
    vector<int> tails;

    vector<vector<int>> back;

    int DFS(int i, int count, int start, vector<int> &vis);
    int DFS2(int i, int f);

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
    F.resize(N);
    back.resize(N);
    for (int i = 0; i < N; ++i) {
        int f;
        cin >> f;
        --f;
        F[i] = f;
        back[f].push_back(i);
    }
}

void TTestCase::Run()
{
    Result = 0;
    vector<int> vis(N);
    fill(vis.begin(), vis.end(), -1);
    tails.resize(N);
    fill(tails.begin(), tails.end(), -1);
    for (int i = 0; i < N; ++i) {
        if (vis[i] == -1)
            Result = max(Result, DFS(i, i * N, i * N, vis));
    }
    if (cycles.size()) {
        int res2 = 0;
        for (auto c : cycles) {
            res2 += DFS2(c.first, c.second);
            res2 += DFS2(c.second, c.first);
            res2 += 2;
        }
        Result = max(Result, res2);
    }
}

int TTestCase::DFS(int i, int count, int start, vector<int> &vis) {
    if (vis[i] != -1) {
        if (vis[i] < start)
            return 0;
        int cycle = count - vis[i];
        if (cycle == 2) {
            cycles.push_back(make_pair(i, F[i]));
            tails[i] = 0;
            tails[F[i]] = 0;
        }
        return cycle;
    }
    vis[i] = count;
    return DFS(F[i], count + 1, start, vis);
}

int TTestCase::DFS2(int i, int f) {
    int res = 0;
    for (auto b:back[i]) {
        if (b == f)
            continue;
        res = max(res, DFS2(b, i) + 1);
    }
    return res;
}

TTestCase::~TTestCase()
{
    cout << Result << endl;
    fsOut << Result << endl;
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
