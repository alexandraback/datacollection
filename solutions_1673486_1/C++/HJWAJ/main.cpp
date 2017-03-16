#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
double p[100005];
double f(int a,int b)
{
    int i;
    double pp=1.0;
    for(i=0;i<a;i++)pp*=p[i];
    return pp*(b-a+1)+(1-pp)*(b-a+1+b+1);
}
double s(int a,int b)
{
    int i,cnt;
    double pp=1.0,min=9999999,tmp;
    for(i=0;i<a;i++)pp*=p[i];
    for(i=1;i<=a;i++)
    {
        cnt=i;
        pp/=p[a-i];
        tmp=pp*(cnt+b-(a-cnt)+1)+(1-pp)*(cnt+b-(a-cnt)+1+b+1);
        if(tmp<min)min=tmp;
    }
    return min;
}
double t(int a,int b)
{
    return (double)(1+b+1);
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int tt,a,b,i,ttt=0;
    double fst,snd,trd,opt;
    scanf("%d",&tt);
    while(tt--)
    {
        ttt++;
        scanf("%d%d",&a,&b);
        for(i=0;i<a;i++)scanf("%lf",p+i);
        fst=f(a,b);
        //printf("%.6lf\n",fst);
        snd=s(a,b);
        //printf("%.6lf\n",snd);
        trd=t(a,b);
        //printf("%.6lf\n",trd);
        if(fst<snd)opt=fst;
        else opt=snd;
        if(trd<opt)opt=trd;
        printf("Case #%d: %.6lf\n",ttt,opt);
    }
    return 0;
}
