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
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v,ar[2000];
    //freopen("C.in","r",stdin);
    //freopen("out.txt","w",stdout);
    sn("%lld",&t);
    while(t--)
    {
        sn("%lld %lld",&n,&m);

        s=(1LL<<(n-1))|(1LL<<(n-2))|3LL;
        c=1;
        ar[0]=s;
        set<ll>vis;
        vis.insert(s);
        for(i=0;i<m&&i<c;i++)
        {
            if(c>=m)
                break;
            for(j=n-2;j>0;j--)
            {
                u=3LL<<j;
                if((ar[i]&u)==0&&vis.count(ar[i]|u)==0)
                {
                    vis.insert(ar[i]|u);
                    ar[c++]=ar[i]|u;
                }
            }
        }
        pf("Case #%lld:\n",cs++);
        for(i=0;i<m;i++)
        {
            for(j=n-1;j>=0;j--)
            {
                if(ar[i]&(1LL<<j))
                    pf("1");
                else
                pf("0");
            }
            for(j=2;j<=10;j++)
            {
                pf(" %lld",j+1);
            }
            pf("\n");
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
