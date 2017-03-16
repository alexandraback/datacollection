#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>


using namespace std;

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, ca = 0;
    cin >> T;
    while (T--)
    {
        vector <string> s(4);

        for (int i = 0; i < 4; i++)
            cin >> s[i];
        int flag = 0;
        int cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            int tot = 0;
            for (int j = 0; j < 4; j++)
                if (s[i][j] == 'X' || s[i][j] == 'T') tot++;
            if (tot == 4) flag = 1;
            tot = 0;
            for (int j = 0; j < 4; j++)
                if (s[j][i] == 'X' || s[j][i] == 'T') tot ++;
            if (tot == 4) flag = 1;
            tot = 0;
            for (int j = 0; j < 4; j++)
                if (s[i][j] == 'O' || s[i][j] == 'T') tot++;
            if (tot == 4) flag = 2;
            tot = 0;
            for (int j = 0; j < 4; j++)
                if (s[j][i] == 'O' || s[j][i] == 'T') tot ++;
            if (tot == 4) flag = 2;
            for (int j = 0; j < 4; j++)
                if (s[i][j] == '.') cnt++;
        }
        int tot = 0;
        for (int i = 0; i < 4; i++)
            if (s[i][i] == 'X' || s[i][i] == 'T') tot++;
        if (tot == 4) flag = 1;

        tot = 0;
        for (int i = 0; i < 4; i++)
            if (s[i][i] == 'O' || s[i][i] == 'T') tot++;
        if (tot == 4) flag = 2;

        tot = 0;
        for (int i = 0; i < 4; i++)
            if (s[i][3 - i] == 'X' || s[i][3 - i] == 'T') tot++;
        if (tot == 4) flag = 1;

        tot = 0;
        for (int i = 0; i < 4; i++)
            if (s[i][3 - i] == 'O' || s[i][3 - i] == 'T') tot++;
        if (tot == 4) flag = 2;

        printf("Case #%d: ", ++ca);
        if (flag == 1) puts("X won");
        else if (flag == 2) puts("O won");
        else if (flag == 0 && cnt) puts("Game has not completed");
        else puts("Draw");
    }
    return 0;
}
