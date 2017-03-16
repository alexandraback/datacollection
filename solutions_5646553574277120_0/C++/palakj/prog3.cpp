#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define s(n) scanf("%d",&n)
#define ss(n) scanf(" %s",n)
#define s2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ii pair<int,int>
#define F first
#define S second
#define P printf
#define E <<endl
#define mid (st+(end-st)/2)
using namespace std;
int t,c,d,v,i,sum,res,cnt,ar[40];
int main()
{
freopen("C-small.in","r",stdin);
   freopen("opx.txt","w",stdout);
   s(t);
   while(t--)
   {
      s2(c,d);
      cnt++;
      s(v);
      for(i=0;i<d;i++)
      s(ar[i]);
      res=0;
      sum=0;
      for(i=0;i<d;i++)
      {
         if(sum<ar[i])
         {
            for(int j=sum+1;j<ar[i];j++)
            {
               sum+=j;
               res++;
               j=sum;
               if(sum>=(ar[i]-1)||(sum>=v))
               break;

            }
         }
         sum+=ar[i];
         if(sum>=v)
         break;

      }
      if(sum<v)
      {
          for(int j=sum+1;j<=v;j++)
            {
               sum+=j;
               res++;
               j=sum;
               if(sum>=v)
               break;
            }
      }
      P("Case #%d: %d\n",cnt,res);
   }
   return 0;
}
