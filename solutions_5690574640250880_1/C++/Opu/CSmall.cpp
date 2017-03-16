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

bool check_for_3()
{
    if(R < 3) return false;

    int nonMine = R*C - M;
    if(nonMine < 4 || nonMine == 5 || nonMine == 7) return false;

    int m = M;

    for(int i = 0;i<R-3;++i) for(int j = 0;j<C;++j)
    {
        if(m)
        {
            --m;
            res[i][j] = '*';
        }
        else res[i][j] = '.';
    }

    for(int i = R-3;i<R;++i) for(int j = 0;j<C;++j)
    {
        if(j < m/3 ) res[i][j] = '*';
        else res[i][j] = '.';
    }
    if( m%3 == 1 ) res[R-3][m/3] = '*';
    if( m%3 == 2 ) res[R-3][m/3] = res[R-3][m/3+1] = '*';
    return true;
}

bool check_for_2()
{
    if( M == (R-2)*C-1 ) return false;
    int can = (R-2) * C;
    int left = M - can;

    if(left > 0)
    {
        if(left%2) return false;
        if(left+2==2*C) return false;
    }

    int m = M;
    for(int i = 0;i<R;++i) for(int j = 0;j<C;++j)
    {
        if(m)
        {
            if(can)
            {
                res[i][j] = '*';
                --can;
                --m;
            }
            else
            {
                if(j<left/2) {res[i][j] = '*'; --M;}
                else res[i][j] = '.';
            }
        }
        else res[i][j] = '.';
    }
    return true;
}

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int T = INPT_INT;

    for(int ca = 1;ca<=T;++ca)
    {
        R = INPT_INT; C = INPT_INT; M = INPT_INT;

        bool flag = false, possible = true;
        if(R>C) {swap(R,C); flag = true;}

        if(R == 1)
        {
            for(int i = 0;i<C;++i)
            {
                if(i<M) res[0][i] = '*';
                else res[0][i] = '.';
            }
        }
        else
        {
            if(R*C-1 == M)
            {
                for(int i = 0;i<R;++i) for(int j = 0;j<C;++j)
                {
                    if(!i && !j) res[i][j] = '.';
                    else res[i][j] = '*';
                }
            }
            else
            {
                possible = check_for_2();
                if(!possible) possible = check_for_3();
            }
        }

        printf("Case #%d:\n",ca);

        if(!possible) puts("Impossible");
        else
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

            if(flag)
            {
                for(int j = 0;j<C;++j)
                {
                    for(int i = 0;i<R;++i) printf("%c",res[i][j]);
                    puts("");
                }
            }
            else
            {
                for(int i = 0;i<R;++i)
                {
                    for(int j = 0;j<C;++j) printf("%c",res[i][j]);
                    puts("");
                }
            }
        }
    }
    return 0;
}
