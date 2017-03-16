#include <iostream>
#include <fstream>

using namespace std;

void print(char p[4][4])
{
    for (int i = 0; i < 4; ++i)
    {

        for (int j =0 ;j < 4; ++j)
            cout << p[i][j];
        cout << endl;
    }

}
int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int T;
    char p[4][4];
    fin >> T;
    string s;
    int line_x_numbers = 0;
    int line_w_numbers = 0;
    int flag;
    for (int i = 0 ; i < T; ++i)
    {
        flag = 0;
        int flag2 = 0;
        for (int j = 0; j < 4; ++j)
        {
            line_w_numbers = 0;
            line_x_numbers = 0;

            fin >> s;
            if ((p[j][0] = s[0]) == 'X')
                ++line_x_numbers;
            else
                if (p[j][0] == 'O')
                    ++line_w_numbers;
                else
                    if (p[j][0] == 'T')
                    {
                        ++line_w_numbers;
                        ++line_x_numbers;
                    }
                    else
                        flag2 = 1;

            if ((p[j][1] = s[1]) == 'X')
                ++line_x_numbers;
            else
                if (p[j][1] == 'O')
                    ++line_w_numbers;
                else
                    if (p[j][1] == 'T')
                    {
                        ++line_w_numbers;
                        ++line_x_numbers;
                    }
                    else
                        flag2 = 1;

            if ((p[j][2] = s[2]) == 'X')
                ++line_x_numbers;
            else
                if (p[j][2] == 'O')
                    ++line_w_numbers;
                else
                    if (p[j][2] == 'T')
                    {
                        ++line_w_numbers;
                        ++line_x_numbers;
                    }
                    else
                        flag2 = 1;

            if ((p[j][3] = s[3]) == 'X')
                ++line_x_numbers;
            else
                if (p[j][3] == 'O')
                    ++line_w_numbers;
                else
                    if (p[j][3] == 'T')
                    {
                        ++line_w_numbers;
                        ++line_x_numbers;
                    }
                    else
                        flag2 = 1;

            if (line_x_numbers == 4)
            {
                flag = 1;
                fout << "Case #" << i + 1 << ": " << "X won" << endl;
                for (int k = j+1 ; k <4 ; ++k)
                    fin >> s;
                break;
            }
            if (line_w_numbers == 4)
            {
                flag = 1;
                fout << "Case #" << i + 1<< ": " << "O won" << endl;
                for (int k = j+1 ; k <4 ; ++k)
                    fin >> s;
                break;
            }

        }
//        getline(fin, s);
        if (flag)
            continue;
 //       print(p);
        for (int j = 0; j < 4; ++j)
        {
//            cout << "---------------" << endl;
            int c_x_num = 0;
            int c_o_num = 0;
            for (int k =0 ; k < 4 ; ++k)
            {
//                cout << i << ":" << k << "," << j << "::" << p[k][j] << endl;
                if (p[k][j] == 'T')
                {
                    ++c_x_num;
                    ++c_o_num;
                }
                else
                    if (p[k][j] == 'X')
                        ++c_x_num;
                    else
                        if (p[k][j] == 'O')
                            ++c_o_num;
            }
            if (c_x_num == 4)
            {
                flag = 1;
                fout << "Case #" << i + 1 << ": " << "X won" << endl;
                break;
            }
            if (c_o_num == 4)
            {
                flag = 1;
                fout << "Case #" << i + 1<< ": " << "O won" << endl;
                break;
            }

        }
        if (flag)
            continue;
        int x_x_num1 = 0 , x_x_num2 = 0;
        int x_o_num1 = 0 , x_o_num2 = 0;
        for (int j = 0; j < 4; ++j)
        {
            switch (p[j][j])
            {
            case 'T':
                ++x_o_num1;
                ++x_x_num1;
                break;
            case 'X':
                ++x_x_num1;
                break;
            case 'O':
                ++x_o_num1;
            }
            switch (p[j][3-j])
            {
            case 'T':
                ++x_o_num2;
                ++x_x_num2;
                break;
            case 'X':
                ++x_x_num2;
                break;
            case 'O':
                ++x_o_num2;
            }
        }
        if (x_x_num1 == 4 || x_x_num2 == 4)
        {
            fout << "Case #" << i + 1 << ": " << "X won" << endl;
            flag = 1;
        }
        if (x_o_num1 == 4 || x_o_num2 == 4)
        {
            fout << "Case #" << i + 1<< ": " << "O won" << endl;
            flag = 1;
        }
        if (flag)
            continue;
        if (flag2)
        {
            fout << "Case #" << i + 1 << ": " << "Game has not completed" << endl;
            continue;
        }
        else
            fout << "Case #" << i + 1 << ": " << "Draw" << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
