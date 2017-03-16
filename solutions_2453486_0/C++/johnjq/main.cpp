#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
#include <queue>>
#include <algorithm>
using namespace std;

int testcase = 0;
void run()
{
    int x, o, t;
    char game[4][5];
    for (int i = 0; i < 4; ++i) {
        gets(game[i]);
    }

    //Check lines and columns
    for (int i = 0; i < 4; ++i) {
        //Check ith line
        x = o = t = 0;
        for (int j = 0; j < 4; ++j) {
            if (game[i][j] == 'X')
                ++x;
            else if (game[i][j] == 'O')
                ++o;
            else if (game[i][j] == 'T')
                ++t;
        }
        if (x+t == 4) {
            puts("X won");
            return;
        } else if (o+t == 4) {
            puts("O won");
            return;
        }
        //Check ith column
        x = o = t = 0;
        for (int j = 0; j < 4; ++j) {
            if (game[j][i] == 'X')
                ++x;
            else if (game[j][i] == 'O')
                ++o;
            else if (game[j][i] == 'T')
                ++t;
        }
        if (x+t == 4) {
            puts("X won");
            return;
        } else if (o+t == 4) {
            puts("O won");
            return;
        }
    }
    //Check first diagonal
    x = o = t = 0;
    for (int i = 0; i < 4; ++i) {
        if (game[i][i] == 'X')
            ++x;
        else if (game[i][i] == 'O')
            ++o;
        else if (game[i][i] == 'T')
            ++t;
    }
    if (x+t == 4) {
        puts("X won");
        return;
    } else if (o+t == 4) {
        puts("O won");
        return;
    }
    //Check second diagonal
    x = o = t = 0;
    for (int i = 0; i < 4; ++i) {
        if (game[i][3-i] == 'X')
            ++x;
        else if (game[i][3-i] == 'O')
            ++o;
        else if (game[i][3-i] == 'T')
            ++t;
    }
    if (x+t == 4) {
        puts("X won");
        return;
    } else if (o+t == 4) {
        puts("O won");
        return;
    }
    //Check if the game has finished
    bool over = true;
    for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
        if (game[i][j] == '.')
            over = false;
    if (over)
        puts("Draw");
    else
        puts("Game has not completed");
}

int main()
{
    #if 0
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w+", stdout);
    #endif // ONLINE_JUDGE

	int testcases;
	scanf("%d", &testcases);
	for (testcase = 1; testcase <= testcases; ++testcase)
	{
	    char line[500];
	    gets(line);
	    printf("Case #%d: ", testcase);
		run();
	}
	return 0;
}
