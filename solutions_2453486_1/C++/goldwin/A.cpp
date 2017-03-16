#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FOR(a,b,c) for(int (a) = (b), _n = (c); (a) <= _n ; (a)++)
#define FORD(a,b,c) for(int (a) = (b), _n = (c) ; (a) >= _n ; (a)--)
#define FOR_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) <= _n ; (a)+= _m )
#define FORD_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) >= _n ; (a)-= _m)
#define EACH(v,it) for(__typeof(v.begin()) it = v.begin(); it != v.end() ; it++)
#define INF 200000000
#define MAX 1

using namespace std;

char arr[10][10];

bool rightDownDiagonalCheck(int player)
{
    int cnt = 0;
    FOR(i,0,3)
    {
        if(arr[i][i] == player) cnt++;
        if(arr[i][i] == 'T') cnt++;
    }
    return cnt == 4;
}

bool leftDownDiagonalCheck(int player)
{
    int cnt = 0;
    FOR(i,0,3)
    {
        if(arr[i][3-i] == player) cnt++;
        if(arr[i][3-i] == 'T') cnt++;
    }
    return cnt == 4;
}

bool horizontalCheck(int player)
{
    FOR(i,0,3)
    {
        int cnt = 0;
        FOR(j,0,3)
        {
            if(arr[i][j] == player || arr[i][j] == 'T') cnt++;
        }
        if(cnt == 4) return true;
    }
    return false;
}

bool verticalCheck(int player)
{
    FOR(i,0,3)
    {
        int cnt = 0;
        FOR(j,0,3)
        {
            if(arr[j][i] == player || arr[j][i] == 'T') cnt++;
        }
        if(cnt == 4) return true;
    }
    return false;
}

bool checkO()
{
    if(rightDownDiagonalCheck('O')) return true;
    if(leftDownDiagonalCheck('O')) return true;
    if(horizontalCheck('O')) return true;
    if(verticalCheck('O')) return true;
    return false;
}

bool checkX()
{
    if(rightDownDiagonalCheck('X')) return true;
    if(leftDownDiagonalCheck('X')) return true;
    if(horizontalCheck('X')) return true;
    if(verticalCheck('X')) return true;
    return false;
}

int countPos()
{
    int cnt = 0;
    FOR(i,0,3)
    {
        FOR(j,0,3)
        {
            if(arr[i][j] == '.') cnt++;
        }
    }
    return cnt;
}

void solve(int ca)
{
    FOR(i,0,3)
    {
        scanf("%s",arr[i]);
    }   
    printf("Case #%d: ",ca);
    if(checkO())
    {
        puts("O won");
    }
    else if(checkX())
    {
        puts("X won");
    }
    else if(countPos() > 0)
    {   
        puts("Game has not completed");
    }
    else
    {
        puts("Draw");
    }
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(ca,1,t)
    {
        solve(ca);
    }
    return 0;
}
