#include <vector>
#include <iostream>
using namespace std;

pair<int, int> find_t_pos(vector<string> &s)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (s[i][j] == 'T')
                return make_pair(i, j);
    return make_pair(-1, -1);
}

bool win_by_row(char ch, vector<string> &s, int i)
{
    for (int j = 0; j < 4; j++)
        if (s[i][j] != ch)
            return false;
    return true;
}

bool win_by_col(char ch, vector<string> &s, int i)
{
    for (int j = 0; j < 4; j++)
        if (s[j][i] != ch)
            return false;
    return true;
}

bool isWinner(char ch, vector<string> &s)
{
    bool d1 = true, d2 = true;
    for (int i = 0; i < 4; i++)
    {
        if (win_by_row(ch, s, i) || win_by_col(ch, s, i))
        {
            return true;
        }
        if (s[i][i] != ch)
            d1 = false;
        if (s[i][3-i] != ch)
            d2 = false;
    }
    return d1 || d2;
}

int main()
{
    int T;
    cin >> T;
    cin.ignore(2, '\n');
    vector<string> s(4);

    for (int task = 1; task <= T; task++)
    {
        cout << "Case #" << task << ": ";
        string result;
        for (int i = 0; i < 4; i++)
        {
            cin >> s[i];
        }
        cin.ignore(1, '\n');

        pair<int, int> t_pos = find_t_pos(s);
        if (t_pos.first >= 0)
        {
            s[t_pos.first][t_pos.second] = 'X';
        }
        if (isWinner('X', s))
        {
            result = "X won";
        }
        else
        {
            if (t_pos.first >= 0)
            {
                s[t_pos.first][t_pos.second] = 'O';
            }
            if (isWinner('O', s))
            {
                result = "O won";
            }
            else
            {
                bool completed = true;
                for (int i = 0; i < 4; i++)
                if (s[i].find('.') != string::npos)
                {
                    completed = false;
                    break;
                }
                result = completed ? "Draw" : "Game has not completed";
            }
        }


        cout << result << endl;
    }
    return 0;
}
