/*
LANG: C++
TASK: xxx
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<sstream>

using namespace std;


#define FOR(i,a,b) for(__typeof(b)i = a; i < b;i++)
#define FORE(i,a,b) for(__typeof(b)i = a; i <= b;i++)
#define FOR_R(i,a,b) for(__typeof(b)i = a; i > b;i--)
#define FORE_R(i,a,b) for(__typeof(b)i = a; i >= b;i--)
#define TR(it , c) for(__typeof((c).end())it = (c).begin(); it != (c).end();it++)

#define NC "Game has not completed"
#define DOT 0
#define X 1
#define O 2
#define T 5

int tCase;
int table[5][5];
bool chk(int c)
{
    int ans = 1;
    FOR(i,0,4) // >>
    {
        ans = 1;
        FOR(j,0,4)
        {
            if(!(table[i][j] == T || table[i][j] == c))
                ans = 0;
        }
        if(ans == 1)    return true;
    }
    FOR(i,0,4) // ^
    {
        ans = 1;
        FOR(j,0,4)
        {
            if(!(table[j][i] == T || table[j][i] == c))
                ans = 0;
        }
        if(ans == 1)    return true;
    }
    ans = 1;
    FOR(i,0,4) //
    {
        if(!(table[i][i] == T || table[i][i] == c))
                ans = 0;
    }
    if(ans == 1)    return true;
    ans = 1;
    FOR(i,0,4) //
    {
        if(!(table[i][3-i] == T || table[i][3-i] == c))
                ans = 0;
    }
    if(ans == 1)    return true;
    return false;
}
bool chkFull()
{
    FOR(i,0,4)
        FOR(j,0,4)
        {
            if(table[i][j] == DOT)  return false;
        }
    return true;
}
void solve(int tt)
{
    printf("Case #%d: ",tt);

    string input;
    FOR(i,0,4)
    {
        cin >> input;
        if(input.length() < 4)
            cin >> input;
        FOR(j,0,4)
        {
            switch(input[j])
            {
                case '.' : table[i][j] = DOT;   break;
                case 'X' : table[i][j] = X;   break;
                case 'O' : table[i][j] = O;   break;
                case 'T' : table[i][j] = T;   break;
            }
        }
    }
    if(chk(X))
    {
        cout << "X won" << endl;
        return;
    }
    if(chk(O))
    {
        cout << "O won" << endl;
        return;
    }
    if(chkFull())
    {
        cout << "Draw" << endl;
        return;
    }
    cout << NC << endl;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("outA.txt","w",stdout);
    scanf("%d",&tCase);
    FORE(tt , 1 , tCase)
    {
        solve(tt);
    }
    return 0;
}
