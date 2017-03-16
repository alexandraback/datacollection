//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfcs(cs,a) printf("Case %d: %d\n",cs,a)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX 1000000
#define INF 1<<29
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b)
{
    return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b)
{
    return (a / gcd<T>(a, b) * b);
}
char in[10][10];
bool complete;
bool ValidRow(int x,char symbol)
{
    int ct=0;
    if(in[x][0]=='.' || in[x][1]=='.' || in[x][2]=='.' || in[x][3]=='.') complete=false;
    if(in[x][0]==symbol ||in[x][0]=='T') ct++;
    if(in[x][1]==symbol||in[x][1]=='T') ct++;
    if(in[x][2]==symbol||in[x][2]=='T') ct++;
    if(in[x][3]==symbol||in[x][3]=='T') ct++;
    if(ct==4 && complete) return true;
    else return false;


}
bool ValidCol(int y,char symbol)
{
    int ct=0;
    if(in[0][y]=='.' ||in[1][y]=='.' || in[2][y]=='.' || in[3][y]=='.') complete=false;
    if(in[0][y]==symbol ||in[0][y]=='T') ct++;
    if(in[1][y]==symbol ||in[1][y]=='T') ct++;
    if(in[2][y]==symbol ||in[2][y]=='T') ct++;
    if(in[3][y]==symbol ||in[3][y]=='T') ct++;
    if(ct==4 && complete) return true;
    else return false;
}


int main()
{

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int i,t,cs;
    sc(t);
    FOR(cs,1,t)
    {
        bool flag=false;
        rep(i,4) scanf("%s",in[i]);
        rep(i,4)
        {
            complete=true;
            if(ValidRow(i,in[i][0])&& in[i][0]!='T') break;
            if(!complete) flag=true;
        }
        if(i<4)
        {  // printf("here:: %d 0\n",i);
            printf("Case #%d: %c won\n",cs,in[i][0]);
            continue;
        }
        rep(i,4)
        {
            complete=true;
            if(ValidRow(i,in[i][3])&& in[i][3]!='T') break;
            if(!complete) flag=true;
        }
        if(i<4)
        {   // printf("here:: %d 3\n",i);
            printf("Case #%d: %c won\n",cs,in[i][3]);
            continue;
        }
        rep(i,4)
        {
            complete=true;
            if(ValidCol(i,in[0][i]) && in[0][i]!='T') break;
            if(!complete) flag=true;
        }
        if(i<4)
        {  //  printf("here:: 0 %d\n",i);
            printf("Case #%d: %c won\n",cs,in[0][i]);
            continue;
        }
        rep(i,4)
        {
            complete=true;
            if(ValidCol(i,in[3][i]) && in[3][i]!='T') break;
            if(!complete) flag=true;
        }
        if(i<4)
        {   // printf("here:: 3 %d\n",i);
            printf("Case #%d: %c won\n",cs,in[3][i]);
            continue;
        }

        int ct=0;
        char symbol=in[0][0];
        if(symbol=='T') symbol=in[1][1];
        complete=true;
        if(in[0][0]=='.' || in[1][1]=='.' || in[2][2]=='.' || in[3][3]=='.') complete=false;
        if(in[0][0]==symbol || in[0][0]=='T') ct++;
        if(in[1][1]==symbol || in[1][1]=='T') ct++;
        if(in[2][2]==symbol || in[2][2]=='T') ct++;
        if(in[3][3]==symbol || in[3][3]=='T') ct++;
        if(ct==4 && complete)
        {
            printf("Case #%d: %c won\n",cs,symbol);
            continue;
        }
        ct=0;
        symbol=in[0][3];
        if(symbol=='T') symbol=in[1][2];
        complete=true;
        if(in[3][0]=='.' || in[2][1]=='.' || in[1][2]=='.' || in[0][3]=='.') complete=false;
        if(in[3][0]==symbol || in[3][0]=='T') ct++;
        if(in[2][1]==symbol || in[2][1]=='T') ct++;
        if(in[1][2]==symbol || in[1][2]=='T') ct++;
        if(in[0][3]==symbol || in[0][3]=='T') ct++;

        if(ct==4 && complete)
        {
            printf("Case #%d: %c won\n",cs,symbol);
            continue;
        }
        if(flag)
        {
            printf("Case #%d: Game has not completed\n",cs);
        }
        else printf("Case #%d: Draw\n",cs);

    }

}
