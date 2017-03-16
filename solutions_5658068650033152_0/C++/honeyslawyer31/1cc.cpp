/*
*************************************************************************
* $ Author : honeyslawyer   $
* $ Name   : shashank gupta $
*************************************************************************
*
* Copyright 2014 @ honeyslawyer and shashank gupta
*
************************************************************************/
#include<cstdio>
#include<iostream>
#include<cmath>
#include<conio.h>
#include<cstring>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<string>
#include<climits>

#define mod 1000000007
#define ll long long

using namespace std;
ll gcd(ll a,ll b) {if(b==0) return a; return gcd(b,a%b);}

ll power(ll b,ll exp,ll m)
 {ll ans=1;
  b%=m;
  while(exp)
   {if(exp&1)
     ans=(ans*b)%m;
    exp>>=1;
	b=(b*b)%m;
   }
  return ans;
 }

int main()
{
    FILE *f1,*f2;
   f1=fopen("input.in","r");
    f2=fopen("output.txt","w");
    int t;
    fscanf(f1,"%d",&t);
    for(int z=1;z<=t;z++)
    {
    int n,m,k,ans;
    fscanf(f1,"%d %d %d",&n,&m,&k);
    if(n<3||m<3)
    {
        int r=max(n,m);
        int c=min(n,m);
        if(c==1)
         {
                if(k<=2)
                ans=k;
                else
                ans=k-1;
            }
        else
        {
            if(k<=4)
            ans=k;
            else if(k%1)
            ans=k;
            else
            ans=k-1;

        }
    }
    else
    {
        int r=max(n,m);
        int c=min(n,m);
        if(r==3&&c==3)
        {
            if(k>=5)
            ans=k-1;
            else
            ans=k;
        }
        else if(r==4&&c==3)
        {
           if(k<5)
           ans=k;
           if(k==5)
           ans=4;
           if(k==6)
           ans=5;
           if(k==7||k==8)
           ans=6;
           if(k>8)
           ans=6+k-8;
        }
        else if(r==4&&c==4)
        {
           if(k<5)
           ans=k;
           if(k==5)
           ans=4;
           if(k==6)
           ans=5;
           if(k==7||k==8)
           ans=6;
           if(k==9||k==10)
           ans=7;
           if(k==11||k==12)
           ans=8;
           if(k>12)
           ans=8+k-12;
        }
        else if(r==5&&c==4)
        {
           if(k<5)
           ans=k;
           if(k==5)
           ans=4;
           if(k==6)
           ans=5;
           if(k==7||k==8)
           ans=6;
           if(k==9||k==10)
           ans=7;
           if(k==11||k==12)
           ans=8;
           if(k==13||ans==14)
           ans=9;
           if(k==15||k==16)
           ans=10;
           if(k>16)
           ans=10+k-16;
        }
        if(r==5&&c==3)
        {
           if(k<5)
           ans=k;
           if(k==5)
           ans=4;
           if(k==6)
           ans=5;
           if(k==7||k==8)
           ans=6;
           if(k==9)
           ans=7;
           if(k==10||k==11)
           ans=8;
           if(k>11)
           ans=8+k-11;
        }
        
    }
    fprintf(f2,"Case #%d: %d\n",z,ans);
    }


getch();
return 0;
/*checklist
1)getch() and conio.h removed.*/
}
