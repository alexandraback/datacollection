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
char c[1001000];
int main()
{
 freopen("a.in","r",stdin);
 freopen("a.out","w",stdout);
 long long t,t1;scanf("%I64d\n",&t);
 for(t1=1;t1<=t;t1++)
 {
  
  printf("Case #%I64d: ",t1);
  long long ls=0,i,k;
  while(c[ls-1]!=' ')
  {
   scanf("%c",&c[ls++]);
  }ls--;
  scanf("%I64d\n",&k);
  
  long long lg=0,o=0,sb=0;
  for(i=0;i<ls;i++)
  {
   if(c[i]!='a'&&c[i]!='e'&&c[i]!='i'&&c[i]!='o'&&c[i]!='u'){sb++;}else{sb=0;}
   if(sb>=k)
   {
    o+=(ls-i)*(i-k+1-lg+1);
    lg=i-k+2;
   }
  }
  printf("%I64d\n",o);
 }
}