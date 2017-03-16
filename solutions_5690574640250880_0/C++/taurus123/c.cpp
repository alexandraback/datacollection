#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int caseIdx = 1; caseIdx <= T; ++ caseIdx)
    {
        int R,C,M;
        cin >> R >> C >> M;
        int nSpace = R * C - M;
        vector<vector<char> > mines;
        for(int row = 0; row < R; ++ row)
        {
            vector<char> curRow;
            for(int col = 0; col < C; ++ col)
                curRow.push_back('*');
            mines.push_back(curRow);
        }
        bool isPossible = false;
        if(R == 1 || C == 1)
        {
            int spaceCount = 0;
            for(int row = 0; row < R && spaceCount < nSpace; ++ row)
                for(int col = 0; col < C && spaceCount < nSpace; ++ col)
            {
                mines[row][col] = '.';
                spaceCount ++;
            }
            isPossible = true;
        }
        else if(R == 2 || C == 2)
        {
            int spaceCount = 0;
            if(nSpace == 1)
            {
                mines[0][0]='.';
                isPossible = true;
            }
            else if(nSpace >= 4)
            {
                for(int row = 0; row < R && spaceCount + 2 <= nSpace; ++ row)
                {
                    mines[row][0] = '.';
                    mines[row][1] = '.';
                    spaceCount += 2;
                }
                for(int col = 2; col < C && spaceCount + 2 <= nSpace; ++col)
                {
                    mines[0][col] = '.';
                    mines[1][col] = '.';
                    spaceCount += 2;
                }
                if(spaceCount == nSpace)
                {
                    isPossible = true;
                }
            }

        }
        else
        {
            int spaceCount = 0;
            if(nSpace == 1)
            {
                mines[0][0] = '.';
                isPossible = true;
            }
            else if(nSpace == 2 || nSpace == 3 || nSpace == 5 || nSpace == 7)
            {

            }
            else if(nSpace == 4 || nSpace == 6)
            {
                for(int row = 0; row < R && spaceCount + 2 <= nSpace; ++ row)
                {
                    mines[row][0] = '.';
                    mines[row][1] = '.';
                    spaceCount += 2;
                }
                isPossible = true;
            }
            else if(nSpace >= 8)
            {
                for(int row = 0; row < 3; ++ row)
                    for(int col = 0; col < 3; ++ col)
                    {
                        mines[row][col] = '.';
                    }
                mines[2][2] = '*';
                spaceCount = 8;
                for(int col = 3; col < C && spaceCount + 2 <= nSpace; ++ col)
                {
                    mines[0][col] = '.';
                    mines[1][col] = '.';
                    spaceCount += 2;
                }
                for(int row = 3; row < R && spaceCount + 2 <= nSpace; ++ row)
                {
                    mines[row][0] = '.';
                    mines[row][1] = '.';
                    spaceCount += 2;
                }
                for(int row = 2; row < R && spaceCount < nSpace; ++ row)
                    for(int col = 2; col < C && spaceCount < nSpace; ++ col)
                    {
                        mines[row][col] = '.';
                        ++ spaceCount;
                    }
                isPossible = true;
            }
        }
        cout<<"Case #" << caseIdx << ":" << endl;
        if(isPossible)
        {
            mines[0][0] = 'c';
            for(int row = 0; row < R; ++ row)
            {
                for(int col = 0; col < C; ++ col)
                {
                    cout<<mines[row][col];
                }
                cout<<endl;
            }
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
