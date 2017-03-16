#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

char mt[4][4];
int n, num, o_num, x_num;

bool judge(ofstream& fout)
{
    if (x_num == 4)
    {
        num++;
        fout << "Case #" << num << ": " << "X won" << endl;
        return true;
    }
    else if (o_num == 4)
    {
        num++;
        fout << "Case #" << num << ": " << "O won" << endl;
        return true;
    }
    return false;
}

void sol(ofstream& fout)
{
    for (int i = 0; i < 4; i++)
    {
        o_num = 0;
        x_num = 0;
        for (int j = 0; j < 4; j++)
        {
            if (mt[i][j] == 'X' || mt[i][j] == 'T')
                x_num++;
            if (mt[i][j] == 'O' || mt[i][j] == 'T')
                o_num++;
        }
        if (judge(fout))
            return;
    }
    
    for (int j = 0; j < 4; j++)
    {
        o_num = 0;
        x_num = 0;
        for (int i = 0; i < 4; i++)
        {
            if (mt[i][j] == 'X' || mt[i][j] == 'T')
                x_num++;
            if (mt[i][j] == 'O' || mt[i][j] == 'T')
                o_num++;
        }
        if (judge(fout))
            return;
    }
    
    o_num = 0;
    x_num = 0;
    for (int i = 0; i < 4; i++)
    {
        if (mt[i][i] == 'X' || mt[i][i] == 'T')
            x_num++;
        if (mt[i][i] == 'O' || mt[i][i] == 'T')
            o_num++;
    }
    if (judge(fout))
        return;
    
    o_num = 0;
    x_num = 0;
    for (int i = 0; i < 4; i++)
    {
        if (mt[i][3 - i] == 'X' || mt[i][3 - i] == 'T')
            x_num++;
        if (mt[i][3 - i] == 'O' || mt[i][3 - i] == 'T')
            o_num++;
    }
    if (judge(fout))
        return;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (mt[i][j] == '.')
            {
                num++;
                fout << "Case #" << num << ": " << "Game has not completed" << endl;
                return;
            }

    num++;
    fout << "Case #" << num << ": " << "Draw" << endl;
    return;
}

int main()
{
    ifstream fin;
    fin.open("A-small-attempt1.in");
    ofstream fout;
    fout.open("output.txt");

    fin >> n;
    num = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                fin >> mt[j][k];
        sol(fout);
    }

    fin.close();
    fout.close();
    return 0;
}
