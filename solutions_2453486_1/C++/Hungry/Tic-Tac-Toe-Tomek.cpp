#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int n;
char str[10][10];
int num[1000];
bool f;
char ans;

int main()
{
    freopen("A-large.in","r",stdin); 
    freopen("A-large.out","w",stdout);
    int i,j,k;
    int ca = 1;
    scanf("%d",&n);
    while(n--)
    {
        f = 0;
        ans = 0;
        for( i = 0; i < 4; ++i)
        {
            scanf("%s",str[i]);
        }
        for( i = 0; i < 4; ++i)
        {
            for( j = 0; j < 4; ++j)
            {
                num['.'] = num['O'] = num['X'] = 0;
                for( k = 0; k < 4; ++k)
                {
                     num[str[i][k]]++;
                }
                if(num['.']) f = 1;
                else
                {
                    if(num['O'] && !num['X']) ans = 'O';
                    else if(num['X'] && !num['O']) ans = 'X';
                }
                num['.'] = num['O'] = num['X'] = 0;
                for( k = 0; k < 4; ++k)
                {
                     num[str[k][j]]++;
                }
                if(num['.']) f = 1;
                else
                {
                    if(num['O'] && !num['X']) ans = 'O';
                    else if(num['X'] && !num['O']) ans = 'X';
                }
            }
        }
        num['.'] = num['O'] = num['X'] = 0;
        for( k = 0; k < 4; ++k)
        {
            num[str[k][k]]++;
        }
        if(num['.']) f = 1;
        else
        {
            if(num['O'] && !num['X']) ans = 'O';
            else if(num['X'] && !num['O']) ans = 'X';
        }
        num['.'] = num['O'] = num['X'] = 0;
        for( k = 0; k < 4; ++k)
        {
            num[str[k][3 - k]]++;
        }
        if(num['.']) f = 1;
        else
        {
            if(num['O'] && !num['X']) ans = 'O';
            else if(num['X'] && !num['O']) ans = 'X';
        }
        printf("Case #%d: ",ca++);
        if(ans == 'X') printf("X won\n");
        else if(ans == 'O') printf("O won\n");
        else if(f == 1) printf("Game has not completed\n");
        else printf("Draw\n");
    }
    return 0;
}













