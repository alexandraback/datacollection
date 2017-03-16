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

// problem entrypoint
int CodeJamMain()
{
    ifstream input;
    ofstream output;

    if (getProblemIO(input, output)) return -1;
    cout << fixed << setprecision(16);
    output << fixed << setprecision(16);

    // Get counts for first and second words.
    // For each pair of words, look at the counts for first and second.
    // It might be fake if both counts are greater than 1.
    // Unless this is the first time encountering one of the words, increment the fake counter.
    // Otherwise, say we've encountered it (assume this is the real topic) and move on.

        //16
        //AO CT
        //AO IW
        //AO RY
        //AO UK
        //CH CT
        //CH IW
        //CH RY
        //CH UK
        //FY CT
        //FY IW
        //FY RY
        //FY UK
        //YM CT
        //YM IW
        //YM RY
        //YM UK

    // my answer: 12

    // optimal manual order:
    // AO CT
    // CH IW
    // FY RY
    // YM UK

    int T;
    input >> T;
    for (int caseNum = 0; caseNum < T; caseNum++)
    {
        int N;
        input >> N;

        vector<pair<string, string>> topics(N);
        for(auto& topic : topics)
        {
            input >> topic.first >> topic.second;
        }

        // New approach - try to reorder the list in the optimal way for fakers (uniques at top).

        map<string, int> counts[2];
        for (const auto& topic : topics)
        {
            counts[0][topic.first]++;
            counts[1][topic.second]++;
        }

        sort(topics.begin(), topics.end(), [&](const pair<string, string>& a, const pair<string, string>& b)
        {
            int a1 = counts[0][a.first];
            int a2 = counts[1][a.second];
            int b1 = counts[0][b.first];
            int b2 = counts[1][b.second];
            if (a1 + a2 < b1 + b2) return true;
            if (a1 + a2 > b1 + b2) return false;
            if (a1 < b1)
            {
                if (a2 < b2) return true;
                if (a2 == b2) return true;
                if (a2 > b2) return false;
            }
            if (a1 == b1)
            {
                if (a2 < b2) return true;
                if (a2 == b2) return false;
                if (a2 > b2) return false;
            }
            if (a1 > b1)
            {
                if (a2 < b2) return true;
                if (a2 == b2) return false;
                if (a2 > b2) return false;
            }
            return false;
        });

        vector<pair<string, string>> topicsB;
        vector<bool> topicAdded(N);
        map<string, bool> wordAdded[2];

        int addedCount = 0;
        bool added = false;
        do
        {
            added = false;
            // try to find doubly-unique
            for(int i = 0; i < N && !added; i++)
            {
                if (!topicAdded[i] && !wordAdded[0][topics[i].first] && !wordAdded[1][topics[i].second])
                {
                    topicsB.push_back(topics[i]);
                    topicAdded[i] = true;
                    wordAdded[0][topics[i].first] = true;
                    wordAdded[1][topics[i].second] = true;
                    added = true;
                    addedCount++;
                }
            }
            if (!added)
            {
                // try to find singly-unique
                for (int i = 0; i < N && !added; i++)
                {
                    if (!topicAdded[i] && (!wordAdded[0][topics[i].first] || !wordAdded[1][topics[i].second]))
                    {
                        topicsB.push_back(topics[i]);
                        topicAdded[i] = true;
                        wordAdded[0][topics[i].first] = true;
                        wordAdded[1][topics[i].second] = true;
                        added = true;
                        addedCount++;
                    }
                }
            }
        } while (added);

        int answer = N - addedCount;
        answer = max(answer, N - min(counts[0].size(), counts[1].size()));

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
