#include <fstream>

using namespace std;

ifstream fin("Tic-Tac-Toe-Tomek.in");
ofstream fout("Tic-Tac-Toe-Tomek.out");

int main()
{
    char tmp[4][4];
    int sumx[3][4];
    int sumo[3][4];

    int t;
    fin >> t;
    for (int k=0; k<t; k++)
    {
        int complete=1;
        for (int i=0; i<3; i++)
            for (int j=0; j<4; j++)
            {
                sumx[i][j] = 0;
                sumo[i][j] = 0;
            }

        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
            {
                fin >> tmp[i][j];
                if (tmp[i][j] == '.')
                    complete = 0;
                if (tmp[i][j] == 'X')
                {
                    sumx[0][i]++;
                    sumx[1][j]++;
                    if (i==j)
                        sumx[2][0]++;
                    if (i+j==3)
                        sumx[2][1]++;
                }
                if (tmp[i][j] == 'O')
                {
                    sumo[0][i]++;
                    sumo[1][j]++;
                    if (i==j)
                        sumo[2][0]++;
                    if (i+j==3)
                        sumo[2][1]++;
                }
                if (tmp[i][j] == 'T')
                {
                    sumx[0][i]++;
                    sumx[1][j]++;
                    sumo[0][i]++;
                    sumo[1][j]++;
                    if (i==j)
                    {
                        sumx[2][0]++;
                        sumo[2][0]++;
                    }
                    if (i+j==3)
                    {
                        sumx[2][1]++;
                        sumo[2][1]++;
                    }
                }
            }

        /*for (int i=0; i<3; i++)
        {
            for (int j=0; j<4; j++)
                fout << sumx[i][j];
            fout << endl;
        }
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<4; j++)
                fout << sumo[i][j];
            fout << endl;
        }*/
        int key=0;
        for (int i=0; i<3&&!key; i++)
        {
            for (int j=0; j<4&&!key; j++)
            {
                if (sumx[i][j]==4)
                    key=1;
                if (sumo[i][j]==4)
                    key=2;
            }
        }

        if (key==1)
            fout << "Case #" << k+1 << ": X won" << endl;
        else if (key==2)
            fout << "Case #" << k+1 << ": O won" << endl;
        else if (key==0)
            if (complete)
                fout << "Case #" << k+1 << ": Draw" << endl;
            else
                fout << "Case #" << k+1 << ": Game has not completed" << endl;
    }

    return 0;
}
