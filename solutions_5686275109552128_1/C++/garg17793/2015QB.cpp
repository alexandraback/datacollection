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
  freopen ("B-large.in", "r", stdin);
  freopen ("BLarge.in", "w", stdout);
  int t,d,i,ans,cs=1,mx,j;
  int a[1010];
  cin>>t;
  while(t--)
  { ans=1000000000; mx=-1;
  	cin>>d;
  	for(i=0;i<d;i++)
  	{
  		cin>>a[i];
  		mx=max(a[i],mx);
  	}
  	
  	for(i=1;i<=mx;i++)
  	{ int steps=0;
  	  for(j=0;j<d;j++)
  	  {
  	  	if(a[j]>=i)
  	  	{
  	  		if(a[j]%i==0)
  	  	  	  		steps+=((a[j]/i)-1);
  	  		else
  	  				steps+=((a[j]/i));
  	  	}
  	  }	
  	  ans=min(ans,steps+i);
  	}

  	cout<<"Case #"<<cs++<<": "<<ans<<"\n";
 }
  return 0;
}

