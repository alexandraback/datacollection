#include <iostream>
using namespace std;
#include <stdio.h>
#define MAXN 1000000
int Level[2000];
int All_level;
void init()
{
    All_level = 0;
    int all = 0;
    Level[0] = 0;
    Level[1] = 1;
    all = 1;
    for(int i=2;;i++)
    {
        all += 4;
        Level[i] = Level[i-1]+all;
        if(Level[i-1]>MAXN) { All_level = i; break; }
    }
}
int find_level(int now) //计算出满的那一层
{
    for(int i=0;i<=All_level;i++)
    {
        if(Level[i]>now) return i-1;
    }
    return All_level;
}
int ABS(int x) {return x>0?x:-x;}
int Calc(int left,int right,int all)
{
    int ans = 0;
    for(int l=0;l<=left;l++)
    {
        if(all-l<0) break;
        if(all-l>right) continue;
        ans ++;
        if(l==all-l) ans++;
    }
    return ans;
}
double WONDER(int left,int total,int x,int y)
{
    if(left == total ) return 1;
    int ter = y+1;
    return Calc(left-ter,left,left)*1.0/Calc(left,left,left);
}
int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    init();
    int T,N,x,y;
    double ans;
    scanf("%d",&T);
    for(int cnt = 1;cnt<=T;cnt++)
    {
        scanf("%d%d%d",&N,&x,&y);
        int xy = ABS(x)+ABS(y);
        int level = find_level(N);
        N = N-Level[level];
        if(level*2<xy) { printf("Case #%d: 0.0\n",cnt);  continue; }
        if(level*2>xy) { printf("Case #%d: 1.0\n",cnt); continue; }
        if(Level[level+1]!=N&&x==0) { printf("Case #%d: 0.0\n",cnt); continue; }
        printf("Case #%d: %lf\n",cnt,WONDER(N,Level[level+1]-Level[level],ABS(x),ABS(y)));
    }
    return 0;
}
