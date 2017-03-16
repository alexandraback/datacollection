#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <list>
#include <cstring>
#include <stack>
#include <bitset>

using namespace std;

#define NMAX 2147483647
#define LMAX 9223372036854775807LL
#define pb push_back
#define pob pop_back
#define mp make_pair
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(a);i>(b);--i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)

int main()
{
  freopen("input.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int TS;
  scanf("%d",&TS);
  FORE(ts,1,TS) {
    double C, F, X;
    scanf("%lf%lf%lf",&C,&F,&X);
    double time = 0, t = 2.0, target, target2;
    while(true) {
      target = time + X / t;
      target2 = time + C / t +  X / (F + t);
      if(target2 < target) {
        time += C / t;
        t += F;
      }
      else
        break;
    }
    printf("Case #%d: %.7lf\n",ts,target);
  }
  return 0;
}
