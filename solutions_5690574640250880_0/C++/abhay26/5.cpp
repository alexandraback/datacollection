/* ***************************
Author: Abhay Mangal (abhay26)
*************************** */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <bitset>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 #define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define maX(a,b) (a) > (b) ? (a) : (b)
#define pii pair< int, int >
#define pip pair< int, pii >
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define REP(i,a,n) for(int i=a;i<(int)n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
int dx[]= {-1,0,1,0,-1,-1,1,1};
int dy[]= {0,1,0,-1,-1,1,-1,1};
vector<string> V[6][6][25];
int valid[6][6][25];
vector<string> H;
void dfs(int x, int y, int R, int C)
{
    //if(H[x][y] != '.' && H[x][y] != 'c')
       // return;
    H[x][y] = 'd';
    FOR(k,8)
    {
        int vx = x+dx[k];
        int vy = y+dy[k];
        if(vx >= 0 && vx < R && vy >= 0 && vy < C)
        {
            if(H[vx][vy] == '*')
            {
                return;
            }
        }
    }
    FOR(k,8)
    {
        int vx = x+dx[k];
        int vy = y+dy[k];
        if(vx >= 0 && vx < R && vy >= 0 && vy < C)
        {
            if(H[vx][vy] == '.')
            {
                dfs(vx, vy, R, C);
            }
        }
    }

}
bool yes(int R, int C, int M, vector<string> &G)
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
          //  cout << "HEHE " << endl;
            if(G[i][j] == '.')
            {
                H = G;
                H[i][j] = 'c';
                //cout << "HEHE";
                dfs(i,j,R,C);
                FOR(k,R)
                {
                    FOR(l,C)
                    {
                        if(H[k][l] == '.')
                            goto agla;
                    }
                }
                G[i][j] = 'c';
                return true;
            }
            agla:
                {

                }
        }
    }
    return false;
}
void calc(int R, int C, int M)
{
    int tot = R*C;
    vector<string> G;
    string st = ".";
    string str = "";
    FOR(i,C)
    str = str + st;
    FOR(i,R)
    G.pb(str);
    for(int i=0;i<(1<<tot);i++)
    {
        int pos = -1;
        int cnt = 0;
        FOR(j,R)
        {
            FOR(k,C)
            {
                pos++;
                if(((1<<pos) & i) != 0)
                {
                    G[j][k] = '*';
                    cnt++;
                    if(cnt > M)
                        goto next;
                }
                else
                    G[j][k] = '.';
            }
        }
        if(cnt == M)
        {
            //cout << "LOL " << endl;
           // FOR(z,G.size())
           // cout << G[z] << endl;
            if(yes(R,C,M,G))
            {
                //FOR(z,H.size())
               // cout << H[z] << endl;
                V[R][C][M] = G;
                return;
            }
            else
                continue;

        }
        next:
            {

            }
    }
    V[R][C][M].pb("Impossible");
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    memset(valid,0,sizeof valid);
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            for(int k=0;k<i*j;k++)
            {
              //  cout << i << " " << j << " " << k << " ";
                calc(i,j,k);
               // FOR(m,V[i][j][k].size())
                //{
               //     cout << V[i][j][k][m] << " ";
               // }
               // cout << endl;
            }
        }
    }
    int t;
    scanf("%d",&t);
    FOR(z,t)
    {
        int R,C,M;
        scanf("%d %d %d",&R,&C,&M);
        printf("Case #%d:\n",z+1);
        FOR(k,V[R][C][M].size())
        cout << V[R][C][M][k] << endl;
    }
return 0;
}
