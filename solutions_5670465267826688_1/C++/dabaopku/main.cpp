//
//  main.cpp
//  Q_C
//
//  Created by dabao on 15/4/11.
//  Copyright (c) 2015年 Peking University. All rights reserved.
//

#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int v[5][5];
long long X;
int L[10010];
int len;
int acc[200000];

int char2dig(char c)
{
    switch (c) {
        case '1':
            return 1;
        case 'i':
            return 2;
        case 'j':
            return 3;
        case 'k':
            return 4;
        default:
            return 0;
    }
}

int dig2char(int i)
{
    switch (i) {
        case 1:
            return '1';
        case 2:
            return 'i';
        case 3:
            return 'j';
        case 4:
            return 'k';
        default:
            return 0;
    }
}

int mul(int x, int y)
{
    if (x > 0 && y > 0) {
        return v[x][y];
    }
    
    if (x > 0 && y < 0) {
        return -v[x][-y];
    }
    
    if (x < 0 && y > 0) {
        return -v[-x][y];
    }
    
    if (x < 0 && y < 0) {
        return v[-x][-y];
    }
    
    return 1;
}

void init()
{
    for (int i = 1; i <= 4; ++i) {
        v[1][i] = i;
    }
    
    for (int i = 1; i <= 4; ++i) {
        v[2][i] = 7 - i;
        if (i <= 2) {
            v[2][i] -= 4;
        }
        if (i % 2 == 0) {
            v[2][i] *= -1;
        }
    }
    
    for (int i = 1; i <= 4; ++i) {
        v[3][i] = i + 2;
        if (i >= 3) {
            v[3][i] -= 4;
        }
        if (i == 2 || i == 3) {
            v[3][i] *= -1;
        }
    }
    
    for (int i = 1; i <= 4; ++i) {
        v[4][i] = 5 - i;
        if (i >= 3) {
            v[4][i] *= -1;
        }
    }
    
    /*
     for (int i = 1; i <= 4; ++i) {
     for (int j = 1; j <= 4; ++j) {
     if (v[i][j] < 0) {
     printf("-");
     }
     printf("%c\t", dig2char(abs(v[i][j])));
     }
     printf("\n");
     }
     */
}

// f(a, b) * f(b, c) = f(a, c)
// f(a, b)^4 * f(b, c) = f(a, b)^3 * f(a, c)
// f(b, c) = f(a, b)^3 * f(a, c)
int check(int start, int end)
{
    int b = acc[start];
    int c = acc[end];
    
    if (b == 1) {
        return c;
    }
    else {
        return -mul(b, c);
    }
}

void input()
{
    scanf("%d %lld", &len, &X);
    char buffer[20000];
    scanf("%s", buffer);
    for (int i = 0; i < len; ++i) {
        L[i] = char2dig(buffer[i]);
    }
}

void solve()
{
    if (X > 11) {
        long long repeatX = (X - 11) /4 * 4;
        X -= repeatX;
    }
    
    int totalLen = (int)(len * X);
    acc[0] = 1;
    for (int i = 1; i <= totalLen; ++i) {
        acc[i] = mul(acc[i - 1], L[(i - 1) % len]);
    }
    
    if (acc[totalLen] != mul(mul(2, 3), 4)) {
        printf("NO\n");
        return;
    }
    int first = 1,
        second = 2;
    
    while (first < totalLen) {
        int i = check(0, first);
        if (i != 2) {
            ++first;
            continue;
        }
        second = first + 1;
        while (second < totalLen) {
            int j = check(first, second);
            int k = check(second, totalLen);
            if (j == 3 && k == 4) {
                printf("YES\n");
                return;
            }
            //printf("%d %d\n", first, second);
            ++second;
        }
        ++first;
    }
    
    printf("NO\n");
}

int main(int argc, const char * argv[])
{
    freopen("/Users/dabao/Desktop/GoogleCodeJam2015/Q_C/input.txt", "r", stdin);
    freopen("/Users/dabao/Desktop/GoogleCodeJam2015/Q_C/output.txt", "w", stdout);
    
    init();

    int caseNumber;
    
    scanf("%d", &caseNumber);
    
    for (int caseId = 1; caseId <= caseNumber; ++caseId) {
        printf("Case #%d: ", caseId);
        input();
        solve();
    }
    
    return 0;
}
