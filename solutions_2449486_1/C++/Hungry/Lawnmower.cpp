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

struct point
{
    int num;
    int lh;
    int rh;
    int uh;
    int dh;
}p[105][105];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int n,m;
    int cas;
    int a,b,c,d;
    int ca = 1;
    int i,j;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&m);
        for( i = 0; i < n; ++i)
        {
             for( j = 0; j < m; ++j)
             {
                  scanf("%d",&p[i][j].num);
                  if(i == 0) p[i][j].uh = p[i][j].num;
                  if(i == n - 1) p[i][j].dh = p[i][j].num;
                  if(j == 0) p[i][j].lh = p[i][j].num;
                  if(j == m - 1) p[i][j].rh = p[i][j].num;
             }
        }
        for( i = 0; i < n; ++i)
        {
            for( j = 0; j < m; ++j)
            {
                if(i) p[i][j].uh = max(p[i][j].num,p[i - 1][j].uh);
                if(j) p[i][j].lh = max(p[i][j].num,p[i][j - 1].lh);
            }
        }
        for( i = n - 1; i >= 0; --i)
        {
            for( j = m - 1; j >= 0; --j)
            {
                if(i != n - 1) p[i][j].dh = max(p[i][j].num,p[i + 1][j].dh);
                if(j != m - 1) p[i][j].rh = max(p[i][j].num,p[i][j + 1].rh);
            }
        }
        //printf("%d %d %d %d\n",p[0][1].uh,p[0][1].dh,p[0][1].lh,p[0][1].rh);
        for( i = 0; i < n; ++i)
        {
            for( j = 0; j < m; ++j)
            {
                 a = b = c = d = 0;
                 if(p[i][j].num < p[i][j].uh) a = 1;
                 if(p[i][j].num < p[i][j].dh) b = 1;
                 if(p[i][j].num < p[i][j].lh) c = 1;
                 if(p[i][j].num < p[i][j].rh) d = 1;
                 //printf("%d %d %d %d\n",a,b,c,d);
                 if(a + b + c + d == 4) break;
                 if(a + c == 2 || a + d == 2 || b + c == 2 || b + d == 2) break;
                 
            }
            if(j != m) break;
        }
        printf("Case #%d: ",ca++);
        if(i != n) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}













