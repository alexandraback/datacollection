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
ll x,y;
}ans[1000000];
char st[200];
char ss[200];

void print(ll u,ll v,ll n)
{
     ll ten=1,c,d;
     for(int i=n-1;i>=0;i--)
     {
         c=u/ten;
         c=c%10;
         st[i]='0'+c;
         d=v/ten;
         d=d%10;
         ss[i]='0'+d;
         ten=ten*10;
     }
     st[n]=0;
     ss[n]=0;
     pf("%s %s\n",st,ss);
}
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen("B.in","r",stdin);
    //freopen("out.txt","w",stdout);
    sn("%lld",&t);
    while(t--)
    {
        sn("%s %s",&st,&ss);
        l=strlen(st);
        u=0;v=0;s=0;
        for(i=0;i<l;i++)
        {
            u=u*10;v=v*10;
            if(st[i]=='?'&&ss[i]!='?')
            {
                if(ss[i]>'0')
                {
                    c=u+ss[i]-'0'-1;d=v+ss[i]-'0';
                    for(j=i+1;j<l;j++)
                    {
                        c=c*10;d=d*10;
                        if(st[j]=='?')
                            c=c+9;
                        else c=c+st[j]-'0';
                        if(ss[j]=='?')
                            d=d+0;
                        else d=d+ss[j]-'0';
                    }
                    ans[s].x=c;ans[s++].y=d;
                }
            }
            if(st[i]!='?'&&ss[i]=='?')
            {
                if(st[i]<'9')
                {
                    c=u+st[i]-'0';d=v+st[i]-'0'+1;
                    for(j=i+1;j<l;j++)
                    {
                        c=c*10;d=d*10;
                        if(st[j]=='?')
                            c=c+9;
                        else c=c+st[j]-'0';
                        if(ss[j]=='?')
                            d=d+0;
                        else d=d+ss[j]-'0';
                    }
                    ans[s].x=c;ans[s++].y=d;
                }
            }
            if(st[i]=='?'&&ss[i]=='?')
            {
              c=u+0;d=v+1;
                    for(j=i+1;j<l;j++)
                    {
                        c=c*10;d=d*10;
                        if(st[j]=='?')
                            c=c+9;
                        else c=c+st[j]-'0';
                        if(ss[j]=='?')
                            d=d+0;
                        else d=d+ss[j]-'0';
                    }
                    ans[s].x=c;ans[s++].y=d;
            }
            if(st[i]!='?'&&ss[i]!='?')
            {
                if(st[i]<ss[i])
                {
                    c=u+st[i]-'0';d=v+ss[i]-'0';
                    for(j=i+1;j<l;j++)
                    {
                        c=c*10;d=d*10;
                        if(st[j]=='?')
                            c=c+9;
                        else c=c+st[j]-'0';
                        if(ss[j]=='?')
                            d=d+0;
                        else d=d+ss[j]-'0';
                    }
                    ans[s].x=c;ans[s++].y=d;
                }
            }
            h=0;
            if(st[i]!='?'&&ss[i]=='?')
            {
                u=u+st[i]-'0';
                v=v+st[i]-'0';
            }
            if(st[i]=='?'&&ss[i]!='?')
            {
                u=u+ss[i]-'0';
                v=v+ss[i]-'0';
            }
            if(st[i]!='?'&&ss[i]!='?')
            {
                if(st[i]!=ss[i])
                    h=1;
                u=u+st[i]-'0';
                v=v+ss[i]-'0';
            }
            if(h==1)
                break;
        }
        pf("Case #%lld: ",cs++);
        if(i==l)
        {
            print(u,v,l);
            continue;
        }
        u=0;v=0;
        for(i=0;i<l;i++)
        {
            u=u*10;v=v*10;
            if(st[i]=='?'&&ss[i]!='?')
            {
                if(ss[i]<'9')
                {
                    c=u+ss[i]-'0'+1;d=v+ss[i]-'0';
                    for(j=i+1;j<l;j++)
                    {
                        c=c*10;d=d*10;
                        if(st[j]=='?')
                            c=c+0;
                        else c=c+st[j]-'0';
                        if(ss[j]=='?')
                            d=d+9;
                        else d=d+ss[j]-'0';
                    }
                    ans[s].x=c;ans[s++].y=d;
                }
            }
            if(st[i]!='?'&&ss[i]=='?')
            {
                if(st[i]>'0')
                {
                    c=u+st[i]-'0';d=v+st[i]-'0'-1;
                    for(j=i+1;j<l;j++)
                    {
                        c=c*10;d=d*10;
                        if(st[j]=='?')
                            c=c+0;
                        else c=c+st[j]-'0';
                        if(ss[j]=='?')
                            d=d+9;
                        else d=d+ss[j]-'0';
                    }
                    ans[s].x=c;ans[s++].y=d;
                }
            }
            if(st[i]=='?'&&ss[i]=='?')
            {
              c=u+1;d=v+0;
                    for(j=i+1;j<l;j++)
                    {
                        c=c*10;d=d*10;
                        if(st[j]=='?')
                            c=c+0;
                        else c=c+st[j]-'0';
                        if(ss[j]=='?')
                            d=d+9;
                        else d=d+ss[j]-'0';
                    }
                    ans[s].x=c;ans[s++].y=d;
            }
            if(st[i]!='?'&&ss[i]!='?')
            {
                if(st[i]>ss[i])
                {
                    c=u+st[i]-'0';d=v+ss[i]-'0';
                    for(j=i+1;j<l;j++)
                    {
                        c=c*10;d=d*10;
                        if(st[j]=='?')
                            c=c+0;
                        else c=c+st[j]-'0';
                        if(ss[j]=='?')
                            d=d+9;
                        else d=d+ss[j]-'0';
                    }
                    ans[s].x=c;ans[s++].y=d;
                }
            }
            h=0;
            if(st[i]!='?'&&ss[i]=='?')
            {
                u=u+st[i]-'0';
                v=v+st[i]-'0';
            }
            if(st[i]=='?'&&ss[i]!='?')
            {
                u=u+ss[i]-'0';
                v=v+ss[i]-'0';
            }
            if(st[i]!='?'&&ss[i]!='?')
            {
                if(st[i]!=ss[i])
                    h=1;
                 u=u+st[i]-'0';
                v=v+ss[i]-'0';
            }
            if(h==1)
                break;
        }
        m=0;
        for(i=0;i<s;i++)
        {
            if(i==0)
            {
                m=abs(ans[i].x-ans[i].y);
            }
            else m=min(m,abs(ans[i].x-ans[i].y));
        }
        u=-1;
        for(i=0;i<s;i++)
        {
             if(m==abs(ans[i].x-ans[i].y))
             {
                 if(u==-1)
                 {
                     u=ans[i].x;
                     v=ans[i].y;
                 }
                 else
                 {
                     if(ans[i].x<u)
                     {
                         u=ans[i].x;
                         v=ans[i].y;
                     }
                     if(ans[i].x==u&&ans[i].y<v)
                     {
                         u=ans[i].x;
                         v=ans[i].y;
                     }
                 }
             }

        }
         print(u,v,l);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
