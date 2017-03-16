#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <string>
#include <cstring>
#include <regex>

using namespace std;

string s[4];
bool check(char player){
    for(int i = 0; i < 4; i++){
        bool flag = true;
        for(int j = 0; j < 4; j++)
            if(s[i][j] != player && s[i][j] != 'T')
            {
                flag = false;
                break;
            }
        if(flag)
            return true;
    }
    for(int i = 0; i < 4; i++){
        bool flag = true;
        for(int j = 0; j < 4; j++)
            if(s[j][i] != player && s[j][i] != 'T')
            {
                flag = false;
                break;
            }
        if(flag)
            return true;
    }
    bool flag = true;
    for(int i = 0; i < 4; i++){
        if(s[i][i] != player && s[i][i] != 'T')
        {
            flag = false;
            break;
        }
    }
    if(flag)
        return true;
    flag = true;
    for(int i = 0; i < 4; i++){
        if(s[3-i][i] != player && s[3-i][i] != 'T')
        {
            flag = false;
            break;
        }
    }
    if(flag)
        return true;
    else
        return false;
}

bool isFinish(){
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(s[i][j] == '.')
                return false;
    return true;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int z = 0; z < T; z++){
        for(int i = 0; i < 4; i++)
            cin >> s[i];
        bool flag1 = check('X');
        bool flag2 = check('O');
        bool finish = isFinish();

        printf("Case #%d: ",z+1);
        if(flag1 && flag2 || (!flag1 && !flag2 && finish))
            printf("Draw");
        else if(flag1)
            printf("X won");
        else if(flag2)
            printf("O won");
        else
            printf("Game has not completed");

        printf("\n");
    }
    return 0;
}

