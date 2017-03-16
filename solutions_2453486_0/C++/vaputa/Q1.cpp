#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>

using namespace std;

char a[1 << 3][1 << 3];
int n;

string solve(){
    int dot = 0;
    for (int i = 0 ;i < 4; ++i)
        cin >> a[i];
    int hasO = 0, hasX = 0, hasD = 0;
    for (int i = 0; i < 4; ++i){
        if (a[i][i] == 'O')
            ++hasO;
        if (a[i][i] == 'X')
            ++hasX;
        if (a[i][i] == '.')
            ++hasD;
    }
    if (!hasD){
        if (hasO >= 3 && hasX == 0)
            return "O won";
        if (hasX >= 3 && hasO == 0)
            return "X won";
    }
    else 
        dot = 1;
    hasO = hasX = hasD = 0;
    for (int i = 0; i < 4; ++i){
        if (a[i][3 - i] == 'O')
            ++hasO;
        if (a[i][3 - i] == 'X')
            ++hasX;
        if (a[i][3 - i] == '.')
            ++hasD;
    }
    if (!hasD){
        if (hasO >= 3 && hasX == 0)
            return "O won";
        if (hasX >= 3 && hasO == 0)
            return "X won";
    }
    else 
        dot = 1;

    for (int i = 0; i < 4; ++i){
        hasO = hasX = hasD = 0;
        for (int j = 0; j < 4; ++j){
            if (a[i][j] == 'O')
                ++hasO;
            if (a[i][j] == 'X')
                ++hasX;
            if (a[i][j] == '.')
                ++hasD;
        }
        if (!hasD){
            if (hasO >= 3 && hasX == 0)
                return "O won";
            if (hasX >= 3 && hasO == 0)
                return "X won";
        }
        else 
            dot = 1;

        hasO = hasX = hasD = 0;
        for (int j = 0; j < 4; ++j){
            if (a[j][i] == 'O')
                ++hasO;
            if (a[j][i] == 'X')
                ++hasX;
            if (a[j][i] == '.')
                ++hasD;
        }
        if (!hasD){
            if (hasO >= 3 && hasX == 0)
                return "O won";
            if (hasX >= 3 && hasO == 0)
                return "X won";
        }
        else 
            dot = 1;
    }
    if (dot)
        return "Game has not completed";
    else 
        return "Draw";
}

int main(){
    cin >> n;
    for (int  v = 0; v < n; ++v)
        cout << "Case #" << (v + 1) << ": " << solve() <<endl;
    return 0;
}

