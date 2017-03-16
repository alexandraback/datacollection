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
int main()
{
 freopen("b.in","r",stdin);
 freopen("b.out","w",stdout);
 long long t,t1;scanf("%I64d\n",&t);
 for(t1=1;t1<=t;t1++)
 {
  
  printf("Case #%I64d: ",t1);
  long long x,y;scanf("%I64d%I64d",&x,&y);
  while(x>0){printf("WE");x--;}
  while(x<0){printf("EW");x++;}
  while(y>0){printf("SN");y--;}
  while(y<0){printf("NS");y++;}
  printf("\n");
 }
}