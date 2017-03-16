#include <iostream>

using namespace std;

void reset(int R, int C, char** out)
{
    for (int i=0; i<R; i++) for (int j=0; j<C; j++) out[i][j]='*';
}

bool rem(int empty, int R, int C, int startRow, char** out)
{
    if (empty>((R-startRow)*C)) return false;
    if (empty == 1) return false;
    for (int rows=1; rows<=R-startRow; rows++)
    {
        for (int cols=2; cols<C; cols++)
        {
            if (rows+startRow==1) continue;
            int left = empty - rows*cols;
            if (left < 0) continue;
            if (left && (rows==(R-startRow))) continue;
            if ((left < cols) && (left != 1))
            {
                for (int r=0; r<rows; r++) for (int c=0; c<cols; c++) out[startRow+r][c]='.';
                for (int c=0; c<left; c++) out[startRow+rows][c]='.';
                return true;
            }
            else
            {
                if (rem(left, R, cols, startRow+rows, out))
                {
                    for (int r=0; r<rows; r++) for (int c=0; c<cols; c++) out[startRow+r][c]='.';
                    return true;
                }
            }
        }
    }
    return false;
}

void runTest()
{
    int R, C, M;
    cin >> R >> C >> M;
    int empty = R*C-M;
    bool poss = false;
    
    char **out = new char*[R];
    for (int i = 0; i < R; ++i)
        out[i] = new char[C];

    reset(R, C, out);
    
    if (empty==1) poss=true;
    
    if (!poss && (M==0))
    {
        for (int i=0; i<R; i++)
            for (int j=0; j<C; j++) out[i][j]='.';
        poss = true;
    }
    
    if (!poss && (R==1))
    {
        for (int i=0; i<empty; i++) out[0][i]='.';
        poss = true;
    }
    
    if (!poss && (C==1))
    {
        for (int i=0; i<empty; i++) out[i][0]='.';
        poss = true;
    }
    
    poss = poss || rem(empty, R, C+1, 0, out);
    
    if (!poss) {cout << "Impossible" << endl;}
    else 
    {
        out[0][0]='c';
        for (int i=0; i<R; i++)
        {
            for (int j=0; j<C; j++)
            {
                cout << out[i][j];
            }
            cout << endl;
        }
    }
        
    for (int i = 0; i < R; ++i)
        delete [] out[i];
    delete [] out;
}

int main()
{
    int T;
    cin >> T;
    for (int test=1; test<=T; test++)
    {
        cout << "Case #" << test << ":" << endl;
        runTest();
    }
    return 0;
}
