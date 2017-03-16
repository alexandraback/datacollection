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
int t,r,c,w,sum,tmp,cnt;
int main()
{
    freopen("A-small.in","r",stdin);
   freopen("opx.txt","w",stdout);
   s(t);
   while(t--)
   {
       s2(r,c);
       cnt++;

       s(w);
       sum=0;
       sum+=((c/w)*r);
       tmp=c/w;
       if(c==(tmp*w))
       sum+=(w-1);
       else
       sum+=w;
       P("Case #%d: %d\n",cnt,sum);
   }
   return 0;
}
