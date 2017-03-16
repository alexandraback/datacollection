/*
  ------ HachiInfinity ------
  ------ Worrachate Bosri ------
  ------ Mahidol Wittayanusorn ------
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<utility>

using namespace std;
#define FOR(i,ST,FN) for(int i=ST;i<FN;i++)
#define FOR2(x) for(it=x.begin();it!=x.end();it++)
#define mod
#define inf
#define PAUSE system("pause")
#define S scanf
#define P printf
#define MAXN

int n,m;
int ans,sum,tmp;
int MAX,MIN;

int b[10];

int main(){

    freopen("C-large.in","r",stdin);
    freopen("ppp","w",stdout);

    b[0]=1;
    for(int i=1;i<=8;i++)
     b[i]=b[i-1]*10;

    int t;
    S("%d",&t);

    for(int k=1;k<=t;k++)
    {
     int x,y;
     S("%d%d",&x,&y);
     ans=0;
     FOR(i,x,y)
     {
      int p=0; tmp=i;

      while(tmp!=0)
       p++,tmp/=10;

      tmp=i;
      do
      {
       int t=tmp,s=0;
       while(t!=0)
        s++,t/=10;

       if( s==p && tmp>i && tmp<=y ) ans++;

       int r=tmp%10;
       tmp=tmp/10+r*b[p-1];

      }while(tmp!=i);
     }
     P("Case #%d: %d\n",k,ans);
    }
}
