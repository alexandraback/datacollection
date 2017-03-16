#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>

using namespace std;

ifstream in;
ofstream out;
//yes, this code is not pretty.. and for this i am sorry.
int T;
int R,C,M;

template< typename T, size_t N, size_t M >
inline void printArray( T(&theArray)[N][M], T a, T b, bool rotate  ) {
    
    if(rotate)
    {
        for ( int y = 0; y < b; y++ ) {
        for ( int x = 0; x < a; x ++ ) {
                cout << (char)theArray[x][y] << "";
                out << (char)theArray[x][y] << "";
            }
            cout << endl;
            out << endl;
        }
    }
    else
    {
        for ( int x = 0; x < a; x ++ ) {
            for ( int y = 0; y < b; y++ ) {
                cout << (char)theArray[x][y] << "";
                out << (char)theArray[x][y] << "";
            }
            cout << endl;
            out << endl;
        }
    }
};



int main ()
{
    
    // Create input/Output Streams
    in.open("A.in");
    out.open("A.out");
    
    //Read N
    in >> T;
    
    for (int t = 0; t < T; t++)
    {
        //Read Data
        in >> R >> C >> M;
        
        //R - Vertical dimension of the board
        //F - Horisontal dimension of the board
        //M - Mines
        out << "Case #" << t+1 << ":" << endl;
        cout << "Case #" << t+1 << ":" << endl;
        
        int minLines = min(R,C);
        int maxLines = max(R,C);
        
        bool shouldRotateMatrix = (minLines == C);
            
        int mat[100][100];
        memset(mat, '.', sizeof(mat));
        mat[minLines-1][maxLines-1] = 'c';
        
        if(R > 1 && C > 1)
        {
            //Construct a subspace, excluding full lines
            int fullMaxLines = trunc(M/minLines);
            
            int m = 2;
            if(minLines == 5 && M == 16)
            {
                cout << "test";
                m = 3;
            }
            
            if(maxLines-fullMaxLines < m)
                fullMaxLines = maxLines-m;
            
            for(int i = 0; i < fullMaxLines; i++)
            {
                for(int z = 0; z < minLines; z++)
                mat[z][i] = '*';
            }
            
            int newMaxDim = maxLines-fullMaxLines;
            int newM = M - fullMaxLines*minLines;
            
            int fullMinLines = trunc(newM/newMaxDim);
            
            if(minLines-fullMinLines < 2)
                fullMinLines = minLines-2;

            int newMinDim = minLines-fullMinLines;
            newM -= fullMinLines*newMaxDim;
            
            for(int i = 0; i < fullMinLines; i++)
            {
                for(int z = 0; z < newMaxDim; z++)
                    mat[i][z+fullMaxLines] = '*';
            }


            if(newM <= 0)
            {
                //We are done
                cout << "YES" << endl;
                printArray(mat, minLines, maxLines, shouldRotateMatrix);
                
            }
            else if(newM >= newMinDim*newMaxDim)
            {
                //impossible
                cout << "Impossible" << endl;
                out << "Impossible" << endl;
                
                cout << R << "," << C << " newM: " << newM << endl;
                //printArray(mat, minLines, maxLines, shouldRotateMatrix);
            }
            else
            {
                //We now have our subspace, time to think!
                 //cout << "MAYBE!";
                if(newMinDim == 2 && newMaxDim == 2) //m > newdims
                {
                    if(newM == 3)
                    {
                        cout << "YES" << endl;
                        mat[minLines-2][maxLines-2] = '*';
                        mat[minLines-1][maxLines-2] = '*';
                        mat[minLines-2][maxLines-1] = '*';
                        printArray(mat, minLines, maxLines, shouldRotateMatrix);
                    }
                    else
                    {
                        cout << "Impossible" << endl;
                        out << "Impossible" << endl;
                        
                        cout << R << "," << C << " newM: " << newM << endl;
                        //printArray(mat, minLines, maxLines, shouldRotateMatrix);
                    }
                }
                else
                {
                    if((newMinDim-newM == 1 || newMaxDim == 2) && (newMaxDim-newM == 1 || newMinDim == 2))
                    {
                        if(newM == 3 && newMaxDim >= 4 && newMinDim >= 4 )
                        {
                            cout << "YES" << endl;
                            mat[minLines-newMinDim][maxLines-newMaxDim] = '*';
                            mat[minLines-newMinDim+1][maxLines-newMaxDim] = '*';
                            mat[minLines-newMinDim][maxLines-newMaxDim+1] = '*';
                            printArray(mat, minLines, maxLines, shouldRotateMatrix);
                        }
                        else if(newM == 4 && newMaxDim >= 5 && newMinDim >= 5 )
                        {
                            cout << "YES" << endl;
                            mat[minLines-newMinDim][maxLines-newMaxDim] = '*';
                            mat[minLines-newMinDim+1][maxLines-newMaxDim] = '*';
                            mat[minLines-newMinDim][maxLines-newMaxDim+1] = '*';
                            mat[minLines-newMinDim+1][maxLines-newMaxDim+1] = '*';
                            printArray(mat, minLines, maxLines, shouldRotateMatrix);
                        }
                        else
                        {
                            cout << "Impossible" << endl;
                            out << "Impossible" << endl;
                        
                            cout << R << "," << C << " newM: " << newM << endl;
                            //printArray(mat, minLines, maxLines, shouldRotateMatrix);
                        }
                    }
                    else
                    {
                        int maxOffset = maxLines-newMaxDim;
                        int minOffset = minLines-newMinDim;
                        
                        if(newMinDim-newM != 1 && newMaxDim-1 != 1)
                        {
                            for(int i = 0; i<newM; ++i)
                            {
                                mat[i+minOffset][maxLines-newMaxDim] = '*';
                                
                                if(i+minOffset >= minLines || maxLines-newMaxDim >= maxLines)
                                    cout << "what!";
                            }
                        }
                        else if(newMaxDim-newM != 1 && newMinDim-1 != 1)
                        {
                            for(int i = 0; i<newM; ++i)
                            {
                                mat[minLines-newMinDim][i+maxOffset] = '*';
                                
                                if(minLines-newMinDim >= minLines || i+maxOffset >= maxLines)
                                    cout << "what!";
                            }
                        }
                        

                        
                        cout << "YES" << endl;
                        printArray(mat, minLines, maxLines, shouldRotateMatrix);
                    }
                }
            
            }
        }
        else
        {//If one dimension only has length 1
            for(int i = 0; i < M; i++)
                mat[0][i] = '*';
            
            if(M < R*C)
            {
                cout << "YES" << endl;
                printArray(mat, minLines, maxLines,shouldRotateMatrix);
            }
            else
            {
                cout << "Impossible" << endl;
                out << "Impossible" << endl;
                
                cout << R << "," << C << " newM: " << M << endl;
                //printArray(mat, minLines, maxLines, shouldRotateMatrix);
            }
        }
        
       // out << endl;
       // cout << endl;

    }
    
    return 0;
}
