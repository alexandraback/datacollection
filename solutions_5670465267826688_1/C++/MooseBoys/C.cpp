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

char mul(char a, char b)
{
    const char neg = 0x80;
    bool negate = ((a & neg) ^ (b & neg)) != 0;
    a &= ~neg;
    b &= ~neg;
    char ret = 'x';
    if (a == '1')
    {
        if (b == '1') ret = '1';
        if (b == 'i') ret = 'i';
        if (b == 'j') ret = 'j';
        if (b == 'k') ret = 'k';
    }
    if (a == 'i')
    {
        if (b == '1') ret = 'i';
        if (b == 'i') ret = neg | '1';
        if (b == 'j') ret = 'k';
        if (b == 'k') ret = neg | 'j';
    }
    if (a == 'j')
    {
        if (b == '1') ret = 'j';
        if (b == 'i') ret = neg | 'k';
        if (b == 'j') ret = neg | '1';
        if (b == 'k') ret = 'i';
    }
    if (a == 'k')
    {
        if (b == '1') ret = 'k';
        if (b == 'i') ret = 'j';
        if (b == 'j') ret = neg | 'i';
        if (b == 'k') ret = neg | '1';
    }
    return ret ^ (negate ? neg : 0);
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
        long long L;
        input >> L;
        long long X;
        input >> X;
        string pattern;
        input >> pattern;

        // it seems like for any target character, if you don't find it within 8 cycles, you won't find it at all
        // so try at most 9 cycles per character = up to 27 iterations of the pattern (let's do 30 in case I'm off by one for some reason)
        // if you haven't found "ijk" by then, early out
        // if you have, collapsing the remainder of the string and remaining patterns should be easy - find the cycle and modulo
        char running = '1';
        int satisfied = 0;
        char target [] = "ijk";
        long long i = 0;
        for (i = 0; i < X && i < 30; i++)
        {
            for (int j = 0; j < L; j++)
            {
                running = mul(running, pattern[j]);
                if (satisfied < 3 && running == target[satisfied])
                {
                    satisfied++;
                    running = '1';
                }
            }
        }

        char collapsed = '1';
        for (int j = 0; j < L; j++)
        {
            collapsed = mul(collapsed, pattern[j]);
        }

        vector<char> cycle;
        cycle.push_back(running);
        while ((running = mul(running, collapsed)) != cycle[0]) cycle.push_back(running);

        long long patternsRemaining = X - i;
        char remainder = cycle[patternsRemaining % cycle.size()];

        string answer = (satisfied == 3 && remainder == '1') ? "YES" : "NO";

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
