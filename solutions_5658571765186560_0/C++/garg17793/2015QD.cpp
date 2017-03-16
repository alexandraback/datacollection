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
  freopen ("D-small-attempt0.in", "r", stdin);
  freopen ("Dsmall.in", "w", stdout);
  int t,x,r,c,cs=1;
  string ans;
  cin>>t;
  while(t--)
  { ans="RICHARD";
  	cin>>x>>r>>c;
  	
	switch(x)
	{
		case 1: ans="GABRIEL"; break;
		case 2: 
		if((r*c)%2==0)
		ans="GABRIEL"; break;
		case 3:
		if(((r*c)%3==0) && (r*c)>3 )
		ans="GABRIEL"; break;
		case 4:
		if(((r*c)%4==0) && (r*c)>8 )
		ans="GABRIEL"; break;
	}
  	cout<<"Case #"<<cs++<<": "<<ans<<"\n";
  }
  return 0;
}

