#include <iostream>
#include <fstream>
#include <sstream>
#include<iomanip>

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>

#include <algorithm>

static char * g_board = nullptr;
#define BOARD(i, j) g_board(()())
const static int MAX_BOARD = 2500;//50 * 50
const static char MINE = '*';
const static char NOMINE = '.';
const static char CLICK = 'c';
const static char ZERO = '0';

void restoreBoard(int Row, int Column)
{
    int offset = 0;
    for (int i = 0; i < Row; ++i)
    {
        for (int j = 0; j < Column; ++j, ++offset)
        {
            if (ZERO == g_board[offset])
            {
                g_board[offset] = NOMINE;
            }
        }
    }
}

bool oneClickSovle(int Row, int Column)
{
    // mark all zero NOMINE in board, none zero NOMINE remains unchanged.
    int offset = 0, clickRow = 0, clickColumn = 0, zeroCount = 0;
    for (int i = 0; i < Row; ++i)
    {
        for (int j = 0; j < Column; ++j, ++offset)
        {
            if (MINE == g_board[offset])
            {
                continue;
            }
            if (i > 0)
            {
                if (j > 0 && MINE == g_board[(i - 1)* Column + j - 1])          //i-1,j-1
                    continue;
                if (MINE == g_board[(i - 1)* Column + j])                       //i-1,j
                    continue;
                if (j < Column - 1 && MINE == g_board[(i - 1)* Column + j + 1]) //i-1,j+1
                    continue;
            }
            if (i < Row - 1)
            {
                if (j > 0 && MINE == g_board[(i + 1)* Column + j - 1])          //i+1,j-1
                    continue;
                if (MINE == g_board[(i + 1)* Column + j])                       //i+1,j
                    continue;
                if (j < Column - 1 && MINE == g_board[(i + 1)* Column + j + 1]) //i+1,j+1
                    continue;
            }
            if (j > 0 && MINE == g_board[i * Column + j - 1])              //i,j-1
                continue;
            if (j < Column - 1 && MINE == g_board[i * Column + j + 1])     //i,j+1
                continue;

            // all neighbours are NOMINE, this is zero.
            g_board[offset] = ZERO;
            zeroCount++;
            // mark a click point.
            clickRow = i;
            clickColumn = j;
        }
    }

    // check board to see if all NOMINE has a neighbour zero.
    offset = 0;
    for (int i = 0; i < Row; ++i)
    {
        for (int j = 0; j < Column; ++j, ++offset)
        {
            // clean if this is MINE or ZERO, we need to check only NOMINE
            if (MINE == g_board[offset] || ZERO == g_board[offset])
            {
                continue;
            }
            if (i > 0)
            {
                if (j > 0 && ZERO == g_board[(i - 1)* Column + j - 1])          //i-1,j-1
                    continue;
                if (ZERO == g_board[(i - 1)* Column + j])                       //i-1,j
                    continue;
                if (j < Column - 1 && ZERO == g_board[(i - 1)* Column + j + 1]) //i-1,j+1
                    continue;
            }
            if (i < Row - 1)
            {
                if (j > 0 && ZERO == g_board[(i + 1)* Column + j - 1])          //i+1,j-1
                    continue;
                if (ZERO == g_board[(i + 1)* Column + j])                       //i+1,j
                    continue;
                if (j < Column - 1 && ZERO == g_board[(i + 1)* Column + j + 1]) //i+1,j+1
                    continue;
            }
            if (j > 0 && ZERO == g_board[i * Column + j - 1])              //i,j-1
                continue;
            if (j < Column - 1 && ZERO == g_board[i * Column + j + 1])     //i,j+1
                continue;

            // this block doesn't have a zero neighbour, one-click-sovle not possible.
            restoreBoard(Row, Column);
            return false;
        }
    }

    // second wrong try, not check distribute zeros.
    if (zeroCount <= 1)
    {
        restoreBoard(Row, Column);
        // mark the click point.
        g_board[clickRow * Column + clickColumn] = CLICK;
        return true;
    }

    // multiple zeros, need to check board to see if all zero are connected.
    offset = 0;
    for (int i = 0; i < Row; ++i)
    {
        for (int j = 0; j < Column; ++j, ++offset)
        {
            // clean if this is MINE or NOMINE, we need to check only ZERO
            if (MINE == g_board[offset] || NOMINE == g_board[offset])
            {
                continue;
            }
            if (i > 0)
            {
                if (j > 0 && ZERO == g_board[(i - 1)* Column + j - 1])          //i-1,j-1
                    continue;
                if (ZERO == g_board[(i - 1)* Column + j])                       //i-1,j
                    continue;
                if (j < Column - 1 && ZERO == g_board[(i - 1)* Column + j + 1]) //i-1,j+1
                    continue;
            }
            if (i < Row - 1)
            {
                if (j > 0 && ZERO == g_board[(i + 1)* Column + j - 1])          //i+1,j-1
                    continue;
                if (ZERO == g_board[(i + 1)* Column + j])                       //i+1,j
                    continue;
                if (j < Column - 1 && ZERO == g_board[(i + 1)* Column + j + 1]) //i+1,j+1
                    continue;
            }
            if (j > 0 && ZERO == g_board[i * Column + j - 1])              //i,j-1
                continue;
            if (j < Column - 1 && ZERO == g_board[i * Column + j + 1])     //i,j+1
                continue;

            // this zero doesn't is isolated, one-click-sovle not possible.
            restoreBoard(Row, Column);
            return false;
        }
    }

    restoreBoard(Row, Column);
    // mark the click point.
    g_board[clickRow * Column + clickColumn] = CLICK;
    return true;
}

bool findOncClickSolve(int Row, int Column, int Mines)
{
    memset(g_board + Mines, NOMINE, Row * Column - Mines);
    memset(g_board, MINE, Mines);

    // one NOMINE or zero MINE is always able to solve-in-one-click.
    if (Mines == 0 || Mines == Row * Column - 1)
    {
        g_board[Row * Column - 1] = CLICK;      // first wrong try, marked wrong click position.
        return true;
    }

    do
    {
        bool oncClickPossible = oneClickSovle(Row, Column);
        if (oncClickPossible)
        {

            return true;
        }
    } while (std::next_permutation(g_board, g_board + Row * Column));

    return false;
}

void testMine()
{
    // read case number
    std::ifstream fin("E:/testdata/mine/sample.in");
    std::string line;
    getline(fin, line);
    std::stringstream ss(line);
    int caseNumber;
    ss >> caseNumber;
    if (caseNumber <= 0)
    {
        return;
    }

    std::ofstream fout("E:/testdata/mine/sample.out");
    g_board = new (std::nothrow) char[MAX_BOARD];
    if (nullptr == g_board)
    {
        return;
    }

    // read input file.
    for (int i = 1; i <= caseNumber; ++i)
    {
        // for one case.
        getline(fin, line);
        if (line.empty())
        {
            continue;
        }
        int Row, Column, Mines;
        std::stringstream ss(line);
        ss >> Row >> Column >> Mines;

        bool solveFound = findOncClickSolve(Row, Column, Mines);
        fout << "Case #" << i << ": " << std::endl;
        if (solveFound)
        {
            int offset = 0;
            for (int i = 0; i < Row; ++i)
            {
                for (int j = 0; j < Column; ++j)
                {
                    fout << g_board[offset++];
                }
                fout << std::endl;
            }
        }
        else
        {
            fout << "Impossible" << std::endl;
        }
    }
    fin.close();
    fout.close();
}

int main()
{
    testMine();
    return 0;
}