#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<int> V[676070];

long long int t,N,d[11],n[11],w[11],e[11],s[11],dd[11],dp[11],ds[11],ans1,c,curr,A[1000];


int main()
{
  cin>>t;
  
  for(int q=1;q<=t;q++)
  {
    cin>>N;
    for(int i=1;i<=N;i++)
    {
      cin>> d[i]>> n[i]>> w[i]>> e[i]>> s[i]>> dd[i]>> dp[i]>> ds[i];
    }
    
    for(int i=0;i<=676060;i++)
    {
      V[i].clear();
    }
    
    for(int i=1;i<=N;i++)
    {
      curr=d[i];
      for(int j=1;j<=n[i];j++)
      {
	V[curr].push_back(i);
	curr+=dd[i];
      }
    }
    
    ans1=0;
    
    for(int i=0;i<=500;i++)
      A[i]=0;
    
    for(int i=0;i<=676060;i++)
    {
//       if(i<15)
//       {
// 	cout<<"Day "<<i<<"\n";
// 	for(int j=-10;j<=10;j++)
// 	  cout<<"A["<<j<<"]="<<A[j+250]<<"\n";
// 	cout<<"\n";
//       }
// 	
	 

      
      for(int j=0;j<V[i].size();j++)
      {
	c=V[i][j];
	
	for(int k=w[c];k<e[c];k++)
	{

	  
	  if(A[k+250]<s[c])
	  {
	    ans1++;
	    break;
	  }
	}
      }
      
      
      for(int j=0;j<V[i].size();j++)
      {
	c=V[i][j];
	
	for(int k=w[c];k<e[c];k++)
	{
	  if(A[k+250]<s[c])
	  {
	    A[k+250]=s[c];
	  }
	}
	
	s[c]+=ds[c];
	w[c]+=dp[c];
	e[c]+=dp[c];
	
      }
      
      
    }
	

    cout<<"Case #"<<q<<": "<<ans1<<"\n";
    /*
    for(int i=1;i<=N;i++)
      cout<<w[i]<<" "<<e[i]<<" "<<s[i]<<"\n";*/
    
  }
}
	