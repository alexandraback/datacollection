#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isX( int value )
{
    return value == 1 || value == 3;
}

bool isO( int value )
{
    return value == 2 || value == 3;
}

int main()
{
    ifstream inFile( "A-small-attempt0.in" );
    int caseCount;
    inFile >> caseCount;
    ofstream outFile( "A-small-attempt0.out" );
    
    for (int i = 0; i < caseCount; ++i)
    {
        int data[4][4];
        bool completed = true;
        
        for (int row = 0; row < 4; ++row)
        {
            for (int column = 0; column < 4; ++column)
            {
                char c;
                inFile >> c;
                switch (c)
                {
                    case '.':
                        data[row][column] = 0;
                        completed = false;
                        break;
                        
                    case 'X':
                        data[row][column] = 1;
                        break;

                    case 'O':
                        data[row][column] = 2;
                        break;
                        
                    case 'T':
                        data[row][column] = 3;
                        break;
                        
                    default:
                        data[row][column] = 4;
                        break;
                }
            }
        }
        bool wonX = false;
        bool wonO = false;
        for (int rowIx = 0; rowIx < 4; ++rowIx)
        {
            if (isX(data[rowIx][0]) && isX(data[rowIx][1]) && isX(data[rowIx][2]) && isX(data[rowIx][3]) )
            {
                wonX = true;
            }
            if (isO(data[rowIx][0]) && isO(data[rowIx][1]) && isO(data[rowIx][2]) && isO(data[rowIx][3]) )
            {
                wonO = true;
            }
        }
        for (int colIx = 0; colIx < 4; ++colIx)
        {
            if (isX(data[0][colIx]) && isX(data[1][colIx]) && isX(data[2][colIx]) && isX(data[3][colIx]) )
            {
                wonX = true;
            }
            if (isO(data[0][colIx]) && isO(data[1][colIx]) && isO(data[2][colIx]) && isO(data[3][colIx]) )
            {
                wonO = true;
            }
        }
        if (isX(data[0][0]) && isX(data[1][1]) && isX(data[2][2]) && isX(data[3][3]) )
        {
            wonX = true;
        }
        if (isX(data[0][3]) && isX(data[1][2]) && isX(data[2][1]) && isX(data[3][0]) )
        {
            wonX = true;
        }
        if (isO(data[0][0]) && isO(data[1][1]) && isO(data[2][2]) && isO(data[3][3]) )
        {
            wonO = true;
        }
        if (isO(data[0][3]) && isO(data[1][2]) && isO(data[2][1]) && isO(data[3][0]) )
        {
            wonO = true;
        }
        
        if (wonX)
        {
            outFile << "Case #" << i + 1 << ": X won" << endl;
        }
        else if (wonO)
        {
            outFile << "Case #" << i + 1 << ": O won" << endl;
        }
        else if (completed)
        {
            outFile << "Case #" << i + 1 << ": Draw" << endl;
        }
        else
        {
            outFile << "Case #" << i + 1 << ": Game has not completed" << endl;
        }
    }

    
    inFile.close();
    outFile.close();
    return 0;
}
