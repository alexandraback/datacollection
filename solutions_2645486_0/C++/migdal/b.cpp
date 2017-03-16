/* Author : migdal */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <sstream>
#include <map>
#include <set>
#include <climits>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define INF 1000000000
#define ALL(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef long long LL;
vector<int>v;
int ma;
int e,r,n;
void sol(int act,int ener,int g)
{
   if(act==n)
   {
      if(ma<g)ma=g;
      return ;
   }
   int i,temp;
   for(i=0;i<=ener;i++)
   {
      temp=ener-i;
      if(temp+r>e)temp=e;
      else temp=temp+r;
      sol(act+1,temp,g+i*v[act]);
   }
   return;
}
int main()
{
   int test,num;
   int i,j;
   j=0;
   cin>>test;
   while(test--)
   {
      v.clear();
      cin>>e>>r>>n;
      for(i=0;i<n;i++){cin>>num;v.PB(num);}
      ma=0;
      sol(0,e,0);
      j=j+1;
      cout<<"Case #"<<j<<": "<<ma<<endl;
   }
   return 0;
}
