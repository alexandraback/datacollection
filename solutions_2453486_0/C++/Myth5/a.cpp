#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 4;

string a[4];

int check()
{
    bool flag;
    for (int i = 0; i < N; ++i) {
        flag = true;
        for (int j = 0; j < N; ++j)
            if (a[i][j] == '.' || a[i][j] == 'X')
                flag = false;
        if (flag)
            return 1;
        flag = true;
        for (int j = 0; j < N; ++j)
            if (a[i][j] == '.' || a[i][j] == 'O')
                flag = false;
        if (flag)
            return -1;
    }
    for (int j = 0; j < N; ++j) {
        flag = true;
        for (int i = 0; i < N; ++i)
            if (a[i][j] == '.' || a[i][j] == 'X')
                flag = false;
        if (flag)
            return 1;
        flag = true;
        for (int i = 0; i < N; ++i)
            if (a[i][j] == '.' || a[i][j] == 'O')
                flag = false;
        if (flag)
            return -1;
    }
    flag = true;
    for (int i = 0; i < N; ++i)
        if (a[i][i] == '.' || a[i][i] == 'X')
            flag = false;
    if (flag)
        return 1;
    flag = true;
    for (int i = 0; i < N; ++i)
        if (a[i][i] == '.' || a[i][i] == 'O')
            flag = false;
    if (flag)
        return -1;
    flag = true;
    for (int i = 0; i < N; ++i)
        if (a[i][N - i - 1] == '.' || a[i][N - i - 1] == 'X')
            flag = false;
    if (flag)
        return 1;
    flag = true;
    for (int i = 0; i < N; ++i)
        if (a[i][N - i - 1] == '.' || a[i][N - i - 1] == 'O')
            flag = false;
    if (flag)
        return -1;
    return 0;
}

int main()
{
    freopen("a0.in", "r", stdin);
    freopen("a0.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);
        
        for (int i = 0; i < N; ++i)
            cin >> a[i];
        bool empty = false;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (a[i][j] == '.')
                    empty = true;
        int result = check();
        if (result == 1)
            printf("O won");
        if (result == -1)
            printf("X won");
        if (result == 0)
            if (empty)
                printf("Game has not completed");
            else
                printf("Draw");
        printf("\n");
    }
    
    return 0;
}
