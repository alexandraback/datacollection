#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
#include <set>
#include <limits.h>

using namespace std;

int T;

int judge(char s[5][5], char x)
{
    for(int i = 0; i < 4; i++)
    {
        int flag = 1;
        for(int j = 0; j < 4; j++)
        {
            if(s[i][j] == x || s[i][j] == 'T')
            {
                continue;
            }
            flag = 0;
        }
        if(flag) return 1;
        flag = 1;
        for(int j = 0; j < 4; j++)
        {
            if(s[j][i] == x || s[j][i] == 'T')
            {
                continue;
            }
            flag = 0;
        }
        if(flag)  return 1;
    }
    int flag = 1;
    for(int i = 0; i < 4; i++)  if(s[i][i] != x && s[i][i] != 'T') flag = 0;
    if(flag) return 1;
    flag = 1;
    for(int i = 0; i < 4; i++) {
        //cout << s[3-i][3-i]
      if(s[i][3-i] != x && s[i][3-i] != 'T')  flag = 0;
    }
   // cout << flag << endl;
    return flag;
}
string f()
{
    char s[5][5];
    for(int i = 0; i < 4; i++)  scanf("%s", s[i]);
    int cc = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cc += (s[i][j] == '.');
        }
    }
    if(judge(s, 'X'))   return "X won";
    if(judge(s, 'O'))   return "O won";
    if(cc == 0) return "Draw";
    return "Game has not completed";
}
int main()
{
  //  freopen("A-large.in", "r", stdin);
  //  freopen("A-large.ans", "w", stdout);
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.ans", "w", stdout);
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        cout << "Case #" << i + 1 << ": " << f() << endl;
    }
    return 0;
}
