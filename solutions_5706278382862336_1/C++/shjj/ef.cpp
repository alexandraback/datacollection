//shjj-ef

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int A[100],ls;
long long x,y,now;

long long lcm(long long x,long long y){return x/__gcd(x,y)*y;}

int main()
{
freopen("ef.in","r",stdin);
freopen("ef.out","w",stdout);
int Test,tt=0;scanf("%d",&Test);
for (;Test--;)
  {
  char c;
  scanf("%I64d%c%I64d",&x,&c,&y);
  if (!x){printf("Case #%d: impossible\n",++tt);continue;}
  long long gg=__gcd(x,y);
  x/=gg;y/=gg;
  if (x==y&&y==1){printf("Case #%d: 0\n",++tt);continue;}
  ls=0;now=1;
  for (int i=1;i<=40&&x;i++)
    {
	now<<=1;
	long long _y=lcm(now,y);
	x*=_y/y;y=_y;
	if (x>=_y/now) x-=_y/now,A[++ls]=i;
	long long gg=__gcd(x,y);
	x/=gg;y/=gg;
	}
  if (x) printf("Case #%d: impossible\n",++tt);
    else printf("Case #%d: %d\n",++tt,A[1]);
  }
}