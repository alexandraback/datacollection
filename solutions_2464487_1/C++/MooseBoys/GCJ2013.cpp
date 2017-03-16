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
#include <algorithm>
#include <cassert>


////////////////////////////////
//  Non-Standard Includes     //
////////////////////////////////

#include <Windows.h>
//#include "BigIntegerLibrary.hh"         // from http://mattmccutchen.net/bigint/
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
enum consoleColor{NORMAL,GOOD,BAD,IMPORTANT};
inline void setColor(consoleColor c)
{
    WORD wAttributes = 0x07;
    if(c==GOOD) wAttributes = 0x0A;
    if(c==BAD) wAttributes = 0x0C;
    if(c==IMPORTANT) wAttributes = 0xF9;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wAttributes);
}


////////////////////////////////
//  Common Functions          //
////////////////////////////////

// find and open a problem input
int loadProblemFile(std::ifstream &inputFile, std::string &inputFileName)
{
    for(char cProblem='A';cProblem<='Z';cProblem++)
    {
        inputFileName = std::string(1,cProblem)+"-test";
        inputFile.open(inputFileName+".in",std::ifstream::in);
        if(inputFile.is_open()) return 0;
        inputFileName = std::string(1,cProblem)+"-large";
        inputFile.open(inputFileName+".in",std::ifstream::in);
        if(inputFile.is_open()) return 0;
        for(char cAttempt='9';cAttempt>='0';cAttempt--)
        {
            inputFileName = std::string(1,cProblem)+"-small-attempt"+cAttempt;
            inputFile.open(inputFileName+".in",std::ifstream::in);
            if(inputFile.is_open()) return 0;
        }
    }
    return -1;
}

// load and create problem input and output streams
int getProblemIO(std::ifstream &input, std::ofstream &output)
{
    std::string fileName;
    if(loadProblemFile(input,fileName)){BadMessage("could not find any input files to load");return -1;}
    else{GoodMessage("successfully loaded input file \""<<fileName<<".in\"");}
    output.open(fileName+".out",std::ofstream::out);
    if(output.is_open()){GoodMessage("successfully created output file \""<<fileName<<".out\"");}
    else{BadMessage("could not create output file \""<<fileName<<".out\"");return -1;}
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

    if(getProblemIO(input,output)) return -1;
    cout<<fixed<<setprecision(16);
    output<<fixed<<setprecision(16);

	int T;
    input>>T;
    for(int caseNum=0;caseNum<T;caseNum++)
    {
        // r^2 terms cancel; paint required = 
        // 1: 2r + 1
        // 2: + 6r + 9 - 4r - 4
        // 3: + 10r + 25 - 8r - 16
        // N: + 2(2N-1)r + (2N-1)^2 - 2(2N-2)r + (2N-2)^2
        //  = + 2r + (2N-1)^2 - (2N-2)^2
        //  = + 2r + 4N - 3
        // total = 2rN + 2N*(N+1) - 3N
        // = 2*N^2 + 2*N*r - N
        // N = floor(0.25 * (sqrt(4r^2 - 4r + 8t + 1) - 2r + 1)

        ULL r,t;
        input>>r>>t;
        ImportantMessage("r="<<r<<", t="<<t);
        //long double ldr = r;
        //long double ldt = t;
        //long double ldn = floor(0.25 * (sqrt(4.0 * ldr * ldr - 4.0 * ldr + 8.0 * ldt + 1.0) - 2.0 * ldr + 1.0));

        ULL N = 0;
        for(ULL bit = 0; bit < 32; bit++) // given max values, max = 0x2A2597DD, only 32 bits!
        {
            ULL bitVal = (1ULL << (31-bit));
            N |= bitVal;
            ULL needed = (2*N + 2*r - 1);
            ULL needed2 = needed * N;
            if(needed2 > t || needed2/N != needed)
            {
                N &= ~bitVal;
            }
        }

        ULL answer = N;

        output<<"Case #"<<caseNum+1<<": ";
        output<<answer<<endl;
        GoodMessage("Case #"<<caseNum+1<<": "<<answer);
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
    if(ret==0){GoodMessage(">>>> SUCCESS <<<<");}
    else{BadMessage(">>>> FAILURE <<<<");}
    system("pause");
    return ret;
}
