#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

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

struct SCreditToSpend
{
    unsigned int index;
    unsigned int p;
    
    bool operator<(const SCreditToSpend& right) const
    {
        return p < right.p;
    }
};

void SolveTestCase(int n, istream& inpStream, CDoubleOutput& outStream)
{
    double c, f, x;
    // read the input first
    inpStream >> c;
    inpStream >> f;
    inpStream >> x;
    
    // try adding factories while we do not have enough
    long double lastTime = numeric_limits<double>::max();
    long double lastFactoriesTime = 0.0;
    unsigned int numOfFactories = 0;
    while (true)
    {
        long double addedFactoryTime = 0.0;
        if (numOfFactories != 0)
            addedFactoryTime = c / ((numOfFactories - 1) * f + 2.0);
        long double totalFactoriesTime = lastFactoriesTime + addedFactoryTime;
        long double totalTime = totalFactoriesTime + (x / (numOfFactories * f + 2.0));
        // stop iteration if we swing to slowing down
        if (totalTime > lastTime)
            break;
        lastTime = totalTime;
        lastFactoriesTime = totalFactoriesTime;
        ++numOfFactories;
    }
    
    // print out the result
    outStream << "Case #" << n + 1 << ": " << fixed << setprecision(7) << lastTime << endl;
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
