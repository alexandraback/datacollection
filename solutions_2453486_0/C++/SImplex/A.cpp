#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


int is_win(char arr[4][5])
{
    for (int i = 0; i < 4; ++i)
    {
        int curX = 0;
        int curO = 0;
        for (int j = 0; j < 4; ++j)
        {
            if ((arr[i][j] == 'X') || (arr[i][j] == 'T'))
                ++curX;
            if ((arr[i][j] == 'O') || (arr[i][j] == 'T'))
                ++curO;
        }
        if (curX == 4)
            return -1;
        if (curO == 4)
            return 1;
        curX = 0;
        curO = 0;

        for (int j = 0; j < 4; ++j)
        {
            if ((arr[j][i] == 'X') || (arr[j][i] == 'T'))
                ++curX;
            if ((arr[j][i] == 'O') || (arr[j][i] == 'T'))
                ++curO;
        }
        if (curX == 4)
            return -1;
        if (curO == 4)
            return 1;
        curX = 0;
        curO = 0;
    }
    int curX = 0;
    int curO = 0;
    for (int j = 0; j < 4; ++j)
    {
         if ((arr[j][j] == 'X') || (arr[j][j] == 'T'))
            ++curX;
        if ((arr[j][j] == 'O') || (arr[j][j] == 'T'))
            ++curO;
    }
    if (curX == 4)
        return -1;
    if (curO == 4)
        return 1;
    curX = 0;
    curO = 0;
    for (int j = 0; j < 4; ++j)
    {
         if ((arr[3-j][j] == 'X') || (arr[3-j][j] == 'T'))
            ++curX;
        if ((arr[3-j][j] == 'O') || (arr[3-j][j] == 'T'))
            ++curO;
    }
    if (curX == 4)
        return -1;
    if (curO == 4)
        return 1;
    return 0;
}

bool is_end(char arr[4][5])
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (arr[i][j] == '.')
                return false;
    return true;
}

int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int T = 0;
    cin >> T;

    char arr[4][5];

    for (int step =1 ;step <= T; ++step)
    {
        cin>>arr[0];
        cin>>arr[1];
        cin>>arr[2];
        cin>>arr[3];
        int res = is_win(arr);
        cout << "Case #"<<step<<": ";
        if (res < 0)
        {
            cout << "X won";
        }
        else
            if (res > 0)
                cout << "O won";
            else
                if (is_end(arr))
                    cout << "Draw";
                else
                    cout << "Game has not completed";
        cout << "\n";
    }
    return 0;
}
