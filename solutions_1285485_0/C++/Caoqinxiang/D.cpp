#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int t, n, m, D, d, x, y, ans;
char s[200][200];
bool _flag[2][200][200];
bool (* flag)[200] = _flag[1];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int sgn(int x)
{
    if (x == 0)
        return 0;
    else if (x > 0)
        return 1;
    else
        return -1;
}

int sqr(int x)
{
    return x * x;
}

bool CheckDeadPoint(int X, int Y, int sX, int sY)
{
    if (sX == 0 || sY == 0)
        return 0;
    return flag[X + sX][Y + sY] && ! flag[X + sX][Y - sY] && ! flag[X - sX][Y + sY] && ! flag[X - sX][Y - sY];
}

bool CheckReflectPoint(int X, int Y, int sX, int sY)
{
    if (sX == 0 || sY == 0)
        return 0;
    return flag[X + sX][Y + sY] &&  flag[X + sX][Y - sY] &&  flag[X - sX][Y + sY] && ! flag[X - sX][Y - sY];
}

bool CheckReflectX(int X, int Y1, int Y2)
{
    if (flag[X + 1][Y1] != flag[X - 1][Y1])
        return 1;
    if (flag[X + 1][Y2] != flag[X - 1][Y2])
        return 1;
    return 0;
}

bool CheckReflectY(int Y, int X1, int X2)
{
    if (flag[X1][Y + 1] != flag[X1][Y - 1])
        return 1;
    if (flag[X2][Y + 1] != flag[X2][Y - 1])
        return 1;
    return 0;
}

int searchX(int X0, int Y0, int dx, int dy, int backX, int backY, int, int, int);
int searchY(int X0, int Y0, int dx, int dy, int backX, int backY, int, int, int);

int search(int X0, int Y0, int dx, int dy, int backX, int backY)
{
    if (sqr(X0 - x) + sqr(Y0 - y) > sqr(D))
        return 0;
    if (backX < 0 || backY < 0 || backX > n + n || backY > m + m)
        return 0;
    int frontX = backX + sgn(dx), frontY = backY + sgn(dy);
    
    if ((frontX - X0) * dy == (frontY - Y0) * dx)
    {
        if (frontX == x && frontY == y)
            return 1;
        if (CheckDeadPoint(frontX, frontY, sgn(dx), sgn(dy)))
            return 0;
        if (CheckReflectPoint(frontX, frontY, sgn(dx), sgn(dy)))
            return search(frontX * 2 - X0, frontY * 2 - Y0, -dx, -dy, frontX, frontY);
    }
        
    if (dx == 0)
        return searchY(X0, Y0, dx, dy, backX, backY, frontY, backX, frontX);
    if (dy == 0)
        return searchX(X0, Y0, dx, dy, backX, backY, frontX, backY, frontY);
    if ((frontX - X0) * 1.0 / dx > (frontY - Y0) * 1.0 / dy)
        return searchY(X0, Y0, dx, dy, backX, backY, frontY, backX, frontX);
    else
        return searchX(X0, Y0, dx, dy, backX, backY, frontX, backY, frontY);
}

int searchX(int X0, int Y0, int dx, int dy, int backX, int backY, int X, int Y1, int Y2)
{
    if (CheckReflectX(X, Y1, Y2))
        return search(X + X - X0, Y0, -dx, dy, X, backY);
    else
        return search(X0, Y0, dx, dy, X, backY);
}

int searchY(int X0, int Y0, int dx, int dy, int backX, int backY, int Y, int X1, int X2)
{
    if (CheckReflectY(Y, X1, X2))
        return search(X0, Y + Y - Y0, dx, -dy, backX, Y);
    else
        return search(X0, Y0, dx, dy, backX, Y);
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", & t);
    for (int ii = 1; ii <= t; ++ ii)
    {
        scanf("%d %d %d\n", & n, & m, & d);
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j <= m; ++ j)
            {
                scanf("%c", s[i] + j);
                if (s[i][j] == 'X')
                {
                    x = i + i + 1;
                    y = j + j + 1;
                }
            }
        D = d * 2;
        
        memset(_flag, 0, sizeof(_flag));
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j <= m; ++ j)
                if (s[i][j] == '#')
                    flag[i + i + 1][j + j + 1] = 1;
        
        ans = 0;
        int tmp;
        for (int i = -d; i <= d; ++ i)
        {
            for (int j = -d; j <= d; ++ j)
            {
                if (i == -1 && j == -3)
                    int pp = 2;
                tmp = 0;
                if (gcd(abs(i), abs(j)) == 1)
                    tmp = search(x, y, i, j, x, y);
                ans += tmp;
//                printf("%d ", tmp);
            }
//            printf("\n");
        }
        printf("Case #%d: %d\n", ii, ans);
    }
//    fclose(stdout);
}


