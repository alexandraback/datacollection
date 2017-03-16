//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back
#define mp make_pair

const double PI=2.0*acos(0);

typedef long long int ll;
using namespace std;
struct T{
int a;
};
struct vec{
double x,y;
 vec(double xx=0,double yy=0)
 {
     x=xx;y=yy;
 }
};
vec make_vac(vec p,vec q)
{
    return vec(q.x-p.x,q.y-p.y);
}
double dotproduct(vec p,vec q)
{
    return p.x*q.x+p.y*q.y;
}
double crossproduct(vec p,vec q)
{
    return p.x*q.y-q.x*p.y;
}
double vec_value(vec p)
{
    return sqrt(p.x*p.x + p.y*p.y);
}
vec unit_vec(vec p)
{
    double va=vec_value(p);
    return vec(p.x/va,p.y/va);
}
double dis(double px,double py,double qx,double qy)
{
    px=fabs(px-qx);
    py=fabs(py-qy);
    return sqrt(px*px+py*py);
}
ll bigmod(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll hh=bigmod(a,b/2,mod);
        return (hh*hh)%mod;
    }
    else
    {
       return (a*bigmod(a,b-1,mod))%mod;
    }
}
char dig[55][55]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int vis[200];
char st[100000];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

  //  freopen("A.in","r",stdin);
    //freopen("out.txt","w",stdout);
    sn("%d",&t);
    while(t--)
    {
           sn("%s",&st);
            l=strlen(st);
            memset(vis,0,sizeof(vis));
            for(i=0;i<l;i++)
            {
                vis[st[i]]++;
            }
            pf("Case #%d: ",cs++);
            int viss[111];
            memset(viss,0,sizeof(viss));
            for(i=0;i<=9;i+=2)
            {
                while(1)
                {
                    u=strlen(dig[i]);
                    c=1;
                    for(j=0;j<u;j++)
                    {
                        if(vis[dig[i][j]]==0)
                            c=0;
                        if(c==0)
                        {
                            for(k=0;k<j;k++)
                            {
                                vis[dig[i][k]]++;
                            }
                            break;
                        }
                        vis[dig[i][j]]--;
                    }
                    if(c==0)
                    {
                      break;
                    }
                    viss[i]++;
                }
            }
            for(i=1;i<=9;i+=2)
            {
                while(1)
                {
                    u=strlen(dig[i]);
                    c=1;
                    for(j=0;j<u;j++)
                    {
                        if(vis[dig[i][j]]==0)
                            c=0;
                        if(c==0)
                        {
                            for(k=0;k<j;k++)
                            {
                                vis[dig[i][k]]++;
                            }
                            break;
                        }
                        vis[dig[i][j]]--;
                    }
                    if(c==0)
                    {
                      break;
                    }
                    viss[i]++;
                }
            }
            for(i=0;i<=9;i++)
                while(viss[i]>0)
            {
                pf("%d",i);viss[i]--;
            }
            pf("\n");
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
