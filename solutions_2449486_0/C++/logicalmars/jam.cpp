#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
using namespace std;

int n,m;
int a[20][20];

int check_row_only_one(int i)
{
    for (int j =0;j<m;j++)
        if (a[i][j] == 2)
            return 0;

    return 1;
}

int check_col_only_one(int j)
{
    for (int i = 0;i<n;i++)        
        if (a[i][j] == 2)
            return 0;

    return 1;
}

int check()
{
    for (int i=0;i<n;i++)
    {
        for (int j = 0;j<m;j++)
        {
            if (a[i][j] == 1)
            {
                if (!check_row_only_one(i) && !check_col_only_one(j))
                    return 0;
            }
        }
    }

    return 1;
}

void work()
{
    scanf("%d%d", &n, &m);
    for (int i = 0;i<n;i++)
    {
        for (int j = 0;j<m;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    if (check())
    {
        printf("YES\n");        
    }
    else 
        printf("NO\n");
}
 
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    // freopen("A-large-practice.in", "r", stdin);    
    // freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
 
    int cs, t;
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++)
    {
        printf("Case #%d: ", cs);
        work();
    }
 
    return 0;
}