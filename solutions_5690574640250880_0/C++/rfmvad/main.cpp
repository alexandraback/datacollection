#include <algorithm>
#include <climits>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void func(ifstream& in, ofstream& out)
{
    int R, C, M;
    in >> R >> C >> M;
    int r = R, c = C;

    char brd[50][50];

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            brd[i][j] = '.';

    while (M >= min(R, C))
        if (R < C)
        {
            for (int i = 0; i < R; i++)
            {
                brd[i][C - 1] = '*';
            }
            C--;
            M -= R;
        }
        else
        {
            for (int j = 0; j < C; j++)
            {
                brd[R - 1][j] = '*';
            }
            R--;
            M -= C;
        }


        int i1, j1;
        if (M > 0)
        {
            if (R < C)
            {
                for (i1 = R - 1; M > 1; M--, i1--)
                    brd[i1][C - 1] = '*';
                if (i1 == 1)
                    brd[R - 1][C - 2] = '*';
                else
                    brd[i1][C - 1] = '*';
            }
            else
            {
                for (j1 = C - 1; M > 1; M--, j1--)
                    brd[R - 1][j1] = '*';
                if (j1 == 1)
                    brd[R - 2][C - 1] = '*';
                else
                    brd[R - 1][j1] = '*';
            }
        }

        int x[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int y[] = {-1, -1, -1, 0, 0, 1, 1, 1};

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (brd[i][j] == '.')
                    for (int k = 0; k < 8; k++)
                    {
                        int nx = j + x[k];
                        int ny = i + y[k];
                        if (ny >= 0 && ny < r && nx >= 0 && nx < c && brd[ny][nx] == '*')
                            brd[i][j] = '?';
                    }
        /*for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cout << brd[i][j];
            cout << endl;
        }
        cout << endl;*/

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (brd[i][j] == '?')
                {
                    bool good = false;
                    for (int k = 0; k < 8; k++)
                    {
                        int nx = j + x[k];
                        int ny = i + y[k];
                        if (ny >= 0 && ny < r && nx >= 0 && nx < c)
                            good |= (brd[ny][nx] == '.' || brd[ny][nx] == 'c');
                    }
                    if (!good && (i > 0 || j > 0))
                    {
                        out << "Impossible" << endl;
                        return;
                    }
                }

        brd[0][0] = 'c';

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                if (brd[i][j] == '?')
                    out << '.';
                else
                    out << brd[i][j];
            out << endl;
        }
}

int main()
{
    ifstream in;
    in.open("C-small-attempt1.in");

    ofstream out;
    out.open("code_jam_out");
    out << fixed << showpoint << setprecision(7);

    int T;
    in >> T;

    for (int t = 1; t <= T; t++)
    {
        //cout << "Case #" << t << endl;
        out << "Case #" << t << ":" << endl;
        func(in, out);
    }

    in.close();
    out.close();

    return 0;
}
