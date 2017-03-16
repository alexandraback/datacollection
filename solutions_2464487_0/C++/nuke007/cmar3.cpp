#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
   int T,r,t,i,j,c,p;
   scanf("%d",&T);
   for(i=1;i<=T;++i)
   {
      scanf("%d %d",&r,&t);
      c=0;
      j=r;
      while(1)
      {
         p=((r+1)*(r+1))-(r*r);
         if(p<=t)
         {
            ++c;
            t-=p;
            r+=2;
         }
         else break;
      }
      printf("Case #%d: %d\n",i,c);
   }
   return 0;
}
