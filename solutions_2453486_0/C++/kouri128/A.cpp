#include <iostream>
#include <vector>
using namespace std;

const int ROW = 4;

bool wins(char c, const string& l)
{
    int countT = 0;

    for (int i = 0; i < ROW; ++i)
    {
        if (l[i] != c && l[i] != 'T')
        {
            return false;
        }
        if (l[i] == 'T')
        {
            ++countT;
            if (countT > 1)
            {
                return false;
            }
        }
    }

    return true;
}

bool wins(char c, const vector<string>& m)
{
    for (int i = 0; i < ROW; ++i)
    {
        if (wins(c, m[i]))
        {
            return true;
        }
    }

    for (int i = 0; i < ROW; ++i)
    {
        string l('.', ROW);
        for (int j = 0; j < ROW; ++j)
        {
            l[j] = m[j][i];
        }

        if (wins(c, l))
        {
            return true;
        }
    }

    {
        string l('.', ROW);
        for (int j = 0; j < ROW; ++j)
        {
            l[j] = m[j][j];
        }

        if (wins(c, l))
        {
            return true;
        }

        for (int j = 0; j < ROW; ++j)
        {
            l[j] = m[j][ROW - 1 - j];
        }

        if (wins(c, l))
        {
            return true;
        }
    }

    return false;
}

bool ends(const vector<string>& m)
{
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < ROW; ++j)
        {
            if (m[i][j] == '.')
            {
                return false;
            }
        }
    }

    return true;
}

string solve(const vector<string>& m)
{
    if (wins('X', m))
    {
        return "X won";
    }
    if (wins('O', m))
    {
        return "O won";
    }
    if (ends(m))
    {
        return "Draw";
    }

    return "Game has not completed";
}

int main()
{
    int N;
    cin>>N;

    for (int i = 0; i < N; ++i)
    {
        vector<string> m(ROW);
        for (int j = 0; j < ROW; ++j)
        {
            cin>>m[j];
        }
        string result = solve(m);
        cout<<"Case #"<<(i + 1)<<": "<<result<<endl;
    }

    return 0;
}
