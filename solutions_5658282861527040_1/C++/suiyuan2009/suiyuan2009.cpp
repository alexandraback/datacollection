#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
#include <stack>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-10;
//const double PI = acos(-1);
const int maxn = 35;
const int inf = 0x3fffffff;
const int mod = 1000000007;

int a,b,k;
ll f[maxn][2][2][2];

ll dfs(int cnt,int x,int y,int z)
{
    if(cnt==-1)return 1;
    if(f[cnt][x][y][z]!=-1)return f[cnt][x][y][z];
    int lx=1,ly=1,lz=1;
    if(x)lx=((a&(1<<cnt))>0);
    if(y)ly=((b&(1<<cnt))>0);
    if(z)lz=((k&(1<<cnt))>0);
    ll ret=0;
    for(int i=0; i<=lx; i++)
        for(int j=0; j<=ly; j++)
        {
            int tt=(i&j);
            if(tt<=lz)ret+=dfs(cnt-1,x&&i==lx,y&&j==ly,z&&tt==lz);
        }
    return f[cnt][x][y][z]=ret;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("out.out","w",stdout);
    int T,ncase=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&k);
        a--,b--,k--;
        memset(f,-1,sizeof(f));
        printf("Case #%d: %lld\n",++ncase,dfs(30,1,1,1));
    }
    return 0;
}
