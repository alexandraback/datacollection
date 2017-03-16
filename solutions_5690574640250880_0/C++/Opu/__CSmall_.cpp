#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;

const inline int __GET_INT(){int ret;scanf("%d",&ret);return ret;}
#define INPT_INT __GET_INT()

typedef long long LL;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int R, C, M;
char res[55][55];

bool good;
int grid[55];

void Test()
{
    int sr = -1, sc = -1, cnt = 0;

    bool canGo[5][5] = {0};

    for(int i = 0;i<R;++i) for(int j = 0;j<C;++j)
    {
        if(grid[i]&(1<<j)) res[i][j] = '*';
        else { sr = i; sc = j; res[i][j] = '.'; canGo[i][j] = true; ++cnt;}
    }

    bool empty[5][5] = {0};
    for(int i = 0;i<R;++i) for(int j = 0;j<C;++j) if(res[i][j]=='.')
    {
        empty[i][j] = true;
        for(int k = 0;k<8;++k)
        {
            int r = i + dx[k];
            int c = j + dy[k];

            if( r >= 0 && r < R && c >= 0 && c < C )
            {
                if(!canGo[r][c])
                {
                    empty[i][j] = false; break;
                }
            }
        }
        if(empty[i][j]) {sr = i; sc = j;}
    }

    bool went[5][5] = {0};
    queue< pair<int,int> > q;

    went[sr][sc] = true;
    q.push( make_pair(sr,sc) );

    while( !q.empty() )
    {
        sr = q.front().first;
        sc = q.front().second;
        q.pop();
        --cnt;

        if(!empty[sr][sc]) continue;

        for(int k = 0;k<8;++k)
        {
            int r = sr + dx[k];
            int c = sc + dy[k];

            if( r >= 0 && r < R && c >= 0 && c < C && !went[r][c] )
            {
                went[r][c] = true;
                q.push( make_pair(r,c) );
            }
        }
    }
    good = !cnt;
}

void gen(int r, int mines)
{
    if(mines > M) return;
    if(r == R)
    {
        if(mines!=M) return;
        Test();
        return;
    }
    for(int i = 0;i<(1<<C) && good == false;++i)
    {
        grid[r] = i;
        gen(r+1, mines+__builtin_popcount(i));
    }
}

int main()
{
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small.out","w",stdout);
    int T = INPT_INT;

    for(int ca = 1;ca<=T;++ca)
    {
        R = INPT_INT; C = INPT_INT; M = INPT_INT;

        good = false;
        gen(0,0);

        printf("Case #%d:\n",ca);

        if(good)
        {
            bool clicked = false;
            for(int i = 0;i<R && !clicked;++i) for(int j = 0;j<C && !clicked;++j) if(res[i][j]=='.')
            {
                bool hasStar = false;
                for(int k = 0;k<8;++k)
                {
                    int r = dx[k]+i;
                    int c = dy[k]+j;

                    if(r >= 0 && r < R && c >= 0 && c < C)
                    {
                        if(res[r][c]=='*') hasStar = true;
                    }
                }
                if(!hasStar)
                {
                    clicked = true;
                    res[i][j] = 'c'; break;
                }
            }

            if(!clicked)
            {
                for(int i = 0;i<R && !clicked;++i) for(int j = 0;j<C && !clicked;++j) if(res[i][j]=='.')
                {
                    res[i][j] = 'c';
                    clicked = true;
                }
            }

            for(int i = 0;i<R;++i)
            {
                for(int j = 0;j<C;++j) printf("%c",res[i][j]);
                puts("");
            }
        }
        else puts("Impossible");
    }
    return 0;
}
