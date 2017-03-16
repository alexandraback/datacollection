#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

#define FOR(i,v,n) for(int i=v;i<=n;i++)
#define tr(c,it) for(typeof(c.begin()) it=c.begin();it!=c.end();it++)

int T;
int x,y;
char s[10000];
int S;
int main()
{
  cin>>T;

  FOR(t,1,T)
    {
      cout<<"Case #"<<t<<": ";
      scanf("%d%d",&x,&y);
      S=0;
      int d=1;
      char r='E',l='W',no='N',so='S';
      if(x<0)
	swap(l,r),x=-x;
      while(x>=d)
	{
	  s[S++]=r;
	  x-=d++;
	}
      while(x)
	s[S++]=l,s[S++]=r,x--,d+=2;

      if(y<0)
	swap(no,so),y=-y;
      while(y>=d)
	s[S++]=no,y-=d++;
      while(y)
	s[S++]=so,s[S++]=no,y--,d+=2;
      s[S]=0;
      printf("%s\n",s);
    }
  return 0;
}
