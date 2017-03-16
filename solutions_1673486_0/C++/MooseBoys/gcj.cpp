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
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cassert>


////////////////////////////////
//  Non-Standard Includes     //
////////////////////////////////

#include "Windows.h"
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

    //    Q<    A
    // 1  2  3  4  5  6  ... B
    // p1 p2 p3 p4 p5 p6 ... pB

    // option 1 special case of option 2 (Q=0)
    // option 2:
    // Q = 0: (p1*p2*p3*...*pA) * (B-A+1) + (1 - p1*p2*p3*...*pA) * (B-A+1 + B+1)
    // Q = 1: (p1*p2*p3*...*p(A-1)) * (B-A+1+2) + (1 - p1*p2*p3*...*p(A-1)) * (B-A+1+2 + B+1)
    // Q = Q: (p1*p2*p3*...*p(A-Q)) * (B-A+1+2*Q) + (1 - p1*p2*p3*...*p(A-Q)) * (B-A+1+2*Q + B+1)
    // option 3: B+2

    // try start at Q=A, mul-accumulate p(N), find min of that and B+2
    // strictly increasing?

    if(getProblemIO(input,output)) return -1;

	int T;
    input>>T;
    for(int caseNum=0;caseNum<T;caseNum++)
    {
        int A;
        int B;
        input>>A;
        input>>B;
        ImportantMessage("A="<<A<<" B="<<B<<"]");

        vector<double> p(A+1);
        for(int i=0;i<A;i++) input>>p[i];
        p[A] = 1.0f;

        double accum = 1.0f;
        vector<double> E(A+1);
        for(int i=0;i<A+1;i++)
        {
            int Q = A-i;
            E[i] = accum * (B-A+1+2*Q) + (1.0f - accum) * (B-A+1+2*Q + B+1);
            accum *= p[i];
        }

        double Ebest = *min_element(E.begin(), E.end());
        if(Ebest > B+2) Ebest = B+2;

        output<<"Case #"<<caseNum+1<<": "<<Ebest<<endl;
        GoodMessage("Case #"<<caseNum+1<<": "<<Ebest);
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
