/*
    Rezwan_4029
    AUST , CSE-25
*/

#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<sstream>
#include<set>
#include <queue>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
using namespace std;
typedef long long ll;
#define FRD freopen("in.txt", "r", stdin)
#define FWR freopen("out.txt", "w", stdout)

#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)

char M[5][5];

bool ROW(char x)
{
   // cout << "now ->> "<< x << endl;
    int cnt  ,t ;
    rep(i,4)
    {
        cnt = t = 0 ;

        rep(j,4) {
            if(M[i][j] == x )cnt++;
            else if( M[i][j] == 'T' )t++;
        }
        //cout << "cnt = " << cnt << "       t= " << t << endl;
        if(( cnt == 3 && t == 1) ||(cnt == 4) )return true;
    }
    return false;
}
bool COLUMN(char x)
{
    int cnt ,t   ;
    rep(j,4)
    {
        cnt = t = 0 ;

        rep(i,4) {if(M[i][j] == x )cnt++;
        else if( M[i][j] == 'T' )t++;
        }
        if( (cnt == 3 && t == 1) || (cnt == 4) )return true;
    }
    return false;
}
bool Diagonal(char x)
{
    int cnt = 0  ,t = 0;
    rep(i,4)if(M[i][i] == x )cnt++;
            else if( M[i][i] == 'T' )t++;

    if(cnt == 4 || (cnt == 3 && t == 1) )return true;

    cnt = t = 0 ;

    if(   M[0][3] == x  ) cnt++;
    if(   M[0][3] == 'T') t++;

    if(   M[1][2] == x  ) cnt++;
    if(   M[1][2] == 'T') t++;

    if(   M[2][1] == x  ) cnt++ ;
    if(   M[2][1] == 'T' )t++;

    if(   M[3][0] == x ) cnt++ ;
    if(   M[3][0] == 'T' ) t++;

    if(cnt == 4 || (cnt == 3 && t == 1) )return true;

    return false;
}
bool run()
{
    rep(i,4)rep(j,4) if( M[i][j] == '.' ) return false;
    return true;
}
int main()
{
    //FRD ;FWR ;
    int test , cs = 1;
    scanf("%d",&test);
    while(test--)
    {
        rep(i,4)scanf("%s",M[i]);

        bool X = ROW('X') || Diagonal('X') || COLUMN('X');
        bool O = COLUMN('O') || Diagonal('O') || ROW('O');
        bool playedFull = run();
        printf("Case #%d: ",cs++);
        if(X) puts("X won");
        else if(O)puts("O won");
        else if(playedFull == false)puts("Game has not completed");
        else puts("Draw");
    }
}
