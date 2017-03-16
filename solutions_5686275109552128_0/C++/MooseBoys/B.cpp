////////////////////////////////////////////////////////////////
//                                                            //
//  Google Code Jam Template                                  //
//  by MooseBoys                                              //
//                                                            //
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////
//                                            //
//  Generic Code                              //
//                                            //
////////////////////////////////////////////////

////////////////////////////////
//  Standard Includes         //
////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <cassert>
#include <map>
#include <functional>
#include <random>


////////////////////////////////
//  Non-Standard Includes     //
////////////////////////////////

#include <Windows.h>
//#include "BigIntegerLibrary.hh" // from http://mattmccutchen.net/bigint/
//#include "boost/math/common_factor.hpp" // from http://www.boost.org/


////////////////////////////////
//  Typedefs and Macros       //
////////////////////////////////

typedef long long           LL;
typedef unsigned long long  ULL;


////////////////////////////////
//  Debug Helpers             //
////////////////////////////////

// colored console messages
#define GoodMessage(message) {setColor(GOOD);std::cout<<message<<std::endl;setColor(NORMAL);}
#define BadMessage(message) {setColor(BAD);std::cout<<message<<std::endl;setColor(NORMAL);}
#define ImportantMessage(message) {setColor(IMPORTANT);std::cout<<message<<std::endl;setColor(NORMAL);}
enum consoleColor{ NORMAL, GOOD, BAD, IMPORTANT };
inline void setColor(consoleColor c)
{
    WORD wAttributes = 0x07;
    if (c == GOOD) wAttributes = 0x0A;
    if (c == BAD) wAttributes = 0x0C;
    if (c == IMPORTANT) wAttributes = 0xF9;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wAttributes);
}


////////////////////////////////
//  Common Functions          //
////////////////////////////////

// find and open a problem input
int loadProblemFile(std::ifstream &inputFile, std::string &inputFileName)
{
    for (char cProblem = 'A'; cProblem <= 'Z'; cProblem++)
    {
        inputFileName = std::string(1, cProblem) + "-test";
        inputFile.open(inputFileName + ".in", std::ifstream::in);
        if (inputFile.is_open()) return 0;
        inputFileName = std::string(1, cProblem) + "-large";
        inputFile.open(inputFileName + ".in", std::ifstream::in);
        if (inputFile.is_open()) return 0;
        for (char cAttempt = '9'; cAttempt >= '0'; cAttempt--)
        {
            inputFileName = std::string(1, cProblem) + "-small-attempt" + cAttempt;
            inputFile.open(inputFileName + ".in", std::ifstream::in);
            if (inputFile.is_open()) return 0;
        }
    }
    return -1;
}

// load and create problem input and output streams
int getProblemIO(std::ifstream &input, std::ofstream &output)
{
    std::string fileName;
    if (loadProblemFile(input, fileName)){ BadMessage("could not find any input files to load"); return -1; }
    else{ GoodMessage("successfully loaded input file \"" << fileName << ".in\""); }
    output.open(fileName + ".out", std::ofstream::out);
    if (output.is_open()){ GoodMessage("successfully created output file \"" << fileName << ".out\""); }
    else{ BadMessage("could not create output file \"" << fileName << ".out\""); return -1; }
    return 0;
}


////////////////////////////////////////////////
//                                            //
//  Problem-Specific Code                     //
//                                            //
////////////////////////////////////////////////

using namespace std;

vector<vector<int>> g_optimalReductions;

vector<int> GetReduction(int p)
{
    return g_optimalReductions[p - 1];
}

void GenOptimalReductions()
{
    vector<vector<int>> reductionCost(1000);
    for (int c = 0; c < 1000; c++)
    {
        for (int r = c; r < 1000; r++)
        {
            reductionCost[r].push_back(c + 1 + (r / (c + 1)));
        }
    }
    for (int r = 0; r < 1000; r++)
    {
        int bestReductionIndex = -1;
        int bestReductionValue = 999999;
        for (int i = 0; i < reductionCost[r].size(); i++)
        {
            if (reductionCost[r][i] < bestReductionValue)
            {
                bestReductionIndex = i;
                bestReductionValue = reductionCost[r][i];
            }
        }
        vector<int> reduction;
        int p = r + 1;
        int reduceTo = bestReductionIndex + 1;
        while (p > reduceTo)
        {
            reduction.push_back(reduceTo);
            p -= reduceTo;
        }
        if (p > 0) reduction.push_back(p);
        g_optimalReductions.push_back(reduction);
    }
}

// problem entrypoint
int CodeJamMain()
{
    ifstream input;
    ofstream output;

    if (getProblemIO(input, output)) return -1;
    cout << fixed << setprecision(16);
    output << fixed << setprecision(16);

    GenOptimalReductions();

    int T;
    input >> T;
    for (int caseNum = 0; caseNum < T; caseNum++)
    {
        int D;
        input >> D;
        priority_queue<int> P;
        for (int i = 0; i < D; i++)
        {
            int Pi;
            input >> Pi;
            P.push(Pi);
        }
        int moves = 0;
        int best = P.top();

        while (P.top() > 1)
        {
            moves++;
            int top = P.top();
            P.pop();
            auto reduction = GetReduction(top);
            for (auto& v : reduction) P.push(v);
            int cost = moves + P.top();
            if (cost < best) best = cost;
        }

        int answer = best;

        output << "Case #" << caseNum + 1 << ": ";
        output << answer << endl;
        GoodMessage("Case #" << caseNum + 1 << ": " << answer);
    }

    return 0;
}

////////////////////////////////////////////////
//                                            //
//  Generic Entrypoint                        //
//                                            //
////////////////////////////////////////////////

int main(int argc, char* argv [])
{
    int ret = CodeJamMain();
    if (ret == 0){ GoodMessage(">>>> SUCCESS <<<<"); }
    else{ BadMessage(">>>> FAILURE <<<<"); }
    system("pause");
    return ret;
}
