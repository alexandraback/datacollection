#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define mod 1000000007
using namespace std;
int main()
{
  std:ios_base::sync_with_stdio(false);
  freopen ("A-large.in", "r", stdin);
  freopen ("Alargeout.in", "w", stdout);
  int t,s,cs=1,i;
  int tmp=0,ans=0;
  string st;
  cin>>t;
  while(t--)
  { tmp=0; ans=0;
  	cin>>s;
  	cin>>st;
  	
  	tmp+=(st[0]-'0');
  	
	for(i=1;i<=s;i++)
  	{
  	  if((st[i]-'0')!=0)
  	  {
  	  	if(tmp>=i)
	    {
	  	 	tmp+=(st[i]-'0');
	    }	
	    else
	    {
	  	 	ans+=(i-tmp);
	  	 	tmp+=(i-tmp);
	  	 	tmp+=(st[i]-'0');
	    }	
  	  }
  	}
  	cout<<"Case #"<<cs++<<": "<<ans<<"\n";
  }
  
  
  return 0;
}

