#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long int t,a,n,ans1,curr,needed,temp1;
vector<long long int> V;

int main()
{
  cin>>t;
  
  for(int q=1;q<=t;q++)
  {
    V.clear();
    cin>>a>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>temp1;
      V.push_back(temp1);
    }
    
    if(a==1)
      ans1=n;
    else
    {
    sort(V.begin(),V.end());
    
    ans1=n;
    
    for(int k=n;k>=1;k--)
    {
      curr=a;
      needed=0;
      for(int i=1;i<=k;i++)
      {
	if(curr<=V[i-1])
	{
	  while(curr<=V[i-1])
	  {
	    needed++;
	    curr=(2*curr)-1;
	  }
	  curr+=V[i-1];
	   
	   
	}
	else
	curr+=V[i-1];
      }
      
      needed += (n-k);
      if(needed<ans1)
	ans1=needed;
    }
    }
    
  
    cout<<"Case #"<<q<<": "<<ans1<<"\n";
    
  }
}
	