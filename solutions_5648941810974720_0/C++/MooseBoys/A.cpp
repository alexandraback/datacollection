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
#include <deque>
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

// problem entrypoint
int CodeJamMain()
{
    ifstream input;
    ofstream output;

    if (getProblemIO(input, output)) return -1;
    cout << fixed << setprecision(16);
    output << fixed << setprecision(16);

    //       ABCDEFGHIJKLMNOPQRSTUVWXYZ
    // ZERO      1         1  1       1
    // ONE       1        11           
    // TWO                 1       1   
    // THREE     2  1         1 1      
    // FOUR       1        1  1  1     
    // FIVE      11  1            1    
    // SIX           1         1    1  
    // SEVEN     2        1    1  1    
    // EIGHT     1 111          1      
    // NINE      1   1    2            

    // G = EIGHT 8
    // U = FOUR 4,8
    // W = TWO 2,4,8
    // X = SIX 2,4,6,8
    // Z = ZERO 0,2,4,6,8
    // F = FOUR + FIVE 0,2,4,5,6,8
    // H = THREE + EIGHT 0,2,3,4,5,6,8
    // V = FIVE + SEVEN 0,2,3,4,5,6,7,8
    // I = FIVE + SIX + EIGHT + NINE 0,2,3,4,5,6,7,8,9
    // O = ZERO + ONE + TWO + FOUR 0,1,2,3,4,5,6,7,8,9

    int T;
    input >> T;
    for (int caseNum = 0; caseNum < T; caseNum++)
    {
        string S;
        input >> S;

        int letters[256]{};
        for (auto c : S)
        {
            letters[c]++;
        }

        int numbers[10]{};
        numbers[8] = letters['G'];
        numbers[4] = letters['U'];
        numbers[2] = letters['W'];
        numbers[6] = letters['X'];
        numbers[0] = letters['Z'];
        numbers[5] = letters['F'] - numbers[4];
        numbers[3] = letters['H'] - numbers[8];
        numbers[7] = letters['V'] - numbers[5];
        numbers[9] = letters['I'] - numbers[5] - numbers[6] - numbers[8];
        numbers[1] = letters['O'] - numbers[0] - numbers[2] - numbers[4];

        ostringstream oss;
        for (int i = 0; i < 10; i++)
        {
            while (numbers[i]--) oss << i;
        }
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
