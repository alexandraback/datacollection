#include <algorithm>
#include <cassert>
#include <cstdio>

using std::max;

int T;
char A[4][4];

bool WonRow(int row, char type)
{
    for(int i = 0; i < 4; ++i)
        if(A[row][i] != type && A[row][i] != 'T')
            return false;
    return true;
}

bool WonColumn(int col, char type)
{
    for(int i = 0; i < 4; ++i)
        if(A[i][col] != type && A[i][col] != 'T')
            return false;
    return true;
}

bool WonForwardDiagonal(char type)
{
    for(int i = 0; i < 4; ++i)
        if(A[i][i] != type && A[i][i] != 'T')
            return false;
    return true;
}

bool WonBackwardDiagonal(char type)
{
    for(int i = 0; i < 4; ++i)
        if(A[3 - i][i] != type && A[3 - i][i] != 'T')
            return false;
    return true;
}

bool Won(char type)
{
    for(int i = 0; i < 4; ++i)
        if(WonRow(i, type) || WonColumn(i, type))
            return true;
    if(WonForwardDiagonal(type) || WonBackwardDiagonal(type))
        return true;
    return false;
}

bool Full()
{
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            if(A[i][j] == '.')
                return false;
    return true;
}

int main(int argc, char** argv)
{
    scanf("%d", &T);
    
    for(int t = 1; t <= T; ++t)
    {
        printf("Case #%d: ", t);
        
        for(int r = 0; r < 4; ++r)
        {
            scanf(" ");
            for(int c = 0; c < 4; ++c)
                scanf("%c", A[r] + c);
        }
        
        bool XWon = Won('X');
        bool OWon = Won('O');
        
        assert(!XWon || !OWon); /// They both can't win - can they?s
        
        if(XWon)
            printf("X won\n");
        else if(OWon)
            printf("O won\n");
        else if(Full())
            printf("Draw\n");
        else
            printf("Game has not completed\n");
    }
    
    return 0;
}