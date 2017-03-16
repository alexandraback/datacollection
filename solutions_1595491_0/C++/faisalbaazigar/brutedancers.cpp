#include<iostream>
#include<cmath>

using namespace std;

int main()
{
  int test;
  cin>>test;
  for(int q=1;q<=test;q++)
  {
    int n,s,p,t,c=0;
    cin>>n>>s>>p;
    for(int i=0;i<n;i++)
    {
      cin>>t;
      bool poss=0,possneed=0;
      for(int i=0;i<=10;i++)
      {
	for(int j=0;j<=10;j++)
	{
	  int k=t-i-j;
	  if(k>=0 && k<=10)
	  {
	    if(abs(k-i)<=1 && abs(k-j)<=1 && abs(j-i)<=1 && max(max(i,j),k)>=p)
	    {
	      //cout<<k<<" "<<i<<" "<<j<<"\n";
	      poss=1;
	    }
	    else if(abs(k-i)<=2 && abs(k-j)<=2 && abs(j-i)<=2 && max(max(i,j),k)>=p)
	    {
	      //cout<<k<<" "<<i<<" "<<j<<"\n";
	      possneed=1;
	    }
	  }
	}
      }
      if(poss)
	c++;
      else if(possneed && s)
      {
	c++;
	s--;
      }
    }
    cout<<"Case #"<<q<<": "<<c<<"\n";
  }
  return 0;
}