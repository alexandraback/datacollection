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


struct car
{
    bool leftLane;
    double speed;
    double position;
};

// problem entrypoint
int CodeJamMain()
{
    ifstream input;
    ofstream output;

    if(getProblemIO(input,output)) return -1;

	int T;
    input>>T;
    for(int caseNum=0;caseNum<T;caseNum++)
    {
        int N;
        input>>N;
        ImportantMessage("N="<<N);
        vector<car> cars(N);
        for(int i=0;i<N;i++)
        {
            char c;
            input>>c;
            cars[i].leftLane = (c == 'L');
            input>>cars[i].speed;
            input>>cars[i].position;
        }

        bool unbound = false;
        bool collided = false;

        double time = 0.0f;
        double dt = 0.05f;

        while(!unbound && !collided)
        {
            vector<car> next = cars;
            for(int i=0;i<N;i++)
            {
                next[i].position += dt * cars[i].speed;
            }
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(i!=j && next[i].leftLane == next[j].leftLane)
                    {
                        if(fabsf(next[i].position-next[j].position) < 5.0f)
                        {
                            next[i].leftLane = !next[i].leftLane;
                        }
                    }
                }
            }
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(i!=j && next[i].leftLane == next[j].leftLane)
                    {
                        if(fabsf(next[i].position-next[j].position) < 5.0f)
                        {
                            next[i].leftLane = !next[i].leftLane;
                        }
                    }
                }
            }
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(i!=j && next[i].leftLane == next[j].leftLane)
                    {
                        if(fabsf(next[i].position-next[j].position) < 5.0f)
                        {
                            collided = true;
                        }
                    }
                }
            }
            bool bound = false;
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(i!=j)
                    {
                        if(cars[i].position <= cars[j].position && cars[i].speed >= cars[j].speed)
                        {
                            bound = true;
                        }
                    }
                }
            }
            if(!bound) unbound = true;
            if(time > 50000) unbound = true;
            time += dt;
            cars = next;
        }
        if(collided)
        {
            time = max(0,time-dt);
        }

        if(unbound)
        {
            output<<"Case #"<<caseNum+1<<": "<<"Possible"<<endl;
            GoodMessage("Case #"<<caseNum+1<<": "<<"Possible");
        }
        else
        {
            output<<"Case #"<<caseNum+1<<": "<<time<<endl;
            GoodMessage("Case #"<<caseNum+1<<": "<<time);            
        }
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
