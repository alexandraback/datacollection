#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

int a[55][55] = {0};
int R , C , M;
int p[8][2] = {{-1 , -1} , {-1 , 0} , {-1 , 1} , {0 , -1} , {0 , 1} , {1 , -1} , {1 , 0} , {1 , 1}};

int check(int x , int y)
{
    a[x][y] = -1;
    int num = 0;
    int open = 1;
    for (int i = 0; i < 8; i ++)
    {
        int xx = x + p[i][0];
        int yy = y + p[i][1];
        if (xx >= 0 && xx < R && yy >= 0 && yy < C && a[xx][yy] >= 0)
        {
            num += a[xx][yy];
        }
    }
    if (num == 0)
    {
        for (int i = 0; i < 8; i ++)
        {
            int xx = x + p[i][0];
            int yy = y + p[i][1];
            if (xx >= 0 && xx < R && yy >= 0 && yy < C && a[xx][yy] >= 0)
            {
                open += check(xx , yy);
            }
        }
    }
    return open;
}

void add(int x , int y , int *m)
{
    if (x >= 0 && y >= 0 && a[x][y] == 0 && m[0] > 0)
    {
        a[x][y] = 1;
        m[0] --;
    }
}

void slove(int r , int c , int m)
{
    int i , j;
    memset(a , 0 , sizeof(a));
    if (m > 0)
    {
        for (i = 0; i < r-2; i ++)
        {
            for (j = 0; j < c-2; j ++)
            {
                a[i][j] = 1;
                m --;
                if (m <= 0) break;
            }
            if (m <= 0) break;
        }
        if (m > 0)
        {
            if (m % 2 == 1 && r-3 >= 0 && c-3 >= 0)
            {
                a[r-3][c-3] = 0;
                m ++;
            }
            for (i = 0; i < r-3; i ++)
            if (m > 0)
            {
                for (j = c-2; j < c; j ++)
                if (j >= 0)
                {
                    a[i][j] = 1;
                    m --;
                    if (m <= 0) break;
                }
            }
            for (j = 0; j < c-3; j ++)
            if (m > 0)
            {
                for (i = r-2; i < r; i ++)
                if (i >= 0)
                {
                    a[i][j] = 1;
                    m --;
                    if (m <= 0) break;
                }
            }
            //last 3 x 3
            //1 2 3
            //4 6 7
            //5 8 9
            add(r-3 , c-3 , &m);
            add(r-3 , c-2 , &m);
            add(r-3 , c-1 , &m);
            add(r-2 , c-3 , &m);
            add(r-1 , c-3 , &m);
            add(r-2 , c-2 , &m);
            add(r-2 , c-1 , &m);
            add(r-1 , c-2 , &m);
            add(r-1 , c-1 , &m);
        }
    }
}

int main()
{
	//freopen("C-large.in" , "r" , stdin);
	freopen("C-small-attempt2.in" , "r" , stdin);
    //freopen("input.txt" , "r" , stdin);
	//freopen("A-large.out" , "w" , stdout);
    //freopen("C-small.out" , "w" , stdout);
    freopen("C-small-attempt2.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d:\n" , ca);
        int i , j;
        scanf("%d %d %d" , &R , &C , &M);
        memset(a , 0 , sizeof(a));
        int m = M;
        slove(R , C , M);
        if (check(R-1 , C-1) == R*C - M)
        {
            a[R-1][C-1] = 2;
            for (i = 0; i < R; i ++)
            {
                for (j = 0; j < C; j ++)
                {
                    if (a[i][j] == 1) printf("*");
                    else if (a[i][j] == 2) printf("c");
                    else printf(".");
                }
                printf("\n");
            }
        }
        else
        {
#if 0
            R ^= C; C ^= R; R ^= C;
            slove(R , C , M);
            if (check(R-1 , C-1) == R*C - M)
            {
                a[R-1][C-1] = 2;
                for (j = 0; j < C; j ++)
                {
                    for (i = 0; i < R; i ++)
                    {
                        if (a[i][j] == 1) printf("*");
                        else if (a[i][j] == 2) printf("c");
                        else printf(".");
                    }
                    printf("\n");
                }
            }
            else
#endif
            {
                printf("Impossible\n");
            }
        }
    }
    return 0;
}