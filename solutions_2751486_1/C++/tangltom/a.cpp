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
int L;
char s[1000005];
int main()
{
  cin>>T;
  FOR(t,1,T)
    {
      cout<<"Case #"<<t<<": ";
      scanf("%s%d",s+1,&L);
      int i=1,cons=0,all=0,startc=0,prevc=0;
      long long sum=0;
      while(s[i])
	{
	  switch(s[i])
	    {
	    case 'a':
	    case 'e':
	    case 'i':
	    case 'o':
	    case 'u':
	      if(cons>=L)
		prevc=startc;
	      cons=0;
	      break;
	    default:
	      if(cons==0)
		startc=i;
	      cons++;
	      all++;
	      if(cons>L)
		startc++;
	    }
	  if(cons<L)
	    {
	      sum+=prevc;
	    }
	  else
	    {
	      sum+=startc;
	    }
	  i++;
	}
      cout<<sum<<'\n';
    }
  return 0;
}
