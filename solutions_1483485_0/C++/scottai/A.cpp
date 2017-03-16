#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#define zero(a) (abs(a)<eps)
#define lowbit(a) ((a)&(-(a)))
#define abs(a) ((a)>0?(a):(-(a)))
#define cj(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define dj(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define dis(x1,y1,x2,y2) sqrt(((x2)-(x1))*((x2)-(x1))+((y2)-(y1))*((y2)-(y1)))
const double eps = 1e-9;
const int oo = 1000000000;
const double E = 2.7182818284590452353602874713527;
const double pi = 3.1415926535897932384626433832795;
using namespace std;

char t[200],str[200];

int main()
{
   freopen("A-small-attempt0.in","r",stdin);
   freopen("A-small-attempt0.out","w",stdout);
   int n;
   t['a']='y';
   t['b']='h';
   t['c']='e';
   t['d']='s';
   t['e']='o';
   t['f']='c';
   t['g']='v';
   t['h']='x';
   t['i']='d';
   t['j']='u';
   t['k']='i';
   t['l']='g';
   t['m']='l';
   t['n']='b';
   t['o']='k';
   t['p']='r';
   t['q']='z';
   t['r']='t';
   t['s']='n';
   t['t']='w';
   t['u']='j';
   t['v']='p';
   t['w']='f';
   t['x']='m';
   t['y']='a';
   t['z']='q';
   t[' ']=' ';
   scanf("%d\n",&n);
   for (int i=1;i<=n;i++)
   {
      gets(str+1);
      printf("Case #%d: ",i);
      for (int j=1;str[j];j++)
         str[j]=t[str[j]];
      puts(str+1);
   }
   return 0;
}
