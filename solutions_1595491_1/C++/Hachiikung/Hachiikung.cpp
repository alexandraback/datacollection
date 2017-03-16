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

struct apple
{ int x,y; }a[110];

bool compare(apple i,apple j){
    return i.y<j.y;
}

int main(){

    freopen("B-large.in","r",stdin);
    freopen("ppp","w",stdout);

    int t;
    S("%d",&t);

    for(int k=1;k<=t;k++)
    {
     int s,p;
     S("%d%d%d",&n,&s,&p);

     FOR(i,0,n)
     {
      S("%d",&a[i].x);
      if(a[i].x%3==0) a[i].y=a[i].x/3;
      else a[i].y=a[i].x/3+1;
     }

     sort(a,a+n,compare);

     ans=0;
     FOR(i,0,n)
     {
      if( a[i].y>=p ) ans++;
      else if( a[i].x>=2 && a[i].x%3!=1 && a[i].y+1>=p && s>0 ) ans++,s--;
     }

     P("Case #%d: %d\n",k,ans);
    }
}
