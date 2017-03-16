#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#define DBLE 1e-8
#define PI 3.1415926535898
#define INF 1000000000
#define MAXN 1010
#define MP(x,y) (make_pair((x),(y)))
#define FI first
#define SE second
using namespace std;
struct _node
{
    int num,times;
    bool operator < (const _node &b)const
    {
        if(times!=b.times)
            return times>b.times;
        else    return num>b.num;
    }
}no[MAXN];
int n,m,k;
int num[MAXN],sta[MAXN];
void dfs(int now,int top,int prev)
{
    if(now==1)
    {
        int tmp=0;
        for(int i=0;i<top;++i)
        {
            ++no[sta[i]*20+tmp].times;
            if(i<n-1&&sta[i]==sta[i+1]) ++tmp;
            else    tmp=0;
        }
        return ;
    }
    for(int i=prev;i>=2;--i)
        if(now%i==0)
            sta[top]=i,dfs(now/i,top+1,i);
}
int main()
{
//    freopen("J:\\MyDocument\\Code\\input.txt","r",stdin);
//    freopen("J:\\MyDocument\\Code\\output.txt","w",stdout);
    int ncase,r;
    scanf("%d",&ncase);
    for(int h=1;h<=ncase;++h)
    {
        scanf("%d%d%d%d",&r,&n,&m,&k);
        printf("Case #%d:\n",h);
        while(r--)
        {
            memset(no,0,sizeof(no));
            for(int i=2;i<=m;++i)
                for(int j=0;j<20;++j)
                    no[i*20+j].num=i,no[i*20+j].times=0;
            for(int i=0;i<k;++i)
                scanf("%d",&num[i]),dfs(num[i],0,m);
            sort(no,no+MAXN);
            for(int i=0;i<n;++i)
                printf("%d",no[i].num);
            printf("\n");
        }
    }
    return 0;
}

