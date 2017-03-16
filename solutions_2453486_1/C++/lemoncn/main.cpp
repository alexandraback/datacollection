#include <fstream>
using namespace std;
int main(void)
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int T;
    fin >> T;
    for(int k = 1; k <= T; k++)
    {
        char lines[5][5];
        for(int i = 0; i < 4; i++)
            fin >> lines[i];
        fout << "Case #" << k << ": ";
        bool solved = false;
        bool completed = true;
        for(int i = 0; i < 4; i++)
        {
            bool o = true, x = true;
            //Row
            for(int j = 0; j < 4; j++)
            {
                if(lines[i][j] == 'X')
                    o = false;
                if(lines[i][j] == 'O')
                    x = false;
                if(lines[i][j] == '.')
                    o = x = completed = false;
            }
            if(o == true)
            {
                solved = true;
                fout << "O won" << endl;
                break;
            }
            if(x == true)
            {
                solved = true;
                fout << "X won" <<endl;
                break;
            }
            //Col
            o = x = true;
            for(int j = 0; j < 4; j++)
            {
                if(lines[j][i] == 'X')
                    o = false;
                if(lines[j][i] == 'O')
                    x = false;
                if(lines[j][i] == '.')
                    o = x = completed = false;
            }
            if(o == true)
            {
                solved = true;
                fout << "O won" << endl;
                break;
            }
            if(x == true)
            {
                solved = true;
                fout << "X won" <<endl;
                break;
            }
        }
        if(!solved)
        {
            bool x = true, o = true;
            for(int i = 0; i < 4; i++)
            {
                if(lines[i][i] == 'O')
                    x = false;
                if(lines[i][i] == 'X')
                    o = false;
                if(lines[i][i] == '.')
                    x = o = false;
            }
            if(o == true)
            {
                solved = true;
                fout << "O won" << endl;
            }
            if(x == true)
            {
                solved = true;
                fout << "X won" <<endl;
            }
            x = true, o = true;
            for(int i = 0; i < 4; i++)
            {
                if(lines[i][3-i] == 'X')
                    o = false;
                if(lines[i][3-i] == 'O')
                    x = false;
                if(lines[i][3-i] == '.')
                    x = o = false;
            }
            if(o == true)
            {
                solved = true;
                fout << "O won" << endl;
            }
            if(x == true)
            {
                solved = true;
                fout << "X won" <<endl;
            }
        }
        if(!solved)
        {
            if(completed)
                fout << "Draw" << endl;
            else
                fout << "Game has not completed" << endl;
        }
    }
    return 0;
}
