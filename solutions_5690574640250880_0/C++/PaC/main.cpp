#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stack>
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

/// Representation of the board used for the problem solving.
/// Not a very clean code, I know, but I do not have enough time :) The code got cluttered as I developed it.
class CBoard
{
public:
    CBoard(unsigned int r, unsigned int c, unsigned int m): r(r), c(c), m(m) 
    {
        data = new char[r * c];
        memset(data, 0, r * c);
        indexToSolve = 0;
    }
    
    ~CBoard()
    {
        delete[] data;
    }
    
    /// returns true when correct solution found
    bool Solve()
    {
        // when we are not solved, try to plant / do not plant the next mine - branch the tree
        if (!IsSolved())
        {
            // make sure that we have enough free space for planting the remaining mines
            if (indexToSolve >= (unsigned int)(r * c))
                return false;
            if (indexToSolve + m > (unsigned int)(r * c))
                return false;
            // go through the branch with mine
            CBoard boardWithMine(*this);
            boardWithMine.NextIndexPlantMine();
            // continue only when created board is still valid and can lead to a correct solution
            if (boardWithMine.Solve())
            {
                // OK, we have a correct solution here, steal new board's internals
                memcpy(data, boardWithMine.data, r * c);
                return true;
            }
            // go through the branch without the mine
            CBoard boardWithoutMine(*this);
            boardWithoutMine.NextIndexSkipMine();
            // no need to check validity, simply skipping solution index can not make the board invalid
            if (boardWithoutMine.Solve())
            {
                // OK, we have a correct solution here, steal new board's internals
                memcpy(data, boardWithoutMine.data, r * c);
                return true;
            }
            // we were not able to solve this branch
            return false;
        }
        return IsValidOrMayBecomeValid();
    }
    
    void PrintToOutput(CDoubleOutput& outStream)
    {
        // if we have some zero, we have to click it 
        if (WeHaveSomeZeroIndex())
        {
            bool clickPrinted = false;
            unsigned int index = 0;
            for (int row = 0; row < r; ++row)
            {
                for (int column = 0; column < c; ++column)
                {
                    if (data[index] == mine)
                        outStream << mine;
                    else if (data[index] == 0)
                    {
                        if (!clickPrinted)
                        {
                            clickPrinted = true;
                            outStream << clickOutput;
                        }
                        else
                            outStream << zeroOutput;
                    }
                    else 
                    {
                        // print all the mine neighbors as zeroOutput
                        outStream << zeroOutput;
                    }
                    ++index;
                }
                outStream << endl;
            }
        }
        else
        {
            // no zero index on the board, we can slimply put c anywhere where no mine is
            bool clickPrinted = false;
            unsigned int index = 0;
            for (int row = 0; row < r; ++row)
            {
                for (int column = 0; column < c; ++column)
                {
                    if (data[index] == mine)
                        outStream << mine;
                    else
                    {
                        if (!clickPrinted)
                        {
                            clickPrinted = true;
                            outStream << clickOutput;
                        }
                        else
                            outStream << zeroOutput;
                    }
                    ++index;
                }
                outStream << endl;
            }
        }
        
    }
    
private:
    
    struct SRCCoords
    {
        SRCCoords(int rowIndex, int colIndex): rowIndex(rowIndex), colIndex(colIndex) {}
        int rowIndex;
        int colIndex;
    };
    
    const char mine = '*';
    const char zeroOutput = '.';
    const char clickOutput = 'c';
    
    /// rows
    int r;
    /// columns
    int c;
    /// remaining mines to plant
    int m;
    /// the board representation as an array of concatenated rows
    char* data;
    /// next index where mine should be planted / not planted
    unsigned int indexToSolve;
    
    CBoard(const CBoard &base)
    {
        r = base.r;
        c = base.c;
        m = base.m;
        data = new char[r * c];
        memcpy(data, base.data, r * c);
        indexToSolve = base.indexToSolve;
    }
    
    /// returns index of first zero we have or r * c when no zero found
    int GetFirstZeroIndex()
    {
        int numOfElements = r * c;
        int firstZeroIndex;
        for (firstZeroIndex = 0; firstZeroIndex < numOfElements; ++firstZeroIndex)
        {
            if (data[firstZeroIndex] == 0)
                break;
        }
        return firstZeroIndex;
    }
    
    bool WeHaveSomeZeroIndex()
    {
        int numOfElements = r * c;
        int firstZeroIndex = GetFirstZeroIndex();
        // no zero inside the board?
        if (firstZeroIndex == numOfElements)
            return false;
        return true;
    }
    
    /// returns whether the board is solved, which means "there are no more mines to plant", says nothing about it's validity
    bool IsSolved()
    {
        return m == 0;
    }
   
    /// returns whether the board is valid
    /// valid <=> it can be solved by one click only (if there is some zero, it has to be clicked and this click has to uncover everything, if there is no zero, it has to be the only non-zero thing there
    bool IsValidOrMayBecomeValid()
    {
        // look for the first zero
        int numOfElements = r * c;
        int firstZeroIndex = GetFirstZeroIndex();
        // no zero inside the board? this means we have to have only a single non-mine thing somewhere
        if (firstZeroIndex == numOfElements)
        {
            int numOfNonMinesFound = 0;
            for (int i = 0; i < numOfElements; ++i)
                if (data[i] != mine)
                    ++numOfNonMinesFound;
            if (numOfNonMinesFound - m == 1) // those things may become mines
                return true;
            return false;
        }
        // we have to click on the zero we have found to uncover what we need
        // flood fill from that index
        char ffData[numOfElements];
        memcpy(ffData, data, numOfElements);
        int rowIndex = firstZeroIndex / c;
        int colIndex = firstZeroIndex % c;
        stack<SRCCoords> ffStack;
        ffStack.emplace(rowIndex, colIndex);
        while (!ffStack.empty())
        {
            SRCCoords coords = ffStack.top();
            ffStack.pop();
            int i = coords.rowIndex * c + coords.colIndex;
            if (ffData[i] == mine || ffData[i] == 2) // leave mines and processed be
                continue;
            bool addNeighbours = false;
            if (ffData[i] == 0)
                addNeighbours = true;
            // mark cell as processed
            ffData[i] = 2;
            if (!addNeighbours)
                continue;
            // add all it's neighbors for processing
            if (coords.rowIndex > 0) // top row
            {
                rowIndex = coords.rowIndex - 1;
                if (coords.colIndex > 0)
                {
                    colIndex = coords.colIndex - 1;
                    ffStack.emplace(rowIndex, colIndex);
                }
                ffStack.emplace(rowIndex, coords.colIndex);
                if (coords.colIndex < c - 1)
                {
                    colIndex = coords.colIndex + 1;
                    ffStack.emplace(rowIndex, colIndex);
                }
            }
            // left neighbor
            if (coords.colIndex > 0)
            {
                colIndex = coords.colIndex - 1;
                ffStack.emplace(coords.rowIndex, colIndex);
            }
            // right neighbor
            if (coords.colIndex < c - 1)
            {
                colIndex = coords.colIndex + 1;
                ffStack.emplace(coords.rowIndex, colIndex);
            }
            if (coords.rowIndex < r - 1) // bottom row
            {
                rowIndex = coords.rowIndex + 1;
                if (coords.colIndex > 0)
                {
                    colIndex = coords.colIndex - 1;
                    ffStack.emplace(rowIndex, colIndex);
                }
                ffStack.emplace(rowIndex, coords.colIndex);
                if (coords.colIndex < c - 1)
                {
                    colIndex = coords.colIndex + 1;
                    ffStack.emplace(rowIndex, colIndex);
                }
            }
        }
        // check that there are no more unmarked things after the flood fill
        for (int i = 0; i < numOfElements; ++i)
        {
            if (ffData[i] != mine && ffData[i] != 2)
                return false;
        }
        return true;
    }
    
    /*
    /// returns whether the board is valid
    /// valid <=> for the currently planted mines there exists only one connected component of zeroes (=> there is at least one zero)
    bool IsValid()
    {
        // look for the first zero
        int numOfElements = r * c;
        int firstZeroIndex;
        for (firstZeroIndex = 0; firstZeroIndex < numOfElements; ++firstZeroIndex)
        {
            if (data[firstZeroIndex] == 0)
                break;
        }
        // no zero inside the board?
        if (firstZeroIndex == numOfElements)
            return false;
        // flood fill from that index
        char ffData[numOfElements];
        memcpy(ffData, data, numOfElements);
        int rowIndex = firstZeroIndex / c;
        int colIndex = firstZeroIndex % c;
        stack<SRCCoords> ffStack;
        ffStack.emplace(rowIndex, colIndex);
        while (!ffStack.empty())
        {
            SRCCoords coords = ffStack.top();
            ffStack.pop();
            int i = coords.rowIndex * c + coords.colIndex;
            if (ffData[i] != 0)
                continue;
            // mark cell as processed
            ffData[i] = 1;
            // add all it's neighbors for processing
            if (coords.rowIndex > 0) // top row
            {
                rowIndex = coords.rowIndex - 1;
                if (coords.colIndex > 0)
                {
                    colIndex = coords.colIndex - 1;
                    if (ffData[rowIndex * c + colIndex] == 0)
                        ffStack.emplace(rowIndex, colIndex);
                }
                ffStack.emplace(rowIndex, coords.colIndex);
                if (coords.colIndex < c - 1)
                {
                    colIndex = coords.colIndex + 1;
                    if (ffData[rowIndex * c + colIndex] == 0)
                        ffStack.emplace(rowIndex, colIndex);
                }
            }
            // left neighbor
            if (coords.colIndex > 0)
            {
                colIndex = coords.colIndex - 1;
                if (ffData[coords.rowIndex * c + colIndex] == 0)
                    ffStack.emplace(coords.rowIndex, colIndex);
            }
            // right neighbor
            if (coords.colIndex < c - 1)
            {
                colIndex = coords.colIndex + 1;
                if (ffData[coords.rowIndex * c + colIndex] == 0)
                    ffStack.emplace(coords.rowIndex, colIndex);
            }
            if (coords.rowIndex < r - 1) // bottom row
            {
                rowIndex = coords.rowIndex + 1;
                if (coords.colIndex > 0)
                {
                    colIndex = coords.colIndex - 1;
                    if (ffData[rowIndex * c + colIndex] == 0)
                        ffStack.emplace(rowIndex, colIndex);
                }
                ffStack.emplace(rowIndex, coords.colIndex);
                if (coords.colIndex < c - 1)
                {
                    colIndex = coords.colIndex + 1;
                    if (ffData[rowIndex * c + colIndex] == 0)
                        ffStack.emplace(rowIndex, colIndex);
                }
            }
        }
        // check that there are no more zeroes after the flood fill
        for (firstZeroIndex = 0; firstZeroIndex < numOfElements; ++firstZeroIndex)
        {
            if (ffData[firstZeroIndex] == 0)
                return false;
        }
        return true;
    }*/
    
    void NextIndexPlantMine()
    {
        // plant new mine here
        data[indexToSolve] = mine;
        --m;
        // mark all the neighbors as mine neighbors
        int rowIndex = indexToSolve / c;
        int colIndex = indexToSolve % c;
        if (rowIndex > 0) // partial optimization :)
        {
            int rowToMark = rowIndex - 1;
            MarkIfNotMine(rowToMark, colIndex - 1, 1);
            MarkIfNotMine(rowToMark, colIndex, 1);
            MarkIfNotMine(rowToMark, colIndex + 1, 1);
        }
        MarkIfNotMine(rowIndex, colIndex - 1, 1);
        MarkIfNotMine(rowIndex, colIndex + 1, 1);
        if (rowIndex < r - 1) // partial optimization :)
        {
            int rowToMark = rowIndex + 1;
            MarkIfNotMine(rowToMark, colIndex - 1, 1);
            MarkIfNotMine(rowToMark, colIndex, 1);
            MarkIfNotMine(rowToMark, colIndex + 1, 1);
        }
        // be ready for the next planting
        ++indexToSolve;
    }
    
    void MarkIfNotMine(int rowIndex, int colIndex, char mark)
    {
        if (rowIndex < 0 || rowIndex >= r || colIndex < 0 || colIndex >= c)
            return;
        unsigned int index = rowIndex * c + colIndex;
        if (data[index] != mine)
            data[index] = mark;
    }
    
    void NextIndexSkipMine()
    {
        // be ready for the next planting
        ++indexToSolve;
    }
};

void SolveTestCase(int n, istream& inpStream, CDoubleOutput& outStream)
{
    unsigned int r, c, m;
    // read the input first
    inpStream >> r;
    inpStream >> c;
    inpStream >> m;
    
    CBoard baseBoard(r, c, m);
    bool solvedAndValid = baseBoard.Solve();
    
    // print out the result
    outStream << "Case #" << n + 1 << ": " << endl;
    if (solvedAndValid)
        baseBoard.PrintToOutput(outStream);
    else
    {
        outStream << "Impossible";
        outStream << endl;
    }
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
