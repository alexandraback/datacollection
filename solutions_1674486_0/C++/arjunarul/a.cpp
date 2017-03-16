#include<iostream>
#include<vector>

using namespace std;


int t,n,temp1,temp2,V[1200],flag1,flag2;
vector<int> A[1200];

void dfs(int v)
{
  if(V[v]!=0)
  {
    V[v]++;
    return;
  }
  V[v]++;
  
  for(int i=0;i<A[v].size();i++)
    dfs(A[v][i]);
  return;
}


int main()
{
  cin>>t;
  
  for(int q=1;q<=t;q++)
  {
    cin>>n;
    
    
    for(int i=1;i<=n;i++)
    {
      cin>>temp1;
      A[i].clear();
      for(int j=1;j<=temp1;j++)
      {
	cin>>temp2;
	A[i].push_back(temp2);
      }
    }
    flag2=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
	V[j]=0;
      }
      
      dfs(i);
      flag1=0;
      for(int j=1;j<=n;j++)
      {
	if(V[j]>1)
	  flag1=1;
      }
      
      if(flag1==1)
      {
	flag2=1;
	break;
      }
    }
      cout<<"Case #"<<q<<": ";

    if(flag2==0)
    {
      cout<<"No";
    }
    else
      cout<<"Yes";
    cout<<endl;
  }
}
  
      

