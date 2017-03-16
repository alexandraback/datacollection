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
int r,n,m,k;
vector<int>pr;
vector<int>form;
int tk[5];
int arr[5];
int ans[5];
void sub(int pos)
{
   int i;
   if(pos>n)
   {
      int pr=1;
      for(i=1;i<=n;i++)if(tk[i])pr=pr*arr[i];
      form.PB(pr);
      return;
   }
   for(i=0;i<=1;i++)
   {
      tk[pos]=i;
      sub(pos+1);
   }
}
int check()
{
   form.clear();
   sub(1);
   int fl=0;
   int i,j;
   for(i=0;i<pr.size();i++)
   {
      fl=0;
      for(j=0;j<form.size();j++)
      {
	 if(pr[i]==form[j])
	 {
	    fl=1;
	 
	    break;
	 }
      }
      if(!fl)return 0;
   }
   return 1;
}
void selection(int sel)
{
   int i;
   if(sel>n)
   {
       if(check())
       {
	  for(i=1;i<=n;i++)ans[i]=arr[i];
       }
       return;
   }
   for(i=2;i<=m;i++)
   {
      arr[sel]=i;
      selection(sel+1);
   }
}
int main()
{
   int test,num;
   int i,j,l;
   cin>>test;
   i=0;
   while(test--)
   {
      i++;
      cout<<"Case #"<<i<<":"<<endl;
      cin>>r>>n>>m>>k;
      for(j=0;j<r;j++)
      {
	  pr.clear();
          for(l=0;l<k;l++)
	  {
	     cin>>num;
	     pr.PB(num);
	  }
	  selection(1);
	  for(l=1;l<=n;l++)cout<<ans[l];
	  cout<<endl;
      }
   }
   return 0;
}
