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
#include <cassert>
#include <map>
#include <functional>
#include <random>


////////////////////////////////
//  Non-Standard Includes     //
////////////////////////////////

#include <Windows.h>
#include "BigIntegerLibrary.hh" // from http://mattmccutchen.net/bigint/
#include "boost/math/common_factor.hpp" // from http://www.boost.org/


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
enum consoleColor { NORMAL, GOOD, BAD, IMPORTANT };
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
    if (loadProblemFile(input, fileName)) { BadMessage("could not find any input files to load"); return -1; }
    else { GoodMessage("successfully loaded input file \"" << fileName << ".in\""); }
    output.open(fileName + ".out", std::ofstream::out);
    if (output.is_open()) { GoodMessage("successfully created output file \"" << fileName << ".out\""); }
    else { BadMessage("could not create output file \"" << fileName << ".out\""); return -1; }
    return 0;
}


////////////////////////////////////////////////
//                                            //
//  Problem-Specific Code                     //
//                                            //
////////////////////////////////////////////////

using namespace std;

bool operator<(const vector<short>& a, const vector<short>& b)
{
    int N = static_cast<int>(a.size());
    for (int i = 0; i < N; i++)
    {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }
    return false;
}

bool strict_lt(const vector<short>& a, const vector<short>& b)
{
    int N = static_cast<int>(a.size());
    for (int i = 0; i < N; i++)
    {
        if (a[i] >= b[i]) return false;
    }
    return true;
}

// problem entrypoint
int CodeJamMain()
{
    ifstream input;
    ofstream output;

    if (getProblemIO(input, output)) return -1;
    cout << fixed << setprecision(16);
    output << fixed << setprecision(16);

    int T;
    input >> T;
    for (int caseNum = 0; caseNum < T; caseNum++)
    {
        string C;
        input >> C;
        string J;
        input >> J;

        int length = C.size();
        int upper = length == 1 ? 10 : length == 2 ? 100 : 1000;

        int mind = 9999;
        int minc = -1;
        int minj = -1;

        for (int c = 0; c < upper; c++)
        {
            ostringstream ssc;
            ssc << setfill('0') << setw(length) << c;
            string sc = ssc.str();
            bool ok = true;
            for (int i = 0; i < length; i++)
            {
                if (!(C[i] == '?' || C[i] == sc[i])) ok = false;
            }
            if (ok)
            {
                for (int j = 0; j < upper; j++)
                {
                    ostringstream ssj;
                    ssj << setfill('0') << setw(length) << j;
                    string sj = ssj.str();
                    ok = true;
                    for (int i = 0; i < length; i++)
                    {
                        if (!(J[i] == '?' || J[i] == sj[i])) ok = false;
                    }
                    if (ok)
                    {
                        int diff = abs(c - j);
                        if (diff < mind)
                        {
                            mind = diff;
                            minc = c;
                            minj = j;
                        }
                        else if (diff == mind)
                        {
                            if (c < minc)
                            {
                                minc = c;
                                minj = j;
                            }
                            else if (c == minc)
                            {
                                if (j < minj)
                                {
                                    minj = j;
                                }
                            }
                        }
                    }
                }
            }
        }

        ostringstream oss;
        oss << setfill('0') << setw(length) << minc << " " << setfill('0') << setw(length) << minj;
        string answer = oss.str();

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

int main(int argc, char* argv[])
{
    int ret = CodeJamMain();
    if (ret == 0) { GoodMessage(">>>> SUCCESS <<<<"); }
    else { BadMessage(">>>> FAILURE <<<<"); }
    system("pause");
    return ret;
}
