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

int reverse(int x)
{
    int rev = 0;
    while (x > 0)
    {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev;
}

vector<int> GenLUT()
{
    vector<int> answers(1000001);
    for (int i = 0; i <= 1000000; i++) answers[i] = i;
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 1; i <= 1000000; i++)
        {
            int rev = reverse(i);
            if (rev <= 1000000 && answers[rev] > answers[i] + 1)
            {
                answers[rev] = answers[i] + 1;
                changed = true;
            }
            if (answers[i] > answers[i - 1] + 1)
            {
                answers[i] = answers[i - 1] + 1;
                changed = true;
            }
        }
    }
    return answers;
}

// problem entrypoint
int CodeJamMain()
{
    ifstream input;
    ofstream output;

    if (getProblemIO(input, output)) return -1;
    cout << fixed << setprecision(16);
    output << fixed << setprecision(16);

    // not always optimal to jump, e.g. 53:
    // 1,2,3,4,5,6,7,8,9,10,11,12,21,22,23,32,33,34,43,44,45,46,47,48,49,50,51,52,53
    // 1,2,3,4,5,6,7,8,9,10,11,12,21,22,23,32,33,34,35,53

    // 1-20 = N
    // 21-30 = N-8
    // 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
    // 1,2,3,4,5,6,7,8,9,10,11,12,21
    // 1,2,3,4,5,6,7,8,9,10,11,12,21,22
    // 1,2,3,4,5,6,7,8,9,10,11,12,21,22,23
    // 1,2,3,4,5,6,7,8,9,10,11,12,21,22,23,24
    // 1,2,3,4,5,6,7,8,9,10,11,12,13,31

    // for small input, just generate a LUT
    auto lut = GenLUT();

    int T;
    input >> T;
    for (int caseNum = 0; caseNum < T; caseNum++)
    {
        int N;
        input >> N;

        int answer = lut[N];

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
    SetConsoleTitle(L"A");
    int ret = CodeJamMain();
    if (ret == 0){ GoodMessage(">>>> SUCCESS <<<<"); }
    else{ BadMessage(">>>> FAILURE <<<<"); }
    system("pause");
    return ret;
}
