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
  freopen ("D-large (1).in", "r", stdin);
  freopen ("DLarge.in", "w", stdout);
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
		ans="GABRIEL"; 	break;
		
		case 3:
		if(r<2 || c<2)	ans="RICHARD";
		else if(((r*c)%3==0) && (r*c)>3 )	ans="GABRIEL"; 	break;
		
		case 4:
		if(r<3 || c<3)	ans="RICHARD";
		else if(((r*c)%4==0) && (r*c)>8 )
		ans="GABRIEL"; break;
		
		case 5:
		if(r<3 || c<3)	ans="RICHARD";
		else if(((r*c)%5==0) && (r*c)>15)
		ans="GABRIEL"; break;
		
		case 6:
		if(r<4 || c<4)	ans="RICHARD";
		else if(((r*c)%6==0) && (r*c)>18)
		ans="GABRIEL"; break;
		
		default:		
		ans="RICHARD";
	}
  	cout<<"Case #"<<cs++<<": "<<ans<<"\n";
  }
  return 0;
}

