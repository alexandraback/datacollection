#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <type_traits>

using namespace std;

/// Duplicator of output into two different streams.
class CDoubleOutput
{
public:
    CDoubleOutput(ostream &stream1, ostream &stream2): stream1(stream1), stream2(stream2) { }
    
    /// normal output operator
    template<typename T>
    CDoubleOutput& operator<<(const T &value)
    {
        stream1 << value;
        stream2 << value;
        return *this;
    }
    /// operator that helps with manipulators
    CDoubleOutput& operator<<(std::ostream &(*fmanip)(std::ostream &))
    {
        fmanip(stream1);
        fmanip(stream2);
        return *this;
    }
    
private:
    ostream &stream1;
    ostream &stream2;
};

/// returs Nomi's result for optimal War game
/// entering lists are expected to be sorted
unsigned int PlayWarNaomi(list<long double> naomiBlocks, list<long double> kenBlocks) // by value so that we can manipulate them and keep them for later use
{
    unsigned int naomiPoints = 0;
    while (!naomiBlocks.empty())
    {
        // Naomi always chooses her lightest block
        decltype(kenBlocks)::iterator na = naomiBlocks.begin();
        /*decltype(kenBlocks)::iterator na = naomiBlocks.end();
        --na;*/
        // Ken chooses the lightest block with weight higher than Naomi's choice
        decltype(kenBlocks)::iterator ke;
        for (ke = kenBlocks.begin(); ke != kenBlocks.end(); ++ke)
        {
            if (*ke > *na)
                break;
        }
        // when Ken has no such a block, he chooses his lightest one (keep heavier for later time)
        if (ke == kenBlocks.end())
            ke = kenBlocks.begin();
        // count the score
        if (*na > *ke)
            ++naomiPoints;
        // destroy both blocks
        naomiBlocks.erase(na);
        kenBlocks.erase(ke);
    }
    return naomiPoints;
}

/// returs Nomi's result for optimal Deceitful War game
/// entering lists are expected to be sorted
unsigned int PlayDeceitfulWarNaomi(list<long double> naomiBlocks, list<long double> kenBlocks) // by value so that we can manipulate them and keep them for later use
{
    unsigned int naomiPoints = 0;
    while (!naomiBlocks.empty())
    {
        // for this game, Naomi should always choose her first stone, which is heavier than Ken's lightest one and tell him, it is heavier than his heaviest one
        // this way Ken chooses his lightest stone and she still beats him while throwing away worthless stones
        decltype(kenBlocks)::iterator ke = kenBlocks.begin();
        decltype(kenBlocks)::iterator na;
        for (na = naomiBlocks.begin(); na != naomiBlocks.end(); ++na)
        {
            if (*na > *ke)
                break;
        }
        // when Naomi has no such a stone which would be heavier than Ken's lightest, she is doomed anyway...
        if (na == naomiBlocks.end())
        {
            // now play normal War (while loosing)
            na = naomiBlocks.begin();
            // Ken chooses the lightest block with weight higher than Naomi's choice
            for (ke = kenBlocks.begin(); ke != kenBlocks.end(); ++ke)
            {
                if (*ke > *na)
                    break;
            }
            // we should never get here
            if (ke == kenBlocks.end())
                ke = kenBlocks.begin();
        }
        // count the score
        if (*na > *ke)
            ++naomiPoints;
        // destroy both blocks
        naomiBlocks.erase(na);
        kenBlocks.erase(ke);
    }
    return naomiPoints;
}

void SolveTestCase(int t, istream& inpStream, CDoubleOutput& outStream)
{
    unsigned int n;
    // read the input first
    inpStream >> n;
    list<long double> naomiBlocks;
    list<long double> kenBlocks;
    long double value;
    for (unsigned int i = 0; i < n; ++i)
    {
        inpStream >> value;
        naomiBlocks.push_back(value);
    }
    for (unsigned int i = 0; i < n; ++i)
    {
        inpStream >> value;
        kenBlocks.push_back(value);
    }
    // arrays are useful sorted
    naomiBlocks.sort();
    kenBlocks.sort();
    // get the results
    unsigned int warScore = PlayWarNaomi(naomiBlocks, kenBlocks);
    unsigned int deceitfulWarScore = PlayDeceitfulWarNaomi(naomiBlocks, kenBlocks);
    
    // print out the result
    outStream << "Case #" << t + 1 << ": " << deceitfulWarScore << " " << warScore << endl;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cerr << "No input file!" << endl;
        return 1;
    }
    ifstream inputFile(argv[1]);
    string outputFileName(argv[1]);
    outputFileName.replace(outputFileName.length() - 3, 3, ".out"); // ok, we know we do not need to check here
    ofstream outputFile(outputFileName);
    CDoubleOutput outputStream(cout, outputFile);
    unsigned int n;
    inputFile >> n;
    for (unsigned int i = 0; i < n; ++i)
        SolveTestCase(i, inputFile, outputStream);
    outputFile.flush();
    outputFile.close();
    return 0;
}
