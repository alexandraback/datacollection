#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define INF (1<<30)
const int N=105;
typedef long long LL;

LL a[N],cnt,tot;
LL iabs(LL x){return x>0?x:-x;}

struct pt
{
    LL x,y;

    pt(){}
    pt(LL x,LL y):
        x(x),y(y) {}
    pt operator - (const pt &p) const { return pt(x-p.x,y-p.y);}

};
LL calu(pt a,pt b)
{
    //puts("");
   // cout<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<endl;
    return iabs(a.x*b.y-a.y*b.x);
}
bool judge(int ind,int x,int y)
{
    if(ind==1)
    {
        if(x==0&&y==0) return 1;
        else return 0;
    }

    int x1=(ind-1)*2,y1=0;
    int x2=-(ind-1)*2,y2=0;
    int x3=0,y3=(ind-1)*2;

    pt p[5];
    p[0]=pt(x1,y1);
    p[1]=pt(x2,y2);
    p[2]=pt(x3,y3);
    pt ix=pt(x,y);

    LL sum1=calu(p[2]-p[0],p[1]-p[0]),sum2=0;

    sum2=calu(p[0]-ix,p[1]-ix);
    sum2+=calu(p[1]-ix,p[2]-ix);
    sum2+=calu(p[2]-ix,p[0]-ix);

    if(sum1==sum2) return 1;
    return 0;
}

void dfs(int num,int lft,int rht,int ind,int x,int y)
{
    if(num==0)
    {
        if( (x<0&&y<lft) || (x>0&&y<rht) ) cnt++;
        tot++;
    }
    else
    {
       if(lft<(ind-1)*2) dfs(num-1,lft+1,rht,ind,x,y);
       if(rht<(ind-1)*2) dfs(num-1,lft,rht+1,ind,x,y);
    }
}
int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("out1.txt","w",stdout);

    int t,t_cnt=0;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;  tot=0;

        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);

        printf("Case #%d: ",++t_cnt);
        if(n==1)
        {
            if(x==0&&y==0) printf("%.8lf\n",1.0);
            else printf("%.8lf\n",0.0);
            continue;
        }

        for(int i=1;i<=10;i++) a[i]=a[i-1]+(i*2-1)*2-1;

        int ind=0;
        for(int i=1;i<=10;i++)
        {
            if(a[i+1]>n)
            {
                ind=i; break;
            }
        }

        if(judge(ind,x,y)) printf("%.8lf\n",1.0);
        else if(judge(ind+1,x,y)==0) printf("%.8lf\n",0.0);
        else
        {
            dfs(n-a[ind],0,0,ind+1,x,y);
            printf("%.8lf\n",cnt*1.0/tot);
        }
    }
	return 0;
}
