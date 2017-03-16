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
   FILE *fpi,*fpo;
   fpi=fopen("input.in","r");
   fpo=fopen("output.txt","w");

  int t;
  fscanf(fpi,"%d",&t);
  for(int z=1;z<=t;z++)
  {
        int p,q;
        fscanf(fpi,"%d/%d",&p,&q);
        int c=0,flag=0,flag1=0,ans=0;
        map<int,int> map;
        map[p]=1;
        while(1)
        {
            //cout<<c<<endl;
            if(flag==0)
            {
               if(p==q)
               {
                    fprintf(fpo,"%d\n",c);
                    ans=c;
                    cout<<c<<endl;
                    flag=1;
                    flag1=1;
                    break;
                }
                else if(p<q)
                {
                    p=p*2;
                    c++;
                    if(map[p]==1)
                    {
                        flag1=2;
                        break;
                    }
                    map[p]=1;
                }
                else if(p>q)
                {
                   ans=c;
                   flag=1;
                }
            }
            else
            {
                if(p>q)
                {
                    p=p-q;
                }
                else if(p<q)
                {
                    p=p*2;
                    if(map[p]==1)
                    {
                        flag1=2;
                        break;
                    }
                    map[p]=1;
                }
                else
                {
                    flag1=0;
                    break;
                }
            }
        }
        if(flag1==0)
        fprintf(fpo,"%d\n",ans);
        else if(flag1==2)
        fprintf(fpo,"impossible\n");
    }


getch();
return 0;
/*checklist
1)getch() and conio.h removed.*/
}
