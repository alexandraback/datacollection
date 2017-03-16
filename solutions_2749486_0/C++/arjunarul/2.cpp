#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

long long int t,x,y;

int main()
{
  cin>>t;
  
  for(int q=1;q<=t;q++)
  {
    cin>>x>>y;
    cout<<"Case #"<<q<<": ";
    
    if(x>=0)
    {
      for(int i=1;i<=x;i++)
      {
	cout<<"WE";
      }
    }
    else
    {
      x*=(-1);
      for(int i=1;i<=x;i++)
      {
	cout<<"EW";
      }
    }
    
    if(y>=0)
    {
      for(int i=1;i<=y;i++)
      {
	cout<<"SN";
      }
    }
    else
    {
      y*=(-1);
      for(int i=1;i<=y;i++)
      {
	cout<<"NS";
      }
    }
      
      
    
    
  
    cout<<"\n";
    
  }
}
	