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
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <map>
#include <functional>


////////////////////////////////
//  Non-Standard Includes     //
////////////////////////////////

#include <Windows.h>
//#include "BigInteger\\BigIntegerLibrary.hh"         // from http://mattmccutchen.net/bigint/
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

// Big Integer class


////////////////////////////////////////////////
//                                            //
//  Problem-Specific Code                     //
//                                            //
////////////////////////////////////////////////

using namespace std;

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
    for (int caseNum = 0; caseNum<T; caseNum++)
    {
        int N;
        input >> N;
        list<double> alice;
        list<double> bob;
        for (int i = 0; i < N; i++)
        {
            double x;
            input >> x;
            alice.push_back(x);
        }
        for (int i = 0; i < N; i++)
        {
            double x;
            input >> x;
            bob.push_back(x);
        }

        // enemy war strategy: given weight X, play lowest weight Y such that Y > X; if no Y exists, play lowest weight
        // proposed deceitful war strategy:
        // if my lowest is greater than enemy lowest, play and claim weight of (enemy max + eps); he plays his lowest and I win
        // otherwise play and claim weight of (enemy max - eps); he plays his highest and wins

        alice.sort();
        bob.sort();

        // regular war:
        // doesn't seem to matter what order alice plays in
        auto bob2 = bob;
        int wScore = 0;
        for (auto a : alice)
        {
            auto b = bob2.begin();
            bool found = false;
            while (!found && b != bob2.end())
            {
                if (*b > a)
                {
                    found = true;
                    bob2.erase(b);
                }
                else
                {
                    b++;
                }
            }
            if (!found)
            {
                bob2.pop_front();
                wScore++;
            }
        }

        // deceitful war:
        int dScore = 0;
        for (auto a : alice)
        {
            if (a > *bob.begin())
            {
                bob.pop_front();
                dScore++;
            }
            else
            {
                bob.pop_back();
            }
        }

        ostringstream ans;
        ans << dScore << " " << wScore;
        string answer = ans.str();

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
    if (ret == 0){ GoodMessage(">>>> SUCCESS <<<<"); }
    else{ BadMessage(">>>> FAILURE <<<<"); }
    system("pause");
    return ret;
}
