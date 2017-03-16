#include<iostream>
#include<cstdio>
using namespace std;

char map[4][4];

int main()
{
    int T;
    freopen("A-small-attempt1.in","r",stdin);
    freopen("dfg.out","w",stdout);
    cin >> T;

    for(int t = 1; t <= T; t++)
    {
        cout << "Case #"<<t<<": ";
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                cin >> map[i][j];

        int win = 4;

        for(int i = 0; i < 4; i++)
        {
            int nT = 0;
            int nO = 0;
            int nX = 0;
            bool complete = true;
            for(int j = 0; j < 4; j++)
            {
                if(map[i][j] == 'O')
                    nO ++;
                else if(map[i][j] == 'X')
                    nX ++;
                else if(map[i][j] == 'T')
                    nT ++;
                else if(map[i][j] == '.')
                    complete = false;
            }
            if(win == 4 | win == 3)
            {
                if(nT + nO == 4)
                    win = 1;
                if(nT + nX == 4)
                    win = 2;
                if(complete == false)
                    win = 3;
            }
        }

        for(int j = 0; j < 4; j++)
        {
            int nT = 0;
            int nO = 0;
            int nX = 0;
            bool complete = true;
            for(int i = 0; i < 4; i++)
            {
                if(map[i][j] == 'O')
                    nO ++;
                else if(map[i][j] == 'X')
                    nX ++;
                else if(map[i][j] == 'T')
                    nT ++;
                else if(map[i][j] == '.')
                    complete = false;
            }
            if(win == 4 | win == 3)
            {
                if(nT + nO == 4)
                    win = 1;
                if(nT + nX == 4)
                    win = 2;
                if(complete == false)
                    win = 3;
            }
        }

        int nT = 0;
        int nO = 0;
        int nX = 0;
        for(int i = 0; i < 4; i++)
        {
            if(map[i][i] == 'O')
                nO ++;
            else if(map[i][i] == 'X')
                nX ++;
            else if(map[i][i] == 'T')
                nT ++;
        }
        if(win == 4 | win == 3)
            {
                if(nT + nO == 4)
                    win = 1;
                if(nT + nX == 4)
                    win = 2;
            }

         nT = 0;
        nO = 0;
         nX = 0;
        for(int i = 0; i < 4; i++)
        {
            if(map[i][3 - i] == 'O')
                nO ++;
            else if(map[i][3 -i] == 'X')
                nX ++;
            else if(map[i][3 -i] == 'T')
                nT ++;
        }
        if(win == 4 | win == 3)
            {
                if(nT + nO == 4)
                    win = 1;
                if(nT + nX == 4)
                    win = 2;
            }

        if(win == 1)
            cout << "O won"<< endl;
        else if(win == 2)
            cout << "X won"<< endl;
        else if(win == 3)
            cout << "Game has not completed"<< endl;
        else if(win == 4)
            cout << "Draw" << endl;
    }
    return 0;
}
