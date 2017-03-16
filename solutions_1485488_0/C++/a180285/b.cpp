/*****************************************
*
* @ingroup UESTC_ACM,2012
* @param   B
* @author  a180285
*
*****************************************/

# include <assert.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <algorithm>
# include <iostream>
# include <string>
# include <queue>
# include <stack>
# include <map>
# include <set>
# include <vector>
# include <cstring>
# include <list>
# include <ctime>
# include <sstream>

# pragma comment (linker,"/STACK:16777216")

# define For(i,a)   for(i=0; i<(a); i++)
# define sz(a)      (sizeof(a))
# define MEM(a)     (memset((a),0,sizeof(a)))
# define MEME(a)    (memset((a),-1,sizeof(a)))
# define MEMX(a)    (memset((a),0xf,sizeof(a)))
# define pb(a)      push_back(a)

using namespace std;

typedef long long           ll      ;
typedef unsigned long long  ull     ;
typedef unsigned int        uint    ;
typedef unsigned char       uchar   ;
typedef istringstream        Iss     ;

template<class T> inline const T& MIN(const T& a,const T& b){return a<b? a : b;}
template<class T> inline const T& MAX(const T& a,const T& b){return a>b? a : b;}
template<class T> inline void checkmin(T &a,const T& b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,const T& b){if(a<b) a=b;}

const int oo=1<<30          ;
const double eps=1e-7       ;
const int N=16               ;
const int M=1               ;
const ll P=10000000097ll    ;

struct dot
{
    int h, l;
    int dis;
};

dot d[N][N];
int r,c;

int Q[1<<20];
int vis[N][N];
int oh;

int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0,-1, 1};

int in(int x,int y)
{
    return x>=0 && x<r
        && y>=0 && y<c;
}

void read()
{
    MEMX(d);
    scanf("%d", &oh);
    scanf("%d %d", &r, &c);
    int i,j;
    For(i, r)
        For(j,c)
            scanf("%d", &d[i][j].h);
    For(i, r)
        For(j, c)
            scanf("%d", &d[i][j].l);
}

void bfs()
{
    int f, b;
    int ux, uy, vx, vy;
    int u,v;
    int k;
    MEM(vis);
    f = b = 0;
    ux = uy = 0;
    d[0][0].dis = 0;
    Q[b++] = ux * N + uy;
    while( f < b )
    {
        u = Q[f++];
        ux = u / N;
        uy = u % N;
//        printf("%d %d\n", ux, uy);
        dot& ud = d[ux][uy];
        vis[ux][uy] = 0;
        int dis = d[ux][uy].dis;
        For(k, 4)
        {
            vx = ux + dx[k];
            vy = uy + dy[k];
            v = vx * N + vy;
            if( !in(vx, vy) )
                continue;
            dot& vd = d[vx][vy];
            if( 50 > MIN(ud.h,vd.h) - MAX(ud.l,vd.l) )
                continue;
            int tdis = MAX(dis, oh-(vd.h-50));
            if( 0 != tdis )
            {
                if( oh-tdis >= ud.l+20 )
                    tdis += 10;
                else
                    tdis += 100;
            }
            if( vd.dis <= tdis )
                continue;
            vd.dis = tdis;
//            printf("v %d %d\n", vx, vy);
            if( vis[vx][vy] )
                continue;
            Q[b++] = v;
            vis[vx][vy] = 1;
        }
    }
}

int doit()
{
    read();
    bfs();
    dot& u = d[r-1][c-1];
    int dis = u.dis;
//    if( 0==dis )
//        return 0;
//    if( oh-dis >= u.l+20 )
//        dis += 10;
//    else
//        dis += 100;
    return dis;
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int T,_=0;
    scanf("%d",&T);
    while( _++ < T )
    {
        int val = doit();
        printf("Case #%d: %f\n", _, val/10.0);
    }
    return 0;
}

/**



Input

Output

4
200 1 2
250 233
180 100
100 3 3
500 500 500
500 500 600
500 140 1000
10 10 10
10 10 490
10 10 10
100 3 3
500 100 500
100 100 500
500 500 500
10 10 10
10 10 10
10 10 10
100 2 2
1000 1000
1000 1000
100 900
900 100

Case #1: 11.7
Case #2: 3.0
Case #3: 18.0
Case #4: 0.0

**/

