#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <string>
#define N 110
using namespace std;
int a[N][N];
bool ok(int i,int j,int n,int m)
{
    int find=0;
    for(int k=1;k<=n;k++)
        if(a[k][j]>a[i][j])
        {
            find=1;break;
        }
    if(!find)return 1;
    find=0;
    for(int k=1;k<=m;k++)
        if(a[i][k]>a[i][j])
        {
            find=1;break;
        }
    if(!find)return 1;
    return 0;
}
bool check(int n,int m)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(!ok(i,j,n,m))
                return 0;
        }
    return 1;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,T=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        printf("Case #%d: ",++T);
        if(check(n,m))puts("YES");
        else puts("NO");
    }
    return 0;
}
