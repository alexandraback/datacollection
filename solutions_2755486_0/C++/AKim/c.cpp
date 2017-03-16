#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
vector<pair<pair<long long,long long>,pair<long long,long long> > > vc;
long long x[660]={0},z[660]={0};
int main()
{
 freopen("c.in","r",stdin);
 freopen("c.out","w",stdout);
 long long t,t1;scanf("%I64d\n",&t);
 for(t1=1;t1<=t;t1++)
 {long long i,f;vc.clear();for(i=0;i<600;i++){x[i]=0;z[i]=0;}
  printf("Case #%I64d: ",t1);
  long long n,q=0;scanf("%I64d",&n);
  for(;n>0;n--)
  {long long d,na,w,e,s,dd,dp,ds;
   scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&d,&na,&w,&e,&s,&dd,&dp,&ds);
   for(i=0;i<na;i++)
   {
    vc.pb(mp(mp(d,s),mp(w,e)));
    q++;
    d+=dd;w+=dp;e+=dp;s+=ds;
   }
  }
  sort(&vc[0],&vc[q]);
  long long d=0,o=0;
  for(i=0;i<q;i++)
  {//printf("%d %d %d %d\n",vc[i].fs.fs,vc[i].fs.sc,vc[i].sc.fs,vc[i].sc.sc);
   if(d<vc[i].fs.fs){for(f=0;f<600;f++){x[f]=max(x[f],z[f]);z[f]=0;}d=vc[i].fs.fs;}
   bool log=0;
   for(f=vc[i].sc.fs+300;f<vc[i].sc.sc+300;f++)
   {z[f]=max(z[f],vc[i].fs.sc);if(vc[i].fs.sc>x[f]){log=1;}}
   if(log){o++;}
  }
  printf("%I64d\n",o);
 }
}