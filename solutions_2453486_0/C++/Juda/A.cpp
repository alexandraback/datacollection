#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
#define DEBUG 0
#define debug(cc) if(DEBUG)cout<<#cc<<" : "<<cc<<endl;
#define REP(i,n) for(i=0;i<n;++i)
#define FOR(i,j,k) for(i=j;i<=k;++i)
#define FORD(i,j,k) for(i=j;i>=k;--i)
#define met(i,j) memset(i,j,sizeof(i))
#define PB push_back
#define MK make_pair
#define sz(x) ((int)x.size())
#define IOopen ios_base::sync_with_stdio(false)
const int inf=2147483647;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;
char map[5][5];
bool yet;

void init()
{
    int i,j;
    yet=0;
    FOR(i,1,4)
    {
        FOR(j,1,4)
        {
            map[i][j]=getchar();
            if(map[i][j]=='.')yet=1;
        }
        getchar();
    }
    scanf("\n");
}

void work()
{
    int i,j,bj;
    FOR(i,1,4)
    {
        bj=1;
        FOR(j,1,4)
        {
            if(!(map[i][j]=='X'||map[i][j]=='T'))
            {
                bj=0;
                break;
            }
        }
        if(bj)
        {
            puts("X won");
            return;
        }
        bj=1;
        FOR(j,1,4)
        {
            if(!(map[i][j]=='O'||map[i][j]=='T'))
            {
                bj=0;
                break;
            }
        }
        if(bj)
        {
            puts("O won");
            return;
        }
    }
    FOR(j,1,4)
    {
        bj=1;
        FOR(i,1,4)
        {
            if(!(map[i][j]=='X'||map[i][j]=='T'))
            {
                bj=0;
                break;
            }
        }
        if(bj)
        {
            puts("X won");
            return;
        }
        bj=1;
        FOR(i,1,4)
        {
            if(!(map[i][j]=='O'||map[i][j]=='T'))
            {
                bj=0;
                break;
            }
        }
        if(bj)
        {
            puts("O won");
            return;
        }
    }
    //=======
    bj=1;
    FOR(i,1,4)
    {
        if(!(map[i][i]=='T' || map[i][i]=='X'))
        {
            bj=0;
            break;
        }
    }
    if(bj)
    {
        puts("X won");
        return;
    }
    bj=1;
    FOR(i,1,4)
    {
        if(!(map[i][i]=='T' || map[i][i]=='O'))
        {
            bj=0;
            break;
        }
    }
    if(bj)
    {
        puts("O won");
        return;
    }
    //=================
    bj=1;
    FOR(i,1,4)
    {
        if(!(map[i][5-i]=='T' || map[i][5-i]=='X'))
        {
            bj=0;
            break;
        }
    }
    if(bj)
    {
        puts("X won");
        return;
    }
    bj=1;
    FOR(i,1,4)
    {
        if(!(map[i][5-i]=='T' || map[i][5-i]=='O'))
        {
            bj=0;
            break;
        }
    }
    if(bj)
    {
        puts("O won");
        return;
    }
    if(yet)
    {
        puts("Game has not completed");
    }else
    {
        puts("Draw");
    }
}

int main()
{
    int i,T;
    scanf("%d\n",&T);
    FOR(i,1,T)
    {
        printf("Case #%d: ",i);
        init();
        work();
    }
}
